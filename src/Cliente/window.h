#ifndef _WINDOW_H_
#define _WINDOW_H_

#include <SDL2/SDL.h>

class Window{
    private:
        SDL_Window *window;
    public:
        Window(int width, int height);
        SDL_Window* get_window();
};

#endif // _WINDOW_H_
