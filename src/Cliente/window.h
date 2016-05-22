#ifndef _WINDOW_H_
#define _WINDOW_H_

#include <SDL2/SDL.h>
#include <iostream>

class Window{
	private:
		void cap_framerate(const Uint32 &starting_tick);
		SDL_Window *window;
		int width;
		int height;
	public:
		Window(int width, int height);
		void run();
		SDL_Window* get_window();
		~Window();
};

#endif

