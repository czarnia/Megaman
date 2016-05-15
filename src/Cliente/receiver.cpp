#include "receiver.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
//TODO:Definir estos valores!
#define FIN_BUFFER '\n'
#define TAM_FIN 1
#define MAX_TAM_BUFFER 70
#define FIN_ENTRADA "End"
#define EN_ESPERA " "

Receiver::Receiver(Socket* conexion){
  skt = conexion;
}

void Receiver::ejecutar(){
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
  //fin = true;
  return;
}
