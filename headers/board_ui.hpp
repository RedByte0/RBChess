#ifndef BOARD_UI_HPP_
#define BOARD_UI_HPP_

#include "board.hpp"

/* I decided to move all the UI related functions into another class
 * since I always find that UI related things take up a lot of space
 * and end up making the code more confusing*/

class board;

class board_ui {
private:
	const board* _board;
	// '#' for the black squares and ' ' for the white ones
	const char TEAM_SQUARES[2] = {'#', ' '};	
	const int SQUARE_COLUMNS = 6;
	const int SQUARE_ROWS = 3;
	//just so it is easier to read there is some padding between the numbers, the letters and the board 
	const int PADDING = 2; 
	const char PADDING_CHAR = ' ';

	void print_row(bool& team, int row) const;
	void print_square_row(bool& team) const;
	void print_square_row_with_row_number(bool& team,int row) const;
	void print_column_letters() const;
	void print_row_number(int row, bool padding_first) const;
	void print_square_row_padding(int starting_point = 0) const;
	
public:
	board_ui(board* b);
	void print() const;

};

#endif
