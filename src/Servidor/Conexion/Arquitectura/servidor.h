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
    void empezar_nivel(int num_nivel);
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
    //Dado un estado, hace un update.
    virtual void update_estado(Estado e);
  private:
    //Dado un socket conectado a un cliente y un id del mismo,
    //se agrega un cliente al servidor.
    void agregar_cliente(Socket* cliente_nuevo);
};

#endif //SERVIDOR_
