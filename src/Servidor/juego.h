#ifndef JUEGO_H
#define JUEGO_H

#include "../Comun/mutex.h"
#include "actualizable.h"
#include "mapa.h"
#include "juego.h"
#include "juego_observable.h"
#include "personaje_factory.h"
#include <string>
#include <iosfwd>
#include <cstddef>

class Juego:
public Juego_observable{
	private:
		Mapa mundo;
		Mutex proteccion;
		bool fin_partida;
		int cant_jugadores;
		std::map<std::string, PersonajeFactory*> factories;

		void inicializar_partida();
	public:
		//Crea un juego nuevo.
		Juego(size_t tamanio, int cant_jugadores);
		//Implementa el ciclo del juego.
		void jugar();
		//Termina la partida en marcha.
		void terminar_partida();
		//Dado un determinado tiempo, actualiza al juego.
		virtual void update(size_t tiempo);
		//Dado el id de un personaje, hace que el mismo ataque en una direccion
		//dada.
		void personaje_atacar(std::string id_pj, int direccion);
		//Dado el id de un personaje, hace que el mismo se mueva en una direccion
		//dada.
		void personaje_mover(std::string id_pj, int direccion);
		//Dado el id de un personaje y un numero de arma, hace que el mismo cambie a
		//la misma.
		void personaje_cambiar_arma(std::string id_pj, int arma);
		//Recibe el id de un personaje muerto y actualiza la partida
		void quitar_observador(Observador_juego *observador);
		void agregar_observador(Observador_juego *observador);
		void notificar_termino_partida();
		void notificar_gameover(std::string id);
		void notificar_murio_personaje(std::string id);
		void notificar_cantidad_vidas(std::string id, int vidas);
		void notificar_porcentaje_vida(std::string id, int cant_vida);
		void notificar_energia(std::string id, int energia);
		void notificar_posicion(std::string id, int x, int y);
		void murio_personaje(std::string id);
		void actualizo_cantidad_vidas(std::string id, int vidas);
		void actualizo_porcentaje_vida(std::string id, int cant_vida);
		void actualizo_energia(std::string id, int energia);
		void actualizo_posicion(std::string id, int x, int y);
		~Juego();
};

#endif //JUEGO_H
