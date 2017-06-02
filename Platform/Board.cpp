#include <iostream>
#include <vector>
#include "ChessDebug.h"
#include "Board.h"
#include "GameState.h"
#include "Move.h"
#include "Piece.h"
#include "Position.h"
using namespace std;


Board::Board(int board_dimension)
	: dimension(board_dimension)
{
	if (board_dimension < 6 || board_dimension > 99) {
		throw invalid_argument("board dimension is out of range");
	}
	for (int i = 0; i < dimension * dimension; ++i) {
		Square square(getSquareColorByIndex(i));
		squares.emplace_back(square);
	}
}

Board::Board(const Board &other_board) :
	dimension(other_board.getDimension())
{
	for (int i = 0; i < dimension * dimension; ++i) {
		squares.emplace_back(other_board.squares[i]);
	}
}

std::shared_ptr<Board> Board::getCopy() const {
	return make_shared<Board>(*this);
}

Square &Board::getSquare(Position pos) {
	return squares[getIndex(pos)];
}

const Square &Board::getSquare(Position pos) const {
	return squares[getIndex(pos)];
}

SquareColor Board::getSquareColor(Position pos) const {
	return getSquare(pos).getColor();
}

bool Board::inBounds(Position pos) const {
	if (pos.x < 0 || pos.x >= dimension) {
		return false;
	}
	if (pos.y < 0 || pos.y >= dimension) {
		return false;
	}
	return true;
}

void Board::makeMove(const Move &move) {
	unique_ptr<const Piece> piece = removePieceFromSquare(move.getStart());
	addPieceToSquare(move.getEnd(), piece);
	applyMoveEffect(move.getEffect());
}

void Board::addPieceToSquare(Position pos, unique_ptr<const Piece> &piece) {
	getSquare(pos).setPiece(piece);
}

unique_ptr<const Piece> Board::removePieceFromSquare(Position pos) {
	return getSquare(pos).removePiece();
}

void Board::applyMoveEffect(const MoveEffect *effect) {
	if (effect == nullptr) {
		return;
	}
	Position pos = effect->getPosition();
	unique_ptr<const Piece> piece = effect->getCopyOfPiece();
	setPiece(pos, piece);
}

bool Board::isPiece(Position pos) const {
	if (getPiece(pos) == nullptr) {
		return false;
	}
	return true;
}

const Piece *Board::getPiece(Position pos) const {
	return getSquare(pos).getPiece();
}

PieceColor Board::getPieceColor(Position pos) const {
	return Piece::getPieceColor(getPiece(pos));
}

string Board::getPieceSymbol(Position pos) const {
	return Piece::getPieceSymbol(getPiece(pos));
}

bool Board::isOppPieceColor(Position pos, PieceColor color) const {
	if (getPieceColor(pos) == PieceColor::NO_PIECE) {
		return false;
	}
	return getPieceColor(pos) != color;
}

void Board::setPiece(Position pos, std::unique_ptr<const Piece> &piece) {
	getSquare(pos).setPiece(piece);
}

bool Board::willKingBeInCheck(GameState &state, const Move &move) const {
	PieceColor turn_before_move = state.getPlayersTurn();
	state.makeMove(move);
	Position king_position = getKingPosition(turn_before_move);
	return canPieceCaptureKing(state, turn_before_move, king_position);
}

Position Board::getKingPosition(PieceColor current_player) const {
	for (int i = 0; i < dimension * dimension; i++) {
		if (squares[i].containsKing(current_player)) {
			return getPosition(i);
		}
	}
	throw runtime_error("no king found for given color");
}

bool Board::canPieceCaptureKing(const GameState state, PieceColor current_player, Position king_position) const {
	for (int i = 0; i < dimension * dimension; i++) {
		const Piece *piece = squares[i].getPiece();
		if (piece != nullptr && piece->getColor() != current_player) {
			vector<Move> moves = piece->getAvailableMoves(state, getPosition(i));
			for (Move move : moves) {
				if (move.getEnd() == king_position) {
					return true;
				}
			}
		}
	}
	return false;
}


int Board::getDimension() const {
	return dimension;
}

int Board::getIndex(Position pos) const {
	return pos.y * dimension + pos.x;
}

Position Board::getPosition(int index) const {
	return Position(index % dimension, index / dimension);
}

SquareColor Board::getSquareColorByIndex(int index) const {
	SquareColor color;
	Position pos = getPosition(index);
	if ((pos.x + pos.y) % 2 == 0) {
		color = SquareColor::DARK;
	}
	else {
		color = SquareColor::LIGHT;
	}
	return color;
}

void Board::throwExceptionIfPieceIsNull(const Piece *piece) const {
	if (piece == nullptr) {
		throw invalid_argument("square does not contain a piece");
	}
}
