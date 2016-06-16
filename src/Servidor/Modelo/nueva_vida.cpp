#include "nueva_vida.h"

#define TIPO_NUEVA_VIDA 13
#define PROBABILIDAD_APARICION 0.01

Nueva_vida::Nueva_vida(Coordenada coord):
Premio(coord, TIPO_NUEVA_VIDA){}

float Nueva_vida::get_probabilidad_aparicion(){
	return PROBABILIDAD_APARICION;
}

void Nueva_vida::interactuar(Personaje *pj){
	pj->ganar_vida();
}
