#include "strategy_mover.h"
#include "celda.h"
#include "celda_aire.h"
#include "personaje.h"
#include <vector>

StrategyMover::StrategyMover(Mapa &mapa):
mapa(mapa){}

std::string& StrategyMover::get_nombre(){
	return nombre_senial;
}

void StrategyMover::mover(Personaje *pj){
	std::vector<Coordenada*> coordenadas_pj = pj->getCoordenadas();
	bool puedo_mover = true;
	Coordenada *coord;
	size_t x, y;
	Celda* celda;
	for(size_t i = 0; i < coordenadas_pj.size(); i++){
		coord = coordenadas_pj[i];
		x = coord->obtener_ordenada();
		y = coord->obtener_abscisa();
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
			nueva_coord = nueva_coordenada(*coordenadas_pj[i]);
			nuevas_coordenadas_pj.push_back(nueva_coord);
			celda_aire = (Celda_aire*)mapa.obtener_celda(*nueva_coord);
			celda_aire->agregar_personaje(pj);
		}
		pj->ubicar(nuevas_coordenadas_pj);
	}
}

StrategyMover::~StrategyMover(){}
