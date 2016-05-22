#include "accion_uno.h"
#include <iostream>
#include <gtk/gtk.h>

#define FIN_ENTRADA "End"

Accion_uno::Accion_uno(Socket* conexion){
  skt = conexion;
  boton = new Gtk::Button("Click 1");
  boton->signal_clicked().connect(sigc::mem_fun(*this, &Accion_uno::on_button_clicked));
}

void Accion_uno::on_button_clicked(){
  std::string mensaje = "Me hicieron un click (1)!";
  std::string end(FIN_ENTRADA);
  std::cout << mensaje << std::endl << end;
  size_t msg_sz = mensaje.size() + end.size();
  skt->send(mensaje.c_str(), msg_sz);
}

Gtk::Button *Accion_uno::devolver_boton(){
   return boton;
}
