#include "juego.h"
#include <cstddef>
#include <iosfwd>
#include <ctime>
#include <unistd.h>
#include "../../Comun/lock.h"
#include "ubicable_factory.h"
#include "megaman_factory.h"
#include "met_factory.h"
#include "escalera_factory.h"
#include "bloque_factory.h"
#include "puas_factory.h"
#include "bumby_factory.h"
#include "snipper_factory.h"
#include "boss_factory.h"
#include "../../Editor/cargador_mapa.h"
#include <iostream>

#define MAIN_PATH_MAPAS "../../../Mapas/"
#define TIEMPO 0.03

Juego::Juego(){
	cant_jugadores = 0;
	//Le paso al cargador el numero de mapa
	//que quiero elegir:
	std::string root_path("../../../Mapas/");
	cargador = new Cargador_mapa(root_path.c_str());
	mundo = NULL;
	cargar_factories(cargador);
	jugando_nivel = false;
	fin_partida = false;
	partida_inicializada = false;
}

void Juego::cargar_factories(Cargador_mapa *cargador){
	factories.push_back(new Bloque_factory(cargador, this));
	factories.push_back(new Escalera_factory(cargador, this));
	factories.push_back(new Puas_factory(cargador, this));
	factories.push_back(new Bumby_factory(cargador, this));
	factories.push_back(new Snipper_factory(cargador, this));
	factories.push_back(new Megaman_factory(cargador, this));
	factories.push_back(new Met_factory(cargador, this));
	factories.push_back(new Boss_factory(cargador, this));
}

void Juego::inicializar_nivel(int numero_mapa){
	cargador->cargar_mapa(numero_mapa);
	int ancho = cargador->get_ancho_mapa();
	int alto = cargador->get_alto_mapa();
	mundo = new Mapa(ancho, alto);
	for (unsigned int i = 0; i < factories.size(); ++i){
		factories[i]->crear(mundo);
	}
	if (!partida_inicializada){
		partida_inicializada = true;
	}
	if (!jugando_nivel){
		jugando_nivel = true;
	}
}

void Juego::inicializar_partida(int num_jugadores){
	cant_jugadores = num_jugadores;
}

void Juego::jugar(){
	while (!fin_partida){ //ESTO EN REALIDAD VA A SER PARA !fin_partida && !fin_nivel(murio boss).
		clock_t iniciar_tiempo = clock();
		{
			Lock l(proteccion);
			update(0.01);
		}
		float delta_tiempo = TIEMPO-float(clock()-iniciar_tiempo)/CLOCKS_PER_SEC;
		sleep(delta_tiempo);
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
	if (pj == NULL){
		std::cout << "PERSONAJE ES NULL \n";
	}
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

bool Juego::esta_jugando_nivel(){
	return jugando_nivel;
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

/*void Juego::murio_boss(){
}*/

void Juego::notificar_personaje_update_escudo(int tipo, int id, bool bajo_escudo){
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

/*std::vector<Coordenada> Juego::bloques(){
	return mundo->coord_bloques();
}*/

std::vector<Ubicable*> Juego::devolver_ubicables(){
	return mundo->devolver_ubicables();
}

int Juego::get_cantidad_jugadores(){
	return cant_jugadores;
}

bool Juego::inicio_partida(){
	return partida_inicializada;
}

Mapa* Juego::get_mapa(){
	return mundo;
}


Juego::~Juego(){
	delete cargador;
	if (mundo != NULL){
		delete mundo;
	}
	size_t tam_factories = factories.size();
	for (size_t i = 0; i < tam_factories; i++){
		Ubicable_factory* factory = factories.back();
    factories.pop_back();
		delete factory;
	}
}
