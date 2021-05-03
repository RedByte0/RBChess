#ifndef QUEEN_HPP_
#define QUEEN_HPP_

#include "piece.hpp"

class queen : public piece {
private:
public:
	queen(int position, bool team);
	queen() = delete;
	
	//void move(unsigned int position) override; 
	const char* icon() const override;
	std::vector<unsigned int> possible_movements() const override;
};

#endif
