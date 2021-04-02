#ifndef BOARD_PRINTER_HPP_
#define BOARD_PRINTER_HPP_

#include "board.hpp"
#include <memory>

/* I decided to move all the UI related functions into a functor
 * since I always find that UI related things take up a lot of space
 * and end up making the code more confusing*/

class board;

class board_printer {
private:
	// '#' for the black squares and '_' for the white ones
	const char TEAM_SQUARES[2] = {'#', '-'};	
	/* SQUARE_COLUMNS can not be a multiple of 2 or smaller than 5 
	 * otherwise the pieces are not printed properly*/
	const unsigned int SQUARE_COLUMNS = 7; 
	const unsigned int SQUARE_ROWS = 3;
	//just so it is easier to read there is some padding between the numbers, the letters and the board 
	const unsigned int PADDING = 2; 
	const char PADDING_CHAR = ' ';

	void print_row(bool team, int row, int& board_position) const;
	void print_square_row(bool team) const;
	void print_square_row_with_row_number(bool team,int row) const;
	void print_square_row_with_piece(bool team, int& board_position) const;
	void print_column_letters() const;
	void print_row_number(int row, bool padding_first) const;
	void print_square_row_padding(int starting_point = 0) const;
	
public:
	board_printer();
	void operator()();
	board_printer(const board& b) = delete;
	board_printer(const board&& b) = delete;
	void operator=(const board& b) = delete;
	void operator=(const board&& b) = delete;
};

#endif