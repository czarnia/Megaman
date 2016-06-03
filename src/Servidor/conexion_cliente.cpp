#include "conexion_cliente.h"
#include <sstream>

#include <iostream>
#include <stdio.h>
#include <string.h>


#define TAM_INT 4

enum Codigo {POSICION = 1, VIDA, ENERGIA, CANT_VIDAS, VICTORIA, DERROTA};

void Conexion_cliente::mandar_bloques(std::vector<Coordenada> b){
	int codigo_bloque = 100;
	int fin_mapa = 6666;
	for(size_t i = 0; i < b.size(); i++){
		int x = b[i].obtener_abscisa();
		int y = b[i].obtener_ordenada();
		skt->send((char*)&codigo_bloque, TAM_INT);
		skt->send((char*)&x, TAM_INT);
		skt->send((char*)&y, TAM_INT);
	}
	skt->send((char*)&fin_mapa, TAM_INT);
}

Conexion_cliente::Conexion_cliente(Socket* conexion, int id, Juego *m) : skt(conexion), id_cliente(id),
rcv(conexion, id, m) {
	char largo_nombre[TAM_INT];
	skt->receive(largo_nombre, TAM_INT);
	int tam = *((int*) largo_nombre);
	char nombre[tam];
	skt->receive(nombre, tam);

	std::cout << "nombre_cliente: " << nombre << "\n";

	skt->send((char*)&id, TAM_INT);
	int long_y = m->long_y_mapa();
	int long_x = m->long_x_mapa();

	skt->send((char*)&long_x, TAM_INT);
	skt->send((char*)&long_y, TAM_INT);

	mandar_bloques(m->bloques());
	int megaman_x = 3; //hardcodeo para que axel pruebe hoy.
	int megaman_y = 6;
	skt->send((char*)&id, TAM_INT);
	skt->send((char*)&megaman_x, TAM_INT);
	skt->send((char*)&megaman_y, TAM_INT);
}



void Conexion_cliente::iniciar_ejecucion(){
	rcv.start();
}

void Conexion_cliente::terminar_ejecucion(){
  rcv.terminar_ejecucion();
}

Conexion_cliente::~Conexion_cliente(){
  rcv.join();
}

void Conexion_cliente::enviar_cambio_posicion(std::string id, int x, int y){
	int posicion = POSICION;
	std::stringstream pos_x, pos_y;
	pos_x << x;
	pos_y << y;
	std::string abscisa = pos_x.str();
	std::string ordenada = pos_y.str();
	skt->send((char*)&posicion, TAM_INT);
	skt->send((char*)&id, TAM_INT);
	skt->send((char*)&abscisa, TAM_INT);
	skt->send((char*)&ordenada, TAM_INT);
}

void Conexion_cliente::enviar_cantidad_vidas(std::string id, int cantidad){
  int cant_vidas = CANT_VIDAS;
  skt->send((char*)&cant_vidas, TAM_INT);
  skt->send((char*)&id, TAM_INT);
  skt->send((char*)&cantidad, TAM_INT);
  skt->send("        ", TAM_INT);
  //Envio una cadena vacía de TAM_INT caracteres.
}

void Conexion_cliente::enviar_porcentaje_vida(std::string id, int porcentaje){
  int vida = VIDA;
  skt->send((char*)&vida, TAM_INT);
  skt->send((char*)&id, TAM_INT);
  skt->send((char*)&porcentaje, TAM_INT);
  skt->send("        ", TAM_INT);
  //Envio una cadena vacía de TAM_INT caracteres.
}

void Conexion_cliente::enviar_porcentaje_energia(int porcentaje){
  int energia = ENERGIA;
  skt->send((char*)&energia, TAM_INT);
  skt->send((char*)&porcentaje, TAM_INT);
  skt->send("        ", TAM_INT*2);
  //Envio una cadena vacía de TAM_INT*2 caracteres.
}

void Conexion_cliente::enviar_victoria(){
  int victoria = VICTORIA;
  skt->send((char*)&victoria, TAM_INT);
  skt->send("            ", TAM_INT*3);
  //Envio una cadena vacía de TAM_INT*3 caracteres.
}

void Conexion_cliente::enviar_gameover(){
  int derrota = DERROTA;
  skt->send((char*)&derrota, TAM_INT);
  skt->send("            ", TAM_INT*3);
  //Envio una cadena vacía de TAM_INT*3 caracteres.
}
