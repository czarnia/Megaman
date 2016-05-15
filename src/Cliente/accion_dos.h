#ifndef ACCION_DOS_H
#define ACCION_DOS_H

#include <gtkmm.h>
#include "../Comun/socket.h"

class Accion_dos{
  private:
    Gtk::Button *boton;
    Socket* skt;
  public:
    Accion_dos(Socket* conexion);
    Gtk::Button *devolver_boton();
  private:
    void on_button_clicked();
};

#endif //ACCION_DOS_H
