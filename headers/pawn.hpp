#ifndef PAWN_HPP_
#define PAWN_HPP_

#include "piece.hpp"

class pawn : public piece {
private:

public:
	pawn(int position, bool team);
	pawn() = delete;

	const char* icon() const override;
	std::vector<unsigned int> possible_movements() const override;	
};


#endif
