#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <netinet/in.h>

#include <string.h>
#include <strings.h>
#include <stdio.h>
#include <errno.h>

#include <netdb.h>

#include "socket.h"
#include <stdlib.h>

#include <cstdlib>
#include <sstream>
#include <iostream>

Socket::Socket(char* ip, char* puerto){
  struct addrinfo* addr = iniciar_addrinfo(ip, puerto);
  this->skt = socket(addr->ai_family, addr->ai_socktype, addr->ai_protocol);
  if (this->skt < 0){
    std::cout << "no tengo socket!! \n";
  }
  freeaddrinfo(addr);
}

Socket::~Socket(){
  close(this->skt);
}


int Socket::shutdown(int como){
  return ::shutdown(this->skt, como);
}


int Socket::listen(int conexiones){
  return ::listen(this->skt, conexiones);
}


int Socket::bind(char* ip, char* puerto){
  struct addrinfo* addr = iniciar_addrinfo(ip, puerto);
  int b = ::bind(this->skt, addr->ai_addr, addr->ai_addrlen);
  freeaddrinfo(addr);
  return b;
}

Socket* Socket::accept(struct sockaddr* dir_cliente){
  socklen_t tam_addr = sizeof(dir_cliente);
  int nuevo_socket = ::accept(this->skt, dir_cliente, &tam_addr);
  if (nuevo_socket < 0){
    return NULL;
  }
  Socket* nuevo = new Socket(nuevo_socket);
  return nuevo;
}

int Socket::conect(char* ip, char* puerto){
  struct addrinfo* server = iniciar_addrinfo(ip, puerto);
  int c = ::connect(this->skt, server->ai_addr, server->ai_addrlen);
  freeaddrinfo(server);
  return c;
}

int Socket::receive(char* buffer, size_t tam_max){
  size_t tam_actual = 0; //el tamaño total de lo que ya recibí.
  int tam_rcv = 0; //el tamaño de lo que recibo en cada ciclo.

  while (tam_actual < tam_max){
    int dif_tam = tam_max-tam_actual;
    tam_rcv = ::recv(this->skt, &buffer[tam_actual], dif_tam, MSG_NOSIGNAL);
    if (tam_rcv <= 0){
      return tam_rcv;
    }
    tam_actual += tam_rcv;
  }

  return tam_actual;
}

int Socket::receiveInt(int *integer, size_t tam_max){
  size_t tam_actual = 0; //el tamaño total de lo que ya recibí.
  int tam_rcv = 0; //el tamaño de lo que recibo en cada ciclo.

  while (tam_actual < tam_max){
    int dif_tam = tam_max-tam_actual;
    tam_rcv = ::recv(this->skt, integer, dif_tam, MSG_NOSIGNAL);
    if (tam_rcv <= 0){
      return tam_rcv;
    }
    tam_actual += tam_rcv;
  }

  return tam_actual;
}

int Socket::send(const char* buffer, size_t tamanio){
  size_t tam_actual = 0; //el tamaño total de lo que ya envié.
  int tam_send = 0; //el tamaño de lo que envio en cada ciclo.

  std::cout << "Envio un: " << buffer << "\n";

  while (tam_actual < tamanio){
    int dif_tam = tamanio-tam_actual;
    tam_send = ::send(this->skt, &buffer[tam_actual], dif_tam, MSG_NOSIGNAL);
    if (tam_send <= 0){
      return -1;
    }
    tam_actual += tam_send;
  }

  return tam_actual;
}

int Socket::sendInt(int* integer, size_t tamanio){
  size_t tam_actual = 0; //el tamaño total de lo que ya envié.
  int tam_send = 0; //el tamaño de lo que envio en cada ciclo.

  while (tam_actual < tamanio){
    int dif_tam = tamanio-tam_actual;
    tam_send = ::send(this->skt, integer, dif_tam, MSG_NOSIGNAL);
    if (tam_send <= 0){
      return -1;
    }
    tam_actual += tam_send;
  }

  return tam_actual;
}

struct addrinfo* Socket::iniciar_addrinfo(char* ip, char* puerto){
  struct addrinfo hints;
  struct addrinfo* server;

  memset(&hints, 0, sizeof(struct addrinfo));
  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_STREAM;

  getaddrinfo(ip, puerto, &hints, &server);

  return server;
}

Socket::Socket(int aceptado){
  this->skt = aceptado;
}
