#ifndef BOARD_HPP_
#define BOARD_HPP_

#include <iostream>

class board {
private:
	bool _team; //true = white and false = black
public:
	board();
	board(const board& b);

	constexpr int rows() const {return 8;}
	constexpr int columns() const {return 8;}
	bool team() const {return _team;} 

	// this class can be copied and moved
	board& operator=(const board& b);
       	board& operator=(const board&& b);	

};

#endif
