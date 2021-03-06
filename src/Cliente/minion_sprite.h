#ifndef _MINION_SPRITE_H_
#define _MINION_SPRITE_H_

#include "Sprite.h"
#include <vector>
#include <string>

class Minion_sprite: public Sprite{
    private:
         int width;
         int height;

        bool movingLeft;
        bool editorMode;
        /// Animaciones
        std::vector<SDL_Rect*> idleAnimation;
        std::vector<SDL_Rect*> runningAnimation;
        std::vector<SDL_Rect*> jumpingAnimation;
        std::vector<SDL_Rect*> shieldUpAnimation;
        enum State{JUMPING, IDLE, SHIELD_UP, RUNNING, EDITORMODE, DYING};
        float currentFrame;
        State currentState;
    public:
        Minion_sprite(SDL_Renderer *r, const char* file, int big);
        void loadAnimations(std::string path);
        void changeState(int x, int y);
        void setState(int &action);
        void clearStates();
        SDL_Rect* get_crop();
        ~Minion_sprite();
};

#endif

