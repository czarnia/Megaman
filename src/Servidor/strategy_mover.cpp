#include "strategy_mover.h"
#include "celda.h"
#include "celda_aire.h"
#include "personaje.h"
#include <vector>
#include <iostream>
#include <sstream>
#include <string>

StrategyMover::StrategyMover(Mapa &mapa):
mapa(mapa){}

std::string StrategyMover::get_nombre(){
	return nombre_senial;
}

bool StrategyMover::ejecutar(Personaje *personaje){
	//FALTA CONSIDERAR VELOCIDAD PARA MOVIMIENTOS SIN GRAVEDAD:
	return mover(personaje);
}

bool StrategyMover::mover(Personaje *pj){
	std::vector<Coordenada*> coordenadas_pj = pj->getCoordenadas();
	bool puedo_mover = true;
	Coordenada *coord;
	size_t x, y;
	Celda* celda;
	for(size_t i = 0; i < coordenadas_pj.size(); i++){
		//Verifico que las nuevas coordenadas estan dentro del mapa
		//y que las celdas destino puedan alojar al personaje.
		coord =  nueva_coordenada(*coordenadas_pj[i]);
		puedo_mover = puedo_mover && mapa.tiene_coordenada(*coord);
		if (puedo_mover){
			celda = mapa.obtener_celda(*coord);
			puedo_mover = puedo_mover && celda->puedo_ubicar();
		}
	}
	if (puedo_mover){
		//Si el movimiento es válido, se actualizan las
		//coordenadas del personaje.
		std::vector<Coordenada*> nuevas_coordenadas_pj;
		Celda_aire* celda_aire;
		Coordenada *nueva_coord;
		for(size_t i = 0; i < coordenadas_pj.size(); i++){
			//TODO: mover esto a la clase mapa:
			celda_aire = (Celda_aire*)mapa.obtener_celda(*coord);
			celda_aire->quitar_personaje(pj);
			nueva_coord = nueva_coordenada(*coordenadas_pj[i]);
			nuevas_coordenadas_pj.push_back(nueva_coord);
			celda_aire = (Celda_aire*)mapa.obtener_celda(*nueva_coord);
			celda_aire->agregar_personaje(mapa, pj);
		}
		pj->ubicar(nuevas_coordenadas_pj);
	}
	return puedo_mover;
}

StrategyMover::~StrategyMover(){}
