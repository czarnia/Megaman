#include "observador_personaje.h"

ObservadorPersonaje::ObservadorPersonaje(Juego* juego):
juego(juego),
coordenada(0,0){
	cantidad_vidas = 0;
	porcentaje_vida = 0;
	energia = 0;
}

void ObservadorPersonaje::update(Observable *obs){
	Personaje *personaje = (Personaje*)obs;
	std::string id = personaje->devolver_id();
	if (!personaje->esta_vivo()){
		juego->murio_personaje(id);
	}else{
		if (cantidad_vidas != personaje->get_cantidad_vidas()){
			cantidad_vidas = personaje->get_cantidad_vidas();
			porcentaje_vida = personaje->get_porcentaje_vida();
			juego->actualizo_cantidad_vidas(id, cantidad_vidas);
		}
		if (porcentaje_vida != personaje->get_porcentaje_vida()){
			porcentaje_vida = personaje->get_porcentaje_vida();
			juego->actualizo_porcentaje_vida(id, cantidad_vidas);
		}
		if (energia != personaje->get_energia()){
			energia = personaje->get_energia();
			juego->actualizo_energia(id, energia);
		}
		if (!(coordenada == personaje->get_coordenada())){
			//Un personaje p actualizo su posicion.
			int x = (int)personaje->get_coordenada().obtener_abscisa();
			int y = (int)personaje->get_coordenada().obtener_ordenada();
			juego->actualizo_posicion(id, x, y);
		}
	}
}

