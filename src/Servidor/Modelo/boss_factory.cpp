#include "boss_factory.h"
#include <sstream>
#include <iostream>
#include "observador_ubicable.h"
#include "observador_personaje.h"

#define NO_BOSS 0

enum eleccion_boss{BOMBMAN = 20, MAGNETMAN, FIREMAN, RINGMAN};

Boss_factory::Boss_factory(Cargador_mapa * cargador, Juego *juego):
Ubicable_factory(cargador, juego),
fact_obs(juego){}

void Boss_factory::crear(Mapa* mapa){
}

