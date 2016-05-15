#include "conexion_cliente.h"

Conexion_cliente(Socket* conexion){
  skt = conexion;
}

virtual void ejecutar(){
  char buffer[MAX_TAM_BUFFER];
  if ((*skt).receive(buffer, MAX_TAM_BUFFER) < 0){
      std::cout << "-1 al recibir \n";
  }
  while (strcmp(buffer, FIN_ENTRADA) != 0){
    if (strcmp(buffer, EN_ESPERA) != 0){
      skt.send(buffer, strlen(buffer)); //sólo reenvio lo que recibí por ahora!
    }
    strncpy(buffer, EN_ESPERA, MAX_TAM_BUFFER);
    if ((*skt).receive(buffer, MAX_TAM_BUFFER) < 0){
        std::cout << "-1 al recibir \n";
    }
  }
  (*skt).shutdown(SHUT_RDWR);
  //fin = true;
  return;
}
