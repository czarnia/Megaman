#include "accion_dos.h"
#include <gtk/gtk.h>
#include <iostream>

Accion_dos::Accion_dos(Socket* conexion){
  skt = conexion;
  boton = new Gtk::Button("Click 2");
  boton->signal_clicked().connect(sigc::mem_fun(*this, &Accion_dos::on_button_clicked));
}

void Accion_dos::on_button_clicked(){
  std::string mensaje = "Me hicieron un click (2)!";
  std::cout << mensaje << std::endl;
  skt->send(mensaje.c_str(), mensaje.size());
}

Gtk::Button *Accion_dos::devolver_boton(){
  return boton;
}
