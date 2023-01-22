/**
 * @file board.c
 *
 * @date nov. 2022
 * @author Nom Prenom
 */

#include "board.h"
#include <assert.h>
#include <stdio.h>

// variables globales du module a definir ici
PieceType board[3][3];
SquareChangeCallback squareChangeCallback;
EndOfGameCallback endOfGameCallback;

/**
 * Check if the game has to be ended. Only alignment from the last
 * modified square are checked.
 *
 * @param [in] boardSquares the board to check
 * @param [in] lastChangeX the colum where the last piece has been put
 * @param [in] lastChangeY the row where the last piece has been put
 * @param [out] gameResult the winning status if the game has ended (value is not set if
 * the game is not finished)
 *
 * @pre lastChangeX must be in [0..2]
 * @pre lastChangeY must be in [0..2]
 * @pre gameResult must point on an allocated GameResult variable
 *
 * @return a boolean that tells if the game is finished
 */
bool isGameFinished (const PieceType boardSquares[3][3], Coordinate lastChangeX,
					 Coordinate lastChangeY, GameResult *gameResult){
	PieceType piece = boardSquares[lastChangeX][lastChangeY];
	GameResult result = DRAW;
	if(piece == CIRCLE){
		result = CIRCLE_WINS;
	} else if (piece == CROSS){
		result = CROSS_WINS;
	}
	if(piece == NONE){
		return false;
	}
	if(lastChangeX == 0 && boardSquares[lastChangeX+1][lastChangeY] == piece && boardSquares[lastChangeX+2][lastChangeY] == piece){
		*gameResult = result;
		return true;
	}
	if(lastChangeX == 1 && boardSquares[lastChangeX-1][lastChangeY] == piece && boardSquares[lastChangeX+1][lastChangeY] == piece){
		*gameResult = result;
		return true;
	}
	if(lastChangeX == 2 && boardSquares[lastChangeX-2][lastChangeY] == piece && boardSquares[lastChangeX-1][lastChangeY] == piece){
		*gameResult = result;
		return true;
	}
	if(lastChangeY == 0 && boardSquares[lastChangeX][lastChangeY+1] == piece && boardSquares[lastChangeX][lastChangeY+2] == piece){
		*gameResult = result;
		return true;
	}
	if(lastChangeY == 1 && boardSquares[lastChangeX][lastChangeY-1] == piece && boardSquares[lastChangeX][lastChangeY+1] == piece){
		*gameResult = result;
		return true;
	}
	if(lastChangeY == 2 && boardSquares[lastChangeX][lastChangeY-2] == piece && boardSquares[lastChangeX][lastChangeY-1] == piece){
		*gameResult = result;
		return true;
	}
	if (lastChangeX + lastChangeY == 0 && boardSquares[lastChangeX + 1][lastChangeY + 1] == piece &&
		boardSquares[lastChangeX + 2][lastChangeY + 2] == piece) {
		*gameResult = result;
		return true;
	}
	if (lastChangeX + lastChangeY == 4 && boardSquares[lastChangeX - 1][lastChangeY - 1] == piece &&
		boardSquares[lastChangeX - 2][lastChangeY - 2] == piece) {
		*gameResult = result;
		return true;
	}
	if(lastChangeX+lastChangeY == 2){
		if(lastChangeY == 0 && boardSquares[lastChangeX-1][lastChangeY+1] == piece && boardSquares[lastChangeX-2][lastChangeY+2] == piece){
			*gameResult = result;
			return true;
		}
		if(lastChangeY == 2 && boardSquares[lastChangeX+1][lastChangeY-1] == piece && boardSquares[lastChangeX+2][lastChangeY-2] == piece){
			*gameResult = result;
			return true;
		}
		if(lastChangeY == 1 && ((boardSquares[lastChangeX+1][lastChangeY-1] == piece &&  boardSquares[lastChangeX-1][lastChangeY+1] == piece) ||
				(boardSquares[lastChangeX-1][lastChangeY-1] == piece && boardSquares[lastChangeX+1][lastChangeY+1] == piece))){
			*gameResult = result;
			return true;
		}
	}
	bool emptyCell = false;
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			if(boardSquares[i][j] == NONE){
				emptyCell = true;
			}
		}
	}
	if(emptyCell == false){
		*gameResult = DRAW;
		return true;
	}
	*gameResult = DRAW;
	return false;
}

void Board_init (SquareChangeCallback onSquareChange, EndOfGameCallback onEndOfGame){
	squareChangeCallback = onSquareChange;
	endOfGameCallback = onEndOfGame;
}

void Board_free(){
	for(int y = 0; y <= 2; y++) {
		for (int x = 0; x <= 2; x++) {
			board[x][y] = NONE;
		}
	}
}

PutPieceResult Board_putPiece (Coordinate x, Coordinate y, PieceType kindOfPiece){
	if(Board_getSquareContent(x,y) == NONE){
		board[x][y] = kindOfPiece;
		squareChangeCallback(x, y, kindOfPiece);
		GameResult result;
		if(isGameFinished(board,x,y,&result)){
			endOfGameCallback(result);
		}
		return PIECE_IN_PLACE;
	} else {
		return SQUARE_IS_NOT_EMPTY;
	}
}

PieceType Board_getSquareContent (Coordinate x, Coordinate y){
	if(x > 2 || y > 2){
		return 0;
	}
    return board[x][y];
}
