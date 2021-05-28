#include "../headers/board.hpp"
#include "../headers/interactive_layer.hpp"
#include <string>

board::board() {
	_team = true;
	_pieces = std::vector<std::shared_ptr<piece>>();
}

bool board::there_is_a_piece_at(int position) const {
	for(std::size_t i = 0; i < _pieces.size(); i++) {
		/* if there is piece with the same _position as the given position
		 * simply return true and exit the method*/
		if(_pieces[i]->position() == position)
			return true;
	}
	return false;
}

bool board::there_is_a_piece_at(int position, bool team) const {
	for(std::size_t i = 0; i < _pieces.size(); i++) {
		if(_pieces[i]->position() == position && _pieces[i]->team() == team)
			return true;
	}
	return false;
}

bool board::delete_piece(int position) {
	/* the position parameter is not the position of the piece within the vector,
	 * it refers to the position of the pieve within the board*/
	for(std::size_t i = 0; i < _pieces.size(); i++) {
		if(_pieces[i]->position() == position) {
			if(std::string(_pieces[i]->icon()) == "Ki") {
				//if the piece is a king the game is over
				interactive_layer::instance()->quit_game();
				std::cout << "The " << (!_pieces[i]->team() ? "white" : "black") << " player wins !" << std::endl;
			}	
			_pieces.erase(_pieces.begin() + i);
			return true;
		}
	}
	return false;
}

std::shared_ptr<piece> board::operator[](int position) {
	for (std::size_t i = 0; i < _pieces.size(); i++) {
		if (_pieces[i]->position() == position)
			return _pieces[i];
	}
	return nullptr;
}

const std::shared_ptr<piece> board::operator[](int position) const {
	for(std::size_t i = 0; i < _pieces.size(); i++) {
		if(_pieces[i]->position() == position)
			return _pieces[i];
	}
	return nullptr;
}
