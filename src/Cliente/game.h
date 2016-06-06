#ifndef _GAME_H_
#define _GAME_H_

#include <iostream>
#include "../Comun/socket.h"
#include "Renderer.h"
#include "gameState.h"
#include "window.h"
#include <string>
#include <utility>

class Game{
	private:
        /// variables tecnicas
        Socket skt;
        Window *window;
        Renderer *renderer;
        /// Esta clase establece los cambios entre estados de juegos
        /// usando esta variable
        GameState* currentState;
        /// para poder conectarme al servidor en distintos puntos
        char *hostname;
        char *port;

        std::pair<int,std::string> playerData;
	public:
		Game(char* hostname,char* port);
		/// Esta funcion corre el juego
		void run();
		~Game();
};

#endif
