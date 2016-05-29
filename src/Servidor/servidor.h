#ifndef SERVIDOR_H
#define SERVIDOR_H

#include <map>
#include <string>
#include "entrada_estandar.h"
#include "conexion_cliente.h"
#include "juego.h"

class Servidor {
  private:
    //guardo a cada cliente con su id!
    std::map<std::string, Conexion_cliente*> clientes;
	  Socket *skt;
    Juego mundo;
    Entrada_estandar entrada;
  public:
    //Crea un servidor.
    Servidor(char *puerto);
    //Destruye un servidor.
    ~Servidor();
    //Acepto a los clientes del servidor (maximo cuatro).
    void aceptar_clientes();
    //Devuelve true si se cierra al servidor, false en caso contrario.
    bool termino_ejecucion();
    void empezar_partida();
  private:
    //Dado un socket conectado a un cliente y un id del mismo, se agrega un cliente
    //al servidor.
    void agregar_cliente(Socket* cliente_nuevo);
};

#endif //SERVIDOR_H
