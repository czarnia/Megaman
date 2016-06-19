#include "puerta_boss.h"
#include <vector>
#include <algorithm> 

#define TIPO_PUERTA_BOSS 18
#define ANCHO 1
#define ALTO 4

typedef std::vector<int>::iterator ItIdPersonajePc;

Puerta_boss::Puerta_boss(Coordenada c, int id):
Elemento(c,TIPO_PUERTA_BOSS, id){
	abierta = true;
	cantidad_personajes = 0;
	ancho = ANCHO;
	alto = ALTO;
}

void Puerta_boss::interactuar(Personaje *pj){
	int id_pj = pj->get_id_unico();
	//Si el personaje es uno de los personajes pc existentes
	//sumo +1 a la cantidad de personajes que pasaron por la puerta:
	ItIdPersonajePc it = std::find(ids_personajes_pc.begin(), 
	ids_personajes_pc.end(), id_pj);
	bool personaje_es_pc = (it != ids_personajes_pc.end());
	if (personaje_es_pc){
		cantidad_personajes++;
		pj->agregar_observador(this);
		if (cantidad_personajes >= ids_personajes_pc.size()){
			abierta = false;
			//Resettar coordenada de respawn.
		}
	} 																								
}

bool Puerta_boss::es_piso(){
	return false;
}

bool Puerta_boss::colisiona(Ubicable* otro_ubic, Coordenada nueva){
	if (!abierta){
		return true;
	}
	Coordenada actual_ubicable = otro_ubic->get_coordenada();
	//Devuelvo true solo si quiere salir de la cueva:
	return actual_ubicable.obtener_abscisa() > nueva.obtener_abscisa();
}

void Puerta_boss::sumar_personaje(int id_pj){
	ids_personajes_pc.push_back(id_pj);
}

void Puerta_boss::restar_personaje(int id_pj){
	ItIdPersonajePc it = std::find(ids_personajes_pc.begin(), ids_personajes_pc.end(), id_pj);
	ids_personajes_pc.erase(it);
}

void Puerta_boss::update(Observable *obs){
	Personaje_pc *personaje = (Personaje_pc*)obs;
	size_t pos_x_pj = personaje->get_coordenada().obtener_abscisa();
	size_t x_min = coord.izquierda(ancho/2).obtener_abscisa();
	//Si alguno de los personajes que ya pasaron por la puerta
	//respawnea, lo saco de la lista de personajes que pasaron.
	if (pos_x_pj < x_min){
		cantidad_personajes--;
	}
}

bool Puerta_boss::puede_ocupar(Ubicable* ubic){
	return true;
}

bool Puerta_boss::puede_ocupar(Personaje* pj){
	return true;
}

bool Puerta_boss::puede_ocupar(Elemento* elem){
	return false;
}

bool Puerta_boss::puede_ocupar(Bala* bala){
	return true;
}

bool Puerta_boss::puede_ocupar(Escalera* esc){
	return false;
}

bool Puerta_boss::puede_ocupar(Bloque* bloque){
	return false;
}

bool Puerta_boss::puede_ocupar(Puas* puas){
	return false;
}

bool Puerta_boss::puede_ocupar(Premio* premio){
	return true;
}
		
		
