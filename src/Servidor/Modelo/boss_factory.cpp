#include "boss_factory.h"
#include <sstream>
#include <iostream>
#include "observador_boss.h"
#include "arma_factory.h"
#include "sparkman.h"
#include "arma_sparkman.h"
#include "bombman.h"
#include "arma_bombman.h"
#include "ringman.h"
#include "arma_ringman.h"
#include "magnetman.h"
#include "arma_magnetman.h"
#include "fireman.h"
#include "arma_fireman.h"

enum eleccion_boss{BOMBMAN = 20, MAGNETMAN, SPARKMAN, RINGMAN, FIREMAN};

Boss_factory::Boss_factory(Cargador_mapa * cargador, Juego *juego):
Ubicable_factory(cargador, juego){}

void Boss_factory::crear(Mapa* mapa){
	//Creacion del boss:
	ArmaFactory arma_fact(juego);
	int codigo_boss = cargador->get_boss();
	std::vector<Coordenada*> coordenadas = cargador->get_coordenada_boss();
	Coordenada *coord_boss = coordenadas[0];
	Personaje_npc *boss;
	Arma_bombman* arma_b;
	Arma_magnetman* arma_m;
	Arma_sparkman* arma_s;
	Arma_ringman* arma_r;
	Arma_fireman* arma_f;
	switch (codigo_boss){
		case BOMBMAN:
			arma_b = arma_fact.crear_arma_bombman();
			boss = new Bombman(mapa, *coord_boss, arma_b, BOMBMAN);
			break;
		case MAGNETMAN:
			arma_m = arma_fact.crear_arma_magnetman();
			boss = new Magnetman(mapa, *coord_boss, arma_m, MAGNETMAN);
			break;
		case SPARKMAN:
			arma_s = arma_fact.crear_arma_sparkman();
			boss = new Sparkman(mapa, *coord_boss, arma_s, SPARKMAN);
			break;
		case RINGMAN:
			arma_r = arma_fact.crear_arma_ringman();
			boss = new Ringman(mapa, *coord_boss, arma_r, RINGMAN);
			break;
		case FIREMAN:
			arma_f = arma_fact.crear_arma_fireman();
			boss = new Fireman(mapa, *coord_boss, arma_f, FIREMAN);
			break;
		default:
			return;
	}
	creados.push_back(boss);
	//observador de boss:
	Observador_boss *obs = new Observador_boss(juego, boss);
	boss->agregar_observador(obs);
	mapa->agregar_personaje(boss);
}

