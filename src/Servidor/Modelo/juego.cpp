#include "juego.h"
#include <cstddef>
#include <iosfwd>
#include <ctime>
#include <unistd.h>
#include "../../Comun/lock.h"
#include "ubicable_factory.h"
#include "megaman_factory.h"
#include "megaman.h"
#include "met_factory.h"
#include "escalera_factory.h"
#include "bloque_factory.h"
#include "puas_factory.h"
#include "bumby_factory.h"
#include "snipper_factory.h"
#include "boss_factory.h"
#include "../../Editor/cargador_mapa.h"
#include "personaje_pc.h"
#include <iostream>
#include <algorithm>

#define MAIN_PATH_MAPAS "../../../Mapas/"
#define TIEMPO 0.03
#define TOT_NIVELES 5

typedef std::vector<int>::iterator ItNiveles;

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
	bool es_nivel = cargador->mapa_es_predefinido();
	mundo = new Mapa(ancho, alto, es_nivel);
	mundo->ubicar_puerta_boss(cargador->get_coordenada_puerta_boss());
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
	while (!fin_partida && jugando_nivel){
		clock_t iniciar_tiempo = clock();
		{
			Lock l(proteccion);
			update(0.005);
		}
		float delta_tiempo = TIEMPO-float(clock()-iniciar_tiempo)/CLOCKS_PER_SEC;
		sleep(delta_tiempo);
	}
}

void Juego::terminar_partida(){
	fin_partida = true;
	jugando_nivel = false;
}

void Juego::update(float tiempo){
	mundo->update(tiempo);
}

void Juego::personaje_atacar(int id_pj, int direccion){ //debería ser sólo para megaman!
	Lock candado(proteccion);
	int id = Megaman::construir_id_megaman(id_pj);
	Personaje* pj = mundo->obtener_pj(id);
	pj->atacar(direccion, mundo);
}

void Juego::personaje_mover(int id_pj, int direccion){
	Lock candado(proteccion);
	std::cout << "JUEGO: AGREGAR MOVIMIENTO PERSONAJE\n";
	int id = Megaman::construir_id_megaman(id_pj);
	Personaje_pc* pj = (Personaje_pc*)mundo->obtener_pj(id); //TODO:DYNAMIC CAST
	if (pj == NULL){
		std::cout << "JUEGO: PERSONAJE NO ESTA EN MAPA\n";
		return;
	}
	pj->agregar_movimiento(direccion);
}

void Juego::personaje_parar(int id_pj, int direccion){
	Lock candado(proteccion);
	std::cout << "JUEGO: OBTENGO AL PERSONAJE\n";
	int id = Megaman::construir_id_megaman(id_pj);
	Personaje_pc* pj = (Personaje_pc*)mundo->obtener_pj(id); //TODO:DYNAMIC CAST
	if (pj == NULL){
		std::cout << "JUEGO: PERSONAJE NO ESTA EN MAPA\n";
		return;
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

void Juego::actualizo_estado_personaje(int tipo, int id, int estado_act){
	for (size_t i = 0; i < observadores.size(); i++){
		Observador_juego *obs = (Observador_juego*)observadores[i];
		obs->update_estado_personaje(tipo, id, estado_act);
	}
}

void Juego::murio_personaje(Personaje *p){
	mundo->quitar_personaje(p->get_id_unico());
	if (p->get_id_unico() > 0 && p->get_id_unico() <= 4){ //IDS de los megamans
		cant_jugadores -= 1;
	}
	if (cant_jugadores == 0){
		notificar_termino_partida();
		terminar_partida();
	}
}

void Juego::murio_boss(){
	//FINALIZAR EL NIVEL.
	jugando_nivel = false;
	int id = mundo->get_id();
	bool mapa_es_nivel = mundo->es_mapa_nivel();
	ItNiveles it = std::find(niveles_ganados.begin(),
	niveles_ganados.end(), id);
	if (it == niveles_ganados.end() && mapa_es_nivel){
		niveles_ganados.push_back(id);
	}
	if (niveles_ganados.size() == TOT_NIVELES){
		//NOTIFICAR VICTORIA JUEGO:
		terminar_partida();
		notificar_termino_partida();
	}else{
		//NOTIFICAR VICTORIA NIVEL:
		notificar_termino_nivel();
	}
	jugando_nivel = false;
}

void Juego::notificar_termino_nivel(){
	for (size_t i = 0; i < observadores.size(); i++){
		Observador_juego *obs = (Observador_juego*)observadores[i];
		obs->update_fin_nivel();
	}
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
