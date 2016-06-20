#ifndef ALMACENADOR_CLIENTES_H
#define ALMACENADOR_CLIENTES_H

#include "conexion_cliente.h"
#include "../Partida/estado.h"
#include <map>

class Almacenador_clientes{
  private:
    std::map<int, Conexion_cliente*> clientes;
	public:
		//Se crea un Almacenador_clientes.
		Almacenador_clientes() {}
		//Destructor del evento.
		~Almacenador_clientes() {};
		//Devuelve la cantidad de clientes del almacenador.
		int devolver_tamanio();
		//Dada una conexion_cliente*, la agrega al almacenador.
		void agregar_cliente (Conexion_cliente* cliente);
		//Inicia la ejecucion de los clientes.
		void iniciar_ejecucion();
    //Dado un estado, notifica del mismo a todos los cleintes
    void update_estado(Estado e);

		//Dado un identificador, notifica un gameover del cliente correspondiente.
		void update_gameover(int id);
		//Notifica el fin de una partida.
		void update_fin_partida();
		//Notifica el fin de una partida.
		void update_fin_nivel();
		//Notifica a los clientes de que ganaron el juego.
		void update_victoria();

		//Le notifica a todos los clientes que se ha iniciado un nuevo nivel.
		void iniciar_nivel(int num_nivel);
};

#endif //ALMACENADOR_CLIENTES_H
