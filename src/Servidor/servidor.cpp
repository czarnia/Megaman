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


Servidor::Servidor(char *puerto):
entrada(FIN_ENTRADA){
	skt = new Socket(NULL, puerto);
	skt->bind(NULL, puerto);
	skt->listen(MAX_CONEXIONES);
	mundo = new Juego(50);
}

Servidor::~Servidor(){
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
  std::stringstream id_cliente;
  id_cliente << id;
  //Agrego al cliente:
  clientes[id_cliente.str()] = new Conexion_cliente(cliente_nuevo, id, mundo);
}

bool Servidor::termino_ejecucion(){
  return entrada.termino();
}

void Servidor::empezar_partida(){
	std::cout << "INICIO PARTIDA\n";
	mundo->agregar_observador(this);
	mundo->inicializar_partida(clientes.size());
	for (ItClientes it = clientes.begin(); it != clientes.end(); ++it){
		it->second->iniciar_ejecucion();
	}
	mundo->jugar();
}

void Servidor::update(Observable *obs){}

void Servidor::update_fin_partida(){
	std::vector<std::string> claves_clientes = obtener_claves(clientes);
	for (size_t i = 0; i < claves_clientes.size(); i++){
		Conexion_cliente* cliente = clientes[claves_clientes[i]];
		clientes.erase(claves_clientes[i]);
		cliente->terminar_ejecucion();
		//delete cliente;
	}
	//delete mundo;
}

void Servidor::update_gameover(std::string id){
	//LE AVISO A TODOS LOS JUGADORES QUE ALGUN JUGADOR PERDIO.
	ItClientes it = clientes.find(id);
	if ((it->first).compare(id) == 0){
		//HAY QUE NOTIFICARLE A LOS OTROS CLIENTES TMB(?)
		(it->second)->enviar_gameover();
		(it->second)->terminar_ejecucion();
		clientes.erase(id);
	}
}

void Servidor::update_murio_personaje(std::string id) {
	//LE AVISO A TODOS LOS JUGADORES QUE ALGUN PERSONAJE MURIO
	for (ItClientes it = clientes.begin(); it != clientes.end(); ++it){
		(it->second)->enviar_cambio_posicion(id, -1, -1);
	}
}

void Servidor::update_cantidad_vidas(std::string id, int vidas) {
	//LE AVISO A TODOS LOS JUGADORES QUE ALGUN PERSONAJE PERDIO
	// PORCENTAJE DE VIDA
	for (ItClientes it = clientes.begin(); it != clientes.end(); ++it){
		(it->second)->enviar_cantidad_vidas(id, vidas);
	}
}

void Servidor::update_porcentaje_vida(std::string id, int vida){
//LE AVISO A TODOS LOS JUGADORES QUE ALGUN PERSONAJE PERDIO VIDA
	for (ItClientes it = clientes.begin(); it != clientes.end(); ++it){
		(it->second)->enviar_porcentaje_vida(id, vida);
	}
}

void Servidor::update_energia(std::string id, int energia){
	ItClientes it = clientes.find(id);
	if ((it->first).compare(id) == 0){
		//HAY QUE NOTIFICARLE A LOS OTROS CLIENTES TMB(?)
		(it->second)->enviar_porcentaje_energia(energia);
	}
}

void Servidor::update_posicion(std::string id, int x, int y){
	//LE AVISO A TODOS LOS JUGADORES QUE ALGUN PERSONAJE ACTUALIZO SU POSICION
	for (ItClientes it = clientes.begin(); it != clientes.end(); ++it){
		(it->second)->enviar_cambio_posicion(id, x, y);
	}
}
