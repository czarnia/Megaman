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

#define PERDER_VIDA -1

class Personaje:
public Atacable,
public Defendible,
public Actualizable{
	public:
		Personaje(Mapa *mapa, Coordenada *c, std::string id);
		virtual void atacar() = 0;
		virtual void update(size_t tiempo) = 0;
		virtual void recibir_ataque(/*Bala ataque*/) = 0;
		
		virtual std::string &devolver_id();
		virtual void perder_vida(int porcentaje = PERDER_VIDA);
		virtual bool esta_vivo();
		virtual void agregar_evento(Evento_mover *mover);
		virtual int get_velocidad();
		virtual Coordenada *get_coordenada();
	private:
		std::vector<Vida*> vidas;
		int velocidad_y, velocidad_x;
		size_t ancho, alto;
		Coordenada *coordenada;
		std::string id;
		size_t tiempo_pasado;
		StrategyMover *movimiento;
		
		friend class StrategyMover;
};

#endif //PERSONAJE_H

