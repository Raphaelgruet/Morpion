/**
 * @file player_manager_scanf.c
 *
 * @date dec. 2022
 * @author Nom Prenom
 */

#include "board.h"
#include "board_view.h"
#include <assert.h>
#include <SDL.h>
#include <stdbool.h>

#ifdef CONFIG_PLAYER_MANAGER_SDL

void PlayerManager_init (void){
	assert (SDL_WasInit (SDL_INIT_VIDEO) != 0);
}

void PlayerManager_free (void){
}

static bool tryMove (int x, int y){
  // TODO: à compléter
  return false;
}

void PlayerManager_oneTurn (void){
	int error;
	SDL_Event event;
	bool validMove;

	do{
		validMove = false;
		error = SDL_WaitEvent (&event);
		assert (error == 1);
		switch (event.type){
			case SDL_WINDOWEVENT:
				// TODO:  Fermeture de la fenêtre = quitter l'application
				break;
			  // TODO: à compléter
		}
	}
	while (!validMove);
}

#endif // defined CONFIG_PLAYER_MANAGER_SCANF
