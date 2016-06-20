#include "personaje_pc.h"

bool Personaje_pc::recibe_danio(Bala* ataque){
	return ataque->dania(this);
}
