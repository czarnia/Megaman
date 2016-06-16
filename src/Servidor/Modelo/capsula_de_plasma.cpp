#include "capsula_de_plasma.h"

#define TIPO_CAPSULA_GRANDE -1
#define PROBABILIDAD_APARICION 0.01

Capsula_de_plasma::Capsula_de_plasma(Coordenada coord):
Premio(coord, TIPO_CAPSULA_GRANDE){}

float Capsula_de_plasma::get_probabilidad_aparicion(){
	return PROBABILIDAD_APARICION;
}

void Capsula_de_plasma::interactuar(Personaje *pj){
	//pj->ganar_plasma(20);
}

Capsula_de_plasma::~Capsula_de_plasma(){}
