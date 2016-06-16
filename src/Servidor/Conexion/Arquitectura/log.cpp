#include "log.h"
#include "../../../Comun/lock.h"
#include <ctime>
#include <algorithm>
#include <sstream>

bool Log::hay_instancia = false;
Log* Log::singleton = NULL;

//-------------------->Auxiliares<--------------------//

std::string obtener_nombre_log(){
	//std::string fin_arch = ".txt";

	std::time_t fecha = std::time(NULL);
	std::string fecha_str = std::ctime(&fecha);
	std::replace(fecha_str.begin(), fecha_str.end(), ' ', '-');
	fecha_str.append(".txt");

	return fecha_str;
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
	//exportar(str.str());
	singleton = NULL;
	hay_instancia = false;
}

void Log::cerrar(){
	if (hay_instancia){
		delete singleton;
	}
}

void Log::inicio_servidor(){
	std::cout << "------------------INICIO SERVIDOR--------------\n";
	std::stringstream str;
	str << "Servidor inicia ejecucion.";
	exportar(str.str());
}

void Log::fin_servidor(){
	std::stringstream str;
	str << "Servidor finaliza ejecucion.";
	exportar(str.str());
}

void Log::cliente_conectado(std::string nombre_cliente){
	std::cout << "------------------CLIENTE CONECTADO--------------\n";
	jugadores[jugadores.size()+1] = nombre_cliente;
	std::stringstream str;
	str << "Cliente " << nombre_cliente << " se ha conectado.";
	exportar(str.str());
}

void Log::cliente_desconectado(int id_cliente){
	std::stringstream str;
	str << "Cliente " << jugadores[id_cliente] << " se ha desconectado.";
	exportar(str.str());
}

void Log::inicio_juego(){
	std::cout << "------------------INICIO JUEGO--------------\n";
	std::stringstream str;
	str << "Se inicia el juego con " << jugadores.size() << " jugadores.";
	exportar(str.str());
}

void Log::fin_juego(){
	std::stringstream str;
	str << "Fin del juego." << std::endl;
	exportar(str.str());
}

void Log::inicio_nivel(int num_nivel){
	std::stringstream str;
  str << "Se inicia el nivel " << num_nivel << ".";
	exportar(str.str());
}

void Log::fin_nivel(){
	std::stringstream str;
	str << "Se finalizo el nivel." << std::endl;
	exportar(str.str());
}

void Log::jugador_atacar(int id_cliente, int direccion){
	std::cout << "------------------JUGADOR ATACAR--------------\n";
	std::stringstream str;
  str << "El jugador " << jugadores[id_cliente] << " ataca en direccion "
  << direccion << ".";
	exportar(str.str());
}

void Log::jugador_mover(int id_cliente, int direccion){
	std::cout << "------------------JUGADOR MOVER--------------\n";
	std::stringstream str;
  str << "El jugador " << jugadores[id_cliente] << " se mueve en direccion"
  << " " << direccion << ".";
	exportar(str.str());
}

void Log::jugador_cambiar_arma(int id_cliente, int arma){
	std::stringstream str;
  str << "El jugador " << jugadores[id_cliente] << " cambia su arma por "
  << arma << ".";
	exportar(str.str());
}

void Log::exportar(std::string mensaje){
	Lock candado(proteccion);
	std::ofstream log_arch;
	log_arch.open(path.c_str(), std::fstream::app | std::fstream::out);
	log_arch << mensaje << std::endl;
	log_arch.close();
}
