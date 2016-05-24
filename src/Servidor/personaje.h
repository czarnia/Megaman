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
#include "vida.h"

#define PERDER_VIDA -1

class Personaje:
public Atacable,
public Defendible,
public Actualizable{
	public:
		Personaje(Mapa &mapa, std::string id);
		virtual void atacar() = 0;
		virtual void update(size_t tiempo) = 0;
		virtual void recibir_ataque(/*Bala ataque*/) = 0;
		virtual std::string &devolver_id();
		virtual void agregar_estrategia(StrategyMover &estrategia);
		virtual void perder_vida(int porcentaje = PERDER_VIDA);
		virtual bool esta_vivo();
		virtual void remover_estrategias();
		virtual void mover(std::string nombre_senial);
		virtual int &getVelocidad();
		virtual bool tiene_estrategia(std::string nombre_estrategia);
		virtual std::vector<Coordenada*> &getCoordenadas();
	private:
		std::vector<Coordenada*> coordenadas_ocupadas;
		//std::vector<Arma*> armas;
		std::vector<Vida*> vidas;
		std::string id;
		int velocidad;
		std::map<std::string, StrategyMover*> estrategias;
		std::map<std::string, StrategyMover*> estrategias_adquiridas;

		virtual bool ubicar(std::vector<Coordenada*> &nuevas_coordenadas);
		friend class Mapa;
		friend bool StrategyMover::mover(Personaje *personaje);
};

#endif //PERSONAJE_H
