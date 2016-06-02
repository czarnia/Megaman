#ifndef _GAMESTATESTART_H_
#define _GAMESTATESTART_H_

#include "gameState.h"
#include "Renderer.h"
#include "../Comun/socket.h"

class gameStateStart: public GameState{
    private:
        int playerno;
        /// variables tecnicas
        SDL_Window *window;
        Renderer *renderer;
        Socket *skt;
        ///

        /// Manejo del flujo
        void updateInput(bool *running);
        void mainLoop();
        void cap_framerate(const Uint32 &starting_tick);
        ///

        /// Teclas
        bool up;
        bool down;
        bool left;
        bool right;
        bool jump;

        /// Estados
        bool quit;
        bool victory;
        bool ko;

    public:
        gameStateStart(SDL_Window *window, Renderer *renderer, Socket *skt);
        void load(int stack = 0);
        int unload();
        StateCode update();
        ~gameStateStart();
};


#endif // _GAMESTATESTART_H_
