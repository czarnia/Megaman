#include "servidor.h"

#include <stdlib.h>

#include <string>
#include <sstream>
#include <iostream>

#include "log.h"
#include "entrada_estandar.h"

#define MAX_CONEXIONES 4
#define FIN_ENTRADA "q"
typedef struct sockaddr* Address;

Servidor::Servidor(char *puerto){
	Log::instancia()->inicio_servidor();
	entrada = new Entrada_estandar(FIN_ENTRADA, this);
	entrada->start();
	skt = new Socket(NULL, puerto);
	skt->bind(NULL, puerto);
	skt->listen(MAX_CONEXIONES);
	mundo = new Juego();
}

Servidor::~Servidor(){
	entrada->join();
	delete entrada;
	delete skt;
	delete mundo;
	Log::instancia()->fin_servidor();
	Log::cerrar();
}

void Servidor::aceptar_clientes(){
  /*Socket* aceptado = skt->accept(NULL);
  if (aceptado){
		agregar_cliente(aceptado);
  }
  cerrar_conexiones();*/

  Socket* aceptado;
  for (size_t i = 0; i < 4; i++){
    aceptado = skt->accept(NULL);
    if (!aceptado){
		return;
    }
    agregar_cliente(aceptado);
  }
}

bool Servidor::termino_ejecucion(){
  return entrada->termino();
}

void Servidor::terminar_ejecucion(){
	cerrar_conexiones();
	mundo->terminar_partida();
	//Enviar a cliente msj de cierre del servidor.
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
  Conexion_cliente* c = new Conexion_cliente(cliente_nuevo, id, mundo, this);
  clientes.agregar_cliente(c);
}

void Servidor::empezar_partida(){
	Log::instancia()->inicio_juego();
	mundo->inicializar_partida(clientes.devolver_tamanio());
	mundo->agregar_observador(this);
}

void Servidor::empezar_nivel(int num_nivel){
	mundo->inicializar_nivel(num_nivel);
	clientes.iniciar_nivel(num_nivel);
}

void Servidor::jugar_nivel(){
	if (mundo->esta_jugando_nivel()){
		mundo->jugar();
	}
}

void Servidor::cerrar_conexiones(){
  skt->shutdown(SHUT_RDWR);
}


void Servidor::update(Observable *obs){}

void Servidor::update_estado(Estado e){
	clientes.update_estado(e);
}
