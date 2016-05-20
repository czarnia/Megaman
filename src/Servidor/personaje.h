#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <vector>
#include "mapa.h"
#include "coordenada.h"
#include "ubicable.h"
#include "atacable.h"
#include "defendible.h"
#include "actualizable.h"

class Personaje:
public Ubicable,
public Atacable,
public Defendible,
public Actualizable{
	public:
		Personaje();
		virtual void atacar() = 0;
		virtual void update(size_t tiempo) = 0;
		virtual void recibir_ataque(/*Bala ataque*/) = 0;
		virtual bool ubicar(Mapa &mapa) = 0;
		//virtual void mover(Mapa &mapa, StrategyMover &accion_mover);
		virtual void devolver_id() = 0;
	private:
		std::vector<Coordenada*> coordenadas_ocupadas;
		//std::vector<Arma*> armas;
		//std::vector<Vida*> vidas;
}

#endif //PERSONAJE_H
