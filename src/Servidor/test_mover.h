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

bool test_personaje_mover(){
  Mapa mapa(10);
  std::string nombre("megaman0");
  Coordenada coord(9,6);
  std::string senial("<-");
  Celda_aire *celda_p = (Celda_aire*)mapa.obtener_celda(coord);
  Personaje *p = celda_p->obtener_personaje(nombre);
  std::vector<Coordenada*> coords_iniciales = p->getCoordenadas();
  p->mover(senial);
  std::vector<Coordenada*> coords_finales = p->getCoordenadas();
  bool passed = true;
  for (size_t i=0; i < coords_iniciales.size(); i++){
    passed = passed && (coords_iniciales[i]->izquierda() == (*coords_finales[i]));	
  }
  coords_iniciales = coords_finales;
  p->mover(senial);
  coords_finales = p->getCoordenadas();
  for (size_t i=0; i < coords_iniciales.size(); i++){
    passed = passed && (coords_iniciales[i]->izquierda() == (*coords_finales[i]));	
  }
  return passed;
}

void run_tests(){
    print_test_result("TEST PERSONAJE MOVER", test_personaje_mover());
}

#endif //TEST_MOVER_H
