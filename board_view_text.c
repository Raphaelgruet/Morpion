/**
 * @file board_view_text.c
 *
 * @date nov. 2022
 * @author Nom Prenom
 */

#include <assert.h>
#include <stdio.h>
#include "board_view.h"

#ifdef CONFIG_TEXTUI

void BoardView_init (void){
}

void BoardView_free (void){
}

void BoardView_displayAll (void){
	for(int y = 0; y <= 2; y++){
		for(int x = 0; x <= 2; x++){
			BoardView_displaySquare(x, y, Board_getSquareContent(x, y));
		}
	}
}

void BoardView_displaySquare (Coordinate x, Coordinate y, PieceType kindOfPiece){
	//BoardView_displayAll();
	if(kindOfPiece == CROSS){
		printf("X");
	} else if (kindOfPiece == CIRCLE){
		printf("O");
	} else {
		printf(" ");
	}
}

void BoardView_displayEndOfGame (GameResult result){
  // TODO: à compléter
}

void BoardView_displayPlayersTurn (PieceType thisPlayer){
  // TODO: à compléter
}

void BoardView_sayCannotPutPiece (void){
  // TODO: à compléter
}

#endif // defined CONFIG_TEXTUI
