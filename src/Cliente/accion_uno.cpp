#include "accion_uno.h"
#include <iostream>

Accion_uno::Accion_uno(Socket* conexion){
  skt = conexion;
  boton = new Gtk::Button("Click 1");
  boton->signal_clicked().connect(sigc::mem_fun(*this, &Accion_uno::on_button_clicked));
}

void Accion_uno::on_button_clicked(){
  std::string mensaje = "Me hicieron un click (1)!";
  std::cout << mensaje << std::endl;
  skt->send(mensaje.c_str(), mensaje.size());
}

Gtk::Button *Accion_uno::devolver_boton(){
   return boton;
}
