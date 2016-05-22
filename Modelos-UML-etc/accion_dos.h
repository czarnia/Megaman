#ifndef ACCION_DOS_H
#define ACCION_DOS_H

#include <gtkmm.h>
#include "../Comun/socket.h"

class Accion_dos{
  private:
    Gtk::Button *boton;
    Socket* skt;
  public:
    //Crea una accion_dos recibiendo como parametro un socket ya conectado.
    Accion_dos(Socket* conexion);
    //Devuelve el boton asociado a la accion_dos (es decir, aquel que la lanza).
    Gtk::Button *devolver_boton();
  private:
    //La accion que se ejecutara al clickear el boton asociado a la accion_dos.
    void on_button_clicked();
};

#endif //ACCION_DOS_H
