#include "bala_especial.h"
#include "personaje_pc.h"
#include "personaje_npc.h"

bool Bala_especial::dania(Personaje_pc* pj){
	return !equipo_pc;
}

bool Bala_especial::dania(Personaje_npc* pj){
	return equipo_pc;
}

void Bala_especial::cambiar_enemigo(){
  equipo_pc = false;
}
