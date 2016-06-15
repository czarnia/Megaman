#include "game.h"

#define IP_POS 1
#define PORT_POS 2

int main(int argc, char *argv[]){
	char* hostname = argv[IP_POS];
	char* port = argv[PORT_POS];
    /// Declaro el juego
	Game game(hostname,port);
	/// Ejecuto
	game.run();

	return 0;
}
