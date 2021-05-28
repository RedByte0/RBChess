#ifndef QUEEN_HPP_
#define QUEEN_HPP_

#include "piece.hpp"

class queen : public piece {
private:
public:
	queen(int position, bool team);
	queen() = delete;
	
	const char* icon() const override;
	std::vector<int> possible_movements() const override;
};

#endif
