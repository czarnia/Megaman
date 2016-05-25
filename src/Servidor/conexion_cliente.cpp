#include "conexion_cliente.h"
#include "../Comun/socket.h"
#include <iostream>
#include <stdio.h>
#include <string.h>

#define TAM_INT 4
#define EN_ESPERA " "
//TODO: redefinir el fin...
#define FIN_ENTRADA "End"

Conexion_cliente::Conexion_cliente(Socket* conexion, int id) : id_cliente(id),
parser(id), handler(id){
  skt = conexion;
  fin = false;
}

Conexion_cliente::~Conexion_cliente(){
  delete skt;
}

void Conexion_cliente::ejecutar(){
  char comando[TAM_INT];
  char argumento[TAM_INT];

  while (!fin){
    if ((skt->receive(comando, TAM_INT) < 0) || (skt->receive(argumento, TAM_INT) < 0)){
      if (fin){
        return;
      }
      std::cout << "-1 al recibir dentro \n";
    }
    if (strcmp(comando, EN_ESPERA) != 0){
      Evento* e = parser.crear_evento(*((int*)comando), *((int*)argumento));
      handler.ejecutar_evento(e);
    }
    strncpy(comando, EN_ESPERA, TAM_INT);
  }
}

void Conexion_cliente::terminar_ejecucion(){
  fin = true;
  (*skt).send(FIN_ENTRADA, strlen(FIN_ENTRADA));
  (*skt).shutdown(SHUT_RDWR);
}
