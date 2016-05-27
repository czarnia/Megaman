#include "../Comun/socket.h"
#include "window.h"

#include <sstream>
#include <iostream>
#include <cstdlib>
#include <string>
#include <string.h>
#include <strings.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

#define WIDTH 640
#define HEIGHT 480
#define IP_POS 1
#define PORT_POS 2

int main(int argc, char *argv[]){
	char* hostname = argv[IP_POS];
	char* puerto = argv[PORT_POS];

    Socket skt(hostname, puerto);
    skt.conect(hostname, puerto);
	// INICIALIZO TODO LO QUE TENGA QUE VER CON SDL
	SDL_Init(SDL_INIT_EVERYTHING);

	Window main_window(WIDTH,HEIGHT);
	// ACA ADENTRO OCURRE LA COMUNICACION
	main_window.run(&skt);


	SDL_Quit();

	return 0;
}
