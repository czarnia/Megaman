#ifndef _RENDERER_H_
#define _RENDERER_H_

#include <SDL2/SDL.h>
#include <vector>
#include "Sprite.h"

class Renderer{
    private:
        SDL_Renderer *renderer;
        std::vector<SDL_Texture*> textures;
        std::vector<SDL_Rect*> rectangles;
        std::vector<SDL_Rect*> crops;
    public:
        SDL_Renderer* get_renderer();
        Renderer(SDL_Window* w);
        void add(Sprite* r);
        void clear();
        void draw(SDL_Texture* texture, SDL_Rect* rect, SDL_Rect* crop);
        void drawAll();
        void present();
        ~Renderer();
};

#endif
