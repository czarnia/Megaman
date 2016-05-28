#ifndef TESTS_MAPA_H
#define TESTS_MAPA_H

bool test_mapa_tiene_coordenada(){
	bool passed = true;
	Mapa mapa(10);
	Coordenada c1(0,0);
	passed = mapa.tiene_coordenada(c1);
	Coordenada c2(10,10);
	passed = passed && mapa.tiene_coordenada(c2);
	Coordenada c3(10,11);
	passed = passed && !mapa.tiene_coordenada(c3);
	Coordenada c4(5, 5);
	passed = passed && mapa.tiene_coordenada(c4);
	Coordenada c5(11,3);
	passed = passed && !mapa.tiene_coordenada(c5);
	return passed;
}

bool test_mapa_puedo_ubicar(){
	bool passed = true;
	Mapa mapa(10);
	
	Coordenada c0(3, 3);
	passed = mapa.puede_ubicarse_en(&c0, 2, 2);
	
	Coordenada c1(2, 3);
	passed = !mapa.puede_ubicarse_en(&c1, 2, 2);
		
	Coordenada c2(2, 2);
	passed = passed && !mapa.puede_ubicarse_en(&c2, 2, 2);
	
	return passed;
}

bool test_mapa_puedo_mover(){
	bool passed = true;
	Mapa mapa(10);
	
	Coordenada origen(5, 4);
	Coordenada destino(9, 1);
	Coordenada mas_cercana(6, 3);
	
	mapa.puede_moverse_a(&origen, &destino, 2, 2);
	
	return (destino == mas_cercana);
}

void run_tests_mapa(){
	print_test_result("TEST MAPA TIENE COORDENADAS", test_mapa_tiene_coordenada());
	print_test_result("TEST MAPA PUEDE UBICARSE EN DEVUELVE FALSE SI HAY BLOQUE", test_mapa_puedo_ubicar());
	//print_test_result("TEST MAPA PUEDE MOVERSE DEVUELVE COORDENADA MAS CERCANA A DESTINO", test_mapa_puedo_mover());
}

#endif //TESTS_MAPA_H
