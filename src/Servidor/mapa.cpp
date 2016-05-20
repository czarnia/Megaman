#include "mapa.h"
#include "coordenada.h"

Mapa::Mapa(){
  //mapa.cargar();
}

bool Mapa::ocupar(Ubicable &nuevo_ubicable, std::vector<Coordenada*> &coordenadas){
	Celda posicion;
	size_t x, y;
	//Antes de ocupar un conjunto de celdas verifico que el
	//la operacion es válida:
	for (size_t pos = 0; pos < coordenadas.size(); pos++){
		x = coordenadas[pos].obtener_abscisa();
		y = coordenadas[pos].obtener_ordenada();
		posicion = celdas[x][y];
		if (!posicion.puede_ocupar(nuevo_ubicable)){
			return false;
		}
	}
	//Ocupo las celdas:
	for (size_t pos = 0; pos < coordenadas.size(); pos++){
		x = coordenadas[pos].obtener_abscisa();
		y = coordenadas[pos].obtener_ordenada();
		posicion = celdas[x][y];
		if (!posicion.ocupar(nuevo_ubicable)){
			return false; //desocupar celdas ocupadas...lanzar excepcion... (?)
		}
	}
	return true;
}

void Mapa::desocupar(std::vector<Coordenada*> &coordenadas){
	size_t x, y = 0;
	for (size_t pos = 0; pos < coordenadas.size(); pos++){
		x = coordenadas[pos].obtener_abscisa();
		y = coordenadas[pos].obtener_ordenada();
		Celda posicion = celdas[x][y];
		posicion.desocupar();
	}
}

/*Ubicable& Mapa::obtener_ubicable(Coordenada &coordenada){
	size_t x = coordenada.obtener_abscisa();
	size_t y = coordenada.obtener_ordenada();
	Celda posicion = celdas[x][y];
	return posicion.obtener_ubicable();
}*/

/*bool Mapa::coordenada_es_ocupable(Coordenada &coordenada){
	size_t x = coordenadas[pos].obtener_abscisa();
	size_t y = coordenadas[pos].obtener_ordenada();
	return celdas[x][y].esta_ocupada();
}*/
