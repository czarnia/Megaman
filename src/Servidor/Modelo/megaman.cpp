#include "megaman.h"
#include "arma_megaman.h"
#include <string>
#include <iostream>
#include <sstream>
#include "bala.h"

#define DERECHA 3
#define IZQUIERDA 4
#define MEGAMAN 1

Megaman::Megaman(Mapa *mapa, Coordenada c, int id, Factory_observador_ubicable *fact_obs):
Personaje(mapa, c, id, fact_obs){
	arma_act = 1;
	armas.push_back(new Arma_megaman(fact_obs));
	tipo = MEGAMAN;
}

void Megaman::update(size_t tiempo){
	Personaje::update(tiempo, mapa);
}

void Megaman::atacar(int dir, Mapa* mapa){
	Bala* bala;
	Coordenada pos_inicial(-1, -1);
	if (dir == DERECHA){
		pos_inicial = coordenada.derecha(ancho/2);
		bala = armas[arma_act-1]->atacar(1, 0, pos_inicial);
	}
	if (dir == IZQUIERDA){
		pos_inicial = coordenada.izquierda(ancho/2);
		bala = armas[arma_act-1]->atacar(-1, 0, pos_inicial);
	}
	mapa->agregar_bala(bala);
}

void Megaman::mover(size_t tiempo, Mapa* mapa){
  if (mapa->esta_en_aire(coordenada, alto)){
    flotando = true;
    velocidad_y += 1; //valor gravedad.
  }
  if (velocidad_x == 0 && velocidad_y == 0){
    return;
  }
  Coordenada nueva_coordenada = coordenada;
  if (velocidad_x > 0){
    std::cout << "MEGAMAN MOVER: derecha \n";
    nueva_coordenada = nueva_coordenada.derecha(2);
  }
  if (velocidad_x < 0){
    std::cout << "MEGAMAN MOVER: izquierda \n";
    nueva_coordenada = nueva_coordenada.izquierda(2);
  }
  if (velocidad_y < 0){
    std::cout << "MEGAMAN MOVER: arriba \n";
    nueva_coordenada = nueva_coordenada.arriba(2);
  }
  if (velocidad_y > 0){
    std::cout << "MEGAMAN MOVER: abajo \n";
    nueva_coordenada = nueva_coordenada.abajo(2);
  }

  if (mapa->puede_ubicarse(this, nueva_coordenada)){
    std::cout << "MEGAMAN MOVER: PUEDE UBICARSE\n";
    coordenada = nueva_coordenada;
  }else{
    std::cout << "MEGAMAN MOVER: COORDENADA RECHAZADA: " <<  "x: " << nueva_coordenada.obtener_abscisa() << "y: "
    << nueva_coordenada.obtener_ordenada() << "\n";
    if (velocidad_x != 0){
		velocidad_x = 0;
    }
    if (velocidad_y != 0){
		velocidad_y = 0;
    }
  }
}

void Megaman::recibir_ataque(Bala* ataque){
	ataque->daniar(this);
}
