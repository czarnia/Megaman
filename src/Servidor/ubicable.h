#ifndef UBICABLE_H
#define UBICABLE_H

class Ubicable{
	public:
		//Devuelve la coordenada central de un ubicable.
		//virtual Coordenada devolver_coordenada_central() = 0;
    //Devuelve todas las coordenadas que ocupa un ubicable.
    virtual std::vector<Coordenada> coordenadas() = 0;
    //Devuelve todas las coordenadas que ocuparía un ubicable si su centro estuvie-
    //ra en c.
    virtual std::vector<Coordenada> coordenadas(Coordenada c) = 0;

		//virtual int devolver_id() = 0;              Euge, te dejo los nombres :)
		//virtual int devolver_id_clase() = 0;

		//virtual int devolver_ancho() = 0;
		//virtual int devolver_alto() = 0;

		//Destructor del ubicable.
    virtual ~Ubicable() {}
};

#endif //UBICABLE_H
