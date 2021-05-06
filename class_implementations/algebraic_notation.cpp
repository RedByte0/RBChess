#include "../headers/algebraic_notation.hpp"
#include "../headers/interactive_layer.hpp"
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

/*cheks if a given string is valid algebraic notation*/
bool algebraic_notation::validate(const std::string& str) const {
	if(str.length() != 2) {
		interactive_layer::instance()->print_error_message("Invalid algebraic notation");
		return false;
	}

	int ch = int(str[0]);
	int num = int(str[1]);
	//letter to lowercase
	if(ch < 97) {
		ch += 32;
	}

	//is a letter between a and z
	if(ch < 97 || ch > 122) {	
		interactive_layer::instance()->print_error_message("Invalid algebraic notation invalid character");
		return false;
	}

	//is a number between 1 and 9
	if(num < 49 || num > 57) {
		interactive_layer::instance()->print_error_message("Invalid algebraic notation invalid numeric value");
		return false;
	}

	return true;
}

/*same deal as in validate(string) but for a whole vector of strings*/
bool algebraic_notation::validate(const std::vector<std::string>& str_vector) const {
	for(std::string str : str_vector) {
		if(validate(str) == false)
			return false;
	}
	return true;
}
