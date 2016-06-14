#include "juego.h"
#include <cstddef>
#include <iosfwd>
#include "../../Comun/lock.h"
#include "ubicable_factory.h"
#include "megaman_factory.h"
#include "met_factory.h"
#include "escalera_factory.h"
#include "bloque_factory.h"
#include "puas_factory.h"
#include "bumby_factory.h"
#include "snipper_factory.h"
#include "../../Editor/cargador_mapa.h"
#include <iostream>

#define TIEMPO 5
#define MAIN_PATH_MAPAS "../../../Mapas/"

Juego::Juego(int id_mapa){
	fin_partida = false;
	cant_jugadores = 0;
	//Le paso al cargador el numero de mapa
	//que quiero elegir:
	std::string root_path(MAIN_PATH_MAPAS);
	Cargador_mapa cargador(root_path, id_mapa); 
	mundo = new Mapa(cargador.get_ancho_mapa(), cargador.get_alto_mapa());
}

void Juego::cargar_factories(Cargador_mapa *cargador){
	factories.push_back(new Megaman_factory(cargador, this));
	factories.push_back(new Met_factory(cargador, this));
	factories.push_back(new Escalera_factory(cargador, this));
	factories.push_back(new Bloque_factory(cargador, this));
	factories.push_back(new Puas_factory(cargador, this));
	factories.push_back(new Bumby_factory(cargador, this));
	factories.push_back(new Snipper_factory(cargador, this));
}

void Juego::inicializar_partida(int num_jugadores){
	cant_jugadores = num_jugadores;
	for (unsigned int i = 0; i < factories.size(); ++i){
		factories[i]->crear(mundo);
	}
}

void Juego::jugar(){
	while (!fin_partida){
		Lock l(proteccion);
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
	std::cout << "JUEGO: AGREGAR MOVIMIENTO PERSONAJE\n";
	std::cout << "ID PERSONAJE: " << id_pj << "\n";
  Personaje* pj = mundo->obtener_pj(id_pj);
	if (pj == NULL){
		std::cout << "PJ ES NULL \n";
	}
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

std::vector<Ubicable*> Juego::devolver_ubicables(){
	return mundo->devolver_ubicables();
}

int Juego::get_cantidad_jugadores(){
	return cant_jugadores;
}

Juego::~Juego(){}
