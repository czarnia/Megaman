#ifndef ARMA_BOSS_H
#define ARMA_BOSS_H

#include "arma.h"

class Arma_boss : public Arma{
  protected:
		bool equipo_pc;
	public:
    //Dado un Factory_observador_ubicable*, crea una arma_boss.
		Arma_boss(int tipo, int id, Factory_observador_ubicable *fact_ubicables):
    Arma(tipo, id, fact_ubicables){};
    //Cambia al dueño del arma (es decir, a su enemigo).
		virtual void cambiar_enemigo();
    //Destructor del Arma_boss.
    //virtual ~Arma_boss();
};

#endif //ARMA_BOSS_H
