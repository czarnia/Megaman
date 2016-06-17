#include "almacenador_clientes.h"

#include <string>
#include <sstream>
#include <iostream>

typedef std::map<int, Conexion_cliente*>::iterator ItClientes;

//--------------->Auxiliares<---------------//
std::vector<int> obtener_claves(std::map<int, Conexion_cliente*> hash){
  std::vector<int> v;
  std::map<int,Conexion_cliente*>::iterator i;
  for (i = hash.begin(); i != hash.end(); i++){
    v.push_back(i->first);
  }
  return v;
}
//------------------------------------------//

int Almacenador_clientes::devolver_tamanio(){
  return clientes.size();
}

void Almacenador_clientes::agregar_cliente(Conexion_cliente* cliente){
  clientes[clientes.size()+1] = cliente;
  cliente->iniciar_ejecucion();
}

void Almacenador_clientes::iniciar_ejecucion(){
	for (ItClientes it = clientes.begin(); it != clientes.end(); ++it){
		it->second->iniciar_ejecucion();
	}
}

void Almacenador_clientes::update_fin_partida(){
	std::cout << "FIN PARTIDA\n";
	std::vector<int> claves_clientes = obtener_claves(clientes);
	for (size_t i = 0; i < claves_clientes.size(); i++){
		Conexion_cliente* cliente = clientes[claves_clientes[i]];
		clientes.erase(claves_clientes[i]);
		cliente->terminar_ejecucion();
		delete cliente;
	}
}

void Almacenador_clientes::update_gameover(int id){
	//LE AVISO A TODOS LOS JUGADORES QUE ALGUN JUGADOR PERDIO.
	ItClientes it = clientes.find(id);
	if (it->first == id){
		//HAY QUE NOTIFICARLE A LOS OTROS CLIENTES TMB(?)
		(it->second)->enviar_gameover();
		(it->second)->terminar_ejecucion();
		clientes.erase(id);
	}
}

void Almacenador_clientes::update_murio_personaje(int tipo, int id) {
	//LE AVISO A TODOS LOS JUGADORES QUE ALGUN PERSONAJE MURIO
	for (ItClientes it = clientes.begin(); it != clientes.end(); ++it){
		(it->second)->enviar_cambio_posicion(tipo, id, -1, -1);
	}
}

void Almacenador_clientes::update_cantidad_vidas(int tipo, int id, int vidas) {
	//LE AVISO A TODOS LOS JUGADORES QUE ALGUN PERSONAJE PERDIO
	// PORCENTAJE DE VIDA
	for (ItClientes it = clientes.begin(); it != clientes.end(); ++it){
		(it->second)->enviar_cantidad_vidas(tipo, id, vidas);
	}
}

void Almacenador_clientes::update_porcentaje_vida(int tipo, int id, int vida){
//LE AVISO A TODOS LOS JUGADORES QUE ALGUN PERSONAJE PERDIO VIDA
	for (ItClientes it = clientes.begin(); it != clientes.end(); ++it){
		(it->second)->enviar_porcentaje_vida(tipo, id, vida);
	}
}

void Almacenador_clientes::update_energia(int tipo, int id, int energia){
	for (ItClientes it = clientes.begin(); it != clientes.end(); ++it){
		//HAY QUE NOTIFICARLE A LOS OTROS CLIENTES TMB(?)
		(it->second)->enviar_porcentaje_energia(tipo, id, energia);
	}
}

void Almacenador_clientes::update_posicion(int tipo, int id, int x, int y){
	std::stringstream s;
	s << id;
	std::cout << "PERSONAJE "+s.str()+"ACTUALIZA POSICION\n";
	//LE AVISO A TODOS LOS JUGADORES QUE ALGUN PERSONAJE ACTUALIZO SU POSICION
	for (ItClientes it = clientes.begin(); it != clientes.end(); ++it){
		(it->second)->enviar_cambio_posicion(tipo, id, x, y);
	}
}

void Almacenador_clientes::iniciar_nivel(int num_nivel){
  for (ItClientes it = clientes.begin(); it != clientes.end(); ++it){
    (it->second)->iniciar_nivel(num_nivel);
  }
}

void Almacenador_clientes::update_personaje_escudo(int tipo, int id, int bajo_escudo){
	for (ItClientes it = clientes.begin(); it != clientes.end(); ++it){
		(it->second)->update_personaje_escudo(tipo, id, bajo_escudo);
	}
}

