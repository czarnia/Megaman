#include "strategy_mover_megaman.h"
#include <iostream>
#include <string>

#define ARRIBA 1
#define ABAJO 2
#define DERECHA 3
#define IZQUIERDA 4
#define SALTAR 5
#define VELOCIDAD_X 10
#define VELOCIDAD_Y 10
#define GRAVEDAD 5
#define VELOCIDAD_SALTO 40

enum estados_pc{MURIENDO, DISPARANDO, RESPAWNEANDO, CORRIENDO, SALTANDO,
		IDLE, ESCALANDO};

StrategyMoverMegaman::StrategyMoverMegaman():
velocidad_x(0),
velocidad_y(0){
	direccion = 0;
}

void StrategyMoverMegaman::mover(Mapa *mapa, Personaje_pc *pj, size_t tiempo){
  if (mapa->esta_en_aire(pj)){
    pj->flotando = true;
    velocidad_y += GRAVEDAD; //valor gravedad.
  }else{
    pj->flotando = false;
  }
  if (velocidad_x == 0 && velocidad_y == 0){
    return;
  }
  Coordenada nueva_coordenada = pj->coordenada;
  if (velocidad_x > 0){
    //std::cout << "MEGAMAN MOVER: derecha \n";
    nueva_coordenada = nueva_coordenada.derecha(VELOCIDAD_X);
    pj->estado_actual = CORRIENDO;
  }
  if (velocidad_x < 0){
    //std::cout << "MEGAMAN MOVER: izquierda \n";
    nueva_coordenada = nueva_coordenada.izquierda(VELOCIDAD_X);
    pj->estado_actual = CORRIENDO;
  }
  if (velocidad_y < 0){
    //std::cout << "MEGAMAN MOVER: arriba \n";
    nueva_coordenada = nueva_coordenada.arriba(VELOCIDAD_Y);
  }
  if (velocidad_y > 0){
    //std::cout << "MEGAMAN MOVER: abajo \n";
    nueva_coordenada = nueva_coordenada.abajo(VELOCIDAD_Y);
    pj->estado_actual = SALTANDO;
  }

  if (mapa->puede_ubicarse(pj, nueva_coordenada)){
    /*std::cout << "MEGAMAN MOVER: PUEDE UBICARSE\n";
	std::cout << "MEGAMAN MOVER: POS FINAL x: " << nueva_coordenada.obtener_abscisa() << "y: "
    << nueva_coordenada.obtener_ordenada() << "\n";*/

    pj->coordenada = nueva_coordenada;
    pj->notificar_observadores();
  }else{
    /*std::cout << "MEGAMAN MOVER: COORDENADA RECHAZADA: " <<  "x: " << nueva_coordenada.obtener_abscisa() << "y: "
    << nueva_coordenada.obtener_ordenada() << "\n";*/
    if (velocidad_x != 0){
		  velocidad_x = 0;
    }
    if (velocidad_y != 0){
		  velocidad_y = 0;
    }
  }
}

void StrategyMoverMegaman::agregar_movimiento(Personaje_pc *pj, int dir){
	direccion = dir;
	//std::cout << "STRATEGY_MOV_MEG: AGREGAR MOVIMIENTO PERSONAJE\n";
	//std::cout << "DIRECCION MOV: " << direccion << "\n";
	if (dir == SALTAR && !pj->flotando){
		//std::cout << "PERSONAJE agregar_mov:caso salto \n";
		velocidad_y -= VELOCIDAD_SALTO;
	}
	if (dir == DERECHA){
		//std::cout << "STRATEGY_MOV_MEG agregar_mov:caso derecha \n";
		velocidad_x += VELOCIDAD_X;
	}
	if (dir == IZQUIERDA){
		//std::cout << "STRATEGY_MOV_MEG agregar_mov:caso izquierda \n";
		velocidad_x -= VELOCIDAD_X;
	}
}

void StrategyMoverMegaman::sacar_movimiento(Personaje_pc *pj, int dir){
	if (direccion == DERECHA){
		//std::cout << "STRATEGY_MOV_MEG sacar_mov: interrumpo mov derecha\n";
		velocidad_x = 0;
	}
	if (direccion == IZQUIERDA){
		//std::cout << "STRATEGY_MOV_MEG sacar_mov: interrumpo mov izquierda \n";
		velocidad_x = 0;
	}
}

StrategyMoverMegaman::~StrategyMoverMegaman(){}
