#ifndef SERVIDOR_H
#define SERVIDOR_H

#include <string>
#include "almacenador_clientes.h"
#include "entrada_estandar.h"
#include "../Partida/observador_juego.h"
#include "../../Modelo/juego.h"
#include "../../../Comun/socket.h"

class Servidor:
public Observador_juego{
  private:
    Juego *mundo;
    Entrada_estandar *entrada;
    Almacenador_clientes clientes;
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
    //Empieza un nuevo nivel.
    void empezar_nivel();
    //Comienza el juego del nivel.
    void jugar_nivel();
    //Termina la ejecución del servidor.
    void terminar_ejecucion();

    //El servidor deja de aceptar clientes.
    void cerrar_conexiones();
    //Se le notifica al servidor que se desconecto un cliente dado un id.
    void cliente_desconectado(int id_cliente);
    //Se le notifica al servidor que se conecto un nuevo cliente.
    void cliente_conectado();
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
	//Notifica a los clientes de que se modifico la posicion de un personaje.
	virtual void update_personaje_escudo(int tipo, int id, bool bajo_escudo);

  private:
    //Dado un socket conectado a un cliente y un id del mismo,
    //se agrega un cliente al servidor.
    void agregar_cliente(Socket* cliente_nuevo);
};

#endif //SERVIDOR_
