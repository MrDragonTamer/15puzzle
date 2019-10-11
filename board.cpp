#include<vector>

enum class dir{
  n=1, w, s, e 
};

struct point{
  int x;
  int y;
};

class board{
  public:
	
	  board();

	  void move_tile(point p1, point p2); //swaps two tiles (if valid)
	  void set_board_width(int bWidth) { boardWidth = bWidth; }

	  point empty_tile() const; //returns point of tile 16 (the empty tile)
	  std::vector<int> tile_order() const;
	  int board_width() const { return boardWidth; }



  private:
	  bool is_board_valid();

	  int boardWidth;
	  std::vector<std::vector<int>> gboard;
};


board::board():
	boardWidth{4}
{
	for(int i=0; i<boardWidth*boardWidth; i++) {
		
	}
}
