#include "escritor_mapa.h"
#include "posicion_invalida.h"
#include "../Servidor/Modelo/mapa.h"

Escritor_mapa::Escritor_mapa(std::string path, int long_x, int long_y):
mapa_real(long_x, long_y){ //modificar cuando mapa pase a tener una long en x y otra en
  //mapa_arch.open(path); //y
}

Escritor_mapa::~Escritor_mapa(){
  mapa_arch.close();
}

void Escritor_mapa::agregar_met(Coordenada coord_central){
  /*Met* nuevo_met = new Met(&mapa_real, coord_central, "");
  if (!mapa_real.ubicar(nuevo_met, coord_central)){
    throw Posicion_invalida("Met en posicion invalida");
  }
  int x = coord_central.obtener_abscisa();
  int y = coord_central.obtener_ordenada();
  mapa_arch << "met " << x << " " << y << "\n";*/
}

void Escritor_mapa::agregar_bloque(Coordenada coord_central){
  /*Bloque* nuevo_bloque = new Bloque(coord_central);
  if (!mapa_real.ubicar(nuevo_bloque, coord_central)){
    throw Posicion_invalida("Bloque en posicion invalida");
    return;
  }
  int x = coord_central.obtener_abscisa();
  int y = coord_central.obtener_ordenada();
  mapa_arch << "bloque " << x << " " << y << "\n";*/
}

void Escritor_mapa::agregar_puas(Coordenada coord_central){
  /*Puas* nuevas_puas = new Puas(coord_central);
  if (!mapa_real.ubicar(nuevas_puas, coord_central)){
    throw Posicion_invalida("Puas en posicion invalida");
  }
  int x = coord_central.obtener_abscisa();
  int y = coord_central.obtener_ordenada();
  mapa_arch << "puas " << x << " " << y << "\n";*/
}

void Escritor_mapa::agregar_escaleras(Coordenada inicio, Coordenada fin){
  /*if (inicio.obtener_abscisa() != fin.obtener_abscisa()){
    throw Posicion_invalida("Las escaleras no son horizontales!");
  }
  std::vector<Coordenada> escaleras = inicio.devolver_intermedias_vertical(fin);
  Escalera* nueva_escalera = new Escalera(inicio); //TODO: calcular que coorde-
  //nada usar...
  for (size_t i = 0; i < escaleras.size(); i++){
    if (!mapa_real.puede_ubicarse(nueva_escalera, escaleras[i])){
      throw Posicion_invalida("Escaleras en posicion invalida");
    }
  }
  for (size_t i = 0; i < escaleras.size(); i++){
    mapa_real.ubicar(nueva_escalera, escaleras[i]);
  }
  int x_inicio = inicio.obtener_abscisa();
  int y_inicio = inicio.obtener_ordenada();
  int x_fin = fin.obtener_abscisa();
  int y_fin = fin.obtener_ordenada();
  mapa_arch << "escalera " << x_inicio << " " << y_inicio << " ";
  mapa_arch << x_fin << " " << y_fin << "\n";*/
}

void Escritor_mapa::agregar_inicio_megamans(Coordenada coord_central){
  /*Megaman* nuevo_megaman = new Megaman(&mapa_real, coord_central, "");
  if (!mapa_real.puede_ubicarse(nuevo_megaman, coord_central)){
    throw Posicion_invalida("Inicio megamans en posicion invalida");
  }
  //agregar al megaman/punto inicio al mapa_real.
  int x = coord_central.obtener_abscisa();
  int y = coord_central.obtener_ordenada();
  mapa_arch << "megaman_inicio " << x << " " << y << "\n";*/
}
