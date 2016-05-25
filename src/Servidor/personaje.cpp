#include "personaje.h"
#include "strategy_mover_izquierda.h"
#include "strategy_mover_derecha.h"
#include "strategy_mover_con_gravedad.h"
#include <iostream>

#define PERDER_VIDA -1
#define VELOCIDAD 1
typedef std::pair<std::string, StrategyMover*> nueva_estrategia;

Personaje::Personaje(Mapa &mapa, std::string id):
id(id){
	//TODO:Pasar las estrategias por parametro desde una Factory:
	StrategyMoverConGravedad *mover_izq = new StrategyMoverConGravedad(mapa, new StrategyMoverIzquierda(mapa));
	StrategyMoverConGravedad *mover_der = new StrategyMoverConGravedad(mapa, new StrategyMoverDerecha(mapa));
	estrategias.insert(nueva_estrategia(mover_izq->get_nombre(), mover_izq));
	estrategias.insert(nueva_estrategia(mover_der->get_nombre(), mover_der));
	//estrategias.insert()
	//agregar estrategias nativas de cada personaje en cada constructor...
	
	velocidad_y = 0; 
	//TODO: levantar este dato de xml/json!!!
	velocidad_x = VELOCIDAD; 
}

int Personaje::get_velocidad(){
	return this->velocidad;
}

void Personaje::update(size_t tiempo){
	StrategyMover *accion;
	Lock l(this->m);
	while (!acciones.empty()){
		accion = acciones.front();
		acciones.pop();
		accion->ejecutar(this);
	}
}

void Personaje::agregar_evento(Evento_mover *movimiento){
	std::string estrategia = movimiento->get_direccion();
	if (estrategias_adquiridas.find(estrategia) != estrategias_adquiridas.end()){
		acciones->push(estrategias_adquiridas[estrategia]);
	}else{
		if (estrategias.find(estrategia) != estrategias.end()){
			acciones->push(estrategias[estrategia]);
		}
	}
}

std::vector<Coordenada*>& Personaje::getCoordenadas(){
	return coordenadas_ocupadas;
}

bool Personaje::ubicar(std::vector<Coordenada*> &nuevas_coordenadas){
	coordenadas_ocupadas = nuevas_coordenadas;
}

/*bool Personaje::tiene_estrategia(std::string nombre_estrategia){
	bool tiene_estrategia = (estrategias_adquiridas.find(nombre_estrategia) != estrategias_adquiridas.end());
	tiene_estrategia = tiene_estrategia || (estrategias.find(nombre_estrategia) != estrategias.end());
	return tiene_estrategia;
}*/

void Personaje::agregar_estrategia(StrategyMover &estrategia){
	this->estrategias_adquiridas.insert( nueva_estrategia(estrategia.get_nombre(), &estrategia) );
}

void Personaje::remover_estrategias(){
	this->estrategias_adquiridas.clear();
}

std::string& Personaje::devolver_id(){
	return id;
}

bool Personaje::esta_vivo(){
	return vidas.empty();
}

void Personaje::perder_vida(int porcentaje){
	if (porcentaje == PERDER_VIDA){
		vidas.erase(vidas.begin());
	}else{
		vidas[0]->perder(porcentaje);
	}
}
