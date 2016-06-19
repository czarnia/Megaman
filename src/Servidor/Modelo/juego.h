#ifndef JUEGO_H
#define JUEGO_H

#include "../../Comun/mutex.h"
#include "../../Editor/cargador_mapa.h"
#include "actualizable.h"
#include "mapa.h"
#include "ubicable.h"
#include "juego_observable.h"
#include <string>
#include <iosfwd>
#include <cstddef>

class Ubicable;
class Ubicable_factory;

class Juego:
public Juego_observable{
	private:
		Mapa *mundo;
		Mutex proteccion;
		int cant_jugadores;
		std::vector<Ubicable_factory*> factories;
		Cargador_mapa *cargador;
		bool fin_partida;
		bool partida_inicializada;
		bool jugando_nivel;
	public:
		//Dado un tamanio, crea un juego nuevo.
		Juego();
		//Dada una cantidad de jugadores, inicializa una partida.
		void inicializar_partida(int cant_jugadores);
		//Implementa el ciclo del juego.
		void jugar();
		//Termina la partida en marcha.
		void terminar_partida();
		//Dado un determinado tiempo, actualiza al juego.
		virtual void update(float tiempo);
		//Notifica a los observadores de un cambio en el estado.
		void notificar_observadores();
		//Hace un update.
		virtual void update(Observable *obs);
		//Dado el id de un personaje, hace que el mismo ataque en una direccion
		//dada.
		void personaje_atacar(int id_pj, int direccion);
		//Dado el id de un personaje, hace que el mismo se mueva en una direccion
		//dada.
		void personaje_mover(int id_pj, int direccion);
		//Dado el id de un personaje, hace que el mismo se deje de mover en una
		//direccion dada.
		void personaje_parar(int id_pj, int direccion);
		//Dado el id de un personaje y un numero de arma, hace que el mismo cambie a
		//la misma.
		void personaje_cambiar_arma(int id_pj, int arma);

		//Devuelve todos los ubicables del mapa.
		std::vector<Ubicable*> devolver_ubicables();
		//Devuelve la longitud y del mapa del juego.
		int long_y_mapa();
		//Devuelve la longitud x del mapa del juego.
		int long_x_mapa();
		//Quita un observador del juego.
		void quitar_observador(Observador_juego *observador);
		//Agrega un observador al juego.
		void agregar_observador(Observador_juego *observador);
		//Notifica a los observadores que finalizo la partida.
		void notificar_termino_partida();
		//Notifica a los observadores que se produjo un gameover.
		void notificar_gameover(int id);
		//Notifica a los observadores que cambio
		//el estado de un personaje.
		void notificar_estado_personaje(int tipo, int id, int accion);
		//Notifica a los observadores que se modifico la cantidad de vidas de un
		//personaje.
		void notificar_cantidad_vidas(int tipo, int id, int vidas);
		//Notifica a los observadores que se modifico el porcentaje de vida de un
		//personaje.
		void notificar_porcentaje_vida(int tipo, int id, int cant_vida);
		//Notifica a los observadores que se modifico el porcentaje de energia de un
		//personaje.
		void notificar_energia(int tipo, int id, int energia);
		//Notifica a los observadores que se modifico la posicion de un personaje.
		void notificar_posicion(int tipo, int id, int x, int y);
		//Recibe id y tipo y un estado correspondientes a un personaje y
		//y notifica al servidor del cambio de estado.
		void actualizo_estado_personaje(int tipo, int id, int estado);
		//Recibe id y tipo correspondiente a un personaje y
		//una cantidad de vidas y notifica al servidor
		//de la nueva cantidad de vidas del mismo.
		void actualizo_cantidad_vidas(int tipo, int id, int vidas);
		//Recibe id y tipo correspondiente a un personaje y
		//un porcentaje de vida y notifica al servidor
		//cantidad de vida del mismo.
		void actualizo_porcentaje_vida(int tipo, int id, int cant_vida);
		//Recibe id y tipo correspondiente a un personaje y
		//un porcentaje de energia y notifica al servidor
		//cantidad de energia del mismo.
		void actualizo_energia(int tipo, int id, int energia);
		//Recibe id y tipo correspondiente a un personaje y
		//su posicion actual y notifica al servidor de
		//la nueva posicion.
		void actualizo_posicion(int tipo, int id, int x, int y);
		//Recibe un id y un tipo y remueve al personaje
		//muerto del juego.
		void murio_personaje(Personaje *p);
		//Finaliza el nivel.
		void murio_boss();
		//Devuelve una lista de coordenadas correspondientes
		//a los bloques del mapa.
		std::vector<Coordenada> bloques();
		//Devuelve la cantidad de jugadores activos.
		int get_cantidad_jugadores();
		//Devuelve true si ya se inicio la partida.
		bool inicio_partida();
		//Recibe un numero de mapa e inicializa un nuevo nivel.
		void inicializar_nivel(int numero_mapa);
		//Devuelve true si ya se inicializo el nivel.
		bool esta_jugando_nivel();
		//Devuelve el mapa actual del juego.
		Mapa* get_mapa();
		//Destructor de juego.
		~Juego();
	private:
		//Carga las factories necesarias para crear las entidades del
		//juego.
		void cargar_factories(Cargador_mapa *cargador);


};

#endif //JUEGO_H
