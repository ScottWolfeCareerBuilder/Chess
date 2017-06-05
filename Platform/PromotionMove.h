#pragma once

#include <string>
#include "ChessEnums.h"
#include "Move.h"
struct position;


class PromotionMove : public Move {

public:
    PromotionMove(Position start, Position end, PieceType piece_type);
    void applyMove(GameState &state) const override;

private:
    PieceType piece_type;

};
