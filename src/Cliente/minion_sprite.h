#ifndef _MINION_SPRITE_H_
#define _MINION_SPRITE_H_

#include "Sprite.h"
#include <vector>
#include <string>

class Minion_sprite: public Sprite{
    private:
        static int width;
        static int height;

        bool movingLeft;
        bool editorMode;
        /// Animaciones
        std::vector<SDL_Rect*> idleAnimation;
        std::vector<SDL_Rect*> runningAnimation;
        std::vector<SDL_Rect*> jumpingAnimation;
        std::vector<SDL_Rect*> deathAnimation;
        std::vector<SDL_Rect*> shieldUpAnimation;
        enum State{DYING, RUNNING, JUMPING, IDLE, SHIELD_UP, EDITORMODE};
        float currentFrame;
        State currentState;
    public:
        Minion_sprite(SDL_Renderer *r, const char* file);
        void loadAnimations(std::string path);
        void changeState(int x, int y);
        void setState(int &action);
        void clearStates();
        SDL_Rect* get_crop();
        ~Minion_sprite();
};

#endif

