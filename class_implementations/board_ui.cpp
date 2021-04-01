#include "../headers/board_ui.hpp"
#include <iostream>

board_ui::board_ui(board* b) {
	_board = b;
}

/* this is the only public method of the board_ui class and is in
 * charge of printing the board using cout
 * */

void board_ui::print() const {
	bool team = _board->team();
	print_column_letters();	
	for(int row = 0; row < _board->rows(); row ++) {
		print_row(team, row);
		team = !team;
	}
	print_column_letters();	
}

/* each row of a board is divided into squares(*I call them squares but the height and width do not match)
 * the characters used to display a square change accordingly to the team they belong to (white or black),
 * the squares are also divided into rows and columns(square_row and square_column). Not all rows are printed the same way, since
 * some of them have to also display the number of the row 
 * */
void board_ui::print_row(bool& team, int row) const {
	//the first row of a square is different from the rest because is where the number of the row is displayed
	print_square_row_with_row_number(team, row);
	for(int square_row = 1; square_row < SQUARE_ROWS; square_row++) 
	{
		print_square_row_padding();
		print_square_row(team);	
		std::cout << std::endl;
	}
}

/*prints a basic square row no number or piece*/
void board_ui::print_square_row(bool& team) const {
	for(int column = 0; column < _board->columns(); column++) {
		for(int square_column = 0; square_column < SQUARE_COLUMNS; square_column++) {
			std::cout << TEAM_SQUARES[team]; 
		}
		team = !team;
	}	
}

void board_ui::print_square_row_with_row_number(bool& team, int row) const {
	print_row_number(row, false);
	print_square_row(team);
	print_row_number(row, true);
	std::cout << std::endl;
}

void board_ui::print_column_letters() const {
	print_square_row_padding();
	for (int column = 0; column < _board->columns(); column++) {
		std::cout << char(65 + column); 
		for(int i = 0; i < SQUARE_COLUMNS - 1; i++) {
			std::cout << ' ';
		}
	}
	std::cout << std::endl;
}

/* the number of the row is displayed on the first row of each square and is showed
 * at both sides. At the left the number goes first and then the padding is added
 * and at the right it starts with the padding and then displays the number
 * */
void board_ui::print_row_number(int row, bool padding_first) const {
	//left
	if(padding_first) {	
		print_square_row_padding(1);
		std::cout << (_board->team() ? row + 1 : _board->rows() - row);
	}
	//right
	else {	
		std::cout << (_board->team() ? row + 1 : _board->rows() - row);
		print_square_row_padding(1);
	}
}

/* prints the horizontal padding that comes before or after the numbers and before the letters.
 * sometimes part of the padding is occupied by a number so not always the same ammount of padding is needed*/
void board_ui::print_square_row_padding(int starting_point) const {
	for(int padding = starting_point; padding < PADDING; padding++) {
		std::cout << PADDING_CHAR;
	}
}
