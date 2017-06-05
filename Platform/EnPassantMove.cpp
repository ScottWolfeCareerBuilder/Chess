#include <memory>
#include "EnPassantMove.h"
#include "GameState.h"
#include "Piece.h"
using namespace std;


EnPassantMove::EnPassantMove(Position start, Position end, Position remove_position)
    : Move(start, end), remove_position(remove_position)
{}

void EnPassantMove::applyMove(GameState &state) const {
    Move::applyMove(state);
    state.removePieceFromSquare(remove_position);
}
