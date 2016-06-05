#include "character_sprite.h"

int Main_character::width = 30;
int Main_character::height = 60;

Main_character::Main_character(SDL_Renderer *r, const char* file):
    Sprite(r,file)
{
    rectangle.w = Main_character::width;
    rectangle.h = Main_character::height;
    crop = NULL;
}
