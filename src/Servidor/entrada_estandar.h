#ifndef ENTRADA_ESTANDAR_H
#define ENTRADA_ESTANDAR_H

#include "../Comun/hilo.h"
#include <string>

class Entrada_estandar: public Hilo{
  private:
    bool fin;
    std::string fin_entrada;
  public:
    //Dada una cadena de fin, crea una entrada_estandar.
    Entrada_estandar(std::string entrada);
    //Ejecuta el ciclo de la entrada_estandar, leyendo de teclado hasta recibir
    //un fin_entrada.
    virtual void ejecutar();
    //Devuelve true si termino el ejecutar, false en caso contrario.
    bool termino();
    //Destructor una entrada_estandar.
    virtual ~Entrada_estandar();
};

#endif //ENTRADA_ESTANDAR_H
