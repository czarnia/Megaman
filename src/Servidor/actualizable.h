#ifndef ACTUALIZABLE_H
#define ACTUALIZABLE_H

class Actualizable{
  public:
    virtual void update(size_t tiempo) = 0;
    virtual ~Actualizable() {}
};

#endif //ACTUALIZABLE_H
