#include "personaje.h"

#define PERDER_VIDA -1

Personaje::Personaje(Mapa &mapa){
	//estrategias.push_back() agregar estrategias nativas de cada personaje...
}

bool Personaje::ubicar(std::vector<Coordenada*> &nuevas_coordenadas){
	coordenadas_ocupadas = nuevas_coordenadas;
}

virtual void agregar_estrategia(StrategyMover &estrategia){
	this->estrategias_adquiridas.push_back(estrategia);
}

bool Personaje::esta_vivo(){
	return vidas.empty();
}

void Personaje::perder_vida(int porcentaje = PERDER_VIDA){
	if (porcentaje == PERDER_VIDA){
		vidas.erase(0);
	}else{
		vidas[0].perder(porcentaje);
	}
}

