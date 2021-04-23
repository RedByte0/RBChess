#ifndef BOARD_HPP_
#define BOARD_HPP_

#include <iostream>
#include <vector>
#include "piece.hpp"
#include <cmath>
#include <memory>

/* this class represents the board where the pieces are located.
 * in order to simplify some things the black pieces are alway placed
 * on top of the white pieces even if displayed otherwise. this makes
 * some calculations much easier.
 **/
class piece;

class board {
private:
	//all of the pieces that are currently on the board
	std::vector<std::shared_ptr<piece>> _pieces;
	bool _team; //true = white and false = black

	//this is a singleton so the constructor is private
	board();
public:
	//this class can not be copied or moved
	board(const board& b) = delete;
	board(const board&& b) = delete;
	board& operator=(const board&) = delete;
	board& operator=(const board&& b) = delete;

	//load a vector of pieces
	void initialize_pieces(std::vector<std::shared_ptr<piece>>& pieces) {
		_pieces = std::move(pieces);
	}

	/* returns a shared pointer to the only instance of this class.
	 * I decided to make this inline because is used all over the program
	 * but I dont know if I will get any performance improvement*/
	inline static std::shared_ptr<board> instance() {
		static std::shared_ptr<board> inst{new board};
		return inst;	
	};

	unsigned int rows() const {return 8;}
	unsigned int columns() const {return 8;}
	bool team() const {return _team;} 
	unsigned int size() const {return rows() * columns();}
	void add_piece(std::shared_ptr<piece> p) {_pieces.push_back(std::move(p));}

	//a simple check to see if a given position is a valid position inside the board
	inline bool position_out_of_bounds(unsigned int position) const {
		return position < size();
	};

	//given a position this method can determine to which row it belongs to
	inline unsigned int get_row_from_position(unsigned int position) const {
		return floor(position / columns());
	}

	/* looks inside the _pieces vector a checks if any piece has the value _position
	 * equal to the given value*/
	bool there_is_a_piece_at(unsigned int position) const;
	//same as the one above but it only looks for pieces with the same _team as the team parameter
	bool there_is_a_piece_at(unsigned int position, bool team) const;

	/* finds and deletes the piece at the given position, if the piece is not found returns false,
	 * true otherwise*/
	bool delete_piece(unsigned int position);

	/* it is possible to get a piece from the board using the [] operator.
	 * the position given to the operator IS NOT the position of the piece
	 * inside the _pieces vector instead it looks for  the value _position 
	 * of the piece*/
	std::shared_ptr<piece> operator[](unsigned int position);
	const std::shared_ptr<piece> operator[](unsigned int position) const;
};

#endif
