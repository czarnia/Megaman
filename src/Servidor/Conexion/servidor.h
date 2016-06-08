#ifndef SERVIDOR_H
#define SERVIDOR_H

#include <map>
#include <string>
#include "conexion_cliente.h"
#include "entrada_estandar.h"
#include "observador_juego.h"
#include "../Modelo/juego.h"
#include "../../Comun/socket.h"

class Servidor:
public Observador_juego{
  private:
    Juego *mundo;
    Entrada_estandar *entrada;
    //guardo a cada cliente con su id!
    std::map<int, Conexion_cliente*> clientes;
	Socket *skt;
  public:
    //Crea un servidor.
    Servidor(char *puerto);
    //Destruye un servidor.
    virtual ~Servidor();
    //Acepto a los clientes del servidor (maximo cuatro).
    void aceptar_clientes();
    //Devuelve true si se cierra al servidor, false en caso contrario.
    bool termino_ejecucion();
    //Empieza una partida.
    void empezar_partida();

    //Dado un observable, realiza un update.
		virtual void update(Observable *obs);
		//Dado un identificador, notifica un gameover del cliente correspondiente.
		virtual void update_gameover(int id);
		//Notifica el fin de una partida.
		virtual void update_fin_partida();
		//Dado un identificador y un tipo, notifica que un personaje murio.
		virtual void update_murio_personaje(int tipo, int id);
		//Dado un identificador, un tipo y una cantidad de vidas, notifica que un
		//personaje vio modificadas las mismas.
		virtual void update_cantidad_vidas(int tipo, int id, int vidas);
		//Dado un identificador, un tipo y una porcentaje de vida, notifica que un
		//personaje vio modificada la misma.
		virtual void update_porcentaje_vida(int tipo, int id, int porcentaje_vida);
		//Dado un identificador, un tipo y una porcentaje de energia, notifica que
		//un personaje vio modificada la misma.
		virtual void update_energia(int tipo, int id, int energia);
		//Dado un identificador, un tipo y nuevas coordenadas en x y en y, notifica
		//que un personaje vio modificadas la mismas.
		virtual void update_posicion(int tipo, int id, int x, int y);

  private:
    //Dado un socket conectado a un cliente y un id del mismo,
    //se agrega un cliente al servidor.
    void agregar_cliente(Socket* cliente_nuevo);
};

#endif //SERVIDOR_H
