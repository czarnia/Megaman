#include "juego.h"
#include <cstddef>
#include <iosfwd>
#include "../Comun/lock.h"
#include "megaman_factory.h"
#include <iostream>

#define TIEMPO 5

Juego::Juego(size_t long_x, size_t long_y){
	mundo = new Mapa(long_x, long_y);
	fin_partida = false;
	cant_jugadores = 0;
	factories.insert(std::pair<std::string, MegamanFactory*>("MEGAMAN", new MegamanFactory(this)));
}

void Juego::inicializar_partida(int num_jugadores){
	cant_jugadores = num_jugadores;
	for (int i = 0; i < cant_jugadores; ++i){
		factories["MEGAMAN"]->crear(mundo);
	}
	//ACA SE PUEDEN CREAR LOS OTROS PERSONAJES.
}

void Juego::jugar(){
	while (!fin_partida){
		update(TIEMPO);
	}
}

void Juego::terminar_partida(){
	fin_partida = true;
}

void Juego::update(size_t tiempo){
	mundo->update(tiempo);
}

void Juego::personaje_atacar(int id_pj, int direccion){ //debería ser sólo para megaman!
	Lock candado(proteccion);
	Personaje* pj = mundo->obtener_pj(id_pj);
	pj->atacar(direccion, mundo);
}

void Juego::personaje_mover(int id_pj, int direccion){
  Lock candado(proteccion);
  Personaje* pj = mundo->obtener_pj(id_pj);
  std::cout << "JUEGO: AGREGAR MOVIMIENTO PERSONAJE\n";
  pj->agregar_movimiento(direccion);
}

void Juego::personaje_parar(int id_pj, int direccion){
  Lock candado(proteccion);
  std::cout << "JUEGO: OBTENGO AL PERSONAJE\n";
  Personaje* pj = mundo->obtener_pj(id_pj);
  std::cout << "JUEGO: LE DIGO AL PERSONAJE QUE DEJE DE MOVERSE\n";
  pj->sacar_movimiento(direccion);
}

void Juego::personaje_cambiar_arma(int id_pj, int arma){
  Lock candado(proteccion);
  /*
  Personaje* pj = mundo.obtener_pj(id_pj);
  personaje.cambiar_arma(arma);
  */
}

int Juego::long_y_mapa(){
	return mundo->obtener_long_y();
}

int Juego::long_x_mapa(){
	return mundo->obtener_long_x();
}

void Juego::agregar_observador(Observador_juego *observador){
	//observadores.push_back(observador);
	Observable::agregar_observador(observador);
}

void Juego::quitar_observador(Observador_juego *observador){
	for (size_t i = 0; i < observadores.size(); i++){
		if (observadores[i] == observador){
			observadores.erase(observadores.begin()+i);
		}
	}
}


void Juego::notificar_observadores(){}

void Juego::update(Observable *obs){}

void Juego::notificar_termino_partida(){
	for (size_t i = 0; i < observadores.size(); i++){
		Observador_juego *obs = (Observador_juego*)observadores[i];
		obs->update_fin_partida();
	}
}

void Juego::notificar_gameover(int id){
	for (size_t i = 0; i < observadores.size(); i++){
		Observador_juego *obs = (Observador_juego*)observadores[i];
		obs->update_gameover(id);
	}
}

void Juego::notificar_murio_personaje(int tipo, int id){
	mundo->quitar_personaje(id);
	for (size_t i = 0; i < observadores.size(); i++){
		Observador_juego *obs = (Observador_juego*)observadores[i];
		obs->update_murio_personaje(tipo, id);
		if (cant_jugadores == 0){
			notificar_termino_partida();
			terminar_partida();
		}
	}
}

void Juego::murio_personaje(int tipo, int id){
	notificar_murio_personaje(tipo, id);
}

void Juego::notificar_cantidad_vidas(int tipo, int id, int cant_vidas){
	for (size_t i = 0; i < observadores.size(); i++){
		Observador_juego *obs = (Observador_juego*)observadores[i];
		obs->update_cantidad_vidas(tipo, id, cant_vidas);
	}
}

void Juego::notificar_porcentaje_vida(int tipo, int id, int cant_vida){
	for (size_t i = 0; i < observadores.size(); i++){
		Observador_juego *obs = (Observador_juego*)observadores[i];
		obs->update_porcentaje_vida(tipo, id, cant_vida);
	}
}

void Juego::notificar_energia(int tipo, int id, int energia){
	for (size_t i = 0; i < observadores.size(); i++){
		Observador_juego *obs = (Observador_juego*)observadores[i];
		obs->update_energia(tipo, id, energia);
	}
}

void Juego::notificar_posicion(int tipo, int id, int x, int y){
	for (size_t i = 0; i < observadores.size(); i++){
		Observador_juego *obs = (Observador_juego*)observadores[i];
		obs->update_posicion(tipo, id, x, y);
	}
}

void Juego::actualizo_cantidad_vidas(int tipo, int id, int vidas){
	notificar_cantidad_vidas(tipo, id, vidas);
}

void Juego::actualizo_porcentaje_vida(int tipo, int id, int cant_vida){
	notificar_porcentaje_vida(tipo, id, cant_vida);
}

void Juego::actualizo_energia(int tipo, int id, int energia){
	notificar_energia(tipo, id, energia);
}

void Juego::actualizo_posicion(int tipo, int id, int x, int y){
	notificar_posicion(tipo, id, x, y);
}

std::vector<Coordenada> Juego::bloques(){
	return mundo->coord_bloques();
}

Juego::~Juego(){}
