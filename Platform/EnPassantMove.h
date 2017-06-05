#pragma once

#include "Move.h"


class EnPassantMove : public Move {

public:
    EnPassantMove(Position start, Position end, Position pawn_to_remove);
    virtual void applyMove(GameState &state) const override;

private:
    Position remove_position;

};
