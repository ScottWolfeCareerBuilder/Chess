#include "Board.h"
#include "ChessDebug.h"
#include "EnPassant.h"
using namespace std;


EnPassant::EnPassant(Position remove_position)
    : remove_position(remove_position)
{}

unique_ptr<MoveEffect> EnPassant::getCopy() const {
    return make_unique<EnPassant>(*this);
}

bool EnPassant::operator==(const MoveEffect &other) const {
    try {
        auto other_casted = dynamic_cast<const EnPassant&>(other);
        if (remove_position == other_casted.remove_position) {
            return true;
        }
        return false;
    }
    catch (bad_cast) {
        return false;
    }
}

void EnPassant::applyEffect(Board &board) const {
    board.removePieceFromSquare(remove_position);
}

MoveEffectType EnPassant::getType() const {
    return MoveEffectType::EN_PASSANT;
}
