#include "./headers/interactive_layer.hpp"
#include "./headers/pawn.hpp"
#include "./headers/rook.hpp"
#include "./headers/bishop.hpp"
#include "./headers/queen.hpp"

void load_pieces();

int main() {
	load_pieces();
	std::shared_ptr<interactive_layer> game = interactive_layer::instance();
	game->start_game();	
	return 0;
}

void load_pieces() {
	std::vector<std::shared_ptr<piece>> pieces = {
		std::shared_ptr<pawn>(new pawn(8, false)), std::shared_ptr<pawn>(new pawn(9, false)),
		std::shared_ptr<pawn>(new pawn(10, false)), std::shared_ptr<pawn>(new pawn(11, false)),
		std::shared_ptr<rook>(new rook(38, true)), std::shared_ptr<rook>(new rook(20, false)),
		std::shared_ptr<bishop>(new bishop(26, true)), std::shared_ptr<bishop>(new bishop(40, false)),
		std::shared_ptr<queen>(new queen(27, true)), std::shared_ptr<queen>(new queen(44, false))
	};
	board::instance()->initialize_pieces(pieces);
}
