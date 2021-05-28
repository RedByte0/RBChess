#ifndef KING_HPP_
#define KING_HPP_

#include "piece.hpp"

class king : public piece {
private:
public:
	king(int position, bool team);
	king() = delete;
	
	//void move(int position) override; 
	const char* icon() const override;
	std::vector<int> possible_movements() const override;
};

#endif
