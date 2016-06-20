#include "escalera.h"
#include "personaje_pc.h"
#include "bala.h"
#include "puas.h"
#include "bloque.h"
#define TIPO_ESCALERA 12
#define ANCHO 30
#define ALTO 30

enum dir_estrategias{ARRIBA, ABAJO, DERECHA, IZQUIERDA};

Escalera::Escalera(Coordenada c) : Elemento(c, TIPO_ESCALERA) {
	ancho = ANCHO;
	alto = ALTO;
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

void Escalera::interactuar(Personaje *pj){
	pj->interactuar(this);
}

void Escalera::interactuar(Personaje_pc* pj){
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
	StrategyMoverPersonajePc *estrategia_arriba = new StrategyMoverPersonajePc();
	estrategia_arriba->set_direccion_arriba();
	StrategyMoverPersonajePc *estrategia_abajo = new StrategyMoverPersonajePc();
	estrategia_abajo->set_direccion_abajo();
	StrategyMoverPersonajePc *estrategia_derecha = new StrategyMoverPersonajePc();
	estrategia_derecha->set_direccion_derecha();
	StrategyMoverPersonajePc *estrategia_izquierda = new StrategyMoverPersonajePc();
	estrategia_izquierda->set_direccion_izquierda();


	size_t piso_personaje = y + (pj->get_alto() / 2);
	size_t tope_escalera = coord.arriba(alto/2).obtener_ordenada();
	if (piso_personaje == tope_escalera){

			//Estrategias para salir de la escalera:
			pj->agregar_movimiento(estrategia_abajo);
			pj->agregar_movimiento(estrategia_derecha);
			pj->agregar_movimiento(estrategia_izquierda);
	}else{
		//Me fijo que el personaje no este en el borde inferior
		//de la escalera(es decir, que el tope del personaje no
		//coincide con el borde inferior externo de la escalera.
		//En ese caso no quiero que el personaje pueda subir.
		size_t tope_personaje = y - (pj->get_alto() / 2);
		size_t piso_escalera = coord.abajo(alto/2).obtener_ordenada();
		if (tope_personaje != piso_escalera){
			pj->agregar_movimiento(estrategia_arriba);
			pj->agregar_movimiento(estrategia_abajo);
		}
	}
}

bool Escalera::colisiona(Ubicable* otro_ubic, Coordenada nueva){
	int alto1 = this->get_alto();
	int ancho1 = this->get_ancho();
	int alto2 = otro_ubic->get_alto();
	int ancho2 = otro_ubic->get_ancho();

	int y1 = this->get_coordenada().arriba(alto1/2).obtener_ordenada();
	int x1 = this->get_coordenada().izquierda(ancho1/2).obtener_abscisa();
	int y2 = nueva.arriba(alto2/2).obtener_ordenada();
	int x2 = nueva.izquierda(ancho2/2).obtener_abscisa();

	int x_aux = std::min(x1+ancho1, x2+ancho2) - std::max(x1, x2);
	int y_aux = std::min(y1+alto1, y2+alto2) - std::max(y1,y2);
	size_t x_colision = std::max(0, x_aux);
	size_t y_colision = std::max(0, y_aux);

	size_t piso_personaje = nueva.abajo(alto2/2).obtener_ordenada();
	size_t tope_escalera = coord.arriba(alto1/2).obtener_ordenada();

	return (((x_colision*y_colision) != 0) || ((x_colision != 0) &&
	(tope_escalera == piso_personaje) && otro_ubic->puede_ocupar(this)));
}

bool Escalera::es_piso(){
	return true;
}

bool Escalera::recibe_danio(Bala* ataque){
	return false;
}

Escalera::~Escalera() {}
