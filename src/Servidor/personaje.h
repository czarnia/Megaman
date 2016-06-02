#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <vector>
#include <map>
#include "mapa.h"
#include "coordenada.h"
#include "atacable.h"
#include "defendible.h"
#include "actualizable.h"
#include "evento_mover.h"
#include "vida.h"
#include "observable.h"

class Bala;

#define PERDER_VIDA -1

class Personaje:
public Atacable,
public Defendible,
public Actualizable,
public Observable{
	protected:
		std::vector<Vida*> vidas;
		int velocidad_y, velocidad_x;
		size_t ancho, alto;
		Coordenada coordenada;
		std::string id;
		bool flotando;
		size_t tiempo_pasado;
	public:
		//Dado un mapa, una coordenada y una cadena que usa como identificador, se
		//crea un personaje.
		Personaje(Mapa *mapa, Coordenada c, std::string id);
		//Hace que el personaje se mueva;
		virtual void mover(size_t tiempo, Mapa* mapa) = 0;
		//Hace que el personaje ataque.
		virtual void atacar(size_t tiempo, int dir, Mapa* mapa) = 0;
		//Le hace un update al personaje.
		virtual void update(size_t tiempo, Mapa* mapa);
		//Dada una bala, recibe un ataque.
		virtual void recibir_ataque(Bala* ataque) = 0;
		//Devuelve el id de un personaje.
		virtual std::string devolver_id();
		//Dado un porcentaje de vida a perder, se la resta al personaje, en caso de
		//ser -1 (por defecto) le resta una vida completa.
		virtual void perder_vida(int porcentaje = PERDER_VIDA);
		//Devuelve true si el personaje está vivo, false en caso contrario.
		virtual bool esta_vivo();
		//Dada una direccion representada como un int, agrega un movimiento en dicha
		//direccion.
		virtual void agregar_movimiento(int direccion);
		//Dada una direccion representada como un int, agrega un ataque en dicha
		//direccion.
		virtual void agregar_ataque(int direccion);
		//Devuelve la coordenada central de un personaje.
		virtual Coordenada get_coordenada();
		//Notifica a los objetos que observan al personaje de un cambio
		//en el estado del mismo.
		virtual void notificar_observadores();
		//Devuelve la cantidad de vidas del personaje.
		int get_cantidad_vidas();
		//Devuelve el porcentaje de vida de la vida en uso
		//o 0 si no hay vidas.
		int get_porcentaje_vida();
		//Devuelve el porcentaje de energia actual del persoanje.
		int get_energia();
};

#endif //PERSONAJE_H
