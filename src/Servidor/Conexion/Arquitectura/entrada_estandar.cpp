#include "entrada_estandar.h"
#include "servidor.h"

#include <cstdlib>
#include <string>
#include <sstream>
#include <iostream>

Entrada_estandar::Entrada_estandar(std::string entrada, Servidor* srv) :
fin_entrada(entrada), s(srv){
	fin = false;
}

void Entrada_estandar::ejecutar(){
	std::string linea_actual;
	std::getline(std::cin,linea_actual);
	while (linea_actual.compare(fin_entrada) != 0){
		std::getline(std::cin,linea_actual);
	}
	fin = true;
	s->terminar_ejecucion();
}

bool Entrada_estandar::termino(){
	return fin;
}

Entrada_estandar::~Entrada_estandar(){}
