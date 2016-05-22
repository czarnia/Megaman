#include "celda_tierra.h"
#include <stdio.h>
#include <stdlib.h>

Celda_tierra::Celda_tierra(size_t x, size_t y):
Celda(x, y){}

bool Celda_tierra::puedo_ubicar(){
  return false;
}

Celda_tierra::~Celda_tierra(){}
