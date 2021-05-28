#include "../headers/bishop.hpp"

bishop::bishop(int position, bool team) : piece(position, team) {}

const char* bishop::icon() const {
	return "Bi";
}

std::vector<int> bishop::possible_movements() const {
	std::vector<int> movements;
	piece::diagonal_movements(movements);
	return movements;
}
