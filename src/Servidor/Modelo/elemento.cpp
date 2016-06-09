#include "elemento.h"
#include <algorithm>

Elemento::Elemento(Coordenada c, int tipo, int id): 
coord(c), tipo(tipo), id(id){}

int Elemento::get_tipo(){
	return tipo;
}

int Elemento::get_id(){
	return id;
}

int Elemento::get_ancho(){
	return ancho;
}

int Elemento::get_alto(){
	return alto;
}

Coordenada Elemento::get_coordenada(){
	return coord;
}

std::vector<Coordenada> Elemento::coordenadas(){
	return coordenadas(this->coord);
}

bool Elemento::puede_ocupar(Ubicable* ubic){
	return ubic->puede_ocupar(this);
}

std::vector<Coordenada> Elemento::coordenadas(Coordenada centro){
	std::vector<Coordenada> s_coord;
	Coordenada coord_aux(0,0);
	for (int i = 0; i <= alto/2; i++){
		for (int j = 0; j <= ancho/2; j++){
			coord_aux = centro.arriba(i).izquierda(j);
			if (std::find(s_coord.begin(), s_coord.end(), coord_aux) == s_coord.end()){
				s_coord.push_back(centro.arriba(i).izquierda(j));
			} 
			coord_aux = centro.arriba(i).derecha(j);
			if (std::find(s_coord.begin(), s_coord.end(), coord_aux) == s_coord.end()){
				s_coord.push_back(centro.arriba(i).derecha(j));
			}
			coord_aux = centro.abajo(i).izquierda(j);
			if (std::find(s_coord.begin(), s_coord.end(), coord_aux) == s_coord.end()){
				s_coord.push_back(centro.abajo(i).izquierda(j));
			}
			coord_aux = centro.abajo(i).derecha(j);
			if (std::find(s_coord.begin(), s_coord.end(), coord_aux) == s_coord.end()){
				s_coord.push_back(centro.abajo(i).derecha(j));
			}
			
		}
	}
	return s_coord;
}


void Elemento::notificar_observadores(){
	for (size_t i = 0; i < observadores.size(); i++){
		observadores[i]->update(this);
	}
}

void Elemento::agregar_observador(Observador_ubicable *observador){
	Observador *obs = (Observador*)observador;
	Observable::agregar_observador(obs);
}

void Elemento::quitar_observador(Observador_ubicable *observador){
	Observador *obs = (Observador*)observador;
	Observable::agregar_observador(obs);
}
