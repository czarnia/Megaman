#include "megaman.h"
#include "arma_megaman.h"
#include <string>
#include <iostream>
#include <sstream>
#include "bala.h"

#define DERECHA 3
#define IZQUIERDA 4
#define MEGAMAN 1

Megaman::Megaman(Mapa *mapa, Coordenada c, Arma_megaman *arma, int id):
Personaje(mapa, c, id){
	armas.push_back(arma);
	arma_act = 0;
	tipo = MEGAMAN;
	movimiento_actual = &movimiento_megaman;
}

void Megaman::update(size_t tiempo){
	Personaje::update(tiempo, mapa);
}

void Megaman::atacar(int dir, Mapa* mapa){
	Bala* bala;
	Coordenada pos_inicial(-1, -1);
	if (dir == DERECHA){
		pos_inicial = coordenada.derecha(ancho/2);
		bala = armas[arma_act]->atacar(dir, 0, pos_inicial);
	}
	if (dir == IZQUIERDA){
		pos_inicial = coordenada.izquierda(ancho/2);
		bala = armas[arma_act]->atacar(dir, 0, pos_inicial);
	}
	mapa->agregar_bala(bala);
	bala->notificar_observadores();
}

void Megaman::mover(size_t tiempo, Mapa* mapa){
	//Me muevo utilizando la estrategia
	//de movimiento actual:
	movimiento_actual->mover(mapa, this);
	//Vuevlo al movimiento normal en caso de que
	//estuviera usando una estrategia especial:
	movimiento_actual = &movimiento_megaman;
	//Elimino todas las estrategias especiales
	//adquiridas hasta el momento:
	movimientos.clear();
	//Interactuo con elementos de la nueva 
	//ubicacion:
	mapa->interactuar_con_entorno(this);
}

void Megaman::agregar_movimiento(int direccion){
	if (movimientos.find(direccion)!= movimientos.end()){
		//Si ya tengo una estrategia para moverme en esta
		//direccion uso esa estrategia:
		movimiento_actual = movimientos.find(direccion)->second;
	}else{
		//Si no tengo una estrategia para moverme
		//en esta direccion agrego la direccion al
		//movimiento normal:
		movimiento_megaman.agregar_movimiento(this, direccion);
		movimiento_actual = &movimiento_megaman;
	}
}

void Megaman::sacar_movimiento(int direccion){
	movimiento_megaman.sacar_movimiento(this, direccion);
}

void Megaman::recibir_ataque(Bala* ataque){
	//ataque->daniar(this);
}

void Megaman::agregar_arma(Arma *arma){
	armas.push_back(arma);
}

 /*if (mapa->esta_en_aire(coordenada, alto)){
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
  }*/
