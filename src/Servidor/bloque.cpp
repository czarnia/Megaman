#include "bloque.h"

Bloque::Bloque(Coordenada &coordenada){
	coordenadas.push_back(&(*coordenada));
}

void Bloque::agregar_coordenada(Coordenada &coordenada){
	coordenadas.push_back(&(*coordenada));
}

bool Bool::ubicar(Mapa &mapa){
	mapa.ocupar(mapa, coordenadas);
}

bool Bloque::puede_compartir_celda(){
	return false;
}

bool Bloque::es_ubicable_con(Ubicable &ubicable){
	return false;
}
		
Bloque::~Bloque() {}
