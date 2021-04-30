#include "./headers/interactive_layer.hpp"
#include "./headers/pawn.hpp"

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
		std::shared_ptr<pawn>(new pawn(14, false)), std::shared_ptr<pawn>(new pawn(15, false))
	};
	board::instance()->initialize_pieces(pieces);
}
