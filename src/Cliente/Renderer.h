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

        std::pair<int,int> map_size;
        int camX;
        int camY;
    public:
        /// vectores que guardan los sprites
        std::map<int,Sprite*> sprites;
        std::map<int,Sprite*> map_sprites;

        /// Devuelve el atributo renderer
        SDL_Renderer* get_renderer();
        Renderer(SDL_Window* w);

        /// Por cuestion de comodidad diferencio entre sprites regulares
        /// y sprites de mapas
        void addSprite(int objectid, Sprite* spr);
        void addMapSprite(int objectid, Sprite* spr);
        /// limpia todos los sprites liberando la memoria de cada uno
        void clearSprites();
        /// Establece el tamanio del mapa
        void setMapSize(int width, int height);
        /// prepara para la impresion en pantalla
        void clear();
        /// Borra un sprite
        void erase(int key);
        /// devuelve true si existe
        bool find(int key);
        /// dibuja un sprite
        void draw(Sprite *spr);
        /// dibuja todos los sprites cargados en los atributos
        void drawAll();
        /// presenta lo dibujado
        void present();
        ~Renderer();
};

#endif
