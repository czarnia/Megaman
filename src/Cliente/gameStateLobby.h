#ifndef _GAMESTATELOBBY_H_
#define _GAMESTATELOBBY_H_

#include "gameState.h"
#include <string>
#include "Renderer.h"
#include "../Comun/socket.h"
#include "../Comun/mutex.h"
#include "lobbyreceiver.h"

class gameStateLobby: public GameState{
    private:
        int selectorPos;
        ///
        Window *window;
        Renderer *renderer;
        Socket *skt;
        Mutex mutex;
        LobbyReceiver *receiver;
        ///
        void updateInput();
        bool buttonPress(int x, int y, Sprite* spr);

        bool startSelect;
        bool start;
        bool quit;

        std::pair<int,std::string> playerData;
        int *level;
    public:
        gameStateLobby(Window *window, Renderer *renderer,
                        Socket *skt, std::pair<int, std::string> &playerData,
                        int *level);
        void moveSelector(std::string direction);
        ///
        void load(int stack = 0);
        int unload();
        StateCode update();
        void render();
        ~gameStateLobby();

};

#endif // _GAMESTATELOBBY_H_
