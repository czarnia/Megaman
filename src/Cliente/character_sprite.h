#ifndef _CHARACTER_SPRITE_H_
#define _CHARACTER_SPRITE_H_

#include "Sprite.h"
#include <vector>


class Character_sprite: public Sprite{
    private:

        enum State{SPAWNING, DYING, RUNNING, JUMPING,
                    IDLE, EDITORMODE, SHOOTING, CLIMBING};
        bool movingLeft;
        bool editorMode;
        /// Animaciones
        std::vector<SDL_Rect*> runningAnimation;
        std::vector<SDL_Rect*> idleAnimation;
        std::vector<SDL_Rect*> jumpingAnimation;
        std::vector<SDL_Rect*> ladderAnimation;
        std::vector<SDL_Rect*> spawnAnimation;
        std::vector<SDL_Rect*> deathAnimation;
        std::vector<SDL_Rect*> shootingAnimation;
        ///
        float currentFrame;
        State currentState;
    public:
        Character_sprite(SDL_Renderer *r, const char* file);
        static int width;
        static int height;

        void loadAnimations(std::string path);
        void changeState(int x, int y);
        void setState(int &action);
        void clearStates();
        void destroy();
        void spawn();
        int get_direction();

        SDL_Rect* get_crop();

        ~Character_sprite();
};

#endif // _CHARACTER_SPRITE_H_
