#include "window.h"
#include <iostream>

Window::Window(int width, int height):
    width(width),
    height(height)
{
    window = SDL_CreateWindow("Window",
                                SDL_WINDOWPOS_UNDEFINED, // POS X
                                SDL_WINDOWPOS_UNDEFINED, // POS Y
                                width,
                                height,
                                SDL_WINDOW_SHOWN);

}

void Window::maximize(){
    SDL_Rect r;
    SDL_GetDisplayBounds(0, &r);
    width = r.w;
    height = r.h;

    SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);
}

void Window::setWindowed(){
    SDL_SetWindowFullscreen(window, 0);
}

int Window::get_width(){
    return width;
}

int Window::get_height(){
    return height;
}

void Window::setTitle(std::string title){
    SDL_SetWindowTitle(window, title.c_str());
}

SDL_Window* Window::get_window(){
    return window;
}
