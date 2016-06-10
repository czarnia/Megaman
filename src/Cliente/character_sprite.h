#ifndef _CHARACTER_SPRITE_H_
#define _CHARACTER_SPRITE_H_

#include "Sprite.h"
#include <vector>


class Character_sprite: public Sprite{
    private:
        static int width;
        static int height;
        bool spawning;
        bool dying;
        bool movingLeft;
        bool movingRight;
        bool jumping;
        bool idle;
        bool editorMode;
        /// Animaciones
        std::vector<SDL_Rect*> runningAnimation;
        std::vector<SDL_Rect*> idleAnimation;
        ///
        float currentFrame;
        void loadAnimations();
    public:
        Character_sprite(SDL_Renderer *r, const char* file);
        void setState(int x, int y);
        void clearStates();
        SDL_Rect* get_crop();
        ~Character_sprite();
};

#endif // _CHARACTER_SPRITE_H_
