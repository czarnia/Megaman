#include "cargador_mapa.h"

#include <sstream>
#include <cstdlib>

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

Cargador_mapa::Cargador_mapa(const char* path):
coordenada_inicio_megaman(0,0),
coordenada_inicio_boss(0,0){
  mapa_arch.open(path);
}


void Cargador_mapa::cargar(){
  std::string linea;
  int codigo_obj;
  int x, y;
  //Primero obtengo las dimensiones del mapa
  getline(mapa_arch, linea);
  int ancho = atoi((const char*)&linea[0]);
  int alto =  atoi((const char*)&linea[1]);
  mapa_real = new Mapa(ancho, alto);
  
  //Ahora obtengo las coordenadas de los objetos del mapa.
  while (getline(mapa_arch, linea)){
    std::vector<std::string> linea_parseada = parsear_cadena_palabras(linea);
    if (linea_parseada.size() != 3){ //necesito un código + 2 coordenadas.
      //excepcion!
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
		default:
			coordenada_inicio_boss = *coordenada;
			break;
	}
  }
  mapa_arch.close();
}

Mapa* Cargador_mapa::get_mapa(){
	return mapa_real;
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
