#include "text_sprite.h"
#include <SDL2/SDL_ttf.h>

Text_sprite::Text_sprite(SDL_Renderer *r, std::string text, int fontSize){
    crop = NULL;
    SDL_Color color;
    color.a = 255;
    color.b = 0;
    color.g = 0;
    color.r = 0;

    TTF_Font *font = TTF_OpenFont("../sprites/font.ttf", fontSize);
    SDL_Surface *textSurface = TTF_RenderText_Solid(font, text.c_str(), color);
    texture = SDL_CreateTextureFromSurface(r, textSurface);
    SDL_FreeSurface(textSurface);

    SDL_QueryTexture(texture, NULL, NULL, &rectangle.w, &rectangle.h);

    rectangle.x = 0;
    rectangle.y = 0;
}

Text_sprite::~Text_sprite(){

}
