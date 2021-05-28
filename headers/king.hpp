#ifndef KING_HPP_
#define KING_HPP_

#include "piece.hpp"

class king : public piece {
private:
	//check if there is any piece between the current kings position and the target position
	bool path_is_clear(const int position) const;
public:
	king(int position, bool team);
	king() = delete;
	
	const char* icon() const override;
	void move(int position) override;
	std::vector<int> possible_movements() const override;
	void castling_moves(std::vector<int>& movements) const;
};

#endif
