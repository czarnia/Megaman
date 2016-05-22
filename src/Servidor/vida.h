#ifndef VIDA_H
#define VIDA_H

#define VIDA_INICIAL 100

class Vida{
	public:
		Vida();
		int get_porcentaje();
		bool esta_vacia();
		void ganar(int porcentaje_reduccion = VIDA_INICIAL);
		void perder(int porcentaje_aumento = VIDA_INICIAL);
	private:
		int porcentaje;
};

#endif //VIDA_H
