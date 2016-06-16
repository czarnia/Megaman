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
        SDL_Rect *crop;
    public:
        Sprite(SDL_Renderer *r, const char* file);
        Sprite();
        /// getters de los atributos de sdl
        SDL_Rect* get_rectangle();
        virtual SDL_Texture* get_texture();
        virtual SDL_Rect* get_crop();

        /// devuelve posicion global
        int getPosX();
        int getPosY();
        int getWidth();
        int getHeight();

        /// establece la posicion global
        void setPosX(int x);
        void setPosY(int y);
        void setWidth(int w);
        void setHeight(int h);
        virtual void setAmmount(int ammount){}

        virtual void setState(int x, int y){}
        virtual void spawn(){}
        virtual void destroy(){}
        virtual void loadAnimations(std::string path){}
        virtual int get_direction(){return 0;}
        /// libera la memoria pedida
        void erase();
        virtual ~Sprite();
};

#endif // SPRITE_H
