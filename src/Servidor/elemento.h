#ifndef ELEMENTO_H
#define ELEMENTO_H

class Personaje;

class Elemento{
	public:
		//Dado un personaje, interactua con el mismo.
		virtual void interactuar(Personaje *pj) = 0;
		//Dado un personaje, dice si el mismo puedo ubicarse en una posicion donde
		//hay un elemento.
		virtual bool puede_ocupar(Personaje *pj) = 0;
};

#endif //ELEMENTO_H
