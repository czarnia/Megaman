#ifndef CONEXION_CLIENTE_H
#define CONEXION_CLIENTE_H

#include "../Comun/socket.h"
#include "receiver_cliente.h"
#include "juego.h"

class Conexion_cliente{
  private:
    Socket* skt;
    int id_cliente;
    Receiver_cliente rcv;
  public:
    //Crea una conexion_cliente recibiendo como parametro un socket ya conecta-
    //do y un id que lo identifica.
    Conexion_cliente(Socket* conexion, int id, Juego *m);
    
    void iniciar_ejecucion();
    //Le informa a la conexion_cliente que debe dejar de recibir datos.
    void terminar_ejecucion();
    //Destructor del Conexion_cliente.
    virtual ~Conexion_cliente();
    //Recibe el id de un personaje y notifica al cliente
    //de su nueva posicion.
    void enviar_cambio_posicion(std::string id, int x, int y);
    //Envia la nueva cantidad de vidas que tiene un jugador/cliente.
    void enviar_cantidad_vidas(std::string id, int cantidad);
    //Envia el nuevo porcentaje de vida que tiene un jugador/cliente.
    void enviar_porcentaje_vida(std::string id, int porcentaje);
    //Envia el nuevo porcentaje de energia que tiene un jugador/cliente.
    void enviar_porcentaje_energia(int porcentaje);
    //Envia un mensaje de victoria al jugador/cliente.
    void enviar_victoria();
    //Envia un mensaje de derrota al jugador/cliente.
    void enviar_gameover();
};

#endif //CONEXION_CLIENTE_H
