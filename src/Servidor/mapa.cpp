#include "mapa.h"
#include "coordenada.h"
#include "elemento.h"
#include "puas.h"
#include "escalera.h"
#include "megaman.h"
#include <vector>
#include <sstream>
#include <queue>

typedef std::vector<Coordenada>::iterator ItBloques;

//-------------->Auxiliares<-----------//
std::vector<Coordenada> coord_tierras(){
	//IMPORTANTE: las coordenadas de los bloques
	//de tierra son las coordenadas internas
	//ya que los bordes de los bloque
	//pueden ser ocupados.
	
	std::vector<Coordenada> tierras;
	
	tierras.push_back(Coordenada(1,1));
	tierras.push_back(Coordenada(2,1));	
	tierras.push_back(Coordenada(3,1));
	tierras.push_back(Coordenada(1,2));
	tierras.push_back(Coordenada(4,1));
	tierras.push_back(Coordenada(8,1));
	tierras.push_back(Coordenada(8,2));
	tierras.push_back(Coordenada(2,8));
	tierras.push_back(Coordenada(3,8));
	tierras.push_back(Coordenada(4,8));
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

bool Mapa::puede_ubicarse_en(Coordenada *coord, size_t alto, size_t ancho){
	bool puedo_ocupar = true;
	//Personajes *
	//Verifico que el mapa tiene las coordenadas:
	puedo_ocupar = (this->tiene_coordenada(coord->derecha(ancho/2).arriba(alto/2)));
	puedo_ocupar = puedo_ocupar && (this->tiene_coordenada(coord->derecha(ancho/2).abajo(alto/2)));
	puedo_ocupar = puedo_ocupar && (this->tiene_coordenada(coord->izquierda(ancho/2).abajo(alto/2)));
	puedo_ocupar = puedo_ocupar && (this->tiene_coordenada(coord->izquierda(ancho/2).arriba(alto/2)));
	
	bool puedo_ocupar_ancho, puedo_ocupar_alto = true;
	
	if (puedo_ocupar){
		for (ItBloques it = bloques.begin(); it != bloques.end(); ++it){
			//puedo_ocupar_ancho = ((*it).obtener_abscisa() <= coord->izquierda(ancho/2).obtener_abscisa());
			//puedo_ocupar_ancho = puedo_ocupar_ancho || ((*it).obtener_abscisa() >= coord->izquierda(ancho/2).obtener_abscisa());
			
			//puedo_ocupar_alto = ((*it).obtener_ordenada() >= (coord->arriba(alto/2).obtener_ordenada()));
			//puedo_ocupar_alto = puedo_ocupar_alto || ((*it).obtener_ordenada() <= (coord->abajo(alto/2).obtener_ordenada()));
			
			puedo_ocupar_ancho = ((*it).obtener_abscisa() < coord->izquierda(ancho/2).obtener_abscisa());
			puedo_ocupar_ancho = puedo_ocupar_ancho || ((*it).obtener_abscisa() > coord->izquierda(ancho/2).obtener_abscisa());
			
			puedo_ocupar_alto = ((*it).obtener_ordenada() > (coord->arriba(alto/2).obtener_ordenada()));
			puedo_ocupar_alto = puedo_ocupar_alto || ((*it).obtener_ordenada() < (coord->abajo(alto/2).obtener_ordenada()));
			puedo_ocupar = puedo_ocupar && puedo_ocupar_ancho && puedo_ocupar_alto;
		}
	}
	return puedo_ocupar;
}

void Mapa::puede_moverse_a(Coordenada *origen, Coordenada *destino, size_t alto, size_t ancho){
	std::queue<Coordenada> camino_minimo;
	Coordenada::camino_minimo(origen, destino, &camino_minimo);
	//Empiezo a recorrer desde el origen:
	*destino = *origen; //definir = para coordenadas.
	
	bool destino_valido = true;
	
	while (destino_valido && (!camino_minimo.empty())){
		Coordenada coord = camino_minimo.front(); 
		camino_minimo.pop();
		
		destino_valido = puede_ubicarse_en(&coord, alto, ancho);
		
		if (destino_valido){
			*destino = coord; //muevo
		}		
	}
}

bool Mapa::tiene_coordenada(Coordenada coordenada){
	float x = coordenada.obtener_abscisa();
	float y = coordenada.obtener_ordenada();
	bool tiene_coordenada = (0 <= x) && (x <= tam) && (0 <= y) && (y <= tam);
	return tiene_coordenada;
}

void Mapa::cargar(){
	bloques = coord_tierras();
}

