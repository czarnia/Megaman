#include "conexion_cliente.h"
#include "../Comun/socket.h"
#include <iostream>
#include <stdio.h>
#include <string.h>

//TODO:Definir estos valores!
#define MAX_TAM_BUFFER 70
#define FIN_ENTRADA "End"
//
#define EN_ESPERA " "

Conexion_cliente::Conexion_cliente(Socket* conexion){
  skt = conexion;
  fin = false;
}

Conexion_cliente::~Conexion_cliente(){
  delete skt;
}


void Conexion_cliente::ejecutar(){
  char buffer[MAX_TAM_BUFFER];
  if ((*skt).receive(buffer, MAX_TAM_BUFFER) < 0){
      std::cout << "-1 al recibir \n";
  }
  while (!fin){
    if (strcmp(buffer, EN_ESPERA) != 0){
      skt->send(buffer, strlen(buffer)); //sólo reenvio lo que recibí por ahora!
    }
    strncpy(buffer, EN_ESPERA, MAX_TAM_BUFFER);
    if ((*skt).receive(buffer, MAX_TAM_BUFFER) < 0){
      if (fin){
        return;
      }
      std::cout << "-1 al recibir \n";
    }
  }
  return;
}

void Conexion_cliente::terminar_ejecucion(){
  (*skt).shutdown(SHUT_RDWR);
}
