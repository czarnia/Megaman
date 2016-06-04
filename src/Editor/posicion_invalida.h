#ifndef POSICION_INVALIDA_H
#define POSICION_INVALIDA_H

#include <iostream>
#include <exception>

class Posicion_invalida{
  private:
    std::string error;
  public:
    Posicion_invalida(std::string msj) : error(msj) {}
    virtual const char* what() const throw(){
      return error;
    }
};

#endif //POSICION_INVALIDA_H
