#ifndef TEST_MOVER_H
#define TEST_MOVE_H

#include <string>
#include <ostream>
#include <sstream>
#include "mapa.h"
#include "personaje.h"
#include "celda_aire.h"

void print_test_result(std::string nombre_test, bool result){
  std::string state = result? "OK":"ERROR";
  std::cout << nombre_test +": "+ state + "\n";
}

bool test_megaman_desplazamiento_lateral(){
	bool passed = true;
	
	Mapa mapa(10);
	std::string nombre("megaman0");
	Coordenada coord(9,6);
	std::string mover_izquierda("<-");
	std::string mover_derecha("->");
	Celda_aire *celda_p = (Celda_aire*)mapa.obtener_celda(coord);
	Personaje *p = celda_p->obtener_personaje(nombre);
	std::vector<Coordenada*> coords_iniciales = p->getCoordenadas();

	//MUEVO A IZQUIERDA:
	p->mover(mover_izquierda);
	std::vector<Coordenada*> coords_finales = p->getCoordenadas();
	passed = passed && (coords_iniciales[0]->izquierda() == (*coords_finales[0]));

	//MUEVO A IZQUIERDA:
	coords_iniciales = p->getCoordenadas();
	p->mover(mover_izquierda);
	coords_finales = p->getCoordenadas();
	passed = passed && (coords_iniciales[0]->izquierda() == (*coords_finales[0]));
	
	//VUELVO A POSICION INICIAL:
	p->mover(mover_derecha);
	p->mover(mover_derecha);
	coords_finales = p->getCoordenadas();
	passed = passed && (*coords_finales[0]== coord);

	return passed;
}

bool test_megaman_desplazamiento_lateral_con_gravedad(){
	bool passed = true;
	
	Mapa mapa(10);
	std::string nombre("megaman0");
	Coordenada coord_inicial(9,6);
	Coordenada coord_final(4,7);
	std::string mover_izquierda("<-");
	Celda_aire *celda_p = (Celda_aire*)mapa.obtener_celda(coord_inicial);
	Personaje *p = celda_p->obtener_personaje(nombre);
	std::vector<Coordenada*> coords_iniciales = p->getCoordenadas();
	int celdas_hasta_caida = coord_inicial.obtener_distancia(coord_final);
	
	for (int i = 0; i <= celdas_hasta_caida; i++){
		p->mover(mover_izquierda);
	}
	
	std::vector<Coordenada*> coords_finales = p->getCoordenadas();
	std::cout << coords_finales[0]->obtener_abscisa() << "," << coords_finales[0]->obtener_ordenada() << "\n";
	return (*coords_finales[0]== coord_final);
}

void run_tests(){
    print_test_result("TEST MEGAMAN DESPLAZAMIENTO LATERAL", test_megaman_desplazamiento_lateral());
    print_test_result("TEST MEGAMAN DESPLAZAMIENTO LATERAL CON GRAVEDAD", test_megaman_desplazamiento_lateral_con_gravedad());
}

#endif //TEST_MOVER_H
