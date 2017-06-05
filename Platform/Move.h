#pragma once

#include "Position.h"
class GameState;

class Move {

public:
    Move(Position start, Position end);
    virtual void applyMove(GameState &state) const;
    //Move(const Move &other_move);
    //Move &operator=(const Move &other);
    //bool operator==(const Move &other) const;
    Position getStart() const;
    Position getEnd() const;

protected:
    Position start;
    Position end;

};
