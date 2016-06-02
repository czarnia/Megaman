#include "conexion_cliente.h"
#include <sstream>
#define TAM_INT 4

enum Codigo {POSICION = 1, VIDA, ENERGIA, CANT_VIDAS, VICTORIA, DERROTA};

Conexion_cliente::Conexion_cliente(Socket* conexion, int id, Juego *m) : skt(conexion), id_cliente(id),
rcv(conexion, id, m) {
	skt->send((char*)&id, TAM_INT);
	int long_y = long_y_mapa();
	int long_x = long_x_mapa();

	skt->send((char*)&long_x, TAM_INT);
	skt->send((char*)&long_y, TAM_INT);

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
