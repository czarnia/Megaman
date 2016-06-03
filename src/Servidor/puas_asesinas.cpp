#include "puas_asesinas.h"
#include "personaje.h"

bool Puas_asesinas::puede_ocupar(Personaje* pj){
	return true;
}

void Puas_asesinas::interactuar(Personaje *pj){
  while (pj->esta_vivo()){
    pj->perder_vida();
  }
}

Puas_asesinas::~Puas_asesinas() {}
