#include <stdio.h>
#include <string.h>

#include <cstdlib>
#include <string>
#include <sstream>
#include <iostream>

#include "socket.h"

#define MAX_CONEXIONES 4

int main(int argc, char *argv[]){
  char* puerto = argv[1];

  Socket* conexion = new Socket(NULL, puerto);
  (*conexion).bind(NULL, puerto);
  (*conexion).listen(MAX_CONEXIONES);

  //Acepto un nuevo socket
  int nuevo_skt = (*skt).accept(NULL);
  if (nuevo_skt < 0 && fin){
    std::cout << "Problema en accept, ";
    printf("%s \n", strerror(errno));
    return 0;
  }
  Socket* aceptado = new Socket(NULL, NULL, nuevo_skt);


  delete conexion;
  delete aceptado;
  return 0;
}
