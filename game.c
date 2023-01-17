/**
 * @file game.c
 *
 * @date nov. 2022
 * @author Nom Prenom
 */

#include "player_manager.h"
#include "game.h"
#include "board.h"

void Game_init (void){
	Board_init(*squareChange, *endOfGame);
}

void Game_free (void){
  // TODO: libérer tous les modules
}

void Game_loop (void){
	// TODO: à compléter
}

void squareChange(Coordinate x, Coordinate y, PieceType newContent){
	board[x][y] = newContent;
}

void endOfGame(GameResult result){

}