#include "../headers/queen.hpp"

queen::queen(int position, bool team) : piece(position, team) {}

const char* queen::icon() const {
	return "Qu";
}


std::vector<int> queen::possible_movements() const {
	std::vector<int> movements;
	piece::vertical_movements(movements);
	piece::horizontal_movements(movements);
	piece::diagonal_movements(movements);
	return movements;
}
