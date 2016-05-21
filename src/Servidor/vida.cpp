#include "vida.h"

#define VIDA_INICIAL 100

Vida::Vida(){
	porcentaje = VIDA_INICIAL;
}

int Vida::get_porcentaje(){
	return porcentaje;
}

void Vida::ganar(int porcentaje_aumento = VIDA_INICIAL){
	if ((porcentaje + porcentaje_aumento) > VIDA_INICIAL){
		porcentaje_aumento = VIDA_INICIAL - porcentaje;
	}
	porcentaje += porcentaje_aumento;	
}

bool Vida::esta_vacia(){
	return (porcentaje == 0);
}

void Vida::perder(int porcentaje_reduccion = VIDA_INICIAL){
	if ((porcentaje - porcentaje_reduccion) < 0){
		porcentaje_reduccion = porcentaje;
	}
	porcentaje = porcentaje - porcentaje_reduccion;
}
