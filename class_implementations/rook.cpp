#include "../headers/rook.hpp"

rook::rook(int position, bool team) : piece(position, team) {}

const char* rook::icon() const {
	return "Ro";
}

std::vector<int> rook::possible_movements() const {
	std::vector<int> movements;
	piece::horizontal_movements(movements);
	piece::vertical_movements(movements);
	return movements;
}
