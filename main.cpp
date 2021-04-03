#include "./headers/board_printer.hpp"
#include "./headers/pawn.hpp"

int main() {
	std::shared_ptr<piece> ptr_piece(new pawn(10,false));
	board::instance()->add_piece(ptr_piece);
	board_printer printer;
	
	printer();
	return 0;
}
