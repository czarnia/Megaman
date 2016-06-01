#ifndef SERVIDOR_H
#define SERVIDOR_H

#include <map>
#include <string>
#include "conexion_cliente.h"
#include "entrada_estandar.h"
#include "observador_juego.h"
#include "juego.h"

class Servidor:
public Observador_juego{
  private:
    Juego *mundo;
    Entrada_estandar entrada;
    //guardo a cada cliente con su id!
    std::map<std::string, Conexion_cliente*> clientes;
	Socket *skt;
  public:
    //Crea un servidor.
    Servidor(char *puerto);
    //Destruye un servidor.
    ~Servidor();
    //Acepto a los clientes del servidor (maximo cuatro).
    void aceptar_clientes();
    //Devuelve true si se cierra al servidor, false en caso contrario.
    bool termino_ejecucion();
    //Empieza una partida.
    void empezar_partida();
    virtual void update(Observable *obs);
    virtual void update_fin_partida();
    virtual void update_gameover(std::string id);
	  virtual void update_murio_personaje(std::string id);
    virtual void update_cantidad_vidas(std::string id, int vidas);
    virtual void update_porcentaje_vida(std::string id, int cant_vida);
    virtual void update_energia(std::string id, int energia);
    virtual void update_posicion(std::string id, int x, int y);

  private:
    //Dado un socket conectado a un cliente y un id del mismo,
    //se agrega un cliente al servidor.
    void agregar_cliente(Socket* cliente_nuevo);
};

#endif //SERVIDOR_H
