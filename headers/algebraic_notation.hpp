#ifndef ALGEBRAIC_NOTATION_CONVERTER_HPP_
#define ALGEBRAIC_NOTATION_CONVERTER_HPP_

#include <string>
/* this functo can convert board positions as integers to algebraic notation
 * and vice versa */
class algebraic_notation {
private:

public:
	algebraic_notation();
	~algebraic_notation();


	int operator()(const std::string& algebraic_notation) const;
	bool operator==(const std::string& str) const;

	algebraic_notation(const algebraic_notation&) = delete;
	algebraic_notation(const algebraic_notation&&) = delete;
	algebraic_notation& operator=(const algebraic_notation&) = delete;
	algebraic_notation& operator=(const algebraic_notation&&) = delete;
};

#endif
