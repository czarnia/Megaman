#include "escalera_factory.h"
#include "escalera.h"

Escalera_factory::Escalera_factory(Cargador_mapa *cargador, Juego *juego):
Ubicable_factory(cargador, juego) {}

void Escalera_factory::crear(Mapa* mapa){
	std::vector<Coordenada*> coord_escaleras = cargador->get_coordenadas_escaleras();
	
	for (unsigned int i = 0; i < coord_escaleras.size(); i++){
		Coordenada *coord = coord_escaleras[i];
		//Creo nueva escalera:
		Escalera *escalera = new Escalera(*coord);
		//La agrego al mapa:
		mapa->ubicar(escalera, *coord);
	}	
}
