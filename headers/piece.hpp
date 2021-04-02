#ifndef PIECE_HPP_
#define PIECE_HPP_

#include "board.hpp"
#include <vector>
#include <iostream>
#include <memory>

class board;

/* this is a pure virual class that acts as the base class for all the 
 * different kinds of pieces*/
class piece {
private:	
	//the team the piece belonds to(true = white, false = black)
	bool _team;
	//the position of the pieces within the board
	unsigned int _position;
	/* registers if the piece has been moved or not, some pieces such as the pawn
	 * behave differently if they have not been moved*/
	bool _moved;

public:
	piece();
	piece(int position, bool team);
	virtual ~piece() = 0;

	bool team() const {return _team;}
	unsigned int position() const {return _position;}
	bool moved() const {return _moved;}

	//the visual representation of a piece when printed
	virtual const char* icon() const {return nullptr;}
	//returns a vector with all the possible movements that a piece can make
	virtual std::vector<unsigned int> possible_movements() const {return std::move(std::vector<unsigned int>());}
};

#endif
