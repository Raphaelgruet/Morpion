/**
 * @file player_manager_mock.c
 *
 * @date nov. 2022
 * @author ???
 */

#include <assert.h>
#include <stdio.h>
#include "player_manager.h"

#ifdef CONFIG_PLAYER_MANAGER_MOCK

void PlayerManager_init (void){
}

void PlayerManager_free (void){
}

void PlayerManager_oneTurn (void){
	while(Board_putPiece(1, 0, CROSS) != PIECE_IN_PLACE) {
		printf("Il y a déjà une pièce à cette emplacement");
	}
}

#endif //  #if defined CONFIG_PLAYER_MANAGER_MOCK
