#include "escalera.h"
#include "personaje.h"
#include "bala.h"
#include "puas.h"
#include "bloque.h"
#define TIPO_ESCALERA 2

enum dir_estrategias{ARRIBA, ABAJO, DERECHA, IZQUIERDA};

Escalera::Escalera(Coordenada c) : Elemento(c, TIPO_ESCALERA) {
	StrategyMoverSinGravedad estrategia_arriba;
	estrategia_arriba.set_direccion_arriba();
	StrategyMoverSinGravedad estrategia_abajo;
	estrategia_abajo.set_direccion_abajo();
	StrategyMoverSinGravedad estrategia_derecha;
	estrategia_derecha.set_direccion_derecha();
	StrategyMoverSinGravedad estrategia_izquierda;
	estrategia_izquierda.set_direccion_izquierda();
	
	estrategias.push_back(estrategia_arriba);
	estrategias.push_back(estrategia_abajo);
	estrategias.push_back(estrategia_derecha);
	estrategias.push_back(estrategia_izquierda);
}

bool Escalera::puede_ocupar(Personaje* pj){
	return true;
}

bool Escalera::puede_ocupar(Elemento* pj){
	return pj->puede_ocupar(this);
}

bool Escalera::puede_ocupar(Bala* bala){
	return true;
}

bool Escalera::puede_ocupar(Escalera* esc){
	return false;
}

bool Escalera::puede_ocupar(Bloque* bloque){
	return false;
}

bool Escalera::puede_ocupar(Premio* premio){
	return true;
}

bool Escalera::puede_ocupar(Ubicable* ubic){
	return ubic->puede_ocupar(this);
}

bool Escalera::puede_ocupar(Puas* puas){
	return false;
}

void Escalera::interactuar(Personaje* pj){
	size_t x = pj->get_coordenada().obtener_abscisa();
	size_t y = pj->get_coordenada().obtener_ordenada();
	
	size_t x_max = (coord.obtener_abscisa() + (ancho / 2));
	size_t x_min = (coord.obtener_abscisa() - (ancho / 2));
	//Si la componente x de la coordenada central del
	//personaje no esta alineada 
	if ( (x < x_min) || (x > x_max) ){
		return;
	}
	//Primero me fijo si el personaje esta apoyado sobre
	//la escalera, en ese caso, le doy estrategias
	//para que se mantenga en su lugar o baje pero 
	//no le permito subir mas:
	size_t piso_personaje = y + (pj->get_alto() / 2);
	size_t tope_escalera = coord.arriba(alto/2).obtener_ordenada();
	if (piso_personaje == tope_escalera){
		//Estrategias para salir de la escalera:
		pj->agregar_movimiento(estrategias[DERECHA].get_direccion(),
								&estrategias[DERECHA]);
		pj->agregar_movimiento(estrategias[IZQUIERDA].get_direccion(),
								&estrategias[IZQUIERDA]);
		pj->agregar_movimiento(estrategias[ABAJO].get_direccion(),
								&estrategias[ABAJO]);
	}else{
		//Me fijo que el personaje no este en el borde inferior
		//de la escalera(es decir, que el tope del personaje no
		//coincide con el borde inferior externo de la escalera. 
		//En ese caso no quiero que el personaje pueda subir. 
		size_t tope_personaje = y + (pj->get_alto() / 2);
		size_t piso_escalera = coord.abajo(alto/2).obtener_ordenada();
		if (tope_personaje != piso_escalera){
			pj->agregar_movimiento(estrategias[ARRIBA].get_direccion(),
									&estrategias[ARRIBA]);
			pj->agregar_movimiento(estrategias[ABAJO].get_direccion(),
									&estrategias[ABAJO]);
		}
	}
}

Escalera::~Escalera() {}
