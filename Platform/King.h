#pragma once

class King : public Piece {
public:
	King(Color color);
	std::string getSymbol() override;
};