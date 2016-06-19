#include "observador_boss.h"

Observador_boss::Observador_boss(Juego* juego, Personaje_npc *personaje):
Observador_personaje_npc(juego, personaje){}

void Observador_boss::update(Observable *obs){
	Personaje_npc *boss = (Personaje_npc*)obs;
	if (!boss->esta_vivo()){
		juego->murio_boss();
	}
	Observador_personaje::update(obs);
}
