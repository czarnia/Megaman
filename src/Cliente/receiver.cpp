#include "receiver.h"

Receiver::Receiver(Socket* conexion){
  skt = conexion;
}

virtual void Receiver::ejecutar(){
  char buffer[MAX_TAM_BUFFER];
  if ((*skt).receive(buffer, MAX_TAM_BUFFER, FIN_BUFFER, TAM_FIN) < 0){
      std::cout << "-1 al recibir \n";
  }
  while (strcmp(buffer, FIN_ENTRADA) != 0){
    if (strcmp(buffer, EN_ESPERA) != 0){
      std::cout << buffer << "\n";
    }
    strncpy(buffer, EN_ESPERA, MAX_TAM_BUFFER);
    if ((*skt).receive(buffer, MAX_TAM_BUFFER, FIN_BUFFER, TAM_FIN) < 0){
        std::cout << "-1 al recibir \n";
    }
  }
  (*skt).shutdown(SHUT_RDWR);
  fin = true;
  return;
}
