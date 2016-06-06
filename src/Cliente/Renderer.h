#ifndef _RENDERER_H_
#define _RENDERER_H_

#include <SDL2/SDL.h>

#include "Sprite.h"
#include "window.h"
#include <utility>
#include <string>
#include <map>

class Renderer{
    private:
        SDL_Renderer *renderer;
        Window *window;
        SDL_Rect auxRect;
        std::pair<int,int> map_size;
    public:
        /// Posiciones de camara
        int camX;
        int camY;
        /// vectores que guardan los sprites
        std::map<int,Sprite*> sprites;
        std::map<int,Sprite*> map_sprites;

        /// Devuelve el atributo renderer
        SDL_Renderer* get_renderer();
        Renderer(Window *window);

        /// Por cuestion de comodidad diferencio entre sprites regulares
        /// y sprites de mapas
        void addSprite(int objectid, Sprite* spr);
        void addMapSprite(int objectid, Sprite* spr);
        /// limpia todos los sprites liberando la memoria de cada uno
        void clearSprites();
        /// Establece el tamanio del mapa
        void setMapSize(int width, int height);
        /// Maneja la posicion de camara centralizada en un jugador
        void updateCamPos(int player);
        /// prepara para la impresion en pantalla
        void clear();
        /// Borra un sprite con una clave
        void erase(int key);
        /// Se usa en el editor
        void erase(int x, int y);
        /// devuelve true si existe
        bool find(int key);
        /// dibuja un sprite
        void draw(Sprite *spr);
        /// dibuja todos los sprites cargados en los atributos
        void drawAll();
        /// Se usa en el editor
        bool ocupied(int x, int y);
        /// presenta lo dibujado
        void present();
        ~Renderer();
};

#endif
