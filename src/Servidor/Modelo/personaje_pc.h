#ifndef PERSONAJE_PC_H
#define PERSONAJE_PC_H

#include "personaje.h"
#include "strategy_mover_personaje_pc.h"

#define PERDER_MAX 100
#define GANAR_MAX 100

class Mapa;
class StrategyMoverPersonajePc;

class Personaje_pc: public Personaje{
	protected:
		int energia;
		std::vector<Vida> vidas;
	public:
		//Dado un Mapa*, una coordenada y un id, crea a un personaje pc.
		Personaje_pc(Mapa *mapa, Coordenada c, int id):
		Personaje(mapa, c, id){}
		//Dado un porcentaje de energia a perder se le resta al personaje,
		//en caso de ser -100 (por defecto) toda la energia disponible.
		virtual void perder_energia(int porcentaje = PERDER_MAX) = 0;
		//Dado un porcentaje de energia a ganar se le suma al personaje,
		//en caso de ser 100 (por defecto) la energia perdida.
		virtual void ganar_energia(int porcentaje = GANAR_MAX) = 0;
		//Dada una direccion representada como un int, agrega un movimiento en dicha
		//direccion.
		virtual void agregar_movimiento(int direccion) = 0;
		//Dada una direccion representada como un int, saca un movimiento en dicha
		//direccion.
		virtual void sacar_movimiento(int direccion) = 0;
		//Recibe una estrategia de movimiento y la agrega
		//a las estrategias de movimiento del personaje.
		virtual void agregar_movimiento(StrategyMoverPersonajePc *movimiento) = 0;
		//Devuelve el porcentaje de energia actual del persoanje.
		virtual int get_energia() = 0;
		//Devuelve la cantidad de vidas del personaje.
		virtual size_t get_cantidad_vidas() = 0;

		friend class StrategyMoverMegaman;
		friend class StrategyMoverPersonajePc;
};

#endif //PERSONAJE_PC_H
