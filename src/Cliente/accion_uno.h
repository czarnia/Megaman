#ifndef ACCION_UNO_H
#define ACCION_UNO_H

#include <gtkmm.h>
#include "socket.h"

class Accion_uno{
  private:
    Gtk::Button boton;
    Socket* skt;
  public:
    Accion_uno(Socket* conexion);
    Gtk::Button devolver_boton();
  private:
    void on_button_clicked();
};

#endif //ACCION_UNO_H