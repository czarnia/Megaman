#ifndef DEFENDIBLE_H
#define DEFENDIBLE_H

class Defendible{
  public:
    virtual void atacar() = 0;
    virtual ~Defendible() {}
};

#endif //DEFENDIBLE_H
