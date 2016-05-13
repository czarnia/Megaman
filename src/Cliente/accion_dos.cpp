#include "accion_dos.h"

Accion_dos::Accion_dos(Socket* conexion){
  skt = conexion;
  Gtk::Button boton("Click 2");
  boton.signal_clicked().connect(sigc::ptr_fun(&on_button_clicked));
}

Accion_dos::on_button_clicked(){
  std::string mensaje = "Me hicieron un click (2)!";
  std::cout << mensaje << std::endl;
  skt.send(mensaje.c_str(), mensaje.size());
}

Gtk::Button Accion_dos::devolver_boton(){
  return boton;
}
