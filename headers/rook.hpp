#ifndef ROOK_HPP_
#define ROOK_HPP_

#include "piece.hpp"

class rook : public piece {
private:
	void vertical_movements(std::vector<int>& movements) const;

public:
	rook(int position, bool team);
	rook() = delete;
	
	//void move(int position) override; 
	const char* icon() const override;
	std::vector<int> possible_movements() const override;
};

#endif
