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
        /// Esta clase establece los cambios entre estados de juegos
        /// usando esta variable
        GameState* currentState;
        char *hostname;
        char *port;
        /// Limitar los FPS para que sean constantes
		void cap_framerate(const Uint32 &starting_tick);
	public:
		Game(char* hostname,char* port);
		/// Esta funcion corre el juego
		void run();
		~Game();
};

#endif
