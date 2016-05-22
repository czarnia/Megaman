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

void StrategyMover::mover(Personaje *pj){
	std::vector<Coordenada*> coordenadas_pj = pj->getCoordenadas();
	bool puedo_mover = true;
	Coordenada *coord;
	size_t x, y;
	Celda* celda;
	for(size_t i = 0; i < coordenadas_pj.size(); i++){
		coord =  nueva_coordenada(*coordenadas_pj[i]);
		x = coord->obtener_abscisa();
		y = coord->obtener_ordenada();
		std::cout << "Verifico coordenadas:"<< x << ","<< y <<"\n";
		celda = mapa.obtener_celda(*coord);
		puedo_mover = puedo_mover && celda->puedo_ubicar();
	}
	if (puedo_mover){
		std::vector<Coordenada*> nuevas_coordenadas_pj;
		Celda_aire* celda_aire;
		Coordenada *nueva_coord;
		for(size_t i = 0; i < coordenadas_pj.size(); i++){
			celda_aire = (Celda_aire*)mapa.obtener_celda(*coord);
			celda_aire->quitar_personaje(pj);
			std::cout << "Muevo coordenadas!\n";
			nueva_coord = nueva_coordenada(*coordenadas_pj[i]);
			std::cout << "Quiero moverme a:"<< nueva_coord->obtener_abscisa();
			std::cout << ","<< nueva_coord->obtener_ordenada() <<"\n";
			nuevas_coordenadas_pj.push_back(nueva_coord);
			celda_aire = (Celda_aire*)mapa.obtener_celda(*nueva_coord);
			std::cout << "Agrego personaje a la celda!\n";
			celda_aire->agregar_personaje(mapa, pj);
		}
		pj->ubicar(nuevas_coordenadas_pj);
	}
}

StrategyMover::~StrategyMover(){}
