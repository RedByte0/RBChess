#include "../headers/board_printer.hpp"
#include <iostream>


board_printer::board_printer() {}

/* this is the only public method of the board_printer class and is in
 * charge of printing the board using cout
 * */
void board_printer::operator()() {
	//bool team = board::instance()->team();
	bool team = true;
	//keeps track of which position of the board is currently been printed
	int board_position = 0;
	
	print_column_letters();	
	for(unsigned int row = 0; row < board::instance()->rows(); row ++) {
		print_row(team, row, board_position);
		team = !team;
	}
	print_column_letters();	
}

/* each row of a board is divided into squares(*I call them squares but the height and width do not match)
 * the characters used to display a square change accordingly to the team they belong to (white or black),
 * the squares are also divided into rows and columns(square_row and square_column). Not all rows are printed the same way, since
 * some of them have to also display the number of the row 
 * */
void board_printer::print_row(bool team, int row, int& board_position) const {
	//the first row of a square is different from the rest because is where the number of the row is displayed
	print_square_row_with_row_number(team, row);
	for(unsigned int square_row = 1; square_row < SQUARE_ROWS; square_row++) 
	{
		print_square_row_padding();
		if(square_row == SQUARE_ROWS / 2)
			print_square_row_with_piece(team, board_position);
		else
		print_square_row(team);	
		std::cout << '\n';
	}

}

/*prints a basic square row no numbers nor pieces*/
void board_printer::print_square_row(bool team) const {
	for(unsigned int column = 0; column < board::instance()->columns(); column++) {
		for(unsigned int square_column = 0; square_column < SQUARE_COLUMNS; square_column++) {
			std::cout << TEAM_SQUARES[team]; 
		}
		team = !team;
	}	
}

void board_printer::print_square_row_with_row_number(bool team, int row) const {
	print_row_number(row, false);
	print_square_row(team);
	print_row_number(row, true);
	std::cout << '\n';
}

void board_printer::print_square_row_with_piece(bool team, int& board_position) const {
	for(unsigned int column = 0; column < board::instance()->columns(); column++) {
		if(board::instance()->there_is_a_piece_at(board_position)) {
			/* if there is a piece on that position its icon has to be printed
			 * the team that it belongs to also has to be printed
			 * the icon is 2 characters long and the team 3*/
			unsigned int square_columns_left = SQUARE_COLUMNS - 5;
			for(unsigned int square_column = 0; square_column < square_columns_left / 2; square_column++) {
				std::cout << TEAM_SQUARES[team];
			}
			std::cout << (*board::instance())[board_position]->icon()
				<< '[' << ((*board::instance())[board_position]->team() ? 'w' : 'b') << ']'; 
			for(unsigned int square_column = 0; square_column < square_columns_left / 2; square_column++) {
				std::cout << TEAM_SQUARES[team];
			}
		}
		else {
			for(unsigned int square_column = 0; square_column < SQUARE_COLUMNS; square_column++) {
				std::cout << TEAM_SQUARES[team]; 
			}
		}
		board_position++;
		team = !team;
	}	
}

void board_printer::print_column_letters() const {
	print_square_row_padding();
	for (unsigned int column = 0; column < board::instance()->columns(); column++) {
		std::cout << char(97 + column); 
		for(unsigned int i = 0; i < SQUARE_COLUMNS - 1; i++) {
			std::cout << ' ';
		}
	}
	std::cout << '\n';
}

/* the number of the row is displayed on the first row of each square and is showed
 * at both sides. At the left the number goes first and then the padding is added
 * and at the right it starts with the padding and then displays the number
 * */
void board_printer::print_row_number(int row, bool padding_first) const {
	//left
	if(padding_first) {	
		print_square_row_padding(1);
		std::cout << row + 1;
	}
	//right
	else {	
		std::cout << row + 1;
		//std::cout << (board::instance()->team() ? row + 1 : board::instance()->rows() - row);
		print_square_row_padding(1);
	}
}

/* prints the horizontal padding that comes before or after the numbers and before the letters.
 * sometimes part of the padding is occupied by a number so not always the same ammount of padding is needed*/
void board_printer::print_square_row_padding(int starting_point) const {
	for(unsigned int padding = starting_point; padding < PADDING; padding++) {
		std::cout << PADDING_CHAR;
	}
}

void board_printer::highlight_positions(std::vector<unsigned int>&& positions) {
	highlight_position = std::move(positions);
}
