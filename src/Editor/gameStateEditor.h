#ifndef _GAMESTATEEDITOR_H_
#define _GAMESTATEEDITOR_H_

#include "../Cliente/gameState.h"
#include "../Cliente/window.h"
#include "../Cliente/Renderer.h"

class gameStateEditor: public GameState{
    private:
        Window* window;
        Renderer *renderer;
        void chooseBlock(SDL_Event *event);
        void updateInput(SDL_Event *event);
    public:
        enum objectType{
            BLOCK, SPIKES, LADDER, MEGAMAN, MET, NOTHING
        };
        objectType object;

        gameStateEditor(Window *window, Renderer* renderer);
        void load(int stack = 0);
        int unload();
        StateCode update();
        void render();
        void updateCameraPos(SDL_Event *event);
        void exportMap();
        ~gameStateEditor();
};


#endif // _EDITOR_H_
