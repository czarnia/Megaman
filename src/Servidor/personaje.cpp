#include "personaje.h"
#include "strategy_mover_izquierda.h"
#include "strategy_mover_con_gravedad.h"
#include <iostream>

#define PERDER_VIDA -1
#define VELOCIDAD 2
typedef std::pair<std::string, StrategyMover*> nueva_estrategia;

Personaje::Personaje(Mapa &mapa, std::string id):
id(id){
	//TODO:Pasar las estrategias por parametro desde una Factory:
	StrategyMoverConGravedad *mover_izq = new StrategyMoverConGravedad(mapa, new StrategyMoverIzquierda(mapa));
	estrategias.insert(nueva_estrategia(mover_izq->get_nombre(), mover_izq));
	//estrategias.insert()
	//agregar estrategias nativas de cada personaje en cada constructor...
	
	//TODO: levantar este dato de xml/json!!!
	velocidad = VELOCIDAD; 
}

int& Personaje::getVelocidad(){
	return this->velocidad;
}

void Personaje::mover(std::string nombre_senial){
	StrategyMover *mover = estrategias[nombre_senial];
	mover->mover(this);
}

std::vector<Coordenada*>& Personaje::getCoordenadas(){
	return coordenadas_ocupadas;
}

bool Personaje::ubicar(std::vector<Coordenada*> &nuevas_coordenadas){
	coordenadas_ocupadas = nuevas_coordenadas;
}

bool Personaje::tiene_estrategia(std::string nombre_estrategia){
	bool tiene_estrategia = (estrategias_adquiridas.find(nombre_estrategia) != estrategias_adquiridas.end());
	tiene_estrategia = tiene_estrategia || (estrategias.find(nombre_estrategia) != estrategias.end());
	return tiene_estrategia;
}

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
