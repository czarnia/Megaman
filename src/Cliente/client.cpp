#include "../Comun/socket.h"
#include "accion_uno.h"
#include "accion_dos.h"

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
#include <gtk/gtk.h>

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

	Accion_uno uno(cliente);
	Accion_uno dos(cliente);

	//Aca va el ciclo del cliente

	Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc, argv, "org.gtkmm.examples.base");

	Gtk::Window window;
	window.set_title("Megaman");
	window.set_default_size(200, 200);

	Gtk::Box *vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));

	vbox->add(*uno.devolver_boton());
	vbox->add(*dos.devolver_boton());

	window.add(*vbox);

	vbox->show_all();

	app->run(window);

	(*cliente).shutdown(SHUT_RDWR);
	delete cliente;
	return 0;
}
