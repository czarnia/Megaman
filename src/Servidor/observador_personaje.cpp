#include "observador_personaje.h"

ObservadorPersonaje::ObservadorPersonaje(Mapa* mapa, Servidor* servidor):
mapa(mapa),
servidor(servidor),
coordenada(0,0){
	cantidad_vidas = 0;
	porcentaje_vida = 0;
	energia = 0;
}

void ObservadorPersonaje::update(Observable *obs){
	Personaje *personaje = (Personaje*)obs;
	std::string id = personaje->devolver_id();
	if (!personaje->esta_vivo()){
		mapa->quitar_personaje(id);
		servidor->enviar_gameover(id);
	}else{
		if (cantidad_vidas != personaje->get_cantidad_vidas()){
			cantidad_vidas = personaje->get_cantidad_vidas();
			porcentaje_vida = personaje->get_porcentaje_vida();
			servidor->enviar_cantidad_vidas(id, cantidad_vidas);
		}
		if (porcentaje_vida != personaje->get_porcentaje_vida()){
			porcentaje_vida = personaje->get_porcentaje_vida();
			servidor->enviar_porcentaje_vida(id, porcentaje_vida);
		}
		if (energia != personaje->get_energia()){
			energia = personaje->get_energia();
			servidor->enviar_porcentaje_energia(id, energia);
		}
		if (!(coordenada == personaje->get_coordenada())){
			//Un personaje p actualizo su posicion.
			int x = (int)personaje->get_coordenada().obtener_abscisa();
			int y = (int)personaje->get_coordenada().obtener_ordenada();
			servidor->enviar_cambio_posicion(id, x, y);
		}
	}
}

