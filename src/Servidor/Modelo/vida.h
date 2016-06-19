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
		//Dado un porcentaje de aumento, lo agrega a la cantidad de vida.
		void ganar(int porcentaje_aumento = VIDA_INICIAL);
		//Dado un porcentaje de reduccion, lo disminuye a la cantidad de vida.
		void perder(int porcentaje_reducion = VIDA_INICIAL);

};

#endif //VIDA_H
