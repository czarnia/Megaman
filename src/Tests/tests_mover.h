#ifndef TESTS_MOVER_H
#define TESTS_MOVER_H

#define ARRIBA 1
#define ABAJO 2
#define DERECHA 3
#define IZQUIERDA 4
#define SALTAR 5

bool test_mover_sin_velocidad_no_me_muevo(){
  Mapa mapa(12);
  Personaje *m0 = mapa.obtener_pj("megaman0");
  Coordenada coord_m0 = m0->get_coordenada();
  m0->update(1, &mapa);
  return (coord_m0 == m0->get_coordenada());
}

bool test_mover_a_la_derecha_en_uno(){
  Mapa mapa(12);
  Personaje *m0 = mapa.obtener_pj("megaman0");
  Coordenada coord_m0 = m0->get_coordenada();
  m0->agregar_movimiento(DERECHA);
  m0->update(1, &mapa);
  return (coord_m0 == (m0->get_coordenada()).derecha(1));
}

bool test_mover_a_la_izquierda_en_uno(){
  Mapa mapa(12);
  Personaje *m0 = mapa.obtener_pj("megaman0");
  Coordenada coord_m0 = m0->get_coordenada();
  m0->agregar_movimiento(IZQUIERDA);
  m0->update(1, &mapa);
  return (coord_m0 == (m0->get_coordenada()).izquierda(1));
}

bool test_mover_a_la_derecha_dos_veces_me_caigo(){
  Mapa mapa(12);
  Personaje *m0 = mapa.obtener_pj("megaman0");
  Coordenada coord_m0 = m0->get_coordenada();
  m0->agregar_movimiento(DERECHA);
  m0->update(1, &mapa);
  m0->agregar_movimiento(DERECHA);
  m0->update(1, &mapa);
  m0->update(1, &mapa);
  return (coord_m0 == (m0->get_coordenada()).derecha(2).abajo(1));
}

bool test_mover_si_salto_me_despego_del_piso(){
  Mapa mapa(12);
  Personaje *m0 = mapa.obtener_pj("megaman0");
  Coordenada coord_m0 = m0->get_coordenada();
  m0->agregar_movimiento(SALTAR);
  m0->update(1, &mapa);
  return (coord_m0 == (m0->get_coordenada()).arriba(1));
}

bool test_mover_si_salto_me_despego_del_piso_y_vuelvo(){
  Mapa mapa(12);
  Personaje *m0 = mapa.obtener_pj("megaman0");
  Coordenada coord_m0 = m0->get_coordenada();
  m0->agregar_movimiento(SALTAR);
  m0->update(1, &mapa);
  m0->update(1, &mapa);
  m0->update(1, &mapa);
  m0->update(1, &mapa);
  return (coord_m0 == m0->get_coordenada());
}

bool test_mover_si_salto_vuelvo_y_no_atravieso_el_piso(){
  Mapa mapa(12);
  Personaje *m0 = mapa.obtener_pj("megaman0");
  Coordenada coord_m0 = m0->get_coordenada();
  m0->agregar_movimiento(SALTAR);
  m0->update(1, &mapa);
  m0->update(1, &mapa);
  m0->update(1, &mapa);
  m0->update(1, &mapa);
  m0->update(1, &mapa);
  return (coord_m0 == m0->get_coordenada());
}

void run_tests_mover(){
	print_test_result("TEST EL PJ NO SE MUEVE SIN VELOCIDAD", test_mover_sin_velocidad_no_me_muevo());
	print_test_result("TEST ME MUEVO A LA IZQUIERDA EN UNA UNIDAD",test_mover_a_la_derecha_en_uno());
	print_test_result("TEST ME MUEVO A LA DERECHA EN UNA UNIDAD", test_mover_a_la_izquierda_en_uno());
  print_test_result("TEST SI EL PJ SE MUEVE DONDE NO HAY BLOQUE SE CAE", test_mover_a_la_derecha_dos_veces_me_caigo());
  print_test_result("TEST SI SALTO ME DESPEGO DEL PISO", test_mover_si_salto_me_despego_del_piso());
  print_test_result("TEST SI SALTO ME DESPEGO DEL PISO Y VUELVO", test_mover_si_salto_me_despego_del_piso_y_vuelvo());
  print_test_result("TEST LA GRAVEDAD NO ME HACE ATRAVESAR COSAS", test_mover_si_salto_vuelvo_y_no_atravieso_el_piso());
}

#endif //TESTS_MOVER_H