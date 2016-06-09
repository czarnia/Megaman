#ifndef MANEJADOR_EVENTOS_H
#define MANEJADOR_EVENTOS_H

class Evento_lobby;
class Servidor;

class Manejador_lobby{
  private:
    Servidor* srv;
  public:
    //Dado un servidor, crea un manejador de lobby.
    Manejador_lobby(Servidor *s);
    //Destructor del manejador de lobby.
    ~Manejador_lobby();
    //Dado un evento_lobby, lo ejecuta.
    void ejecutar_evento(Evento_lobby* e);
};

#endif //MANEJADOR_EVENTOS_H
