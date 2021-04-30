#ifndef ALGEBRAIC_NOTATION_CONVERTER_HPP_
#define ALGEBRAIC_NOTATION_CONVERTER_HPP_

#include <string>
#include <vector>
/* this class can convert board positions as integers to algebraic notation
 * and vice versa */
class algebraic_notation {
private:

public:
	algebraic_notation();
	~algebraic_notation();


	int operator()(const std::string& algebraic_notation) const;
	bool validate(const std::string& str) const;
	bool validate(const std::vector<std::string>& str_vector) const;

	algebraic_notation(const algebraic_notation&) = delete;
	algebraic_notation(const algebraic_notation&&) = delete;
	algebraic_notation& operator=(const algebraic_notation&) = delete;
	algebraic_notation& operator=(const algebraic_notation&&) = delete;
};

#endif
