#ifndef _MAIN_MENU_H
#define _MAIN_MENU_H

#include "gameState.h"
#include "Renderer.h"
#include <string>
#include <utility>
#include "window.h"
#include "music.h"

class MainMenu: public GameState{
    private:
        ///
        Window *window;
        Renderer *renderer;
        ///
        ///
        bool start;
        bool quit;
        ///
        void updateInput();
        Music music;
        ///
        std::pair<int, std::string> &playerData;
    public:
        MainMenu(Window *window, Renderer *renderer,
                    std::pair<int, std::string> &playerData);

        /// Carga sprites, musica etc
        void load(int stack = 0);
        /// Libera sprites
        int unload();
        /// Logica del estado
        StateCode update();
        void render();
        ~MainMenu();
};

#endif // _MAIN_MENU_H
