#include "personaje.h"
#include "strategy_mover_izquierda.h"
#include <iostream>

#define PERDER_VIDA -1
typedef std::pair<std::string, StrategyMover*> nueva_estrategia;

Personaje::Personaje(Mapa &mapa, std::string &id):
id(id){
	StrategyMoverIzquierda *mover_izq = new StrategyMoverIzquierda(mapa);
	estrategias.insert(nueva_estrategia(mover_izq->get_nombre(), mover_izq));
	//estrategias.insert()
	//agregar estrategias nativas de cada personaje en cada constructor...
}

void Personaje::mover(std::string nombre_senial){
	std::cout << "Entre al mover!\n";
	StrategyMover *mover = estrategias[nombre_senial];
	std::cout << "Obtuve el strategy\n";
	mover->mover(this);
}

std::vector<Coordenada*>& Personaje::getCoordenadas(){
	std::cout << "Entre al getCoordenadas\n";
	return coordenadas_ocupadas;
}

bool Personaje::ubicar(std::vector<Coordenada*> &nuevas_coordenadas){
	coordenadas_ocupadas = nuevas_coordenadas;
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
