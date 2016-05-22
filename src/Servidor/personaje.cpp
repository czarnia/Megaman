#include "personaje.h"

#define PERDER_VIDA -1
typedef std::pair<std::string*, StrategyMover*> nueva_estrategia;

Personaje::Personaje(Mapa &mapa, std::string &id):
id(id){
	//estrategias.insert() agregar estrategias nativas de cada personaje...
}

std::vector<Coordenada*>& Personaje::getCoordenadas(){
	return coordenadas_ocupadas;
}

bool Personaje::ubicar(std::vector<Coordenada*> &nuevas_coordenadas){
	coordenadas_ocupadas = nuevas_coordenadas;
}

void Personaje::agregar_estrategia(StrategyMover &estrategia){
	this->estrategias_adquiridas.insert( nueva_estrategia(&estrategia.get_nombre(), &estrategia) );
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

