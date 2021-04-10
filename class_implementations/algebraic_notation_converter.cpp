#include "../headers/algebraic_notation_converter.hpp"
#include "../headers/board.hpp"
#include <cctype>

algebraic_notation_converter::algebraic_notation_converter() {

}

algebraic_notation_converter::~algebraic_notation_converter() {

}

/*this method does not check if the given algebraic notation is valid or not*/
int algebraic_notation_converter::operator()(const std::string& algebraic_notation) const {
	return ((int)std::tolower(algebraic_notation[0]) - 97) + ((int)algebraic_notation[1] - 49) * board::instance()->rows();	
}
