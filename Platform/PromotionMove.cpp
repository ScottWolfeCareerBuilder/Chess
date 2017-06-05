#include "GameState.h"
#include "Piece.h"
#include "PromotionMove.h"
using namespace std;


PromotionMove::PromotionMove(Position start, Position end, PieceType piece_type)
    : Move(start, end)
{
    if (piece_type == PieceType::PAWN || piece_type == PieceType::KING) {
        throw invalid_argument("invalid PieceType");
    }
    this->piece_type = piece_type;
}

void PromotionMove::applyMove(GameState &state) const {
    Move::applyMove(state);
    auto piece = Piece::createPiece(piece_type, state.getPieceColor(end));
    state.addPieceToSquare(end, piece);
}
