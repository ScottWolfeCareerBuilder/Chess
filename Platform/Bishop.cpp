#include <vector>
#include "ChessDebug.h"
#include "Bishop.h"
#include "GameState.h"
#include "Move.h"
#include "Position.h"

namespace chess {


Bishop::Bishop(PieceColor color) : Piece(color) {}

std::unique_ptr<Piece> Bishop::getCopy() const {
    return std::make_unique<Bishop>(*this);
}

PieceType Bishop::getType() const {
    return PieceType::BISHOP;
}

const std::string Bishop::getSymbol() const {
    return BISHOP_SYMBOL;
}

std::vector<Position> Bishop::getSquaresAttacked(const Board &board, Position start) const {
    std::vector<Position> positions;
    getDiagonalSquaresAttacked(positions, board, start);
    return positions;
}

void Bishop::addMoveEffect(const GameState &state, Move &move) const {
    return;
}


}
