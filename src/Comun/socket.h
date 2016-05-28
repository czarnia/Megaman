#ifndef SOCKET_H
#define SOCKET_H

#include <stddef.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

class Socket{
  private:
    int skt;

  public:
    //Dado un puerto y una ip, crea un socket.
    Socket(char* puerto, char* ip);
    //Destruye un socket (hace close).
    ~Socket();
    //Hace un shutdown, devuelve menor a cero en caso de error.
    int shutdown(int como);
    //Hace un listen, devuelve menor a cero en caso de error.
    int listen(int conexiones);
    //Hace un bind, devuelve menor a cero en caso de error.
    int bind(char* id, char* puerto);
    //Hace un accept, devuelve NULL en caso de un error en el accept.
    Socket* accept(struct sockaddr* dir_cliente);
    //Hace un connect, devuelve menor a cero en caso de error.
    int conect(char* ip, char* puerto);
    //Hace un receive, recibe una cantidad "tamanio" de datos, devuelve menor a
    //cero en caso de error.
    int receive(char* buffer, size_t tam_max);
	  int receiveInt(int* integer, size_t tam_max);
    //Hace un send, devuelve menor a cero en caso de error.
    int send(const char* buffer, size_t tamanio);
	  //Hace un send de un int en lugar de usar un buffer.
	  int sendInt(int* integer, size_t tamanio);

  private:
    //Inicia un addrinfo.
    struct addrinfo* iniciar_addrinfo(char* ip, char* puerto);
    //Creador que ya recibe un socket de c (producto de un accept).
    explicit Socket(int aceptado);
};

#endif // SOCKET_H
