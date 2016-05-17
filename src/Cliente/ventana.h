#ifndef VENTANA_H
#define VENTANA_H

#include "SDL.h"

class Ventana{
	public:
		Ventana();
		int run();
	private:
		SDL_Window *window;
};

#endif //VENTANA_H
