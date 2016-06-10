#include "capsula_de_energia.h"

#define TIPO_CAPSULA_GRANDE -1
#define PROBABILIDAD_APARICION 0.01

Capsula_de_energia::Capsula_de_energia(Coordenada coord):
Premio(coord, TIPO_CAPSULA_GRANDE){}

float Capsula_de_energia::get_probabilidad_aparicion(){
	return PROBABILIDAD_APARICION;
}

void Capsula_de_energia::interactuar(Personaje *pj){
	pj->ganar_energia(20);
}

Capsula_de_energia::~Capsula_de_energia(){}
