#include <vector>
#include "ChessDebug.h"
#include "Bishop.h"
#include "GameState.h"
#include "Move.h"
#include "Position.h"
using namespace std;


Bishop::Bishop(PieceColor color) : Piece(color) {}

const string Bishop::getSymbol() const {
	return BISHOP_SYMBOL;
}

vector<Move> Bishop::getMoves(const GameState &state, Position pos) const {
	vector<Move> moves;
	getDiagonalMoves(moves, state, pos);
	return moves;
}
