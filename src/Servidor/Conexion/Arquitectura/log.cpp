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
  const char* path = obtener_nombre_log();
  jugadores = std::map<int, std::string>();
  log_arch.open(path);
}

Log::~Log(){
  log_arch.close();
}

void Log::inicio_servidor(){
	Lock candado(proteccion);
  log_arch << "Servidor inicia ejecucion.\n";
}

void Log::fin_servidor(){
	Lock candado(proteccion);
	log_arch << "Servidor finaliza ejecucion.\n";
}

void Log::cliente_conectado(std::string nombre_cliente){
  Lock candado(proteccion);
  jugadores[jugadores.size()+1] = nombre_cliente;
  log_arch << "Cliente " << nombre_cliente << " se ha conectado.\n";
}

void Log::cliente_desconectado(int id_cliente){
  Lock candado(proteccion);
  log_arch << "Cliente " << jugadores[id_cliente] << " se ha desconectado.\n";
}

void Log::inicio_juego(){
	Lock candado(proteccion);
	log_arch << "Se inicia el juego con " << jugadores.size() << " jugadores.\n";
}

void Log::fin_juego(){
	Lock candado(proteccion);
	log_arch << "Fin del juego.\n";
}

void Log::inicio_nivel(int num_nivel){
  Lock candado(proteccion);
  log_arch << "Se inicia el nivel " << num_nivel << ".\n";
}

void Log::fin_nivel(){
  Lock candado(proteccion);
  log_arch << "Se finalizo el nivel.\n";
}

void Log::jugador_atacar(int id_cliente, int direccion){
  Lock candado(proteccion);
  log_arch << "El jugador " << jugadores[id_cliente] << " ataca en direccion "
  << direccion << ".\n";
}

void Log::jugador_mover(int id_cliente, int direccion){
  Lock candado(proteccion);
  log_arch << "El jugador " << jugadores[id_cliente] << " se mueve en direccion"
  << " " << direccion << ".\n";
}

void Log::jugador_cambiar_arma(int id_cliente, int arma){
  Lock candado(proteccion);
  log_arch << "El jugador " << jugadores[id_cliente] << " cambia su arma por "
  << arma << ".\n";
}
