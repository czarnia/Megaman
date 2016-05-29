#include "megaman.h"

Megaman::Megaman(Mapa *mapa, Coordenada c, std::string id):
Personaje(mapa, c, id){}

void Megaman::atacar(int direccion, Mapa* mapa){}

void Megaman::mover(size_t tiempo, Mapa* mapa){
  if (velocidad_x == 0 || velocidad_y == 0){
    return;
  }
  Coordenada nueva_coordenada = coordenada;
  if (velocidad_x > 0){
    nueva_coordenada = nueva_coordenada.derecha(1);
  }
  if (velocidad_x < 0){
    nueva_coordenada = nueva_coordenada.izquierda(1);
  }
  if (velocidad_y < 0){
    nueva_coordenada = nueva_coordenada.arriba(1);
  }
  if (velocidad_y > 0){
    nueva_coordenada = nueva_coordenada.abajo(1);
  }

  if (mapa->puede_ubicarse_en(nueva_coordenada, alto, ancho)){
    coordenada = nueva_coordenada;
  }else{
    if (nueva_coordenada.obtener_abscisa() > 0){
      velocidad_x = 0;
    }
    if (nueva_coordenada.obtener_ordenada() > 0){
      velocidad_y = 0;
    }
  }
  if (mapa->esta_en_aire(nueva_coordenada, alto)){
    flotando = true;
    velocidad_y += 1; //valor gravedad.
  }

}

void Megaman::recibir_ataque(/*Bala ataque*/){}
