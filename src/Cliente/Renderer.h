#ifndef _RENDERER_H_
#define _RENDERER_H_

#include <SDL2/SDL.h>
#include <vector>
#include "Sprite.h"
#include <utility>
#include <string>
#include <map>

class Renderer{
    private:
        SDL_Renderer *renderer;
        std::map<int,Sprite*> sprites;
    public:
        SDL_Renderer* get_renderer();
        Renderer(SDL_Window* w);
        void execute(int command, int option, std::pair<int,int> coord);
        void add(int objectid, Sprite* spr);
        void clearSprites();
        void clear();
        void draw(Sprite *spr);
        void drawAll();
        void present();
        ~Renderer();
};

#endif
