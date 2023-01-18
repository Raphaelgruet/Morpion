/**
 * @file board.c
 *
 * @date nov. 2022
 * @author Nom Prenom
 */

#include "board.h"
#include <assert.h>

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
	PieceType piece = boardSquares[lastChangeY][lastChangeX];
	if(piece == NONE){
		return false;
	}
	if(lastChangeX == 0 && boardSquares[lastChangeY][lastChangeX+1] == piece && boardSquares[lastChangeY][lastChangeX+2] == piece){
		*gameResult = (GameResult) piece;
		return true;
	}
	if(lastChangeX == 1 && boardSquares[lastChangeY][lastChangeX-1] == piece && boardSquares[lastChangeY][lastChangeX+1] == piece){
		*gameResult = (GameResult) piece;
		return true;
	}
	if(lastChangeX == 2 && boardSquares[lastChangeY][lastChangeX-2] == piece && boardSquares[lastChangeY][lastChangeX-1] == piece){
		*gameResult = (GameResult) piece;
		return true;
	}
	if(lastChangeY == 0 && boardSquares[lastChangeY+1][lastChangeX] == piece && boardSquares[lastChangeY+2][lastChangeX] == piece){
		*gameResult = (GameResult) piece;
		return true;
	}
	if(lastChangeY == 1 && boardSquares[lastChangeY-1][lastChangeX] == piece && boardSquares[lastChangeY+1][lastChangeX] == piece){
		*gameResult = (GameResult) piece;
		return true;
	}
	if(lastChangeY == 2 && boardSquares[lastChangeY-2][lastChangeX] == piece && boardSquares[lastChangeY-1][lastChangeX] == piece){
		*gameResult = (GameResult) piece;
		return true;
	}
	if(lastChangeX+lastChangeY != 1 && lastChangeX+lastChangeY != 3){
		if(lastChangeX+lastChangeY == 0 && boardSquares[lastChangeY+1][lastChangeX+1] == piece && boardSquares[lastChangeY+2][lastChangeX+2] == piece){
			*gameResult = (GameResult) piece;
			return true;
		}
		if(lastChangeX+lastChangeY == 4 && boardSquares[lastChangeY-1][lastChangeX-1] == piece && boardSquares[lastChangeY-2][lastChangeX-2] == piece){
			*gameResult = (GameResult) piece;
			return true;
		}
		if(lastChangeY == 0 && boardSquares[lastChangeY+1][lastChangeX-1] == piece && boardSquares[lastChangeY+2][lastChangeX-2] == piece){
			*gameResult = (GameResult) piece;
			return true;
		}
		if(lastChangeY == 2 && boardSquares[lastChangeY-1][lastChangeX+1] == piece && boardSquares[lastChangeY-2][lastChangeX+2] == piece){
			*gameResult = (GameResult) piece;
			return true;
		}
		if(lastChangeY == 1 && ((boardSquares[lastChangeY-1][lastChangeX+1] == piece &&  boardSquares[lastChangeY+1][lastChangeX-1] == piece) ||
		(boardSquares[lastChangeY-1][lastChangeX-1] == piece && boardSquares[lastChangeY+1][lastChangeX+1] == piece))){
			*gameResult = (GameResult) piece;
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

void Board_free (){
    // TODO: à compléter
}

PutPieceResult Board_putPiece (Coordinate x, Coordinate y, PieceType kindOfPiece){
	if(Board_getSquareContent(x,y) == NONE){
		squareChangeCallback(x, y, kindOfPiece);
		board[x][y] = kindOfPiece;
		GameResult  result;
		if(isGameFinished(board,x,y,&result)){
			endOfGameCallback(result);
		}
		return PIECE_IN_PLACE;
	} else {
		return SQUARE_IS_NOT_EMPTY;
	}
}

PieceType Board_getSquareContent (Coordinate x, Coordinate y){
    return board[x][y];
}
