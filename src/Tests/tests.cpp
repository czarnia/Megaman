#ifndef TEST_MOVER_H
#define TEST_MOVER_H

#include <string>
#include <iostream>
#include <sstream>

#include "../Servidor/personaje.h"
#include "../Servidor/coordenada.h"
#include "../Servidor/mapa.h"

void print_test_result(std::string nombre_test, bool result){
  std::string state = result? "OK":"ERROR";
  std::cout << nombre_test +": "+ state + "\n";
}

#include "tests_mapa.h"
#include "tests_strategy_mover.h"
#include "tests_coordenada.h"

bool test_megaman_desplazamiento_lateral(){
	bool passed = false;
	return passed;
}

bool test_megaman_desplazamiento_lateral_con_gravedad(){
	bool passed = false;
	return passed;
}

bool test_megaman_desplazamiento_y_caida(){
	bool passed = false;
	return passed;
}

bool test_megaman_pasa_puas_y_pierde_vida(){
	bool passed = false;
	return passed;
}

void run_tests(){
	std::cout << "--------------TESTS MAPA------------\n";
	run_tests_mapa();
	std::cout << "------------TESTS COORDENADA--------\n";
	run_tests_coordenadas();
	std::cout << "---------TESTS STRATEGY MOVER-------\n";
	run_tests_strategy_mover();
	std::cout << "------------TESTS MEGAMAN-----------\n";
    print_test_result("TEST MEGAMAN DESPLAZAMIENTO LATERAL", test_megaman_desplazamiento_lateral());
    print_test_result("TEST MEGAMAN DESPLAZAMIENTO LATERAL CON GRAVEDAD", test_megaman_desplazamiento_lateral_con_gravedad());
    print_test_result("TEST MEGAMAN DESPLAZAMIENTO LATERAL Y CAIDA", test_megaman_desplazamiento_y_caida());
    print_test_result("TEST MEGAMAN PASA PUAS Y PIERDE VIDA", test_megaman_pasa_puas_y_pierde_vida());
}


int main(int argc, char *argv[]){
	run_tests();
}
#endif //TEST_MOVER_H



	/*Mapa mapa(10);
	std::string nombre("megaman1");
	Coordenada coord_inicial(3,3);
	std::string mover_izquierda("<-");
	std::string mover_derecha("<-");
	Celda_aire *celda_p = (Celda_aire*)mapa.obtener_celda(coord_inicial);
	Personaje *p = celda_p->obtener_personaje(nombre);
	
	p->mover(mover_izquierda);
	
	//PIERDE 1 VIDA
	p->mover(mover_izquierda);
	p->mover(mover_derecha);

	//PIERDE 1 VIDA
	p->mover(mover_izquierda);	
	p->mover(mover_derecha);
	
	//PIERDE 1 VIDA
	p->mover(mover_izquierda);
	
	passed = !p->esta_vivo();*/
	
		/*Mapa mapa(10);
	std::string nombre("megaman1");
	Coordenada coord_inicial(3,3);
	Coordenada coord_caida(4,7);
	std::string mover_derecha("->");
	Celda_aire *celda_p = (Celda_aire*)mapa.obtener_celda(coord_inicial);
	Personaje *p = celda_p->obtener_personaje(nombre);
	
	p->mover(mover_derecha);
	
	std::vector<Coordenada*> coords_finales = p->getCoordenadas();
	
	passed = (*coords_finales[0] == coord_caida);*/
	
		/*Mapa mapa(10);
	std::string nombre("megaman0");
	Coordenada coord_inicial(9,6);
	Coordenada coord_caida_1(4,7);
	Coordenada coord_caida_2(3,8);
	std::string mover_izquierda("<-");
	Celda_aire *celda_p = (Celda_aire*)mapa.obtener_celda(coord_inicial);
	Personaje *p = celda_p->obtener_personaje(nombre);
	int celdas_hasta_caida = coord_inicial.obtener_distancia(coord_caida_1);
	
	for (int i = 0; i < celdas_hasta_caida; i++){
		p->mover(mover_izquierda);
	}
	
	std::vector<Coordenada*> coords_finales = p->getCoordenadas();
	passed = (*coords_finales[0] == coord_caida_1);
	
	p->mover(mover_izquierda);
	coords_finales = p->getCoordenadas();
	passed = passed && (*coords_finales[0] == coord_caida_2);*/
	
	/*	Mapa mapa(10);
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
	passed = passed && (*coords_finales[0]== coord);*/
