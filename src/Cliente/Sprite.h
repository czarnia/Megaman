#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_

#include <SDL2/SDL.h>
#include <string>

class Sprite{
    protected:
        SDL_Rect rectangle;
        SDL_Texture *texture;
        SDL_Surface *surface;
        SDL_Rect crop;
    public:
        Sprite(SDL_Renderer *r, const char* file);
        SDL_Rect* get_rectangle();
        SDL_Texture* get_texture();
        SDL_Rect* get_crop();
        int getPosX();
        int getPosY();
        void setPosX(int x);
        void setPosY(int y);
        void erase();
        virtual ~Sprite();
};

class Backround_sprite: public Sprite{
    private:
        static int width;
        static int height;
    public:
        Backround_sprite(SDL_Renderer *r, const char* file);
};


class Block_sprite: public Sprite{
    private:
        static int width;
        static int height;
    public:
        Block_sprite(SDL_Renderer *r, const char* file);
};

#endif // SPRITE_H
