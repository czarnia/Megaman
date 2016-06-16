#ifndef _BAR_SPRITE_H
#define _BAR_SPRITE_H

#include "Sprite.h"

#include <vector>

class Bar_sprite: public Sprite{
    private:
        static int width;
        static int height;
        int ammount;
        std::vector<SDL_Texture*> bar_vector;
    public:
        Bar_sprite(SDL_Renderer *r, bool hp);
        void setAmmount(int ammount);
        SDL_Texture* get_texture();
};

#endif


