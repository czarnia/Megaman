#include "mapa.h"
#include "coordenada.h"
#include "celda_aire.h"
#include "celda_tierra.h"
#include "elemento.h"
#include "puas.h"
#include "escalera.h"

//-------------->Auxiliares<-----------//
std::vector<Coordenada> coord_tierras(){
	std::vector<Coordenada> tierras;

	for (size_t i = 0; i < 5; i++){
		tierras.push_back(Coordenada(i,9));
		tierras.push_back(Coordenada(i,1));
	}
	tierras.push_back(Coordenada(0,8));
	tierras.push_back(Coordenada(1,8));
	tierras.push_back(Coordenada(0,7));
	tierras.push_back(Coordenada(4,8));

	for (i = 5, i < 10; i++){
		tierras.push_back(Coordenada(i,7));
		tierras.push_back(Coordenada(i,4));
	}
	for(i = 1; i < 4; i++){
		tierras.push_back(Coordenada(i,4));
	}

	return tierras;
}

std::vector<Coordenada> coord_puas(){
	std::vector<Coordenada> puas;

	puas.push_back(Coordenada(2,0));
	puas.push_back(Coordenada(1,3));
	puas.push_back(Coordenada(6,3));

	return puas;
}

std::vector<Coordenada> coord_escaleras(){
	std::vector<Coordenada> escaleras;

	for (i = 0; i < 3; i++){
		escaleras.push_back(Coordenada(0,i+4));
		escaleras.push_back(Coordenada(5,i+1));
	}

	return escaleras;
}

//------------------------------------//



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

Celda* Mapa::obtener_celda(Coordenada &coordenada){
	size_t x = coord.obtener_ordenada();
	size_t y = coord.obtener_abscisa()
	return celdas[x][y];
}

void Mapa::ocupar_tierra(std::vector<Coordenada> coordenadas){
	for (size_t i = 0; i < coordenadas.size(); i++){
		Coordenada coord = coordenadas[i];
		size_t x = coord.obtener_ordenada();
		size_t y = coord.obtener_abscisa()
		celdas[x][y] = new Celda_tierra();
	}
}

void Mapa::rellenar_aire(){
	for (size_t i = 0; i < tam; i++){
		for (size_t j = 0; j < tam; j++){
			if (!celdas[i][j]){
				celdas[i][j] = new Celda_aire();
			}
		}
	}
}

void Mapa::cargar(){
	std::vector<Coordenada> tierras = coord_tierras();
	std::vector<Coordenada> puas = coord_puas();
	std::vector<Coordenada> escaleras = coord_escaleras();

	Puas pinches;
	Escalera esc;

	ocupar_tierra(tierras);
	ocupar_elemento(pinches, puas);
	ocupar_elemento(es, escaleras);
	rellenar_aire();
}
