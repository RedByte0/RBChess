#ifndef KNIGHT_HPP_
#define KNIGHT_HPP_

#include "piece.hpp"

class knight : public piece {
private:

	void horizontal_movements(std::vector<int>& movements) const;
	void vertical_movements(std::vector<int>& movements) const;

public:
	knight(int position, bool team);
	knight() = delete;

	const char* icon() const override;
	std::vector<int> possible_movements() const override;
};


#endif
