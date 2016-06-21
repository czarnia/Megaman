#include "almacenador_clientes.h"

#define GAMEOVER 7

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

void Almacenador_clientes::update_fin_nivel(){
	for (ItClientes it = clientes.begin(); it != clientes.end(); ++it){
		it->second->finalizar_nivel();
	}
}

void Almacenador_clientes::iniciar_nivel(int num_nivel){
  for (ItClientes it = clientes.begin(); it != clientes.end(); ++it){
    (it->second)->iniciar_nivel(num_nivel);
  }
}

void Almacenador_clientes::update_estado(Estado e){
  for (ItClientes it = clientes.begin(); it != clientes.end(); ++it){
		it->second->update_estado(e);
	}
  if (e.get_comando() == GAMEOVER){
    ItClientes it = clientes.find(e.get_arg1());
    if (it->first == e.get_arg1()){
  		(it->second)->terminar_ejecucion();
  		clientes.erase(e.get_arg1());
  	}
  }
}
