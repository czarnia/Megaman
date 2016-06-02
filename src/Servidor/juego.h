#ifndef JUEGO_H
#define JUEGO_H

#include "../Comun/mutex.h"
#include "actualizable.h"
#include "mapa.h"
#include "juego_observable.h"
#include "personaje_factory.h"
#include <string>
#include <iosfwd>
#include <cstddef>

class Juego:
public Juego_observable{
	private:
		Mapa *mundo;
		Mutex proteccion;
		bool fin_partida;
		int cant_jugadores;
		std::map<std::string, PersonajeFactory*> factories;

	public:
		//Dado un tamanio, crea un juego nuevo.
		Juego(size_t tamanio);
		//Dada una cantidad de jugadores, inicializa una partida.
		void inicializar_partida(int cant_jugadores);
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
		//Dado el id de un personaje, hace que el mismo se deje de mover en una
		//direccion dada.
		void personaje_parar(std::string id_pj, int direccion);
		//Dado el id de un personaje y un numero de arma, hace que el mismo cambie a
		//la misma.
		void personaje_cambiar_arma(std::string id_pj, int arma);

		int long_y_mapa();
		int long_x_mapa();

		//Quita un observador del juego.
		void quitar_observador(Observador_juego *observador);
		//Agrega un observador al juego.
		void agregar_observador(Observador_juego *observador);
		//Notifica a los observadores que finalizo la partida.
		void notificar_termino_partida();
		//Notifica a los observadores que se produjo un gameover.
		void notificar_gameover(std::string id);
		//Notifica a los observadores que murio un determinado pj.
		void notificar_murio_personaje(std::string id);
		//Notifica a los observadores que se modifico la cantidad de vidas de un
		//personaje.
		void notificar_cantidad_vidas(std::string id, int vidas);
		//Notifica a los observadores que se modifico el porcentaje de vida de un
		//personaje.
		void notificar_porcentaje_vida(std::string id, int cant_vida);
		//Notifica a los observadores que se modifico el porcentaje de energia de un
		//personaje.
		void notificar_energia(std::string id, int energia);
		//Notifica a los observadores que se modifico la posicion de un personaje.
		void notificar_posicion(std::string id, int x, int y);

		void murio_personaje(std::string id);
		void actualizo_cantidad_vidas(std::string id, int vidas);
		void actualizo_porcentaje_vida(std::string id, int cant_vida);
		void actualizo_energia(std::string id, int energia);
		void actualizo_posicion(std::string id, int x, int y);

		std::vector<Coordenada> bloques();

		//Destructor de juego.
		~Juego();
};

#endif //JUEGO_H
