#ifndef TESTS_STRATEGY_MOVER_H
#define TESTS_STRATEGY_MOVER_H

bool test_strategy_mover_lateral(){
	bool passed = true;
	Mapa mapa(10);
	Personaje *m2 = mapa.obtener_pj("megaman2");
	Coordenada *coord_inicial = m2->get_coordenada();
	Evento_mover mover(0,2);
	m2->agregar_evento(&mover);
	m2->update(1);
	Coordenada *coord_final = m2->get_coordenada();
	passed = ((*coord_inicial).derecha() == (*coord_final));
	std::cout << coord_final->obtener_abscisa() << "," << coord_final->obtener_ordenada() << "\n";
	return passed;
}

void run_tests_strategy_mover(){
	print_test_result("TEST STRATEGY MOVER DESPLAZAMIENTO LATERAL", test_strategy_mover_lateral());
}

#endif //TESTS_STRATEGY_MOVER_H
