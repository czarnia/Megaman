#include "cargador_mapa.h"

#include "../Servidor/Modelo/mapa.h"
#include "../Servidor/Modelo/met.h"
#include "../Servidor/Modelo/bloque.h"

#include <string>
#include <sstream>
#include <cstdlib>

//---------------------->Auxiliares<-------------------//

std::vector<std::string> parsear_cadena_palabras(std::string cadena){
  std::istringstream cadena_parseada(cadena);
  std::string palabra;
  std::vector<std::string> v;

  while (cadena_parseada >> palabra){
    v.push_back(palabra);
  }
  return v;
}

//-----------------------------------------------------//

Cargador_mapa::Cargador_mapa(char* path){
  mapa_arch.open(path);
  mapa_real = new Mapa(0,0);
}

Cargador_mapa::~Cargador_mapa(){
  mapa_arch.close();
}

Mapa* Cargador_mapa::cargar(){
  std::string linea;
  int codigo_obj;
  int x, y;
  while (getline(mapa_arch, linea)){
    std::vector<std::string> linea_parseada = parsear_cadena_palabras(linea);
    if (linea_parseada.size() != 3){ //necesito un código + 2 coordenadas.
      //excepcion!
    }
    codigo_obj = atoi(linea_parseada[0].c_str());
    x = atoi(linea_parseada[1].c_str());
    y = atoi(linea_parseada[2].c_str());

    std::cout << codigo_obj << x << y << "\n"; //para que no tire warnings
    //acá se llaman a los agregar
  }
  return mapa_real;
}

void Cargador_mapa::agregar_met(Coordenada coord_central){
  Met* nuevo_met = new Met(mapa_real, coord_central, 0);
  mapa_real->ubicar(nuevo_met, coord_central);
}

void Cargador_mapa::agregar_bloque(Coordenada coord_central){
  Bloque* nuevo_bloque = new Bloque(coord_central);
  mapa_real->ubicar(nuevo_bloque, coord_central);
}

void Cargador_mapa::agregar_puas(Coordenada coord_central){
  /*Puas* nuevas_puas = new Puas(coord_central);
  mapa_real->ubicar(nuevas_puas, coord_central);*/
}

void Cargador_mapa::agregar_escalera(Coordenada coord_central){
  /*Escalera* nueva_escalera = new Escalera(coord_central);
  mapa_real->ubicar(nueva_escalera, coord_central);*/
}

void Cargador_mapa::agregar_inicio_megamans(Coordenada coord_central){

}
