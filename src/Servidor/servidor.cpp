#include "servidor.h"
#include <stdlib.h>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <iostream>

#define MAX_CONEXIONES 4
typedef struct sockaddr* Address;


//--------------->Auxiliares<---------------//
std::vector<std::string> obtener_claves(std::map<std::string,
                                                Conexion_cliente*> hash){
  std::vector<std::string> v;
  std::map<std::string,Conexion_cliente*>::iterator i;
  for (i = hash.begin(); i != hash.end(); i++){
    v.push_back(i->first);
  }
  return v;
}
//------------------------------------------//


Servidor::Servidor(char *puerto){
	skt = new Socket(NULL, puerto);
	skt->bind(NULL, puerto);
	skt->listen(MAX_CONEXIONES);
}

Servidor::~Servidor(){
  std::vector<std::string> claves_clientes = obtener_claves(clientes);
  for (size_t i = 0; i < claves_clientes.size(); i++){
    Conexion_cliente* cliente = clientes[claves_clientes[i]];
    clientes.erase(claves_clientes[i]);
    cliente->terminar_ejecucion();
    cliente->join();
    delete cliente;
  }
}

void Servidor::aceptar_clientes(){
  Socket* aceptado = skt->accept(NULL);
  /*char buffer[4];
  aceptado->receive(buffer, 4);
  std::cout << buffer << "\n";*/
  agregar_cliente(aceptado);

  skt->shutdown(SHUT_RDWR);
}

void Servidor::agregar_cliente(Socket* cliente_nuevo){
  //Armo un id para el nuevo cliente con el numero de cliente.
  int id = (clientes.size() + 1);
  std::stringstream	s;
  s << id;
  std::string id_cliente(s.str());

  //Agrego al cliente:
  clientes[id_cliente] = new Conexion_cliente(cliente_nuevo, id);
  clientes[id_cliente]->start();
}
