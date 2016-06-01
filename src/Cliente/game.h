#ifndef _GAME_H_
#define _GAME_H_

#include <SDL2/SDL.h>
#include <iostream>
#include "../Comun/socket.h"
#include "Renderer.h"
#include "gameState.h"

class Game{
	private:
        Socket skt;
        SDL_Window *window;
        Renderer *renderer;
        GameState* currentState;
        char *hostname;
        char *port;
		void cap_framerate(const Uint32 &starting_tick);
	public:
		Game(char* hostname,char* port);
		void run();
		~Game();
};

#endif
