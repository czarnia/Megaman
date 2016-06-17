#ifndef MAPA_H
#define MAPA_H

#include <iosfwd>
#include <cstddef>
#include <map>
#include <vector>

#include "coordenada.h"
#include "actualizable.h"
#include "personaje.h"
#include "bala.h"
#include "ubicable.h"
#include "premio_factory.h"

class Personaje;
class Elemento;
class Bala;

class Mapa{
  private:
	  size_t long_x, long_y;
    std::vector<Coordenada> bloques; //borrar estos bloques!
    std::vector<Bala*> balas;
    std::map<int, Personaje*> personajes;
    std::map<int, std::map<int, std::vector<Elemento*> > > elementos;
    std::map<int, Premio_factory*> premios;
  public:
    //Dados un tamanio crea un mapa con tantas divisiones como indique el tamanio.
    Mapa(size_t long_x, size_t long_y);
    //Destructor del mapa.
    ~Mapa();
    //Devuelve el ancho del mapa.
    int obtener_long_y();
    //Devuelve el ancho del mapa.
    int obtener_long_x();
    //Devuelve true si la coordenada pertenece al mapa y false en el caso con-
    //trario.
    bool tiene_coordenada(Coordenada coordenada);
    //Dado un ubicable y una coordenada, devuelve true si el mismo puede
    //ubicarse en la misma.
    bool puede_ubicarse(Ubicable* ubic, Coordenada c);
    //Dado un personaje y una coordenada, lo ubica en la misma, en caso de no
    //ser posible, devuelve false.
    bool ubicar(Personaje* pj, Coordenada c);
    //Dado un elemento y una coordenada, lo ubica en la misma, en caso de no
    //ser posible, devuelve false.
    bool ubicar(Elemento* elem, Coordenada c);
    //Dado una bala y una coordenada, la ubica en la misma, en caso de no
    //ser posible, devuelve false.
    bool ubicar(Bala* bala, Coordenada c);
    //Recibe un puntero a un bloque y su coordenada
    //y lo ubica en el mapa.
    bool ubicar(Bloque* bloque, Coordenada c);
    //Dado el id de un personaje, lo devuelve.
    Personaje *obtener_pj(int id_pj);
    //Devuelve un vector con todos los actualizables que se ubican en el mapa.
    std::vector<Actualizable*> obtener_actualizables();
    //Devuelve true si abajo de un objeto de un alto determinado hay aire, false
    //en caso contrario.
    bool esta_en_aire(Coordenada coord, size_t alto);
    //Devuelve true si hay tierra en dicha coordenada, false en caso contrario.
    bool hay_tierra(Coordenada coord);
    //Recibe el id de un personaje y lo remueve del mapa.
    void quitar_personaje(int id);
    //Recibe un personaje y lo agrega al mapa.
    void agregar_personaje(Personaje *p);
    //Recibe uns bala y lo agrega al mapa.
    void agregar_bala(Bala *b);
    //Recibe un puntero a una bala y la remueve del mapa.
    void quitar_bala(Bala *b);
    //Recibe un tiempo de update y actualiza el estado de
    //todos los actualizables en el mapa.
    void update(size_t tiempo);
	  //Recibe una coordenada y devuelve true si hay un personaje
	  //posicionado en ella.
    bool hay_personaje(Coordenada *coord);
    //Dado un personaje, hace que el mismo interactue con su entorno.
    void interactuar_con_entorno(Personaje* pj);
    //Devuelve todos los ubicables que tiene un mapa.
    std::vector<Ubicable*> devolver_ubicables();
    //Dada una coordenada, ubica un premio en la misma con una probabilidad de
    //0,31, devuelve true si la ubicacion fue exitosa, false en caso contrario.
    bool ubicar_premio(Coordenada c);

    std::vector<Coordenada> coord_bloques(); //TODO: quizas se flete.
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
