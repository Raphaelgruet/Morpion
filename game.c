/**
 * @file game.c
 *
 * @date nov. 2022
 * @author Nom Prenom
 */

#include "player_manager.h"
#include "game.h"
#include "board_view.h"

bool isFinish = false;

void Game_init (void){
	Board_init(squareChange, endOfGame);
}

void Game_free (void){
	Board_free();
}

void Game_loop (void){
	while(isFinish == false){
		PlayerManager_oneTurn();
	}
}

void squareChange(Coordinate x, Coordinate y, PieceType newContent){
	BoardView_displayAll();
}

void endOfGame(GameResult result){
	printf("-------------- fin de partie --------------\n");
	if(result == DRAW){
		printf(">>   Il y a egalite\n");
	} else {
		char* gagnant;
		if(result == CROSS_WINS){
			gagnant = "CROIX";
		} else {
			gagnant = "CERCLES";
		}
		printf(">>   Victoire des %s\n", gagnant);
	}
	printf("-------------------------------------------\n");
	isFinish = true;
}