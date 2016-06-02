#include "juego.h"
#include <cstddef>
#include <iosfwd>
#include "../Comun/lock.h"
#include "megaman_factory.h"
#include <iostream>

#define TIEMPO 5

Juego::Juego(size_t tamanio){
	mundo = new Mapa(tamanio);
	fin_partida = false;
	cant_jugadores = 0;
	factories.insert(std::pair<std::string, PersonajeFactory*>("MEGAMAN", new MegamanFactory(this)));
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

void Juego::personaje_atacar(std::string id_pj, int direccion){ //debería ser sólo para megaman!
	Lock candado(proteccion);
	Personaje* pj = mundo->obtener_pj(id_pj);
	pj->atacar(0, direccion, mundo);
}

void Juego::personaje_mover(std::string id_pj, int direccion){
  Lock candado(proteccion);
  Personaje* pj = mundo->obtener_pj(id_pj);
  std::cout << "JUEGO: AGREGAR MOVIMIENTO PERSONAJE\n";
  pj->agregar_movimiento(direccion);
}

void Juego::personaje_parar(std::string id_pj, int direccion){
  Lock candado(proteccion);
  std::cout << "JUEGO: OBTENGO AL PERSONAJE\n";
  Personaje* pj = mundo.obtener_pj(id_pj);
  std::cout << "JUEGO: LE DIGO AL PERSONAJE QUE DEJE DE MOVERSE\n";
  pj->sacar_movimiento(direccion);
}

void Juego::personaje_cambiar_arma(std::string id_pj, int arma){
  Lock candado(proteccion);
  /*
  Personaje* pj = mundo.obtener_pj(id_pj);
  personaje.cambiar_arma(arma);
  */
}

void Juego::agregar_observador(Observador_juego *observador){
	observadores.push_back(observador);
}

void Juego::quitar_observador(Observador_juego *observador){
	for (size_t i = 0; i < observadores.size(); i++){
		if (observadores[i] == observador){
			observadores.erase(observadores.begin()+i);
		}
	}
}

void Juego::notificar_termino_partida(){
	for (size_t i = 0; i < observadores.size(); i++){
		observadores[i]->update_fin_partida();
	}
}

void Juego::notificar_gameover(std::string id){
	for (size_t i = 0; i < observadores.size(); i++){
		observadores[i]->update_gameover(id);
	}
}

void Juego::notificar_murio_personaje(std::string id){
	mundo->quitar_personaje(id);
	for (size_t i = 0; i < observadores.size(); i++){
		observadores[i]->update_murio_personaje(id);
		if (cant_jugadores == 0){
			notificar_termino_partida();
			terminar_partida();
		}
	}
}

void Juego::murio_personaje(std::string id){
	notificar_murio_personaje(id);
}

void Juego::notificar_cantidad_vidas(std::string id, int cant_vidas){
	for (size_t i = 0; i < observadores.size(); i++){
		observadores[i]->update_cantidad_vidas(id, cant_vidas);
	}
}

void Juego::notificar_porcentaje_vida(std::string id, int cant_vida){
	for (size_t i = 0; i < observadores.size(); i++){
		observadores[i]->update_porcentaje_vida(id, cant_vida);
	}
}

void Juego::notificar_energia(std::string id, int energia){
	for (size_t i = 0; i < observadores.size(); i++){
		observadores[i]->update_energia(id, energia);
	}
}

void Juego::notificar_posicion(std::string id, int x, int y){
	for (size_t i = 0; i < observadores.size(); i++){
		observadores[i]->update_posicion(id, x, y);
	}
}

void Juego::actualizo_cantidad_vidas(std::string id, int vidas){
	notificar_cantidad_vidas(id, vidas);
}

void Juego::actualizo_porcentaje_vida(std::string id, int cant_vida){
	notificar_porcentaje_vida(id, cant_vida);
}

void Juego::actualizo_energia(std::string id, int energia){
	notificar_energia(id, energia);
}

void Juego::actualizo_posicion(std::string id, int x, int y){
	notificar_posicion(id, x, y);
}

Juego::~Juego(){}
