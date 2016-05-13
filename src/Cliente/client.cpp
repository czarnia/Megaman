#include "socket.h"

#include <gtkmm.h>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <string>
#include <string.h>
#include <strings.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

void on_button_clicked1(){
  std::cout << "Me hicieron un click (1)!" << std::endl;
}

void on_button_clicked2(){
  std::cout << "Me hicieron un click (2)!" << std::endl;
}

int main(int argc, char *argv[]){
  char* id = argv[1];
  char* puerto = argv[2];
  Socket* cliente = new Socket(NULL, puerto);

  //Me conecto al servidor
  if ((*cliente).conect(id, puerto) < 0){
    std::cout << "Problema en conect \n";
    printf("%s \n", strerror(errno));
    return 0;
  }

  //Aca va el ciclo del cliente

  Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc, argv, "org.gtkmm.examples.base");

  Gtk::Window window;
  window.set_title("Megaman");
  window.set_default_size(200, 200);

  Gtk::Box *vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
  window.add(*vbox);

  Gtk::Button boton1("Click 1");
  Gtk::Button boton2("Click 2");

  boton1.signal_clicked().connect(sigc::ptr_fun(&on_button_clicked1));
  boton2.signal_clicked().connect(sigc::ptr_fun(&on_button_clicked2));

  (*vbox).add(boton1);
  (*vbox).add(boton2);

  vbox->show_all();

  app->run(window);

  //

  (*cliente).shutdown(SHUT_RDWR);
  delete cliente;
  return 0;
}
