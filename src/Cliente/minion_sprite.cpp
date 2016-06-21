#include "minion_sprite.h"
#include <fstream>
#include <iostream>

#define PDYING 0

#define PRUNNING 3
#define PJUMPING 4
#define PIDLE 5
#define PCLIMBING 6
#define PSHIELDUP 7


Minion_sprite::Minion_sprite(SDL_Renderer *r, const char* file, int big):
    Sprite(r,file)
{
    currentState = IDLE;
    if(big){
        Minion_sprite::height = 60;
    }else{
        Minion_sprite::height = 30;
    }
    Minion_sprite::width = 30;

    rectangle.w = Minion_sprite::width;
    rectangle.h = Minion_sprite::height;
    currentFrame = 0;

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

    ifile >> framesNumber;
    for (int i = 0; i <framesNumber; i++){
        SDL_Rect *aux = new SDL_Rect;
        ifile >> aux->x;
        ifile >> aux->y;
        ifile >> aux->w;
        ifile >> aux->h;
        shieldUpAnimation.push_back(aux);
    }
}

void Minion_sprite::changeState(int x, int y){

    if (x < 0){
        editorMode = true;
        return;
    }
    if (x > rectangle.x){
        movingLeft = false;

    }
    if (x < rectangle.x){
        movingLeft = true;

        if (y > rectangle.y)
            currentState = JUMPING;
    }
    if (x == rectangle.x){
        if (y == rectangle.y){
            currentState = IDLE;
        }else if (y > rectangle.y)
            currentState = JUMPING;
    }
}

void Minion_sprite::clearStates(){
    editorMode = false;
}

void Minion_sprite::setState(int &action){
    currentFrame = 0;
    switch(action){
        case PDYING:
            currentState = DYING;
            break;
        case PRUNNING:
            currentState = RUNNING;
            break;
        case PJUMPING:
            currentState = JUMPING;
            break;
        case PIDLE:
            currentState = IDLE;
            break;
        case PSHIELDUP:
            currentState = SHIELD_UP;
            break;
        default:
            break;
    }
}

SDL_Rect* Minion_sprite::get_crop(){
    if (editorMode)
        return NULL;
    if (currentState == IDLE){
        currentFrame += 0.01;
        if ((unsigned)round(currentFrame) == idleAnimation.size())
            currentFrame = 0;
        return idleAnimation[round(currentFrame)];
    }else if (currentState == DYING){
        currentFrame += 0.01;
        if((unsigned)round(currentFrame) == deathAnimation.size()){
            currentFrame = 0;
        }
        return deathAnimation[round(currentFrame)];
    }else if (currentState == SHIELD_UP){
        currentFrame += 0.01;
        if((unsigned)round(currentFrame) == deathAnimation.size()){
            currentFrame = 0;
        }
        return shieldUpAnimation[round(currentFrame)];
    }else if (currentState == JUMPING){
        currentFrame = 0;
        return jumpingAnimation[currentFrame];
    }
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
    it = shieldUpAnimation.begin();
    for (; it != shieldUpAnimation.end(); ++it)
        delete *it;
}
