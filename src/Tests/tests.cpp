#ifndef TEST_H
#define TEST_H

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
#include "tests_mover.h"
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
	/*std::cout << "--------------TESTS MAPA------------\n";
	run_tests_mapa();
	std::cout << "------------TESTS COORDENADA--------\n";
	run_tests_coordenadas();*/
	std::cout << "---------TESTS MOVER-------\n";
	run_tests_mover();
	/*std::cout << "------------TESTS MEGAMAN-----------\n";
    print_test_result("TEST MEGAMAN DESPLAZAMIENTO LATERAL", test_megaman_desplazamiento_lateral());
    print_test_result("TEST MEGAMAN DESPLAZAMIENTO LATERAL CON GRAVEDAD", test_megaman_desplazamiento_lateral_con_gravedad());
    print_test_result("TEST MEGAMAN DESPLAZAMIENTO LATERAL Y CAIDA", test_megaman_desplazamiento_y_caida());
    print_test_result("TEST MEGAMAN PASA PUAS Y PIERDE VIDA", test_megaman_pasa_puas_y_pierde_vida());
    */
}


int main(int argc, char *argv[]){
	run_tests();
}
#endif //TEST_H
