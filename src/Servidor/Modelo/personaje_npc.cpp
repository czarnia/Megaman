#include "personaje_npc.h"

void Personaje_npc::perder_vida(int porcentaje){
	vida.perder(porcentaje);
}

void Personaje_npc::ganar_vida(int porcentaje){
	vida.ganar(porcentaje);
}

int Personaje_npc::get_porcentaje_vida(){
	return vida.get_porcentaje();
}

bool Personaje_npc::esta_vivo(){
	return !vida.esta_vacia();
}

void Personaje_npc::activar(){
	activo = true;
}

void Personaje_npc::desactivar(){
	activo = false;
}

bool Personaje_npc::recibe_danio(Bala* ataque){
	return ataque->dania(this);
}
