#include "bloque_factory.h"
#include "bloque.h"

Bloque_factory::Bloque_factory(Cargador_mapa *cargador, Juego *juego) :
Ubicable_factory(cargador, juego) {}

void Bloque_factory::crear(Mapa* mapa){
	std::vector<Coordenada*> coord_bloques = cargador->get_coordenadas_bloques();

	for (unsigned int i = 0; i < coord_bloques.size(); i++){
		Coordenada *coord = coord_bloques[i];
		//Creo nuevo bloque:
		Bloque* bloque = new Bloque(*coord);
		//Lo agrego al mapa:
		mapa->ubicar(bloque, *coord);
	}
}
