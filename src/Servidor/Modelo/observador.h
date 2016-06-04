#ifndef OBSERVADOR_H
#define OBSERVADOR_H

class Observable;

class Observador{
	public:
		virtual void update(Observable *obs) = 0;
};

#endif //OBSERVADOR_H
