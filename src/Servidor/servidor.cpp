#include "servidor.h"
#include <stdlib.h>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <iostream>
#include "entrada_estandar.h"

#define MAX_CONEXIONES 4
#define FIN_ENTRADA "q"
typedef struct sockaddr* Address;
typedef std::map<std::string, Conexion_cliente*>::iterator ItClientes;

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


Servidor::Servidor(char *puerto) : 
mundo(this, 50), 
entrada(FIN_ENTRADA){
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
    delete cliente;
  }
  entrada.join();
}

void Servidor::aceptar_clientes(){
  Socket* aceptado = skt->accept(NULL);
  if (!aceptado){
    std::cout << "no acepté nada!";
  }
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
  clientes[id_cliente] = new Conexion_cliente(cliente_nuevo, id, mundo);
}

bool Servidor::termino_ejecucion(){
  return entrada.termino();
}

void Servidor::empezar_partida(){
  mundo.jugar();
}

void Servidor::enviar_porcentaje_energia(std::string id, int energia){
	ItClientes it = clientes.find(id);
	if ((it->first).compare(id) == 0){
		//HAY QUE NOTIFICARLE A LOS OTROS CLIENTES TMB(?)
		(it->second)->enviar_porcentaje_energia(energia);
	}
}

void Servidor::enviar_porcentaje_vida(std::string id, int vida){
	//LE AVISO A TODOS LOS JUGADORES QUE ALGUN PERSONAJE PERDIO VIDA
	for (ItClientes it = clientes.begin(); it != clientes.end(); ++it){
		(it->second)->enviar_porcentaje_vida(id, vida);
	}
}

void Servidor::enviar_cantidad_vidas(std::string id, int cant_vidas){
	//LE AVISO A TODOS LOS JUGADORES QUE ALGUN PERSONAJE PERDIO PORCENTAJE DE VIDA
	for (ItClientes it = clientes.begin(); it != clientes.end(); ++it){
		(it->second)->enviar_cantidad_vidas(id, cant_vidas);
	}
}

void Servidor::enviar_cambio_posicion(std::string id, int x, int y){
	for (ItClientes it = clientes.begin(); it != clientes.end(); ++it){
		(it->second)->enviar_cambio_posicion(id, x, y);
	}
}

void Servidor::enviar_gameover(std::string id){
	ItClientes it = clientes.find(id);
	if ((it->first).compare(id) == 0){
		//HAY QUE NOTIFICARLE A LOS OTROS CLIENTES TMB(?)
		(it->second)->enviar_gameover();
		(it->second)->terminar_ejecucion();
		clientes.erase(id);
	}
}

