#include "./headers/board.hpp"
#include "./headers/board_ui.hpp"

int main() {
	board newBoard;
	board_ui ui(&newBoard);
	ui.print();

	return 0;
}
