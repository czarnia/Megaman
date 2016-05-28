#ifndef ACTUALIZABLE_H
#define ACTUALIZABLE_H

#include <cstddef>

class Actualizable{
  public:
    //Hace que pase un tiempo para un actualizable.
    virtual void update(size_t tiempo) = 0;
    //Destructor del actualizable.
    virtual ~Actualizable() {}
};

#endif //ACTUALIZABLE_H
