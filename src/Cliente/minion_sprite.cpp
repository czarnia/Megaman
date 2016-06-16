#include "minion_sprite.h"
#include <fstream>
#include <iostream>

int Minion_sprite::width = 30;
int Minion_sprite::height = 30;

Minion_sprite::Minion_sprite(SDL_Renderer *r, const char* file):
    Sprite(r,file)
{
    rectangle.w = Minion_sprite::width;
    rectangle.h = Minion_sprite::height;
    //currentFrame = 0;
    //clearStates();
}

void Minion_sprite::loadAnimations(std::string path){
    std::ifstream ifile;
    ifile.open(path.c_str());
    int framesNumber;

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
        runningAnimation.push_back(aux);
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
        deathAnimation.push_back(aux);
    }
}

void Minion_sprite::setState(int x, int y){
    clearStates();
    if (x < 0){
        editorMode = true;
        return;
    }
    if (x > rectangle.x){
        movingLeft = false;
        running = true;
        idle = false;
        if (y > rectangle.y)
            jumping = true;
    }
    if (x < rectangle.x){
        movingLeft = true;
        running = true;
        idle = false;
        if (y > rectangle.y)
            jumping = true;
    }
    if (x == rectangle.x){
        if (y == rectangle.y){
            idle = true;
            running = false;
        }else if (y > rectangle.y)
            jumping = true;
    }
}

void Minion_sprite::clearStates(){
    spawning = false;
    dying = false;
    running = false;
    jumping = false;
    editorMode = false;
    idle = true;
}


SDL_Rect* Minion_sprite::get_crop(){
    /*if (editorMode)
        return NULL;
    if (idle){
        currentFrame += 0.01;
        if ((unsigned)round(currentFrame) == idleAnimation.size())
            currentFrame = 0;
        return idleAnimation[round(currentFrame)];
    }
    else if (dying){
        currentFrame += 0.01;
        if((unsigned)round(currentFrame) == deathAnimation.size()){
            currentFrame = 0;
            dying = false;
            idle = true;
        }
        return deathAnimation[round(currentFrame)];
    }
    if (running){
        currentFrame += 0.15 ;
        if ((unsigned)round(currentFrame) == runningAnimation.size())
            currentFrame = 0;
        return runningAnimation[round(currentFrame)];
    }*/
    return NULL;
}

Minion_sprite::~Minion_sprite(){
    std::vector<SDL_Rect*>::iterator it = runningAnimation.begin();
    for (; it != runningAnimation.end(); ++it)
        delete *it;
    it = idleAnimation.begin();
    for (; it != idleAnimation.end(); ++it)
        delete *it;
    it = jumpingAnimation.begin();
    for (; it != jumpingAnimation.end(); ++it)
        delete *it;
    it = deathAnimation.begin();
    for (; it != deathAnimation.end(); ++it)
        delete *it;
}
