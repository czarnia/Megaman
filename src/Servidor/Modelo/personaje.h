#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <vector>
#include <map>
#include "mapa.h"
#include "coordenada.h"
#include "atacable.h"
#include "defendible.h"
#include "actualizable.h"
#include "vida.h"
#include "personaje_observable.h"
#include "observador_personaje.h"
#include "observador_ubicable.h"
class StrategyMover;
class StrategyMoverSinGravedad;
class StrategyMoverBumby;
class StrategyMoverJumpingSnipper;
class Observador_personaje;
class Bala;

#define PERDER_MAX -100
#define GANAR_MAX 100

class Personaje:
public Atacable,
public Defendible,
public Actualizable,
public Personaje_observable{
	protected:
		std::vector<Vida> vidas;
		std::map<int, StrategyMover*> movimientos;
		//int velocidad_y, velocidad_x;
		size_t ancho, alto;
		Coordenada coordenada;
		int energia;
		int id;
		int tipo;
		bool flotando;
		size_t tiempo_pasado;
	public:
		//Dado un mapa, una coordenada y una cadena que usa como identificador, se
		//crea un personaje.
		Personaje(Mapa *mapa, Coordenada c, int id);
		//Hace que el personaje se mueva;
		virtual void mover(size_t tiempo, Mapa* mapa) = 0;
		//Hace que el personaje ataque.
		virtual void atacar(int dir, Mapa* mapa) = 0;
		//Le hace un update al personaje.
		virtual void update(size_t tiempo, Mapa* mapa);
		//Dada una bala, recibe un ataque.
		virtual void recibir_ataque(Bala* ataque) = 0;
		//Devuelve el id de un personaje.
		virtual int get_id();
		//Devuelve el tipo de un personaje.
		virtual	int get_tipo();
		//Dado un porcentaje de vida a perder, se la resta al personaje,
		//en caso de ser -100 (por defecto) una vida completa.
		virtual void perder_vida(int porcentaje = PERDER_MAX);
		//Dado un porcentaje de vida a ganar, se la suma al personaje,
		//en caso de ser 100 (por defecto) una vida completa.
		virtual void ganar_vida(int porcentaje = GANAR_MAX);
		//Dado un porcentaje de energia a perder se le resta al personaje,
		//en caso de ser -100 (por defecto) toda la energia disponible.
		virtual void perder_energia(int porcentaje = PERDER_MAX);
		//Dado un porcentaje de energia a ganar se le suma al personaje,
		//en caso de ser 100 (por defecto) la energia perdida.
		virtual void ganar_energia(int porcentaje = GANAR_MAX);
		//Devuelve true si el personaje está vivo, false en caso contrario.
		virtual bool esta_vivo();
		//Dada una direccion representada como un int, agrega un movimiento en dicha
		//direccion.
		virtual void agregar_movimiento(int direccion) = 0;  //TODO: esto debería ser de pc.
		//Recibe una estrategia de movimiento y la agrega
		//a las estrategias de movimiento del personaje.
		virtual void agregar_movimiento(int dir, StrategyMover *movimiento);
		//Dada una direccion representada como un int, saca un movimiento en dicha
		//direccion.
		virtual void sacar_movimiento(int direccion) = 0;
		//Devuelve la coordenada central de un personaje.
		virtual Coordenada get_coordenada();
		//Notifica a los objetos que observan al personaje de un cambio
		//en el estedo del mismo.
		virtual void notificar_observadores();
		//Devuelve la cantidad de vidas del personaje.
		int get_cantidad_vidas();
		//Devuelve el porcentaje de vida de la vida en uso
		//o 0 si no hay vidas.
		int get_porcentaje_vida();
		//Devuelve el porcentaje de energia actual del persoanje.
		int get_energia();
		//Devuelve el ancho del personaje.
		int get_ancho();
		//Devuelve el alto del personaje.
		int get_alto();
		//Recibe un observador de ubicables y lo agrega a
		//su lista de observadores:
		void agregar_observador(Observador_ubicable *observador);
		//Recibe un puntero a un observador de ubicables
		//y lo remueve de su lista de observadores:
		void quitar_observador(Observador_ubicable *observador);
		//Recibe un observador de personajes y lo agrega a
		//su lista de observadores:
		void agregar_observador(Observador_personaje *observador);
		//Recibe un puntero a un observador de personajes
		//y lo remueve de su lista de observadores:
		void quitar_observador(Observador_personaje *observador);
		//Devuelve todas las coordenadas que ocupa un personaje dada una coordenada
		//c central, en caso de no pasarse ninguna, se toma la como central a la
		//actual.
		std::vector<Coordenada> coordenadas(Coordenada c);
		//Devuelve todas las coordenadas ocupadas por el personaje
		//tomando la coordenada central actual del mismo como
		//referencia.
		std::vector<Coordenada> coordenadas();
		//Dado un ubicable, dice si puede ubicarse en las mismas coordenadas que
		//este.
		virtual bool puede_ocupar(Ubicable* ubic);
		//Dado un personaje, dice si puede ubicarse en las mismas coordenadas que
		//este.
		virtual bool puede_ocupar(Personaje* pj);
		//Dado un elemento, dice si puede ubicarse en las mismas coordenadas que
		//este.
		virtual bool puede_ocupar(Elemento* elem);
		//Dada una bala, dice si puede ubicarse en las mismas coordenadas que
		//este.
		virtual bool puede_ocupar(Bala* bala);
		//Dada una escalera, dice si puede ubicarse en las mismas coordenadas que
		//este.
		virtual bool puede_ocupar(Escalera* esc);
		//Dada una escalera, dice si puede ubicarse en las mismas coordenadas que
		//este.
		virtual bool puede_ocupar(Bloque* bloque);
		//Dadas unas puas, dice si puede ubicarse en las mismas coordenadas que
		//este.
		virtual bool puede_ocupar(Puas* puas);
		//Dado un Premio, devuelve true si el premio puede ubicarse
		//en las mismas coordenadas que este elemento.
		virtual bool puede_ocupar(Premio* premio);
		//Dada una posicion para respawnear, se mueve al personaje a la misma.
		virtual void respawn(Coordenada posicion_inicial);

		friend class StrategyMoverBumby;
		friend class StrategyMoverSinGravedad;
		friend class StrategyMoverMegaman;
		friend class StrategyMoverJumpingSnipper;
};

#endif //PERSONAJE_H
