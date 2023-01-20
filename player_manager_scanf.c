/**
 * @file player_manager_scanf.c
 *
 * @date nov. 22
 * @author Prenom Nom
 */

#include "board.h"
#include "board_view.h"
#include "player_manager.h"
#include <assert.h>
#include <stdio.h>
#include <ctype.h>

#ifdef CONFIG_PLAYER_MANAGER_SCANF

PieceType tour = CIRCLE;

void PlayerManager_init (void){
  // TODO: voir etape 1
}

void PlayerManager_free (void){
}

void PlayerManager_oneTurn (void){
	char coords[3];
	char* joueur;
	char signe;
	if(tour == CROSS){
		joueur = "CROIX";
		signe = 'X';
	} else {
		joueur = "CERCLES";
		signe = 'O';
	}
	printf("C'est au joueur des %s [%c] de jouer\nEntrez les coordonnes sous forme x,y :", joueur, signe);
	scanf("%s", coords);
	if(isdigit(coords[0]) == false || isdigit(coords[2]) == false){
		printf("[!] x et y doivent etre des chiffres\n");
		PlayerManager_oneTurn();
		return;
	}
	int x = (int)coords[0] - '0', y = (int)coords[2] - '0';
	if(x > 2 || y > 2){
		printf("[!] x et y doivent etre compris entre 0 et 2\n");
		PlayerManager_oneTurn();
		return;
	}
	if(Board_putPiece(x, y, tour) != PIECE_IN_PLACE) {
		printf("[!] Il y a deja une piece a cette emplacement\n");
		PlayerManager_oneTurn();
	} else {
		if(tour == CIRCLE){
			tour = CROSS;
		}else{
			tour = CIRCLE;
		}
	}
}

#endif // defined CONFIG_PLAYER_MANAGER_SCANF
