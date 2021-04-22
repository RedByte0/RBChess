#include "../headers/algebraic_notation.hpp"
#include "../headers/board.hpp"
#include <cctype>

algebraic_notation::algebraic_notation() {

}

algebraic_notation::~algebraic_notation() {

}

/*this method does not check if the given algebraic notation is valid or not*/
int algebraic_notation::operator()(const std::string& algebraic_notation) const {
	return ((int)std::tolower(algebraic_notation[0]) - 97) + ((int)algebraic_notation[1] - 49) * board::instance()->rows();	
}

bool algebraic_notation::operator==(const std::string& str) const {
	if(str.length() != 2)
		return false;
	int ch = int(str[0]);
	int num = int(str[1]);
	//letter to lowercase
	if(ch < 97)
		ch += 32;
	//is a letter between a and z
	if(ch < 97 || ch > 122)
		return false;

	//is a number between 1 and 9
	if(num < 49 || num > 57)
		return false;

	return true;
}
