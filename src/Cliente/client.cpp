#include "../Comun/socket.h"
#include "game.h"

#include <sstream>
#include <iostream>
#include <cstdlib>
#include <string>
#include <string.h>
#include <strings.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

#define IP_POS 1
#define PORT_POS 2

int main(int argc, char *argv[]){
	char* hostname = argv[IP_POS];
	char* port = argv[PORT_POS];

	SDL_Init(SDL_INIT_EVERYTHING);

	Game game(hostname,port);
	game.run();

	SDL_Quit();
	return 0;
}
