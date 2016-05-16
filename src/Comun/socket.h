#ifndef SOCKET_H
#define SOCKET_H

#include <stddef.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <vector>

class Socket{
  private:
    int skt;
  public:
    //Dado un puerto y una ip, crea un socket. Si se le pasa un skt de C como
    //tercer atributo, se crea con el mismo.
    Socket(char* puerto, char* ip, int sktc = -1);
    //Destruye un socket (hace close).
    ~Socket();
    //Hace un shutdown, devuelve menor a cero en caso de error.
    int shutdown(int como);
    //Hace un listen, devuelve menor a cero en caso de error.
    int listen(int conexiones);
    //Hace un bind, devuelve menor a cero en caso de error.
    int bind(char* id, char* puerto);
    //Hace un accept, devuelve un nuevo socket o NULL en caso de error.
    Socket* accept(struct sockaddr* dir_cliente);
    //Hace un connect, devuelve menor a cero en caso de error.
    int conect(char* ip, char* puerto);
    //Hace un receive, recibe una cantidad "tamanio" de datos, devuelve menor a
    //cero en caso de error.
    int receive(char* buffer, size_t tamanio);
    //Hace un send, devuelve menor a cero en caso de error.
    int send(const char* buffer, size_t tamanio);

  private:
    //Inicia un addrinfo.
    struct addrinfo* iniciar_addrinfo(char* ip, char* puerto);
	std::vector<Socket*> creados;
	char* ip; 
	char* puerto; 
	int sktc;
};

#endif // SOCKET_H
