#ifndef ACCION_UNO_H
#define ACCION_UNO_H

//#include <gtk/gtk.h>
#include <gtkmm.h>
#include "../Comun/socket.h"

class Accion_uno{
  private:
    Gtk::Button *boton;
    Socket* skt;
  public:
    //Crea una accion_dos recibiendo como parametro un socket ya conectado.
    Accion_uno(Socket* conexion);
    //Devuelve el boton asociado a la accion_uno (es decir, aquel que la lanza).
    Gtk::Button *devolver_boton();
  private:
    //La accion que se ejecutara al clickear el boton asociado a la accion_uno.
    void on_button_clicked();
};

#endif //ACCION_UNO_H
