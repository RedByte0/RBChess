#include "./headers/interactive_layer.hpp"
#include "./headers/pawn.hpp"
#include "./headers/rook.hpp"

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
		std::shared_ptr<pawn>(new pawn(12, false)), std::shared_ptr<pawn>(new pawn(13, false)),
		std::shared_ptr<pawn>(new pawn(14, false)), std::shared_ptr<pawn>(new pawn(15, false)),
		std::shared_ptr<pawn>(new pawn(30, true)), std::shared_ptr<pawn>(new pawn(31, true)),
		std::shared_ptr<pawn>(new pawn(32, true)), std::shared_ptr<pawn>(new pawn(33, true)),
		std::shared_ptr<pawn>(new pawn(34, true)), std::shared_ptr<pawn>(new pawn(35, true)),
		std::shared_ptr<pawn>(new pawn(35, true)), std::shared_ptr<pawn>(new pawn(36, true)),
		std::shared_ptr<rook>(new rook(38, true)), std::shared_ptr<rook>(new rook(20, false))

	};
	board::instance()->initialize_pieces(pieces);
}
