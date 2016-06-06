#ifndef _GAMESTATELOBBY_H_
#define _GAMESTATELOBBY_H_

#include "gameState.h"
#include <string>
#include "Renderer.h"
#include "../Comun/socket.h"

class gameStateLobby: public GameState{
    private:
        int selectorPos;
        ///
        Window *window;
        Renderer *renderer;
        Socket *skt;
        ///
        void updateInput();

        bool start;
        bool quit;

        std::string playername;
        int playernumber;
    public:
        gameStateLobby(Window *window, Renderer *renderer,
                        Socket *skt, std::string &player);
        void moveSelector(std::string direction);
        ///
        void load(int stack = 0);
        int unload();
        StateCode update();
        void render();
        ~gameStateLobby();

};

#endif // _GAMESTATELOBBY_H_
