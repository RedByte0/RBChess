#include "./headers/interactive_layer.hpp"
#include "./headers/pawn.hpp"
#include "./headers/rook.hpp"
#include "./headers/bishop.hpp"
#include "./headers/queen.hpp"
#include "./headers/king.hpp"
#include "./headers/knight.hpp"
#include "./headers/board.hpp"

void load_pieces();

int main() {
	load_pieces();
	std::shared_ptr<interactive_layer> game = interactive_layer::instance();
	game->start_game();	
	return 0;
}

void load_pieces() {
	const unsigned int size = board::instance()->size();
	std::vector<std::shared_ptr<piece>> pieces = {
		std::shared_ptr<piece>(new rook(0, false)), std::shared_ptr<piece>(new knight(1, false)),
		std::shared_ptr<piece>(new bishop(2, false)), std::shared_ptr<piece>(new queen(3, false)),
		std::shared_ptr<piece>(new king(4, false)), std::shared_ptr<piece>(new bishop(5, false)),
		std::shared_ptr<piece>(new knight(6, false)), std::shared_ptr<piece>(new rook(7, false)),
		std::shared_ptr<piece>(new pawn(8, false)), std::shared_ptr<piece>(new pawn(9, false)),
		std::shared_ptr<piece>(new pawn(10, false)), std::shared_ptr<piece>(new pawn(11, false)),
		std::shared_ptr<piece>(new pawn(12, false)), std::shared_ptr<piece>(new pawn(13, false)),
		std::shared_ptr<piece>(new pawn(14, false)), std::shared_ptr<piece>(new pawn(15, false)),
	
		std::shared_ptr<piece>(new rook(size-1, true)), std::shared_ptr<piece>(new knight(size-2, true)),
		std::shared_ptr<piece>(new bishop(size-3, true)), std::shared_ptr<piece>(new king(size-4, true)),
		std::shared_ptr<piece>(new queen(size-5, true)), std::shared_ptr<piece>(new bishop(size-6, true)),
		std::shared_ptr<piece>(new knight(size-7, true)), std::shared_ptr<piece>(new rook(size-8, true)),
		std::shared_ptr<piece>(new pawn(size-9, true)),  std::shared_ptr<piece>(new pawn(size-10, true)),
		std::shared_ptr<piece>(new pawn(size-11, true)), std::shared_ptr<piece>(new pawn(size-12, true)),
		std::shared_ptr<piece>(new pawn(size-13, true)), std::shared_ptr<piece>(new pawn(size-14, true)),
		std::shared_ptr<piece>(new pawn(size-15, true)), std::shared_ptr<piece>(new pawn(size-16, true))
	};

	board::instance()->initialize_pieces(pieces);
}
