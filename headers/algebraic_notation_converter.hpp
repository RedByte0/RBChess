#ifndef ALGEBRAIC_NOTATION_CONVERTER_HPP_
#define ALGEBRAIC_NOTATION_CONVERTER_HPP_

#include <string>
/* this functo can convert board positions as integers to algebraic notation
 * and vice versa */
class algebraic_notation_converter {
private:

public:
	algebraic_notation_converter();
	~algebraic_notation_converter();


	int operator()(const std::string& algebraic_notation) const;

	algebraic_notation_converter(const algebraic_notation_converter&) = delete;
	algebraic_notation_converter(const algebraic_notation_converter&&) = delete;
	algebraic_notation_converter& operator=(const algebraic_notation_converter&) = delete;
	algebraic_notation_converter& operator=(const algebraic_notation_converter&&) = delete;
};

#endif
