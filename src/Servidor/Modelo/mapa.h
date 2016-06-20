#ifndef MAPA_H
#define MAPA_H

#include <iosfwd>
#include <cstddef>
#include <map>
#include <vector>

#include "coordenada.h"
#include "actualizable.h"

#include "../Conexion/Arquitectura/log.h"
#include "bala.h"
#include "ubicable.h"
#include "premio_factory.h"

class Personaje;
class Personaje_npc;
class Personaje_pc;
class Elemento;
class Bala;
class Puerta_boss;

class Mapa{
  private:
		size_t long_x, long_y;
		std::vector<Bala*> balas;
		std::map<int, Personaje_pc*> personajes_pc;
		std::map<int, Personaje_npc*> personajes_npc;
		std::vector<Elemento*> elementos;
		std::map<int, Premio_factory*> premios;
		Puerta_boss *puerta_boss;
		int id;
		bool es_nivel;
		
		static int contador_id_mapa;
  public:
    //Dados un tamanio crea un mapa con tantas divisiones como indique el tamanio.
    Mapa(size_t long_x, size_t long_y, bool es_nivel = false);
    //Destructor del mapa.
    ~Mapa();
    //Devuelve el id de mapa que es 0 por default.
    int get_id();
    //Devuelve el ancho del mapa.
    int obtener_long_y();
    //Devuelve el ancho del mapa.
    int obtener_long_x();
    //Activa a todos los npcs del mapa.
    void activar_npcs();
    //Devuelve true si el mapa
    //es un mapa de nivel.
    bool es_mapa_nivel();
    //Devuelve true si la coordenada pertenece al mapa y false en el caso con-
    //trario.
    bool tiene_coordenada(Coordenada coordenada);
    //Dado un ubicable y una coordenada, devuelve true si el mismo puede
    //ubicarse en la misma.
    bool puede_ubicarse(Ubicable* ubic, Coordenada c);
    //Dado un personaje_npc y una coordenada, lo ubica en la misma, en caso de no
    //ser posible, devuelve false.
    bool ubicar(Personaje_npc* pj, Coordenada c);
    //Dado un personaje_pc y una coordenada, lo ubica en la misma, en caso de no
    //ser posible, devuelve false.
    bool ubicar(Personaje_pc* pj, Coordenada c);
    //Dado un elemento y una coordenada, lo ubica en la misma, en caso de no
    //ser posible, devuelve false.
    bool ubicar(Elemento* elem, Coordenada c);
    //Dado una bala y una coordenada, la ubica en la misma, en caso de no
    //ser posible, devuelve false.
    bool ubicar(Bala* bala, Coordenada c);
    //Recibe un puntero a un bloque y su coordenada
    //y lo ubica en el mapa.
    bool ubicar(Bloque* bloque, Coordenada c);
    //Dado el id de un personaje_pc, lo devuelve.
    Personaje *obtener_pj(int id_pj);
    //Devuelve un vector con todos los actualizables que se ubican en el mapa.
    std::vector<Actualizable*> obtener_actualizables();
    //Devuelve true si abajo de un objeto de un alto determinado hay aire, false
    //en caso contrario.
    bool esta_en_aire(Personaje* pj);
    //Recibe el id de un personaje y lo remueve del mapa.
    void quitar_personaje(int id);
    //Recibe un personaje_npc y lo agrega al mapa.
    void agregar_personaje(Personaje_npc *p);
    //Recibe un personaje_pc y lo agrega al mapa.
    void agregar_personaje(Personaje_pc *p);
    //Recibe uns bala y lo agrega al mapa.
    void agregar_bala(Bala *b);
    //Recibe un puntero a una bala y la remueve del mapa.
    void quitar_bala(Bala *b);
    //Recibe un tiempo de update y actualiza el estado de
    //todos los actualizables en el mapa.
    void update(float tiempo);
	//Recibe una coordenada y devuelve true si hay un personaje
	//posicionado en ella.
    bool bala_colisiona_con_pj(Bala *b, Coordenada *coord);
    //Dado un personaje, hace que el mismo interactue con su entorno.
    void interactuar_con_entorno(Personaje* pj);
    //Devuelve todos los ubicables que tiene un mapa.
    std::vector<Ubicable*> devolver_ubicables();
    //Dada una coordenada, ubica un premio en la misma con una probabilidad de
    //0,31, devuelve true si la ubicacion fue exitosa, false en caso contrario.
    bool ubicar_premio(Coordenada c);
	//Ubica una puerta de boss en la coordenada c.
	void ubicar_puerta_boss(Coordenada c);
    //Dado un Personaje_npc* le da la coordenada de un enemigo.
    Coordenada obtener_coordenada_enemigo(Personaje_npc* pj);
    //Devuelve un id para el mapa.
    static int get_id_mapa();
  private:
    //Carga todas las factories de todos los premios disponibles en el juego.
    void cargar_premios_factories();
    //Devuelve true si debe aparecer un premio, false en caso contrario.
    bool toca_premio();
    //Devuelve un premio al azar ubicado en una Coordenada c según las probabi-
    //lidades de aparición de cada uno.
    Premio* premio_al_azar(Coordenada c);
    //Recibe un elemento y las coordenadas donde se desea posicionar al mismo.
    void ocupar_elemento(Elemento& elem, std::vector<Coordenada> &coordenadas);
    //Recibe un vector con coordenadas de donde se quieran agregar las celdas;
    void ocupar_tierra(std::vector<Coordenada> &coordenadas);

};

#endif //MAPA_H
