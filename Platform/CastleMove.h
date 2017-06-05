#pragma once

#include "Move.h"


class CastleMove : public Move {

public:
    CastleMove(Position king_start, Position king_end, Position rook_start, Position rook_end);
    virtual void applyMove(GameState &state) const override;

private:
    Position rook_start;
    Position rook_end;

};
