#ifndef CARGADOR_MAPA_H
#define CARGADOR_MAPA_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "../Servidor/Modelo/coordenada.h"
#include "../Servidor/Modelo/mapa.h"

class Cargador_mapa{
	private:
		Mapa *mapa_real;
		std::ifstream mapa_arch;
		Coordenada coordenada_inicio_megaman;
		Coordenada coordenada_inicio_boss;
		std::vector<Coordenada*> coordenadas_mets;
		std::vector<Coordenada*> coordenadas_bloques;
		std::vector<Coordenada*> coordenadas_puas;
		std::vector<Coordenada*> coordenadas_escaleras;
		std::vector<Coordenada*> coordenadas_snippers;
		std::vector<Coordenada*> coordenadas_j_snippers;
		std::vector<Coordenada*> coordenadas_bumby;
	public:
		//Dado un path para un nuevo archivo donde se guardará un mapa y una longi-
		//tud en x y otra en y para el mismo, se crea un Cargador_mapa.
		Cargador_mapa(const char* path);
		//Devuelve el mapa elegido.
		Mapa *get_mapa();    
		//Carga las coordenadas del mapa indicado por el path.
		void cargar();
		//Devuelve la coordenada de inicio de los megamans para
		//el mapa especificado.
		Coordenada& get_coordenada_megamans();
		//Devuelve las coordenadas del boss
		//para el mapa especificado.
		Coordenada& get_coordenada_boss();
		//Devuelve las coordenadas de los mets para
		//el mapa especificado.
		std::vector<Coordenada*> get_coordenadas_mets();
		//Devuelve las coordenadas de los bloques para
		//el mapa especificado.
		std::vector<Coordenada*> get_coordenadas_bloques();
		//Devuelve las coordenadas de las puas para
		//el mapa especificado.
		std::vector<Coordenada*> get_coordenadas_puas();
		//Devuelve las coordenadas de las escaleras para
		//el mapa especificado.
		std::vector<Coordenada*> get_coordenadas_escaleras(); 
		//Devuelve las coordenadas de los snippers.
		std::vector<Coordenada*> get_coordenadas_snippers(); 
		//Devuelve las coordenadas de los jumping snippers.
		std::vector<Coordenada*> get_coordenadas_j_snippers(); 
		//Devuelve las coordenadas de los bumby.
		std::vector<Coordenada*> get_coordenadas_bumby();
	private:
		std::vector<std::string> parsear_cadena_palabras(std::string cadena);
};

#endif //CARGADOR_MAPA_H
