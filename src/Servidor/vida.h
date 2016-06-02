#ifndef VIDA_H
#define VIDA_H

#define VIDA_INICIAL 100

class Vida{
	private:
		int porcentaje;
	public:
		//Crea una vida.
		Vida();
		//Devuelve el porcentaje de vida actual.
		int get_porcentaje();
		//Devuelve si la vida esta vacia.
		bool esta_vacia();
		void ganar(int porcentaje_reduccion = VIDA_INICIAL);
		void perder(int porcentaje_aumento = VIDA_INICIAL);

};

#endif //VIDA_H
