#include "observador_personaje.h"
#include <iostream>
#include <sstream>

ObservadorPersonaje::ObservadorPersonaje(Juego* juego, 
Coordenada *coord_inicial): juego(juego),
coordenada(coord_inicial->obtener_abscisa(),
coord_inicial->obtener_ordenada()){
	cantidad_vidas = 0;
	porcentaje_vida = 0;
	energia = 0;
}

Coordenada ObservadorPersonaje::get_coordenada(){
	return coordenada;
}

void ObservadorPersonaje::update(Observable *obs){
	Personaje *personaje = (Personaje*)obs;
	std::string id = personaje->devolver_id();
	if (!personaje->esta_vivo()){
		std::cout << "OBSERVER_P: PERSONAJE " + id + "MURIO\n";
		juego->murio_personaje(id);
	}else{
		if (cantidad_vidas != personaje->get_cantidad_vidas()){
			std::cout << "OBSERVER_P: PERSONAJE " + id + "ACTUALIZO CANTIDAD VIDAS\n";
			cantidad_vidas = personaje->get_cantidad_vidas();
			porcentaje_vida = personaje->get_porcentaje_vida();
			juego->actualizo_cantidad_vidas(id, cantidad_vidas);
		}
		if (porcentaje_vida != personaje->get_porcentaje_vida()){
			std::cout << "OBSERVER_P: PERSONAJE " + id + "ACTUALIZO % VIDA\n";
			porcentaje_vida = personaje->get_porcentaje_vida();
			juego->actualizo_porcentaje_vida(id, cantidad_vidas);
		}
		if (energia != personaje->get_energia()){
			std::cout << "OBSERVER_P: PERSONAJE " + id + "ACTUALIZO ENERGIA\n";
			energia = personaje->get_energia();
			juego->actualizo_energia(id, energia);
		}
		if (!(coordenada == personaje->get_coordenada())){
			std::cout << "OBSERVER_P: PERSONAJE " + id + "ACTUALIZO POSICION\n";
			std::stringstream inicial;
			inicial << coordenada.obtener_abscisa() << "," << coordenada.obtener_ordenada() << "\n";
			std::cout << "OBSERVER_P: POS INICIAL " + inicial.str() + "\n";
			//Un personaje p actualizo su posicion.
			int x = (int)personaje->get_coordenada().obtener_abscisa();
			int y = (int)personaje->get_coordenada().obtener_ordenada();
			std::stringstream pos_final;
			pos_final << x << "," << y << "\n";
			std::cout << "OBSERVER_P: POS FINAL " + pos_final.str() + "\n";
			juego->actualizo_posicion(id, x, y);
			coordenada = personaje->get_coordenada();
			
		}
	}
}

