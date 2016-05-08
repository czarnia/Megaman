#include "server_procesador_servidor.h"
#include "server_conexion_cliente.h"

#include <vector>
#include <map>
#include <sstream>
#include <string>
#include <iostream>
#include <ostream>

#include <stdlib.h>


Procesador_servidor::Procesador_servidor(){
}

Procesador_servidor::~Procesador_servidor(){
}

void Procesador_servidor::agregar_cliente(Conexion_cliente* cliente){
  (*cliente).start();
  clientes.push_back(cliente);
}

void Procesador_servidor::agregar_temperatura(char* cadena){
}

void Procesador_servidor::join(){
}
