#ifndef DEFENDIBLE_H
#define DEFENDIBLE_H

class Defendible{
  public:
    //Hace que un defendible ataque.
    virtual void atacar() = 0;
    //Destructor del defendible.
    virtual ~Defendible() {}
};

#endif //DEFENDIBLE_H