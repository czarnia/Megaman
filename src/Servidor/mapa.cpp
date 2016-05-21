#include "mapa.h"
#include "coordenada.h"
#include "celda_aire.h"
#include "celda_tierra.h"
#include "elemento.h"
#include "puas.h"
#include "escalera.h"

Mapa::Mapa(size_t tamanio){
	tam = tamanio;
  mapa.cargar();
}

void Mapa::ocupar_elemento(Elemento& elem, std::vector<Coordenada> coordenadas){
	for (size_t i = 0; i < coordenadas.size(); i++){
		Coordenada coord = coordenadas[i];
		size_t x = coord.obtener_ordenada();
		size_t y = coord.obtener_abscisa()
		celdas[x][y] = new Celda_aire(elem);
	}
}

void Mapa::ocupar_tierra(std::vector<Coordenada> coordenadas){
	for (size_t i = 0; i < coordenadas.size(); i++){
		Coordenada coord = coordenadas[i];
		size_t x = coord.obtener_ordenada();
		size_t y = coord.obtener_abscisa()
		celdas[x][y] = new Celda_aire();
	}
}

void Mapa::cargar(){
	std::vector<Coordenada> tierras;
	std::vector<Coordenada> puas;
	std::vector<Coordenada> escaleras;

	for (size_t i = 0; i < 5; i++){
		tierras.push_back(Coordenada(i,9));
		tierras.push_back(Coordenada(i,1));
	}
	tierras.push_back(Coordenada(3,8));
	for (i = 4, i < 10; i++){
		tierras.push_back(Coordenada(i,7));
		tierras.push_back(Coordenada(i,4));
	}
	tierras.push_back(Coordenada(1,4));
	tierras.push_back(Coordenada(2,4));

	puas.push_back(Coordenada(6,6));
	puas.push_back(Coordenada(9,6));
	puas.push_back(Coordenada(6,3));

	escaleras.push_back(Coordenada(8,6));
	escaleras.push_back(Coordenada(8,5));
	escaleras.push_back(Coordenada(4,3));
	escaleras.push_back(Coordenada(4,2));
}
