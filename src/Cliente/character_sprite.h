#ifndef _CHARACTER_SPRITE_H_
#define _CHARACTER_SPRITE_H_

#include "Sprite.h"
#include <vector>


class Character_sprite: public Sprite{
    private:
        static int width;
        static int height;
        enum State{SPAWNING, DYING, RUNNING, JUMPING, IDLE, EDITORMODE};
        bool spawning;
        bool dying;
        bool movingLeft;
        bool running;
        bool jumping;
        bool idle;
        bool editorMode;
        /// Animaciones
        std::vector<SDL_Rect*> runningAnimation;
        std::vector<SDL_Rect*> idleAnimation;
        std::vector<SDL_Rect*> jumpingAnimation;
        std::vector<SDL_Rect*> ladderAnimation;
        std::vector<SDL_Rect*> spawnAnimation;
        std::vector<SDL_Rect*> deathAnimation;
        ///
        float currentFrame;
        State currentState;
    public:
        Character_sprite(SDL_Renderer *r, const char* file);


        void loadAnimations(std::string path);
        void setState(int x, int y);
        void clearStates();
        void destroy();
        void spawn();
        int get_direction();

        SDL_Rect* get_crop();

        ~Character_sprite();
};

#endif // _CHARACTER_SPRITE_H_
