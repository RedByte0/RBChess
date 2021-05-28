#ifndef PAWN_HPP_
#define PAWN_HPP_

#include "piece.hpp"

class pawn : public piece {
private:

	/* when a pawn reaches the end of the board
	 * it can be promoted into another piece*/
	void promote();
public:
	pawn(int position, bool team);
	pawn() = delete;

	void move(int position) override; 
	const char* icon() const override;
	std::vector<int> possible_movements() const override;
};


#endif
