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
	
	/* all of the pieces share an static instances of
	 * the board class, board is a singleton and board::instance()
	 * can be called from any point within the program
	 * so I think that it is fine to leave this as public*/
	static std::shared_ptr<board> board_ptr;

	bool team() const {return _team;}
	unsigned int position() const {return _position;}
	bool moved() const {return _moved;}

	/* moves the piece to a new position. It is important to know
	 * that this method does not check if the new poisition is 
	 * a valid one or not, that should be checked before calling this method*/
	virtual void move(unsigned int position);

	//the visual representation of a piece when printed
	virtual const char* icon() const {return nullptr;}
	//returns a vector with all the possible movements that a piece can make
	virtual std::vector<unsigned int> possible_movements() const {return std::move(std::vector<unsigned int>());}
	//cheks if the given position is part of the vector returned by possible_movements
	bool valid_move(unsigned int position);

	/* horizontal movements are a bit different from the rest. It is important that we are not taking as valid positions
	 *  that are not from the same row as the original*/
	void horizontal_movements(std::vector<unsigned int>& movements) const;
	/* most pieces can move on different directions until they reach the end of the board or they collide*/
	void vertical_movements(std::vector<unsigned int>& movements) const;
	void diagonal_movements(std::vector<unsigned int>& movements) const;
};

#endif
