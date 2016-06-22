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

#include <SDL2/SDL.h>

enum Codigo {INICIAR_NIVEL, POSICION, VIDA, ENERGIA, CANT_VIDAS,
	CAMBIO_ESTADO, FIN_NIVEL, DERROTA, VICTORIA};

#define MAIN_PATH_MAPAS "../../../Mapas/"
#define TIEMPO 20
#define TOT_NIVELES 5
#define MEGAMAN 1

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
			update(TIEMPO);
			enviar_estados();
		}
		float delta_tiempo = TIEMPO-float(clock()-iniciar_tiempo)/CLOCKS_PER_SEC;
		SDL_Delay(delta_tiempo);
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

//--------------------------HASTA ACÁ TODO BIEN-------------------------------//


void Juego::notificar_observadores(){}
void Juego::update(Observable *obs){}


void Juego::murio_personaje(Personaje *p){
	int id = p->get_id();
	int tipo = p->get_tipo();
	actualizo_posicion(tipo, id, -1, -1);

	mundo->quitar_personaje(p->get_id_unico());
	if (p->get_tipo() == MEGAMAN){
		//Esto es mejor pero es casi lo mismo:
	//bool es_pj_pc = (Ubicable::construir_id_unico(MEGAMAN, p->get_id()) == pj->get_id_unico());
	//if (es_pj_pc){
		cant_jugadores -= 1;
		actualizo_gameover(p->get_id_unico());
	}
	if (cant_jugadores == 0){
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
		actualizo_victoria();
	}else{
		//NOTIFICAR VICTORIA NIVEL:
		actualizo_termino_nivel();
	}
	jugando_nivel = false;
}



//-------------------------------------------------------------------//

void Juego::actualizo_gameover(int id){
	Estado nuevo_estado(DERROTA, id);
	cola_estados.push(nuevo_estado);
}

void Juego::actualizo_victoria(){
	Estado nuevo_estado(VICTORIA);
	cola_estados.push(nuevo_estado);
}

void Juego::actualizo_termino_nivel(){
	Estado nuevo_estado(FIN_NIVEL);
	cola_estados.push(nuevo_estado);
}

void Juego::actualizo_cantidad_vidas(int tipo, int id, int vidas){
	Estado nuevo_estado(CANT_VIDAS, tipo, id, vidas);
	cola_estados.push(nuevo_estado);

}

void Juego::actualizo_porcentaje_vida(int tipo, int id, int cant_vida){
	Estado nuevo_estado(VIDA, tipo, id, cant_vida);
	cola_estados.push(nuevo_estado);
}

void Juego::actualizo_energia(int tipo, int id, int energia){
	Estado nuevo_estado(ENERGIA, tipo, id, energia);
	cola_estados.push(nuevo_estado);
}

void Juego::actualizo_posicion(int tipo, int id, int x, int y){
	Estado nuevo_estado(POSICION, tipo, id, x, y);
	cola_estados.push(nuevo_estado);
}

void Juego::actualizo_estado_personaje(int tipo, int id, int estado){
	Estado nuevo_estado(CAMBIO_ESTADO, tipo, id, estado);
	cola_estados.push(nuevo_estado);
}

void Juego::enviar_estados(){
	while(!cola_estados.empty()){
		Estado e = cola_estados.front();
		for (size_t i = 0; i < observadores.size(); i++){
			Observador_juego *obs = (Observador_juego*)observadores[i];
			obs->update_estado(e);
		}
		cola_estados.pop();
	}
}

//-------------------------------------------------------------------//


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
