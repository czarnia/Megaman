#include "character_sprite.h"
#include <fstream>
#include <iostream>
#include <math.h>

#define PDYING 0
#define PSHOOTING 1
#define PRESPAWN 2
#define PRUNNING 3
#define PJUMPING 4
#define PIDLE 5
#define PCLIMBING 6

#define PSHIELDUP 7

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
    editorMode = false;
    movingLeft = false;
    currentFrame = 0;
    currentState = IDLE;
}

void Character_sprite::changeState(int x, int y){
    if (x < 0){
        editorMode = true;
        return;
    }
    if (x > rectangle.x){
        movingLeft = false;
        currentState = RUNNING;
        if (y > rectangle.y)
            currentState = JUMPING;
    }
    if (x < rectangle.x){
        movingLeft = true;
        currentState = RUNNING;
        if (y > rectangle.y)
            currentState = JUMPING;
    }
    if (x == rectangle.x){
        if (y == rectangle.y){
            currentState = IDLE;
        }else if (y > rectangle.y || y < rectangle.y)
            currentState = JUMPING;
    }
}

void Character_sprite::setState(int &action){
    currentFrame = 0;
    switch(action){
        case PSHOOTING:
            currentState = SHOOTING;
            break;
        case PCLIMBING:
            currentState = CLIMBING;
            break;
        case PDYING:
            currentState = DYING;
            break;
        case PRUNNING:
            currentState = RUNNING;
            break;
        case PJUMPING:
            currentState = JUMPING;
            break;
        case PRESPAWN:
            currentState = SPAWNING;
            break;
        case PIDLE:
            currentState = IDLE;
            break;
        default:
            break;
    }
}

void Character_sprite::clearStates(){
    editorMode = false;
    movingLeft = false;
    currentState = IDLE;
}

SDL_Rect* Character_sprite::get_crop(){
    /// EDITORMODE
    if (editorMode){
        return NULL;
    /// IDLE
    }else if (currentState == IDLE){
        currentFrame += 0.01;
        if ((unsigned)round(currentFrame) == idleAnimation.size())
            currentFrame = 0;
        return idleAnimation[round(currentFrame)];
    /// JUMPING
    }else if (currentState == JUMPING){
        currentFrame = 0;
        return jumpingAnimation[currentFrame];
    /// RUNNING
    }else if (currentState == RUNNING){
        currentFrame += 0.15 ;
        if ((unsigned)round(currentFrame) == runningAnimation.size())
            currentFrame = 0;
        return runningAnimation[round(currentFrame)];
    /// SPAWNING
    }else if (currentState == SPAWNING){
        currentFrame += 0.08;
        if ((unsigned)round(currentFrame) == spawnAnimation.size()){
            currentFrame = 0;
            currentState = IDLE;
        }
        return spawnAnimation[round(currentFrame)];
    /// CLIMBING
    }else if (currentState == CLIMBING){
        currentFrame += 0.05;
        if ((unsigned)round(currentFrame) == ladderAnimation.size()){
            currentFrame = 0;
        }
        return ladderAnimation[round(currentFrame)];
    /// SHOOTING
    }else if (currentState == SHOOTING){
        currentFrame = 0;
        return shootingAnimation[currentFrame];
    }
    return NULL;
}

int Character_sprite::get_direction(){
    if(movingLeft)
        return 1;
    else
        return 0;
}

void Character_sprite::destroy(){
    currentFrame = 0;
}

void Character_sprite::spawn(){
    currentFrame = 0;
    currentState = SPAWNING;
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

    ifile >> framesNumber;
    for (int i = 0; i <framesNumber; i++){
        SDL_Rect *aux = new SDL_Rect;
        ifile >> aux->x;
        ifile >> aux->y;
        ifile >> aux->w;
        ifile >> aux->h;
        shootingAnimation.push_back(aux);
    }
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
    it = shootingAnimation.begin();
    for (; it != shootingAnimation.end(); ++it)
        delete *it;
}
