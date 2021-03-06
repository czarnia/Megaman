#include "conexion_cliente.h"
#include "../../Modelo/coordenada.h"
#include "../../Modelo/juego.h"
#include <sstream>
#include <cstring>
#include <iostream>
#include <stdio.h>
#include <string.h>

#define TAM_INT 4

#define ALTO_BLOQUE 30
#define ANCHO_BLOQUE 30

enum Codigo {INICIAR_NIVEL, POSICION, VIDA, ENERGIA, CANT_VIDAS,
	CAMBIO_ESTADO, FIN_NIVEL, DERROTA, VICTORIA};
//enum Acciones {ATACAR = 1, SALTAR, ESCALAR, ESCUDO_UP, ESCUDO_DOWN, FRENAR};

Conexion_cliente::Conexion_cliente(Socket* conexion, int id, Juego *m,
Servidor* s): skt(conexion), id_cliente(id),
rcv(conexion, id, m, s), m(m) {
	std::string jugador = obtener_nombre_jugador();
	Log::instancia()->cliente_conectado(jugador);
	skt->send((char*)&id, TAM_INT); //le envio al jugador su id
	//enviar_mapa_inicial(m, id);
}

void Conexion_cliente::enviar_mapa_inicial(){
	enviar_tamanio_mapa(m);
	int fin_mapa = 6666;
	int codigo_mapa = POSICION;
	std::vector<Ubicable*> ubicables = m->devolver_ubicables();
	for (size_t i = 0; i < ubicables.size(); i++){
		Ubicable* ubicable = ubicables[i];
		int tipo = ubicable->get_tipo();
		int id = ubicable->get_id();

		Coordenada central = ubicable->get_coordenada();
		int alto = ubicable->get_alto();
		int ancho = ubicable->get_ancho();
		Coordenada a_enviar = central.arriba(alto/2).izquierda(ancho/2);
		int x = a_enviar.obtener_abscisa();
		int y = a_enviar.obtener_ordenada();
		std::cout << "ENVIO tipo: " << tipo << "id: " << id;
		std::cout << "coord: " << x << "," << y << "\n";
		skt->send((char*)&codigo_mapa, TAM_INT);
		skt->send((char*)&tipo, TAM_INT);
		skt->send((char*)&id, TAM_INT);
		skt->send((char*)&x, TAM_INT);
		skt->send((char*)&y, TAM_INT);
	}
	skt->sendInt(&fin_mapa, TAM_INT);
	m->get_mapa()->activar_npcs();
}

std::string Conexion_cliente::obtener_nombre_jugador(){
	char largo_nombre[TAM_INT];
	skt->receive(largo_nombre, TAM_INT);
	int tam = *((int*) largo_nombre);
	char nombre[tam];
	skt->receive(nombre, tam);

	std::string nombre_j(nombre);
	return nombre_j;
}

void Conexion_cliente::enviar_tamanio_mapa(Juego* m){
	int long_y = m->long_y_mapa()/ALTO_BLOQUE - 1;
	int long_x = m->long_x_mapa()/ANCHO_BLOQUE;

	skt->send((char*)&long_x, TAM_INT);
	skt->send((char*)&long_y, TAM_INT);
}

void Conexion_cliente::iniciar_ejecucion(){
	rcv.start();
}

void Conexion_cliente::terminar_ejecucion(){
	int derrota = DERROTA;
	skt->send((char*)&derrota, TAM_INT);
	skt->send("                ", TAM_INT*4);
  rcv.terminar_ejecucion();
}

void Conexion_cliente::iniciar_nivel(int nivel){
	int iniciar_nivel = INICIAR_NIVEL;
	skt->send((char*)&iniciar_nivel, TAM_INT);
	skt->send((char*)&nivel, TAM_INT);

	enviar_mapa_inicial();
	rcv.iniciar_nivel();
}

void Conexion_cliente::finalizar_nivel(){
	int fin_nivel = FIN_NIVEL;
	skt->send((char*)&fin_nivel, TAM_INT);
	skt->send("                ", TAM_INT*4);
	//Envio una cadena vacía de TAM_INT*4 caracteres.
	rcv.finalizar_nivel();
}


Conexion_cliente::~Conexion_cliente(){
  rcv.join();
}


void Conexion_cliente::update_estado(Estado estado){
	estado.enviar(skt);
}
















/*void Conexion_cliente::update_estado_personaje(int tipo, int id, int estado){
	int cambio_estado = CAMBIO_ESTADO;
	skt->send((char*)&cambio_estado, TAM_INT);
	skt->send((char*)&tipo, TAM_INT);
	skt->send((char*)&id, TAM_INT);
	skt->send((char*)&estado, TAM_INT);
	skt->send("        ", TAM_INT);
}

void Conexion_cliente::enviar_cambio_posicion(int tipo, int id, int x, int y){
	int posicion = POSICION;

	skt->send((char*)&posicion, TAM_INT);
	skt->send((char*)&tipo, TAM_INT);
	skt->send((char*)&id, TAM_INT);
	skt->sendInt(&x, TAM_INT);
	skt->sendInt(&y, TAM_INT);
}

void Conexion_cliente::enviar_cantidad_vidas(int tipo, int id, int cantidad){
  int cant_vidas = CANT_VIDAS;
  skt->send((char*)&cant_vidas, TAM_INT);
  skt->send((char*)&tipo, TAM_INT);
  skt->send((char*)&id, TAM_INT);
  skt->send((char*)&cantidad, TAM_INT);
  skt->send("        ", TAM_INT);
  //Envio una cadena vacía de TAM_INT caracteres.
}

void Conexion_cliente::enviar_porcentaje_vida(int tipo, int id, int porcentaje){
  int vida = VIDA;
  skt->send((char*)&vida, TAM_INT);
  skt->send((char*)&tipo, TAM_INT);
  skt->send((char*)&id, TAM_INT);
  skt->send((char*)&porcentaje, TAM_INT);
  skt->send("    ", TAM_INT);
  //Envio una cadena vacía de TAM_INT caracteres.
}

void Conexion_cliente::enviar_porcentaje_energia(int tipo, int id, int porcentaje){
  int energia = ENERGIA;
  skt->send((char*)&energia, TAM_INT);
  skt->send((char*)&tipo, TAM_INT);
  skt->send((char*)&id, TAM_INT);
  skt->send((char*)&porcentaje, TAM_INT);
  skt->send("    ", TAM_INT);
  //Envio una cadena vacía de TAM_INT caracteres.
}

void Conexion_cliente::enviar_victoria(){
  int victoria = VICTORIA;
  skt->send((char*)&victoria, TAM_INT);
  skt->send("                ", TAM_INT*4);
  //Envio una cadena vacía de TAM_INT*4 caracteres.
}

void Conexion_cliente::enviar_gameover(){
  int derrota = DERROTA;
  skt->send((char*)&derrota, TAM_INT);
  skt->send("                ", TAM_INT*4);
  //Envio una cadena vacía de TAM_INT*4 caracteres.
}*/
