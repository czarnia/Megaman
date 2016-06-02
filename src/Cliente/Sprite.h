#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_

#include <SDL2/SDL.h>
#include <string>

/// Esta clase contiene todo lo necesario para poder
/// dibujar un objeto en pantalla a traves de renderer

class Sprite{
    protected:
        SDL_Rect rectangle;
        SDL_Texture *texture;
        SDL_Surface *surface;
        SDL_Rect crop;
    public:
        Sprite(SDL_Renderer *r, const char* file);
        /// getters de los atributos de sdl
        SDL_Rect* get_rectangle();
        SDL_Texture* get_texture();
        SDL_Rect* get_crop();

        /// devuelve posicion global
        int getPosX();
        int getPosY();

        /// establece la posicion global
        void setPosX(int x);
        void setPosY(int y);

        /// libera la memoria pedida
        void erase();
        virtual ~Sprite();
};

#endif // SPRITE_H
