#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_

#include <SDL2/SDL.h>

class Sprite{
    protected:
        SDL_Rect rectangle;
        SDL_Texture *texture;
        SDL_Rect crop;
        int origin;
    public:
        Sprite(SDL_Renderer *r, const char *file);
        virtual void set_Sprite(int posx, int posy, int width,
                                int height, int origin,
                                int cropw, int croph);
        SDL_Rect* get_rectangle();
        SDL_Texture* get_texture();
        SDL_Rect* get_crop();
        int getPosX();
        int getPosY();
        void setPosX(int x);
        void setPosY(int y);
        void erase();
        ~Sprite();
};


#endif // SPRITE_H

