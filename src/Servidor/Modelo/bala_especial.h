#ifndef BALA_ESPECIAL_H
#define BALA_ESPECIAL_H

#include "bala.h"

class Bala_especial: public Bala {
  protected:
		bool equipo_pc;
	public:
    //Dada una direccion en x, una en y (hacia donde se movera) y una coordenada
		//inicial y un id, crea una bala.
		Bala_especial(int dir_x, int dir_y, Coordenada c, int tipo, int id) :
    Bala(dir_x, dir_y, c, tipo, id) {}
    //Dado un personaje pc, dice si puede daniar al mismo.
		virtual bool dania(Personaje_pc* pj);
		//Dado un personaje npc, dice si puede daniar al mismo.
		virtual bool dania(Personaje_npc* pj);
    //Cambia al dueño de la bala (es decir, a su enemigo).
    virtual void cambiar_enemigo();
};

#endif //BALA_ESPECIAL_H
