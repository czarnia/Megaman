#ifndef TEST_OBSERVADORES_H
#define TEST_OBSERVADORES_H

#define DERECHA 3

bool test_observador_personaje_observa_mover(){
	Juego juego(12, 1);
	ObservadorPersonaje obs(&juego);
	Mapa mapa(12);
	Personaje *m0 = mapa.obtener_pj("megaman0");
	Coordenada coord_m0 = m0->get_coordenada();
	m0->agregar_observador(&obs);
	m0->agregar_movimiento(DERECHA);
	m0->update(1, &mapa);
	
	return (coord_m0 == obs.get_coordenada());
}

void run_tests_observadores(){
	print_test_result("TEST OBSERVADOR NOTIFICA CUANDO SE MUEVE EL PERSONAJE", test_observador_personaje_observa_mover());
}

#endif //TEST_OBSERVADORES_H
