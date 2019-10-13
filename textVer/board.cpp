#include<vector>
#include<time.h>
#include<cstdlib>
#include<iostream>
#include<iomanip>
#include<stdexcept>
#include<sstream>

enum class dir{
  n=1, w, s, e 
};

struct point{
  int x;
  int y;
};

class board{
  public:
	
	  board(int bWidth=4, int tWidth=4);
		
	  void init();
	  void swap_tile(point p1, point p2); //swaps two tiles (if valid)
	  void set_board_width(int w);

	  std::vector<int> tile_order() const;
	  point empty_tile() const; //returns point of tile 16 (the empty tile)
	  int board_width() const { return boardWidth; }
	  bool valid_point(point p) const;
	  int tile(point p) const;
	  void draw() const;
	  



  private:
	  bool is_board_valid() const;

	  int boardWidth; //number of tiles on board (e.g 4 = 4 by 4 board)
	  int tileWidth;  //number of chars for setw when drawing board
	  std::vector<std::vector<int>> gboard; 
};


board::board(int bWidth, int tWidth):
	tileWidth{tWidth}
{
	set_board_width(bWidth);
	init();
}

void board::init() {
	//clear gboard incase already init once
	gboard.clear();
	//init gboard
	for(int row=0; row<boardWidth; row++) {
		std::vector<int> currRow;
		for(int col=0; col<boardWidth; col++) {
			//create row vector
			currRow.push_back(-1); //-1 is an invalid number for the final gboard, so if something weird happens hopefully it'll be easier to detect
		}
		//put row vector in gboard
		gboard.push_back(currRow);
	}

	srand(time(0));

	std::vector<int> usedNums; 
	for(int row=0; row<boardWidth; row++) {
		for(int col=0; col<boardWidth; col++) {
			int num=rand()%(boardWidth*boardWidth)+1;
			for(size_t currTile=0; currTile<usedNums.size(); currTile++) {
				if(usedNums.size()!=0) {	
					if(usedNums[currTile]==num) {
						num=rand()%(boardWidth*boardWidth)+1;
						currTile=-1;
					}
				}
			}
			gboard[row][col]=num;
			usedNums.push_back(num);
		}
	}
	if(!is_board_valid()) {
		throw std::runtime_error("Invalid Board!");
	}
}

void board::swap_tile(point p1, point p2) {
	int temp = gboard[p2.y][p2.x];
	gboard[p2.y][p2.x]=gboard[p1.y][p1.x];
	gboard[p1.y][p1.x]=temp;
}

void board::set_board_width(int w) {
	if(w<=0) {
		throw std::runtime_error("board::set_board_width(int w): Invalid board width, width must be greater than 0");
	}
	else{
		boardWidth=w;
	}
}

std::vector<int> board::tile_order() const {
	std::vector<int> nums;
	for(int row=0; row<boardWidth; row++) {
		for(int col=0; col<boardWidth; col++) {
			nums.push_back(gboard[row][col]);
		}
	}

	return nums;
}

point board::empty_tile() const {
	std::vector<int> tiles=tile_order();
	int empTile=-1;
	for(size_t i=0; i<tiles.size(); i++) {
		if(tiles[i]==boardWidth*boardWidth) {
			empTile=i;
		}
	}
	
	point p;

	//calculate x
	p.x=empTile%boardWidth;

	//calculate y
	p.y=(empTile-p.x)/boardWidth;
	
	return p;
}

bool board::valid_point(point p) const {
	if(p.x>=0 && p.x<boardWidth && p.y>=0 && p.y<boardWidth) {
		return true;
	}
	return false;
}

int board::tile(point p) const {
	if(!valid_point(p)) {
		std::ostringstream err;
		err<<"invalid point to board::tile(point p)! point: ("<<p.x<<","<<p.y<<")";
		throw std::runtime_error(err.str());
	}
	return gboard[p.y][p.x];
}


void board::draw() const {
	for(int row=0; row<boardWidth; row++) {
		for(int col=0; col<boardWidth; col++) {
			if(gboard[row][col]!=boardWidth*boardWidth) {
				std::cout<<std::setw(tileWidth/2)<<gboard[row][col]<<std::setw(tileWidth/2)<<"";
			}
			else {
				std::cout<<std::setw(tileWidth/2)<<" "<<std::setw(tileWidth/2)<<"";
			}
		}
		std::cout<<std::endl;
	}
}

bool board::is_board_valid() const {
	std::vector<int> usedNums;
	for(int row=0; row<boardWidth; row++) {
		for(int col=0; col<boardWidth; col++) {
			usedNums.push_back(gboard[row][col]);
		}
	}

	for(size_t i=0; i<usedNums.size(); i++) {
		int currNum=usedNums[i];
		for(size_t j=0; j<usedNums.size(); j++) {
			if(!(j==i)) {
				if(currNum==usedNums[j]) {
					return false;
				}
			}
		}
	}
	return true;
}
