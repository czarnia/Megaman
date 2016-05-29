#ifndef OBSERVADOR_PERSONAJE_H
#define OBSERVADOR_PERSONAJE_H

class ObservadorPersonaje{
	public:
		virtual void update(Personaje *p) = 0;
		virtual ~ObservadorPersonaje() = 0;
}

#endif //OBSERVADOR_PERSONAJE_H
