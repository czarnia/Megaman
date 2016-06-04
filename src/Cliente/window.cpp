#include "window.h"

Window::Window(int width, int height){
    window = SDL_CreateWindow("Main menu",
                                SDL_WINDOWPOS_UNDEFINED, // POS X
                                SDL_WINDOWPOS_UNDEFINED, // POS Y
                                width,
                                height,
                                SDL_WINDOW_SHOWN);

}

SDL_Window* Window::get_window(){
    return window;
}
