#include "strategy_mover.h"
#include "personaje.h"
#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <math.h>

//#define GRAVEDAD -0.2
#define GRAVEDAD -0.2

typedef enum {ARRIBA, ABAJO, DERECHA, IZQUIERDA} Direccion; //definir bien los valores segun protocolo!!

StrategyMover::StrategyMover(Mapa *mapa, Personaje *p, bool aplicar_gravedad):
mapa(mapa),
personaje(p),
aplicar_gravedad(aplicar_gravedad){
	gravedad = GRAVEDAD;
}

void StrategyMover::agregar_direccion(int dir){
	bool incluir_dir = true;
	for(size_t i = 0; i < direcciones.size(); i++){
		if (direcciones[i] == dir){
			incluir_dir = false;
		}
	}
	if (incluir_dir) direcciones.push_back(dir);
}

void StrategyMover::mover(size_t tiempo){
	int delta_y = 0;
	int delta_x = 0;
	Coordenada *actual = personaje->get_coordenada();
	
	for(size_t i = 0; i < direcciones.size(); i++){
		switch(direcciones[i]){
			case ARRIBA:
				delta_y += (personaje->velocidad_y*tiempo);
				break;
			case ABAJO:
				delta_y += (personaje->velocidad_y*tiempo)*(-1);
				break;
			case DERECHA:
				delta_x += (personaje->velocidad_x*tiempo);
				std::cout << "DELTA X " << delta_x << "\n";
				break;
			case IZQUIERDA:
				delta_x += (personaje->velocidad_x*tiempo)*(-1);
				break;
		}
	}	
	Coordenada abajo = actual->abajo();
	if (aplicar_gravedad && mapa->puede_ubicarse_en(&abajo, personaje->alto, personaje->ancho)){ 
		delta_y += GRAVEDAD*0.5*pow(tiempo,2);
		personaje->velocidad_y += GRAVEDAD*tiempo + personaje->velocidad_y;
		std::cout << "DELTA Y " << delta_y << "\n";
	}
	
	int x_actual = actual->obtener_abscisa();
	int y_actual = actual->obtener_ordenada();
	Coordenada *nueva_coord = new Coordenada(x_actual + delta_x, y_actual + delta_y);
	
	//
	std::cout << "ORIGEN: " << x_actual << "," << y_actual << "\n";
	std::cout << "DESTINO: " << nueva_coord->obtener_abscisa() << "," << nueva_coord->obtener_ordenada() << "\n";
	//
		
	//El mapa posiciona nueva_coord en la coordenada mas cercana a la que puedo mover.
	mapa->puede_moverse_a(actual, nueva_coord, personaje->alto, personaje->ancho);
	
	//Si llegue a un piso hay que actualizar velocidad_y = 0!!!
	bool no_cai = ((actual->obtener_ordenada() - nueva_coord->obtener_ordenada()) == 0);
	if (no_cai){
		personaje->velocidad_y = 0;
	}
	
	//
	std::cout << "MAS CERCANA: " << nueva_coord->obtener_abscisa() << "," << nueva_coord->obtener_ordenada() << "\n";
	//
	*(personaje->coordenada) = (*nueva_coord);
	direcciones.erase(direcciones.begin(), direcciones.end());
}
