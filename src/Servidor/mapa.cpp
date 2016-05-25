#include "mapa.h"
#include "coordenada.h"
#include "celda_aire.h"
#include "celda_tierra.h"
#include "elemento.h"
#include "puas.h"
#include "escalera.h"
#include "megaman.h"
#include <vector>
#include <sstream>

//-------------->Auxiliares<-----------//
std::vector<Coordenada> coord_tierras(){
	std::vector<Coordenada> tierras;
	size_t i;
	for (i = 0; i < 5; i++){
		tierras.push_back(Coordenada(i,9));
		tierras.push_back(Coordenada(i,1));
	}
	tierras.push_back(Coordenada(0,8));
	tierras.push_back(Coordenada(1,8));
	tierras.push_back(Coordenada(0,7));
	tierras.push_back(Coordenada(4,8));

	for (i = 5; i < 10; i++){
		tierras.push_back(Coordenada(i,7));
		tierras.push_back(Coordenada(i,4));
	}
	for(i = 1; i < 4; i++){
		tierras.push_back(Coordenada(i,4));
	}

	return tierras;
}

std::vector<Coordenada*> coord_personajes(){
	std::vector<Coordenada*> personajes;
	personajes.push_back(new Coordenada(9,6));
	personajes.push_back(new Coordenada(3,3));
	return personajes;
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
	size_t i;
	for (i = 0; i < 3; i++){
		escaleras.push_back(Coordenada(0,i+4));
		escaleras.push_back(Coordenada(5,i+1));
	}

	return escaleras;
}

//------------------------------------//



Mapa::Mapa(size_t tamanio){
	tam = tamanio;
	this->cargar();
}

void Mapa::ocupar_elemento(Elemento& elem, std::vector<Coordenada> &coordenadas){
	for (size_t i = 0; i < coordenadas.size(); i++){
		Coordenada coord = coordenadas[i];
		size_t x = coord.obtener_ordenada();
		size_t y = coord.obtener_abscisa();
		celdas[x][y] = new Celda_aire(x, y, &elem);
	}
}

Celda* Mapa::obtener_celda(Coordenada &coord){
	size_t x = coord.obtener_ordenada();
	size_t y = coord.obtener_abscisa();
	return celdas[x][y];
}

void Mapa::ocupar_tierra(std::vector<Coordenada> &coordenadas){
	for (size_t i = 0; i < coordenadas.size(); i++){
		Coordenada coord = coordenadas[i];
		size_t x = coord.obtener_ordenada();
		size_t y = coord.obtener_abscisa();
		celdas[x][y] = new Celda_tierra(x,y);
	}
}

void Mapa::ocupar_personajes(std::vector<Coordenada*> &coordenadas){
	Megaman *megaman;
	for (size_t i = 0; i < coordenadas.size(); i++){
		std::stringstream nombre;
		nombre << "megaman" << i;
		megaman = new Megaman(*this, nombre.str());
		Coordenada *coord = coordenadas[i];
		size_t x = coord->obtener_ordenada();
		size_t y = coord->obtener_abscisa();
		Celda_aire *aire = (Celda_aire*)celdas[x][y];
		aire->agregar_personaje(*this, megaman);
		std::vector<Coordenada*> coords_megaman;
		coords_megaman.push_back(coord);
		megaman->ubicar(coords_megaman);
	}
}

void Mapa::rellenar_aire(){
	for (size_t i = 0; i < tam; i++){
		for (size_t j = 0; j < tam; j++){
			if (!celdas[i][j]){
				celdas[i][j] = new Celda_aire(i, j);
			}
		}
	}
}

bool Mapa::tiene_coordenada(Coordenada &coordenada){
	size_t x = coordenada.obtener_abscisa();
	size_t y = coordenada.obtener_ordenada();
	bool tiene_coordenada = (celdas.find(x) !=  celdas.end());
	if (tiene_coordenada){
		tiene_coordenada = (celdas[x].find(y) !=  celdas[x].end());
	}
	return tiene_coordenada;
}

void Mapa::cargar(){
	std::vector<Coordenada> tierras = coord_tierras();
	std::vector<Coordenada> puas = coord_puas();
	std::vector<Coordenada> escaleras = coord_escaleras();
	std::vector<Coordenada*> personajes = coord_personajes();

	Puas pinches;
	Escalera esc;

	ocupar_tierra(tierras);
	ocupar_elemento(pinches, puas);
	ocupar_elemento(esc, escaleras);
	rellenar_aire();
	ocupar_personajes(personajes);
}
