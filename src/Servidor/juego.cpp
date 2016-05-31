#include "juego.h"
#include <cstddef>
#include <iosfwd>
#include "../Comun/lock.h"
#include "megaman_factory.h"

#define TIEMPO 5

Juego::Juego(Servidor *s, size_t tamanio, int jugadores): 
mundo(tamanio),
cant_jugadores(jugadores){
  fin_partida = false;
  factories.insert(std::pair<std::string, MegamanFactory>("MEGAMAN", new MegamanFactory(this)));
}

void Juego::inicializar_partida(){
	for (int i = 0; i < cant_jugadores; i++){
		factories["MEGAMAN"].crear(mundo);
	}
	//ACA SE PUEDEN CREAR LOS OTROS PERSONAJES.
}

void Juego::jugar(){
	inicializar_partida();
	while (!fin_partida){
		update(TIEMPO);
	}
}

void Juego::terminar_partida(){
  fin_partida = true;
}

void Juego::update(size_t tiempo){
  /*
  std::vector<Actualizable*> actualizables = mundo.obtener_actualizables();
  for (size_t i = 0; i < actualizables.size(); i++){
    actualizables[i]->update(tiempo, mapa);
  }
  */
}

void Juego::personaje_atacar(std::string id_pj){
  Lock candado(proteccion);
  /*
  Personaje* pj = mundo.obtener_pj(id_pj);
  personaje.atacar(mundo, direccion);
  */
}

void Juego::personaje_mover(std::string id_pj){
  Lock candado(proteccion);
  /*
  Personaje* pj = mundo.obtener_pj(id_pj);
  personaje.mover(mundo, direccion);
  */
}

void Juego::personaje_cambiar_arma(std::string id_pj, int arma){
  Lock candado(proteccion);
  /*
  Personaje* pj = mundo.obtener_pj(id_pj);
  personaje.cambiar_arma(arma);
  */
}

void Juego::murio_personaje(std::string id){
	mapa->quitar_personaje(id);
	servidor->enviar_gameover(id);
	cant_jugadores--;
	if (cant_jugadores == 0){
		terminar_partida();
	}
}

void Juego::actualizo_cantidad_vidas(std::string id, int cantidad_vidas){
	servidor->enviar_cantidad_vidas(id, cantidad_vidas);
}

void Juego::actualizo_porcentaje_vida(std::string id, int porcentaje_vida){
	servidor->enviar_porcentaje_vida(id, porcentaje_vida);
}

void Juego::actualizo_energia(std::string id, int energia){
	servidor->enviar_porcentaje_energia(id, energia);
}

void Juego::actualizo_posicion(std::string id, int x, int y){
	servidor->enviar_cambio_posicion(id, x, y);
}

Juego::~Juego(){}
