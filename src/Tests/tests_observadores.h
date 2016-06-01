#ifndef TEST_OBSERVADORES_H
#define TEST_OBSERVADORES_H

bool test_observador_personaje_observa_mover(){
	Servidor server(puerto);
	Mapa mapa(12);
	Personaje *m0 = mapa.obtener_pj("megaman0");
	Coordenada coord_m0 = m0->get_coordenada();
	m0->agregar_movimiento(DERECHA);
	m0->update(1, &mapa);
	return false;
}

void run_tests_observadores(){
	print_test_result("TEST OBSERVADOR NOTIFICA CUANDO SE MUEVE EL PERSONAJE", test_observador_personaje_observa_mover());
}

#endif //TEST_OBSERVADORES_H
