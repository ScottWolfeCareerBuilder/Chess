#pragma once

#include <memory>
#include <vector>
#include "Board.h"
#include "ChessEnums.h"
#include "Move.h"

namespace chess {

struct Position;
class GameObserver;


class GameState {

public:
    GameState(Board board, PieceColor beginning_player);
    GameState(const GameState &other);
    std::shared_ptr<GameState> getCopy() const;
    const Board &getBoard() const;
    int getBoardDimension() const;
    bool isPiece(Position pos) const;
    const Piece *getPiece(Position pos) const;
    PieceColor getPieceColor(Position pos) const;
    PieceType getPieceType(Position pos) const;
    bool isMoveAvailable(const Move &move) const;
    bool willKingBeInCheck(const Move &move) const;
    bool isKingInCheck() const;
    bool isSquareAttacked(Position pos, PieceColor color) const;
    void makeMove(const Move &move);
    std::unique_ptr<Piece> removePieceFromSquare(Position pos);
    void addPieceToSquare(Position pos, std::unique_ptr<Piece> &piece);
    void addMoveEffect(Move &move) const;
    bool isOppPieceColor(Position pos, PieceColor color) const;
    bool inBounds(Position pos) const;
    bool hasPieceMoved(Position pos) const;
    PieceColor getCurrentPlayersTurn() const;
    const Move *getLastMove() const;
    bool canCurrentPlayerMakeMove() const;
    std::vector<Move> getAvailableMoves() const;
    bool isGameOver() const;
    void resignation();
    void drawByAgreement();
    bool drawBy50Moves();
    void drawByRepetition();
    GameEndType getGameOverState() const;

private:
    Board board;
    PieceColor current_turn;
    GameEndType game_over_state;
    std::vector<Move> move_history;
    int turns_since_capture_or_pawn_push;

    void changePlayersTurn();
    void incrementCaptureAndPawnCounter(const Move &move);
    void updateGameOverState();

    bool isMate() const;
    bool have50MovesPassed() const;
    void mate();

};


}
