#include "log.h"
#include "../../../Comun/lock.h"
#include <ctime>
#include <algorithm>

//-------------------->Auxiliares<--------------------//

const char* obtener_nombre_log(){
	//std::string fin_arch = ".txt";

	std::time_t fecha = std::time(NULL);
	std::string fecha_str = std::ctime(&fecha);
	std::replace(fecha_str.begin(), fecha_str.end(), ' ', '-');
	fecha_str.append(".txt");

	return fecha_str.c_str();
}

//----------------------------------------------------//

Log::Log(){
  path = obtener_nombre_log();
  jugadores = std::map<int, std::string>();
}

Log::~Log(){
	//this->log_arch.close();
}

void Log::inicio_servidor(){
	std::cout << "Entro al inicio serv.";
	Lock candado(proteccion);
	this->log_arch.open(path, std::ios::out | std::ios::app);
	this->log_arch << "Servidor inicia ejecucion.\n";
	this->log_arch.close();
}

void Log::fin_servidor(){
	Lock candado(proteccion);
	this->log_arch.open(path, std::ios::out | std::ios::app);
	this->log_arch << "Servidor finaliza ejecucion.\n";
	this->log_arch.close();
}

void Log::cliente_conectado(std::string nombre_cliente){
  Lock candado(proteccion);
	jugadores[jugadores.size()+1] = nombre_cliente;
	this->log_arch.open(path, std::ios::out | std::ios::app);
	this->log_arch << "Cliente " << nombre_cliente << " se ha conectado.\n";
	this->log_arch.close();
}

void Log::cliente_desconectado(int id_cliente){
  Lock candado(proteccion);
	this->log_arch.open(path, std::ios::out | std::ios::app);
	this->log_arch << "Cliente " << jugadores[id_cliente] << " se ha desconectado.\n";
	this->log_arch.close();
}

void Log::inicio_juego(){
	Lock candado(proteccion);
	this->log_arch.open(path, std::ios::out | std::ios::app);
	this->log_arch << "Se inicia el juego con " << jugadores.size() << " jugadores.\n";
	this->log_arch.close();
}

void Log::fin_juego(){
	Lock candado(proteccion);
	this->log_arch.open(path, std::ios::out | std::ios::app);
	log_arch << "Fin del juego.\n";
	this->log_arch.close();
}

void Log::inicio_nivel(int num_nivel){
  Lock candado(proteccion);
	this->log_arch.open(path, std::ios::out | std::ios::app);
  log_arch << "Se inicia el nivel " << num_nivel << ".\n";
	this->log_arch.close();
}

void Log::fin_nivel(){
  Lock candado(proteccion);
	this->log_arch.open(path, std::ios::out | std::ios::app);
  log_arch << "Se finalizo el nivel.\n";
	this->log_arch.close();
}

void Log::jugador_atacar(int id_cliente, int direccion){
  Lock candado(proteccion);
	this->log_arch.open(path, std::ios::out | std::ios::app);
  log_arch << "El jugador " << jugadores[id_cliente] << " ataca en direccion "
  << direccion << ".\n";
	this->log_arch.close();
}

void Log::jugador_mover(int id_cliente, int direccion){
  Lock candado(proteccion);
	this->log_arch.open(path, std::ios::out | std::ios::app);
  log_arch << "El jugador " << jugadores[id_cliente] << " se mueve en direccion"
  << " " << direccion << ".\n";
	this->log_arch.close();
}

void Log::jugador_cambiar_arma(int id_cliente, int arma){
  Lock candado(proteccion);
	this->log_arch.open(path, std::ios::out | std::ios::app);
  log_arch << "El jugador " << jugadores[id_cliente] << " cambia su arma por "
  << arma << ".\n";
	this->log_arch.close();
}
