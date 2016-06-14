#include "cargador_mapa.h"
#include <sstream>
#include <string>
#include <iostream>
#include <cstdlib>

#define NOMBRE_ARCH_MAPAS "mapa"
#define EXTENSION_ARCH_MAPAS ".txt"

enum codigos_personajes{MEGAMAN = 1, BUMBY, J_SNIPPER, MET, SNIPPER};
enum codigos_elementos{BLOQUE = 10, PUAS, ESCALERA};
enum codigos_bosses{BOMBMAN = 20, MAGNETMAN, SPARKMAN, RINGMAN, FIREMAN};

//---------------------->Auxiliares<-------------------//

std::vector<std::string> Cargador_mapa::parsear_cadena_palabras(std::string cadena){
  std::istringstream cadena_parseada(cadena);
  std::string palabra;
  std::vector<std::string> v;

  while (cadena_parseada >> palabra){
    v.push_back(palabra);
  }
  return v;
}

//-----------------------------------------------------//

Cargador_mapa::Cargador_mapa(std::string root, int id_mapa):
coordenada_inicio_megaman(0,0),
coordenada_inicio_boss(0,0){
	std::stringstream id;
	id << id_mapa;
	std::string nombre_arch(NOMBRE_ARCH_MAPAS);
	std::string extension_arch(EXTENSION_ARCH_MAPAS);
	std::string full_path = root + nombre_arch + id.str() + extension_arch;
	mapa_arch.open(full_path.c_str());
	ancho_mapa = 0;
	alto_mapa = 0;
	cargar_coordenadas();
}


void Cargador_mapa::cargar_coordenadas(){
  std::string linea;
  int codigo_obj;
  int x = 0, y = 0;
  //Primero obtengo las dimensiones del mapa
  getline(mapa_arch, linea);
  ancho_mapa = atoi((const char*)&linea[0]);
  alto_mapa =  atoi((const char*)&linea[2]);
  
  //Ahora obtengo las coordenadas de los objetos del mapa.
  while (getline(mapa_arch, linea)){
    std::vector<std::string> linea_parseada = parsear_cadena_palabras(linea);
    if (linea_parseada.size() != 3){ //necesito un código + 2 coordenadas.
      //excepcion!
      return;
    }
    codigo_obj = atoi(linea_parseada[0].c_str());
    x = atoi(linea_parseada[1].c_str());
    y = atoi(linea_parseada[2].c_str());
	Coordenada *coordenada = new Coordenada(x, y);
    switch(codigo_obj){
		case MEGAMAN:
			coordenada_inicio_megaman = *coordenada;
			break;
		case BUMBY:
			coordenadas_bumby.push_back(coordenada);
			break;
		case J_SNIPPER:
			coordenadas_bumby.push_back(coordenada);
			break;
		case MET:
			coordenadas_mets.push_back(coordenada);
			break;
		case SNIPPER:
			coordenadas_snippers.push_back(coordenada);
			break;
		case BLOQUE:
			coordenadas_bloques.push_back(coordenada);
			break;
		case ESCALERA:
			coordenadas_escaleras.push_back(coordenada);
			break;
		case PUAS:
			coordenadas_puas.push_back(coordenada);
			break;
		case BOMBMAN:
			coordenada_inicio_boss = *coordenada;
			break;
		case MAGNETMAN:
			coordenada_inicio_boss = *coordenada;
			break;
		case SPARKMAN:
			coordenada_inicio_boss = *coordenada;
			break;
		case RINGMAN:
			coordenada_inicio_boss = *coordenada;
			break;
		case FIREMAN:
			coordenada_inicio_boss = *coordenada;
			break;
	}
  }
  mapa_arch.close();
}
   
Coordenada& Cargador_mapa::get_coordenada_boss(){
	return coordenada_inicio_boss;
}

Coordenada &Cargador_mapa::get_coordenada_megamans(){
	return coordenada_inicio_megaman;
}

std::vector<Coordenada*> Cargador_mapa::get_coordenadas_mets(){
	return coordenadas_mets;
}

std::vector<Coordenada*> Cargador_mapa::get_coordenadas_bloques(){
	return coordenadas_bloques;
}

std::vector<Coordenada*> Cargador_mapa::get_coordenadas_puas(){
	return coordenadas_puas;
}

std::vector<Coordenada*> Cargador_mapa::get_coordenadas_escaleras(){
	return coordenadas_escaleras;
}

std::vector<Coordenada*> Cargador_mapa::get_coordenadas_snippers(){
	return coordenadas_snippers;
}

std::vector<Coordenada*> Cargador_mapa::get_coordenadas_j_snippers(){
	return coordenadas_j_snippers;
}

std::vector<Coordenada*> Cargador_mapa::get_coordenadas_bumby(){
	return coordenadas_bumby;
}	

int Cargador_mapa::get_ancho_mapa(){
	return ancho_mapa;
}

int Cargador_mapa::get_alto_mapa(){
	return alto_mapa;
}


/*Cargador_mapa::Cargador_mapa(char* path){
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
  //Met* nuevo_met = new Met(mapa_real, coord_central, 0);
  //mapa_real->ubicar(nuevo_met, coord_central);
}

void Cargador_mapa::agregar_bloque(Coordenada coord_central){
  Bloque* nuevo_bloque = new Bloque(coord_central);
  mapa_real->ubicar(nuevo_bloque, coord_central);
}

void Cargador_mapa::agregar_puas(Coordenada coord_central){
  Puas* nuevas_puas = new Puas(coord_central);
  mapa_real->ubicar(nuevas_puas, coord_central);
}

void Cargador_mapa::agregar_escalera(Coordenada coord_central){
  Escalera* nueva_escalera = new Escalera(coord_central);
  mapa_real->ubicar(nueva_escalera, coord_central);
}

void Cargador_mapa::agregar_inicio_megamans(Coordenada coord_central){

}*/
