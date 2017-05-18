#include <iostream>
#include "Piece.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "King.h"
#include "Queen.h"
#include "Pawn.h"
#include "Square.h"
#include "Board.h"
#include "ConsoleBoardPresenter.h"
#include "BoardInitializer.h"
#include "windows.h"
using namespace std;

int main() {
	cout << "Hello World of Chess!" << endl;
	cout << endl;

	// Testing Pieces
	cout << "Pieces" << endl;
	Rook rook(PieceColor::WHITE);
	cout << (int) rook.getColor() << endl;

	Knight knight(PieceColor::BLACK);
	cout << (int) knight.getColor() << endl;

	Bishop bishop(PieceColor::WHITE);
	cout << (int) bishop.getColor() << endl;

	King king(PieceColor::BLACK);
	cout << (int) king.getColor() << endl;

	Queen queen(PieceColor::WHITE);
	cout << (int) queen.getColor() << endl;

	Pawn pawn(PieceColor::BLACK);
	cout << (int) pawn.getColor() << endl;
	cout << endl;

	// Testing Squares
	cout << "Squares" << endl;

	Square square1(SquareColor::DARK, &rook);
	cout << (int) square1.getPiece()->getColor() << endl;

	Square square2(SquareColor::LIGHT, &knight);
	cout << (int) square2.getPiece()->getColor() << endl;

	Square square3(SquareColor::DARK);
	if (square3.getPiece()) {
		cout << (int)square2.getPiece()->getColor() << endl;
	}
	else {
		cout << "No piece" << endl;
	}
	cout << endl;

	// Testing Board
	cout << "Board" << endl;
	int board_dimension(8);
	Board board(board_dimension);
	
	board.addPieceToSquare(1, 0, &rook);
	board.addPieceToSquare(1, 7, &knight);
	board.addPieceToSquare(3, 3, &bishop);
	board.addPieceToSquare(3, 0, &queen);
	board.addPieceToSquare(4, 0, &king);
	board.addPieceToSquare(0, 1, &pawn);
	
	ConsoleBoardPresenter presenter;
	presenter.displayBoard(&board);
	cout << endl;

	// Testing BoardInitialization
	cout << "Board Initialization" << endl;
	BoardInitializer initializer;
	unique_ptr<Board> new_board = initializer.initializeStandardGame();
	Board *copy_board = new_board.get();
	presenter.displayBoard(copy_board);
	cout << endl;
	
	system("pause");

	return 0;
}
