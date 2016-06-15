#include "character_sprite.h"
#include <fstream>
#include <iostream>
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
    if (spawning){
        currentFrame += 0.01;
        if ((unsigned)round(currentFrame) == spawnAnimation.size()){
            currentFrame = 0;
            spawning = false;
        }
        return spawnAnimation[round(currentFrame)];
    }
    if (dying){
        currentFrame += 0.01;
        if((unsigned)round(currentFrame) == deathAnimation.size()){
            currentFrame = 0;
            dying = false;

        }
        return deathAnimation[round(currentFrame)];
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
    it = jumpingAnimation.begin();
    for (; it != jumpingAnimation.end(); ++it)
        delete *it;
    it = ladderAnimation.begin();
    for (; it != ladderAnimation.end(); ++it)
        delete *it;
    it = spawnAnimation.begin();
    for (; it != spawnAnimation.end(); ++it)
        delete *it;
    it = deathAnimation.begin();
    for (; it != deathAnimation.end(); ++it)
        delete *it;
}

void Character_sprite::loadAnimations(std::string path){
    std::ifstream ifile;
    ifile.open(path.c_str());
    int framesNumber;

    ifile >> framesNumber;
    for (int i = 0; i <framesNumber; i++){
        SDL_Rect *aux = new SDL_Rect;
        ifile >> aux->x;
        ifile >> aux->y;
        ifile >> aux->w;
        ifile >> aux->h;
        runningAnimation.push_back(aux);
    }

    ifile >>framesNumber;
    for (int i = 0; i <framesNumber; i++){
        SDL_Rect *aux = new SDL_Rect;
        ifile >> aux->x;
        ifile >> aux->y;
        ifile >> aux->w;
        ifile >> aux->h;
        idleAnimation.push_back(aux);
    }

    ifile >> framesNumber;
    for (int i = 0; i <framesNumber; i++){
        SDL_Rect *aux = new SDL_Rect;
        ifile >> aux->x;
        ifile >> aux->y;
        ifile >> aux->w;
        ifile >> aux->h;
        jumpingAnimation.push_back(aux);
    }

    ifile >> framesNumber;
    for (int i = 0; i <framesNumber; i++){
        SDL_Rect *aux = new SDL_Rect;
        ifile >> aux->x;
        ifile >> aux->y;
        ifile >> aux->w;
        ifile >> aux->h;
        ladderAnimation.push_back(aux);
    }

    ifile >> framesNumber;
    for (int i = 0; i <framesNumber; i++){
        SDL_Rect *aux = new SDL_Rect;
        ifile >> aux->x;
        ifile >> aux->y;
        ifile >> aux->w;
        ifile >> aux->h;
        spawnAnimation.push_back(aux);
    }

    ifile >> framesNumber;
    for (int i = 0; i <framesNumber; i++){
        SDL_Rect *aux = new SDL_Rect;
        ifile >> aux->x;
        ifile >> aux->y;
        ifile >> aux->w;
        ifile >> aux->h;
        deathAnimation.push_back(aux);
    }
}
