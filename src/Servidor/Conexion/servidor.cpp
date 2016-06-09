#include "servidor.h"
#include <stdlib.h>

#include <string>
#include <sstream>
#include <iostream>
#include "entrada_estandar.h"

#define MAX_CONEXIONES 4
#define FIN_ENTRADA "q"
typedef struct sockaddr* Address;

Servidor::Servidor(char *puerto){
	entrada = new Entrada_estandar(FIN_ENTRADA);
	skt = new Socket(NULL, puerto);
	skt->bind(NULL, puerto);
	skt->listen(MAX_CONEXIONES);
	mundo = new Juego(12, 12);
}

Servidor::~Servidor(){
  entrada->join();
}

void Servidor::aceptar_clientes(){
  Socket* aceptado = skt->accept(NULL);
  if (!aceptado){
    std::cout << "no acepté nada!";
  }
  agregar_cliente(aceptado);
  cerrar_conexiones();
  /*
  Socket* aceptado;
  for (size_t i = 0; i < 4; i++){
    aceptado = skt->accept(NULL);
    if (!aceptado){
      return;
    }
    agregar_cliente(aceptado);
  }
  */
}

bool Servidor::termino_ejecucion(){
  return entrada->termino();
}

void Servidor::cliente_desconectado(int id_cliente){
  //sacar al cliente.
  //enviar nueva cantidad de clientes al resto.
}

void Servidor::cliente_conectado(){
  //enviar nueva cantidad de clientes a todos.
}

void Servidor::agregar_cliente(Socket* cliente_nuevo){
  //Armo un id para el nuevo cliente con el numero de cliente.
  int id = (clientes.devolver_tamanio() + 1);
  //Agrego al cliente:
  Conexion_cliente* c = new Conexion_cliente(cliente_nuevo, id, mundo);
  clientes.agregar_cliente(c);
}

void Servidor::empezar_partida(){
	std::cout << "INICIO PARTIDA\n";
	mundo->agregar_observador(this);
	mundo->inicializar_partida(clientes.devolver_tamanio());
  //clientes.iniciar_ejecucion();
	mundo->jugar();
}

void Servidor::cerrar_conexiones(){
  skt->shutdown(SHUT_RDWR);
}


void Servidor::update(Observable *obs){}

void Servidor::update_fin_partida(){
  clientes.update_fin_partida();
}

void Servidor::update_gameover(int id){
  clientes.update_gameover(id);
}

void Servidor::update_murio_personaje(int tipo, int id) {
  clientes.update_murio_personaje(tipo, id);
}

void Servidor::update_cantidad_vidas(int tipo, int id, int vidas) {
  clientes.update_cantidad_vidas(tipo, id, vidas);
}

void Servidor::update_porcentaje_vida(int tipo, int id, int vida){
  clientes.update_porcentaje_vida(tipo, id, vida);
}

void Servidor::update_energia(int tipo, int id, int energia){
  clientes.update_energia(tipo, id, energia);
}

void Servidor::update_posicion(int tipo, int id, int x, int y){
  clientes.update_posicion(tipo, id, x, y);
}
