#include "CastleMove.h"
#include "GameState.h"
#include "Rook.h"
using namespace std;


CastleMove::CastleMove(Position king_start, Position king_end, Position rook_start, Position rook_end)
    : Move(king_start, king_end), rook_start(rook_start), rook_end(rook_end)
{}

void CastleMove::applyMove(GameState &state) const {
    state.removePieceFromSquare(rook_start);
    state.addPieceToSquare(rook_end);
    Move::applyMove(state);
}
