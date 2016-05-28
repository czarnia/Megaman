#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <vector>
#include <map>
#include "mapa.h"
#include "coordenada.h"
#include "atacable.h"
#include "defendible.h"
#include "actualizable.h"
#include "strategy_mover.h"
#include "evento_mover.h"
#include "vida.h"

class Bala;

#define PERDER_VIDA -1

class Personaje:
public Atacable,
public Defendible,
public Actualizable{
	private:
		friend class StrategyMover;

		std::vector<Vida*> vidas;
		int velocidad_y, velocidad_x;
		size_t ancho, alto;
		Coordenada *coordenada;
		std::string id;
		size_t tiempo_pasado;
		StrategyMover *movimiento;

	public:
		//Dado un mapa, una coordenada y una cadena que usa como identificador, se
		//crea un personaje.
		Personaje(Mapa *mapa, Coordenada *c, std::string id);
		//Hace que el personaje ataque.
		virtual void atacar(int direccion) = 0;
		//Le hace un update al personaje.
		virtual void update(size_t tiempo) = 0;
		//Dada una bala, recibe un ataque.
		virtual void recibir_ataque(/*Bala* ataque*/) = 0;
		//Devuelve el id de un personaje.
		virtual std::string &devolver_id();
		//Dado un porcentaje de vida a perder, se la resta al personaje, en caso de
		//ser -1 (por defecto) le resta una vida completa.
		virtual void perder_vida(int porcentaje = PERDER_VIDA);
		//Devuelve true si el personaje está vivo, false en caso contrario.
		virtual bool esta_vivo();
		virtual void agregar_evento(Evento_mover *mover);
		//Dada una direccion representada como un int, agrega un movimiento en dicha
		//direccion.
		virtual void agregar_movimiento(int direccion);
		//Dada una direccion representada como un int, agrega un ataque en dicha
		//direccion.
		virtual void agregar_ataque(int direccion);
		//Devuelve la velocidad de un personaje.
		virtual int get_velocidad();
		//Devuelve la coordenada central de un personaje.
		virtual Coordenada *get_coordenada();
};

#endif //PERSONAJE_H
