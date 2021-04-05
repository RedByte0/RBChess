#include "./headers/interactive_layer.hpp"

int main() {
	std::shared_ptr<interactive_layer> game = interactive_layer::instance();
	game->start_game();	
	return 0;
}
