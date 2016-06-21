#include "estado.h"

#define TAM_INT 4

Estado::Estado(int op, int t, int i, int x, int y) :
comando(op), tipo(t), id(i), coord_x(x), coord_y(y) {}

void Estado::enviar(Socket* skt){
  skt->send((char*)&comando, TAM_INT);
  skt->send((char*)&tipo, TAM_INT);
  skt->send((char*)&id, TAM_INT);
  skt->send((char*)&coord_x, TAM_INT);
  skt->send((char*)&coord_y, TAM_INT);
}

int Estado::get_comando(){
  return comando;
}

int Estado::get_arg1(){
  return tipo;
}
