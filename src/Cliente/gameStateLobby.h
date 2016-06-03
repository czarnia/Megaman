#ifndef _GAMESTATELOBBY_H_
#define _GAMESTATELOBBY_H_

#include "gameState.h"

#include "Renderer.h"
#include "../Comun/socket.h"

class gameStateLobby: public GameState{
    private:
        int playerno;

        SDL_Window *window;
        Renderer *renderer;
        Socket *skt;

        void mainLoop();
    public:
        void load(int stack = 0);
        int unload();
        StateCode update();

};

#endif // _GAMESTATELOBBY_H_
