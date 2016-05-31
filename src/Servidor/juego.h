#ifndef JUEGO_H
#define JUEGO_H

#include "../Comun/mutex.h"
#include "actualizable.h"
#include "mapa.h"
#include "servidor.h"
#include "personaje_factory.h"
#include <string>
#include <iosfwd>
#include <cstddef>

class Juego{
	private:
		Mapa mundo;
		Mutex proteccion;
		bool fin_partida;
		int cant_jugadores;
		Servidor *s;
		std::map<std::string, PersonajeFactory*> factories;
		
		void inicializar_partida();
	public:
		//Crea un juego nuevo.
		Juego(Servidor *s, size_t tamanio, int cant_jugadores);
		//Implementa el ciclo del juego.
		void jugar();
		//Termina la partida en marcha.
		void terminar_partida();
		//Dado un determinado tiempo, actualiza al juego.
		virtual void update(size_t tiempo);
		//Dado el id de un personaje, hace que el mismo ataque en una direccion
		//dada.
		void personaje_atacar(std::string id_pj);
		//Dado el id de un personaje, hace que el mismo se mueva en una direccion
		//dada.
		void personaje_mover(std::string id_pj);
		//Dado el id de un personaje y un numero de arma, hace que el mismo cambie a
		//la misma.
		void personaje_cambiar_arma(std::string id_pj, int arma);
		//Recibe el id de un personaje muerto y actualiza la partida
		void murio_personaje(std::string id);
		//Recibe el id de un personaje cuya cantidad de vidas fue modificada
		//y actualiza la partida.
		void actualizo_cantidad_vidas(std::string id, int cantidad_vidas);
		//Recibe el id de un personaje cuyo porcentaje de vida fue modificado
		//y actualiza la partida.
		void actualizo_porcentaje_vida(std::string id, int porcentaje_vida);
		//Recibe el id de un personaje cuya energia fue modificada
		//y actualiza la partida.
		void actualizo_energia(std::string id, int energia);
		//Recibe el id de un personaje que se movio y su nueva posicion
		//y actualiza la partida.
		void actualizo_posicion(std::string id, int x, int y);
		//Destructor del juego.
		~Juego();
};

#endif //JUEGO_H
