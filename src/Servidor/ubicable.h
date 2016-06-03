#ifndef UBICABLE_H
#define UBICABLE_H

class Ubicable{
	public:
    //Devuelve todas las coordenadas que ocupa un ubicable.
    virtual std::vector<Coordenada> coordenadas() = 0;
    //Devuelve todas las coordenadas que ocuparía un ubicable si su centro estuvie-
    //ra en c.
    virtual std::vector<Coordenada> coordenadas(Coordenada c) = 0;
    //Destructor del ubicable.
    virtual ~Ubicable() {}
};

#endif //UBICABLE_H
