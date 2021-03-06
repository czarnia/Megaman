#ifndef _WINDOW_H_
#define _WINDOW_H_

#include <SDL2/SDL.h>
#include <string>

class Window{
    private:
        SDL_Window *window;
        SDL_DisplayMode displaymode;
        int width;
        int height;
    public:
        Window(int width, int height);
        void maximize();
        void setWindowed();
        void setTitle(std::string title);
        int get_width();
        int get_height();
        SDL_Window* get_window();
};

#endif // _WINDOW_H_
