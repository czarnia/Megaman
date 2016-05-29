#include "mapa.h"
#include "coordenada.h"
#include "elemento.h"
#include "puas.h"
#include "escalera.h"
#include "megaman.h"
#include "bala.h"
#include <vector>
#include <sstream>
#include <queue>

#define TAM_BLOQUE 1

typedef std::vector<Coordenada>::iterator ItBloques;
typedef std::pair<std::string, Megaman*> IdPersonaje;

//-------------->Auxiliares<-----------//
std::vector<Coordenada> coord_tierras(){
	//IMPORTANTE: las coordenadas de los bloques
	//de tierra son las coordenadas internas
	//ya que los bordes de los bloque
	//pueden ser ocupados.

	std::vector<Coordenada> tierras;

	tierras.push_back(Coordenada(1,11));
	tierras.push_back(Coordenada(3,11));
	tierras.push_back(Coordenada(5,11));
	tierras.push_back(Coordenada(7,11));
	tierras.push_back(Coordenada(9,11));
	tierras.push_back(Coordenada(11,11));
	tierras.push_back(Coordenada(1,9));
	tierras.push_back(Coordenada(3,9));
	tierras.push_back(Coordenada(5,9));
	return tierras;
}

std::vector<Coordenada*> coord_personajes(){
	std::vector<Coordenada*> personajes;
	personajes.push_back(new Coordenada(3,6));
	return personajes;
}

void Mapa::cargar_personajes(std::vector<Coordenada*> &coord){
	for (size_t i = 0; i < coord.size(); i++){
		std::stringstream id_personaje;
		id_personaje << "megaman" << i;
		Megaman *megaman = new Megaman(this, *coord[i], id_personaje.str());
		personajes.insert(IdPersonaje(id_personaje.str(), megaman));
	}
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

bool Mapa::puede_ubicarse_en(Coordenada coord, size_t alto, size_t ancho){
	bool puedo_ocupar;
	//Personajes *
	//Verifico que el mapa tiene las coordenadas:

	Coordenada superior_derecha = coord.arriba(alto/2).derecha(ancho/2);
	Coordenada superior_izquierda = coord.arriba(alto/2).izquierda(ancho/2);
	Coordenada inferior_derecha = coord.abajo(alto/2).derecha(ancho/2);
	Coordenada inferior_izquierda = coord.abajo(alto/2).izquierda(ancho/2);

	puedo_ocupar = (this->tiene_coordenada(superior_derecha));
	puedo_ocupar = puedo_ocupar && (this->tiene_coordenada(superior_izquierda));
	puedo_ocupar = puedo_ocupar && (this->tiene_coordenada(inferior_derecha));
	puedo_ocupar = puedo_ocupar && (this->tiene_coordenada(inferior_izquierda));

	if (!puedo_ocupar){
		return false;
	}

	for (ItBloques it = bloques.begin(); it != bloques.end(); ++it){
		Coordenada coord_bloque_central = (*it);
		int ymax = coord_bloque_central.obtener_ordenada()+TAM_BLOQUE;
		int ymin = coord_bloque_central.obtener_ordenada()-TAM_BLOQUE;
		int xmax = coord_bloque_central.obtener_abscisa()+TAM_BLOQUE;
		int xmin = coord_bloque_central.obtener_abscisa()-TAM_BLOQUE;

		if ((superior_derecha.esta_en_rango(xmin, xmax, ymin, ymax)) ||
		(superior_izquierda.esta_en_rango(xmin, xmax, ymin, ymax)) ||
		(inferior_derecha.esta_en_rango(xmin, xmax, ymin, ymax)) ||
		(superior_izquierda.esta_en_rango(xmin, xmax, ymin, ymax)) ||
		(coord.esta_en_rango(xmin, xmax, ymin, ymax))){
			return false;
		}
	}
	return false;
}

/*void Mapa::puede_moverse_a(Coordenada *origen, Coordenada *destino, size_t alto, size_t ancho){
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
}*/

Personaje* Mapa::obtener_pj(std::string id_pj){
	return personajes[id_pj];
}

std::vector<Actualizable*> Mapa::obtener_actualizables(){
	std::vector<Actualizable*> v;
  std::map<std::string,Personaje*>::iterator i;
  for (i = personajes.begin(); i != personajes.end(); i++){
    v.push_back(i->second);
  }
	for (size_t j = 0; j < balas.size(); j++){
		v.push_back(balas[j]);
	}
  return v;
}

bool Mapa::esta_en_aire(Coordenada coord, size_t alto){
	hay_tierra(coord.abajo(alto/2+1)); //asumo los bloques son de tamaño 2
}

bool Mapa::hay_tierra(Coordenada coord){
	for (size_t i = 0; i < bloques.size(); i++){
		if (bloques[i] == coord){
			return true;
		}
	}
	return false;
}

bool Mapa::tiene_coordenada(Coordenada coordenada){
	float x = coordenada.obtener_abscisa();
	float y = coordenada.obtener_ordenada();
	bool tiene_coordenada = (0 <= x) && (x <= tam) && (0 <= y) && (y <= tam);
	return tiene_coordenada;
}

void Mapa::cargar(){
	bloques = coord_tierras();
	std::vector<Coordenada*> coordenadas_personajes = coord_personajes();
	cargar_personajes(coordenadas_personajes);
}
