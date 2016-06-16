#ifndef _MINION_SPRITE_H_
#define _MINION_SPRITE_H_

#include "Sprite.h"
#include <vector>
#include <string>

class Minion_sprite: public Sprite{
    private:
        static int width;
        static int height;

        bool spawning;
        bool dying;
        bool movingLeft;
        bool running;
        bool jumping;
        bool idle;
        bool editorMode;
        /// Animaciones
        std::vector<SDL_Rect*> idleAnimation;
        std::vector<SDL_Rect*> runningAnimation;
        std::vector<SDL_Rect*> jumpingAnimation;
        std::vector<SDL_Rect*> deathAnimation;

        float currentFrame;
    public:
        Minion_sprite(SDL_Renderer *r, const char* file);
        void loadAnimations(std::string path);
        void setState(int x, int y);
        void clearStates();
        SDL_Rect* get_crop();
        ~Minion_sprite();
};

#endif

