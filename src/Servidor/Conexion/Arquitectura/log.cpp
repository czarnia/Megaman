#include "log.h"
#include "../../../Comun/lock.h"
#include <ctime>
#include <algorithm>

bool Log::hay_instancia = false;
Log* Log::singleton = NULL;

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

Log* Log::instancia(){
	if (!hay_instancia){
		singleton = new Log();
		hay_instancia = true;
	}
	return singleton;
}

Log::Log(){
  path = obtener_nombre_log();
  jugadores = std::map<int, std::string>();
}

Log::~Log(){
	//this->log_arch.close();
	singleton = NULL;
	hay_instancia = false;
}

void Log::inicio_servidor(){
	std::cout << "------------------INICIO SERVIDOR--------------\n";
	Lock candado(proteccion);
	this->log_arch.open(path, std::ios::out | std::ios::app);
	this->log_arch << "Servidor inicia ejecucion." << std::endl;
	this->log_arch.close();
}

void Log::fin_servidor(){
	Lock candado(proteccion);
	this->log_arch.open(path, std::ios::out | std::ios::app);
	this->log_arch << "Servidor finaliza ejecucion." << std::endl;
	this->log_arch.close();
}

void Log::cliente_conectado(std::string nombre_cliente){
	std::cout << "------------------CLIENTE CONECTADO--------------\n";
  Lock candado(proteccion);
	jugadores[jugadores.size()+1] = nombre_cliente;
	this->log_arch.open(path, std::ios::out | std::ios::app);
	this->log_arch << "Cliente " << nombre_cliente << " se ha conectado." << std::endl;
	this->log_arch.close();
}

void Log::cliente_desconectado(int id_cliente){
  Lock candado(proteccion);
	this->log_arch.open(path, std::ios::out | std::ios::app);
	this->log_arch << "Cliente " << jugadores[id_cliente] << " se ha desconectado." << std::endl;
	this->log_arch.close();
}

void Log::inicio_juego(){
	std::cout << "------------------INICIO JUEGO--------------\n";
	Lock candado(proteccion);
	this->log_arch.open(path, std::ios::out | std::ios::app);
	this->log_arch << "Se inicia el juego con " << jugadores.size() << " jugadores." << std::endl;
	this->log_arch.close();
}

void Log::fin_juego(){
	Lock candado(proteccion);
	this->log_arch.open(path, std::ios::out | std::ios::app);
	log_arch << "Fin del juego." << std::endl;
	this->log_arch.close();
}

void Log::inicio_nivel(int num_nivel){
  Lock candado(proteccion);
	this->log_arch.open(path, std::ios::out | std::ios::app);
  log_arch << "Se inicia el nivel " << num_nivel << "." << std::endl;
	this->log_arch.close();
}

void Log::fin_nivel(){
  Lock candado(proteccion);
	this->log_arch.open(path, std::ios::out | std::ios::app);
  log_arch << "Se finalizo el nivel." << std::endl;
	this->log_arch.close();
}

void Log::jugador_atacar(int id_cliente, int direccion){
	std::cout << "------------------JUGADOR ATACAR--------------\n";
  Lock candado(proteccion);
	this->log_arch.open(path, std::ios::out | std::ios::app);
  log_arch << "El jugador " << jugadores[id_cliente] << " ataca en direccion "
  << direccion << "." << std::endl;
	this->log_arch.close();
}

void Log::jugador_mover(int id_cliente, int direccion){
	std::cout << "------------------JUGADOR MOVER--------------\n";
  Lock candado(proteccion);
	this->log_arch.open(path, std::ios::out | std::ios::app);
  log_arch << "El jugador " << jugadores[id_cliente] << " se mueve en direccion"
  << " " << direccion << "." << std::endl;
	this->log_arch.close();
}

void Log::jugador_cambiar_arma(int id_cliente, int arma){
  Lock candado(proteccion);
	this->log_arch.open(path, std::ios::out | std::ios::app);
  log_arch << "El jugador " << jugadores[id_cliente] << " cambia su arma por "
  << arma << "." << std::endl;
	this->log_arch.close();
}
