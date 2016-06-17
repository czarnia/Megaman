#ifndef MEGAMAN_H
#define MEGAMAN_H

#include "mapa.h"
#include "escalera.h"
#include "personaje_pc.h"
#include "strategy_mover_megaman.h"
#include "capsula_de_energia.h"
#include "../../Comun/lock.h"
#include "../../Comun/mutex.h"

class Arma;
class Arma_megaman;
class StrategyMoverMegaman;

#define PERDER_MAX -100
#define GANAR_MAX 100

class Megaman: public Personaje_pc{
	private:
		Mutex m;
		Mapa *mapa;
		std::vector<Arma*> armas;
		std::map<int, StrategyMoverPersonajePc*> movimientos;
		StrategyMoverMegaman *movimiento_megaman;
		StrategyMoverPersonajePc *movimiento_actual;
		size_t arma_act;
	public:
		//Dado un Mapa*, una coordenada, un Arma_megaman* y un id, crea un megaman.
		Megaman(Mapa *mapa, Coordenada c, Arma_megaman *arma, int id);
		//Dado una Mapa* y una direccion, ataca.
		virtual void atacar(int dir, Mapa* mapa);
		//Dado un tiempo pasado y un Mapa*, se mueve.
		virtual void mover(size_t tiempo, Mapa* mapa);
		//Dada una Bala*, recibe un ataque.
		virtual void recibir_ataque(Bala* ataque);
		//Dado un tiempo, realiza un update.
		virtual void update(size_t tiempo);
		//Dada un Arma*, se la agrega a la armeria del megaman.
		virtual void agregar_arma(Arma *arma);
		//Dado una direccion, se agrega un movimiento en dicha direccion.
		virtual void agregar_movimiento(int direccion);
		//Dado una direccion, se saca un movimiento en dicha direccion.
		virtual void sacar_movimiento(int direccion);
		//Recibe una estrategia de movimiento y la agrega
		//a las estrategias de movimiento del personaje.
		virtual void agregar_movimiento(StrategyMoverPersonajePc *movimiento);
		//Recibe una escalera e interactúa con la misma
		//para actualizar sus coordenadas.
		void interactuar(Escalera *esc);
		//Recibe una capsula de energia e interactúa con la misma.
		void interactuar(Capsula_de_energia *capsula);
		//Dado un porcentaje de vida a perder, se la resta al personaje,
		//en caso de ser -100 (por defecto) una vida completa.
		void perder_vida(int porcentaje = PERDER_MAX);
		//Dado un porcentaje de vida a ganar, se la suma al personaje,
		//en caso de ser 100 (por defecto) una vida completa.
		void ganar_vida(int porcentaje = GANAR_MAX);
		//Dado un porcentaje de energia a perder se le resta al personaje,
		//en caso de ser -100 (por defecto) toda la energia disponible.
		virtual void perder_energia(int porcentaje = PERDER_MAX);
		//Dado un porcentaje de energia a ganar se le suma al personaje,
		//en caso de ser 100 (por defecto) la energia perdida.
		virtual void ganar_energia(int porcentaje = GANAR_MAX);
		//Devuelve el porcentaje de energia actual del persoanje.
		virtual int get_energia();
		//Devuelve la cantidad actual de vidas del personaje.
		int get_cantidad_vidas();
		//Devuelve el porcentaje de vida que le queda al personaje.
		int get_porcentaje_vida();
		//Devuelve true si el personaje esta vivo.
		virtual bool esta_vivo();
		
		friend class StrategyMoverMegaman;
		friend class StrategyMoverPersonajePc;
};

#endif //MEGAMAN_H
