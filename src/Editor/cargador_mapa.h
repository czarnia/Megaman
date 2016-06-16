#ifndef CARGADOR_MAPA_H
#define CARGADOR_MAPA_H

#include <fstream>
#include <vector>

#include "../Servidor/Modelo/coordenada.h"

class Cargador_mapa{
	private:
		std::string root_path;
		int boss;
		int ancho_mapa, alto_mapa;
		std::ifstream mapa_arch;
		std::vector<Coordenada*> coordenada_megaman;
		std::vector<Coordenada*> coordenada_boss;
		std::vector<Coordenada*> coordenadas_mets;
		std::vector<Coordenada*> coordenadas_bloques;
		std::vector<Coordenada*> coordenadas_puas;
		std::vector<Coordenada*> coordenadas_escaleras;
		std::vector<Coordenada*> coordenadas_snippers;
		std::vector<Coordenada*> coordenadas_j_snippers;
		std::vector<Coordenada*> coordenadas_bumby;
		
		//Carga las coordenadas del mapa indicado por el path.
		void cargar_coordenadas();
	public:
		//Dado un path para un nuevo archivo donde se guardará un mapa y una longi-
		//tud en x y otra en y para el mismo, se crea un Cargador_mapa.
		Cargador_mapa(const char *root);
		//Carga un nuevo mapa:
		void cargar_mapa(int id_mapa);
		//Devuelve la coordenada de inicio de los megamans para
		//el mapa especificado.
		std::vector<Coordenada*> get_coordenada_megamans();
		//Devuelve las coordenadas del boss
		//para el mapa especificado.
		std::vector<Coordenada*> get_coordenada_boss();
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
		//Devuelve el ancho del mapa.
		int get_ancho_mapa();
		//Devuelve el alto del mapa.
		int get_alto_mapa();
		//Devuelve el codigo de boss
		int get_boss();
	private:
		std::vector<std::string> parsear_cadena_palabras(std::string cadena);
		//Reinicializa las coordenadas guardadas por el cargador:
		void limpiar_coordenadas();
};

#endif //CARGADOR_MAPA_H
