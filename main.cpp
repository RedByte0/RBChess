#include "./headers/interactive_layer.hpp"
#include "./headers/pawn.hpp"
#include "./headers/rook.hpp"
#include "./headers/bishop.hpp"
#include "./headers/queen.hpp"
#include "./headers/king.hpp"
#include "./headers/knight.hpp"

void load_pieces();

int main() {
	load_pieces();
	std::shared_ptr<interactive_layer> game = interactive_layer::instance();
	game->start_game();	
	return 0;
}

void load_pieces() {
	std::vector<std::shared_ptr<piece>> pieces = {
		std::shared_ptr<piece>(new rook(0, false)), std::shared_ptr<piece>(new knight(1, false)),
		std::shared_ptr<piece>(new bishop(2, false)), std::shared_ptr<piece>(new king(3, false)),
		std::shared_ptr<piece>(new queen(4, false)), std::shared_ptr<piece>(new bishop(5, false)),
		std::shared_ptr<piece>(new knight(6, false)), std::shared_ptr<piece>(new rook(7, false)),
		std::shared_ptr<piece>(new bishop(41, true))
	};

	board::instance()->initialize_pieces(pieces);
}
