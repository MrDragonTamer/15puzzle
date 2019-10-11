#include<iostream>
#include<stdexcept>
#include"board.cpp"


int main() {
	try{
		
		return 0;
	}
	catch(std::exception& e) {
		std::cerr<<e.what()<<std::endl;
		return 1;
	}
	catch(...) {
		std::cerr<<"Unknown Exception Thrown"<<std::endl;
		return 2;
	}

	return 0;
}
