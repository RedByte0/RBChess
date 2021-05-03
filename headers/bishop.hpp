#ifndef BISHOP_HPP_
#define BISHOP_HPP_

#include "piece.hpp"

class bishop : public piece {
private:
public:
	bishop(int position, bool team);
	bishop() = delete;
	
	//void move(unsigned int position) override; 
	const char* icon() const override;
	std::vector<unsigned int> possible_movements() const override;
};

#endif
