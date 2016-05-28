#ifndef TESTS_COORDENADA_H
#define TESTS_COORDENADA_H

#include <queue>

bool test_coordenada_camino_minimo(){
	bool passed = true;
	Coordenada origen(5, 4);
	Coordenada destino(10, 2);
	
	std::queue<Coordenada> camino;
	std::queue<Coordenada> camino_esperado;
	
	camino_esperado.push(Coordenada(6,3));
	camino_esperado.push(Coordenada(7,2));
	camino_esperado.push(Coordenada(8,2));
	camino_esperado.push(Coordenada(9,2));
	camino_esperado.push(Coordenada(10,2));
	
	Coordenada::camino_minimo(&origen, &destino, &camino);
	
	while (!camino.empty()){
		Coordenada coord_esperada = camino.front();
		Coordenada coord = camino_esperado.front();
		passed = passed && (coord == coord_esperada);
		camino.pop();
		camino_esperado.pop();
	}
	return passed;
}

void run_tests_coordenadas(){
	print_test_result("TEST COORDENADAS CAMINO MINIMO", test_coordenada_camino_minimo());
}

#endif //TESTS_COORDENADA_H
