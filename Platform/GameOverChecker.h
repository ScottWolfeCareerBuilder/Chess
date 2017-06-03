#pragma once

enum class GameEndType;
class GameState;


class GameOverChecker {

public:
	GameEndType isGameOver(const GameState &state) const;

private:
	GameEndType isCheckMate(const GameState &state) const;
	GameEndType getCheckmateType(PieceColor current_color) const;

};
