#include "log.h"

Log::Log(char* path){
  jugadores = std::map<int, std::string>();
  log_arch.open(path);
}

Log::~Log(){
  log_arch.close();
}

void Log::cliente_conectado(std::string nombre_cliente){
  jugadores[jugadores.size()+1] = nombre_cliente;
  log_arch << "Cliente " << nombre_cliente << " se ha conectado.\n";
}

void Log::cliente_desconectado(int id_cliente){
  log_arch << "Cliente " << jugadores[id_cliente] << " se ha desconectado.\n";
}

void Log::inicio_nivel(int num_nivel){
  log_arch << "Se inicia el nivel " << num_nivel << ".\n";
}

void Log::fin_nivel(){
  log_arch << "Se finalizo el nivel.\n";
}

void Log::jugador_atacar(int id_cliente, int direccion){
  log_arch << "El jugador " << jugadores[id_cliente] << " ataca en direccion "
  << direccion << ".\n";
}

void Log::jugador_mover(int id_cliente, int direccion){
  log_arch << "El jugador " << jugadores[id_cliente] << " se mueve en direccion"
  << " " << direccion << ".\n";
}

void Log::jugador_cambiar_arma(int id_cliente, int arma){
  log_arch << "El jugador " << jugadores[id_cliente] << " cambia su arma por "
  << arma << ".\n";
}
