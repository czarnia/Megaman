#include "puas_factory.h"
#include "puas.h"

Puas_factory::Puas_factory(Cargador_mapa *cargador, Juego* juego):
Ubicable_factory(cargador, juego) {}

void Puas_factory::crear(Mapa* mapa){
	std::vector<Coordenada*> coordenadas_puas = cargador->get_coordenadas_puas();
	for (size_t i = 0; i < coordenadas_puas.size(); i++){
		Coordenada *coord = coordenadas_puas[i];
		//Creo puas nuevas:
		Puas* puas = new Puas(*coord);
		//Agrego las puas creadas al mapa:
		mapa->ubicar(puas, *coord);
	}
}
