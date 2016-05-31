#ifndef SERVIDOR_H
#define SERVIDOR_H

#include <map>
#include <string>
#include "juego.h"
#include "conexion_cliente.h"
#include "entrada_estandar.h"

class Servidor{
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
    //Envia a los clientes un mensaje indicando que algun personaje
    //actualizo su posicion.
    void enviar_cambio_posicion(std::string id, int x, int y);
    //Envia a los clientes un mensaje indicando que algun jugador 
    //perdio el juego.
    void enviar_gameover(std::string id);
    //Envia a los clientes un mensaje indicando que algun jugador 
    //actualizo su cantidad de vidas.
    void enviar_cantidad_vidas(std::string id, int cant_vidas);
    //Envia a los clientes un mensaje indicando que algun jugador 
    //actualizo su porcentaje de vida.
    void enviar_porcentaje_vida(std::string id, int vida);
    //Envia a los clientes un mensaje indicando que algun jugador 
    //actualizo su porcentaje de energia.
    void enviar_porcentaje_energia(std::string id, int energia);
  private:
    //Dado un socket conectado a un cliente y un id del mismo, se agrega un cliente
    //al servidor.
    void agregar_cliente(Socket* cliente_nuevo);
};

#endif //SERVIDOR_H
