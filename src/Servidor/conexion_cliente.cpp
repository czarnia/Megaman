#include "conexion_cliente.h"

#define TAM_INT 4

enum Codigo {POSICION = 1, VIDA, ENERGIA, CANT_VIDAS, VICTORIA, DERROTA};

Conexion_cliente::Conexion_cliente(Socket* conexion, int id, Juego m) : skt(conexion), id_cliente(id),
rcv(conexion, id, m) {
  rcv.start();
}

void Conexion_cliente::terminar_ejecucion(){
  rcv.terminar_ejecucion();
}

Conexion_cliente::~Conexion_cliente(){
  rcv.join();
}

void Conexion_cliente::enviar_cambio_posicion(Personaje *p, Coordenada *nueva_coord){
	int posicion = POSICION;
	std::string id_pj = p->devolver_id();
	int abscisa = nueva_coord->obtener_abscisa();
	int ordenada = nueva_coord->obtener_ordenada();
	
	skt->send((char*)&posicion, TAM_INT);
	skt->send((char*)&id_pj, TAM_INT);
	skt->send(&abscisa, TAM_INT);
	skt->send(&ordenada, TAM_INT);
}

void Conexion_cliente::enviar_cantidad_vidas(int cantidad){
  int cant_vidas = CANT_VIDAS;
  skt->send((char*)&cant_vidas, TAM_INT);
  skt->send((char*)&cantidad, TAM_INT);
  skt->send("        ", TAM_INT*2);
  //Envio una cadena vacía de TAM_INT*2 caracteres.
}

void Conexion_cliente::enviar_porcentaje_vida(int porcentaje){
  int vida = VIDA;
  skt->send((char*)&vida, TAM_INT);
  skt->send((char*)&porcentaje, TAM_INT);
  skt->send("        ", TAM_INT*2);
  //Envio una cadena vacía de TAM_INT*2 caracteres.
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
