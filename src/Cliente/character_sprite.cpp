#include "character_sprite.h"
#include <math.h>

/// Auxiliares
int round(float d){
    return (int)floor(d+0.5);
}
///

int Character_sprite::width = 30;
int Character_sprite::height = 60;

Character_sprite::Character_sprite(SDL_Renderer *r, const char* file):
    Sprite(r,file)
{
    rectangle.w = Character_sprite::width;
    rectangle.h = Character_sprite::height;

    loadAnimations();

    currentFrame = 0;
    clearStates();
}

void Character_sprite::setState(int x, int y){
    clearStates();
    if (x < 0){
        editorMode = true;
        return;
    }
    if (x > rectangle.x){
        movingRight = true;
        if (y > rectangle.y)
            jumping = true;
    }
    if (x < rectangle.x){
        movingLeft = true;
        if (y > rectangle.y)
            jumping = true;
    }
    if (x == rectangle.x){
        if (y == rectangle.y)
            idle = true;
        else if (y > rectangle.y)
            jumping = true;
    }
}

void Character_sprite::clearStates(){
    spawning = false;
    dying = false;
    movingLeft = false;
    movingRight = false;
    jumping = false;
    editorMode = false;
    idle = true;
}

SDL_Rect* Character_sprite::get_crop(){
    if (editorMode)
        return NULL;
    if (movingRight){
        currentFrame += 0.15 ;
        if ((unsigned)round(currentFrame) == runningAnimation.size())
            currentFrame = 0;
        return runningAnimation[round(currentFrame)];
    }
    if (idle){
        currentFrame += 0.01;
        if ((unsigned)round(currentFrame) == idleAnimation.size())
            currentFrame = 0;
        return idleAnimation[round(currentFrame)];
    }
    return NULL;
}

Character_sprite::~Character_sprite(){
    std::vector<SDL_Rect*>::iterator it = runningAnimation.begin();
    for (; it != runningAnimation.end(); ++it)
        delete *it;
    it = idleAnimation.begin();
    for (; it != idleAnimation.end(); ++it)
        delete *it;
}

void Character_sprite::loadAnimations(){
    SDL_Rect *aux = new SDL_Rect;
    aux->x = 13;
    aux->y = 46;
    aux->w = 35;
    aux->h = 23;
    runningAnimation.push_back(aux);

    aux = new SDL_Rect;
    aux->x = 49;
    aux->y = 46;
    aux->w = 33;
    aux->h = 23;
    runningAnimation.push_back(aux);

    aux = new SDL_Rect;
    aux->x = 83;
    aux->y = 46;
    aux->w = 30;
    aux->h = 23;
    runningAnimation.push_back(aux);

    aux = new SDL_Rect;
    aux->x = 112;
    aux->y = 46;
    aux->w = 33;
    aux->h = 23;
    runningAnimation.push_back(aux);

    aux = new SDL_Rect;
    aux->x = 102;
    aux->y = 10;
    aux->w = 25;
    aux->h = 23;
    idleAnimation.push_back(aux);

    aux = new SDL_Rect;
    aux->x = 132;
    aux->y = 10;
    aux->w = 25;
    aux->h = 23;
    idleAnimation.push_back(aux);

    aux = new SDL_Rect;
    aux->x = 159;
    aux->y = 10;
    aux->w = 25;
    aux->h = 23;
    idleAnimation.push_back(aux);
}
