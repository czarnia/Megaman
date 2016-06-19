#ifndef ALMACENADOR_CLIENTES_H
#define ALMACENADOR_CLIENTES_H

#include "conexion_cliente.h"
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
		//Dado un identificador, notifica un gameover del cliente correspondiente.
		void update_gameover(int id);
		//Notifica el fin de una partida.
		void update_fin_partida();
		//Dado un id, un tipo y un codigo de accion, notifica que un
		//hubo un cambio en el estado del personaje.
		void update_estado_personaje(int tipo, int id, int accion);
		//Dado un identificador, un tipo y una cantidad de vidas, notifica que un
		//personaje vio modificadas las mismas.
		void update_cantidad_vidas(int tipo, int id, int vidas);
		//Dado un identificador, un tipo y una porcentaje de vida, notifica que un
		//personaje vio modificada la misma.
		void update_porcentaje_vida(int tipo, int id, int porcentaje_vida);
		//Dado un identificador, un tipo y una porcentaje de energia, notifica que
		//un personaje vio modificada la misma.
		void update_energia(int tipo, int id, int energia);
		//Dado un identificador, un tipo y nuevas coordenadas en x y en y, notifica
		//que un personaje vio modificadas la mismas.
		void update_posicion(int tipo, int id, int x, int y);
    //Le notifica a todos los clientes que se ha iniciado un nuevo nivel.
    void iniciar_nivel(int num_nivel);
};

#endif //ALMACENADOR_CLIENTES_H
