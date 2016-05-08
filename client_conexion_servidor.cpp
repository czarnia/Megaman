#include "client_conexion_servidor.h"

Conexion_servidor(Socket* conexion){
  skt = conexion;
}

~Conexion_servidor(){}

void ejecutar(){
  char buffer[MAX_TAM_BUFFER];
  if ((*skt).receive(buffer, MAX_TAM_BUFFER, FIN_BUFFER, TAM_FIN) < 0){
      std::cout << "-1 al recibir \n";
  }
  while (strcmp(buffer, FIN_ENTRADA) != 0){
    if (strcmp(buffer, EN_ESPERA) != 0){
      std::cout << buffer << "\n";
      //Acá se procesa la información y se hacen las modificaciones en la vista
    }
    strncpy(buffer, EN_ESPERA, MAX_TAM_BUFFER);
    if ((*skt).receive(buffer, MAX_TAM_BUFFER, FIN_BUFFER, TAM_FIN) < 0){
        std::cout << "-1 al recibir \n";
    }
  }
  (*skt).shutdown(SHUT_RDWR);
}
