#ifndef _MAIN_MENU_H
#define _MAIN_MENU_H

#include "gameState.h"
#include "Renderer.h"

class MainMenu: public GameState{
    private:
        SDL_Window* window;
        Renderer *renderer;
        bool start;
        bool quit;
        void updateInput();
    public:
        MainMenu(SDL_Window *window, Renderer *renderer);

        /// Carga sprites, musica etc
        void load(int stack = 0);
        int unload();
        StateCode update();
        void render();
        ~MainMenu();
};

#endif // _MAIN_MENU_H