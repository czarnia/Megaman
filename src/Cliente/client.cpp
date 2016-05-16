#include "../Comun/socket.h"
#include "accion_uno.h"
#include "accion_dos.h"

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
#include <gdk/gdkx.h>
#include <gtkmm.h>
#include <gtkmm/application.h>

int main(int argc, char *argv[]){
	char* hostname = argv[1];
	char* puerto = argv[2];
	Socket* cliente = new Socket(NULL, puerto);
	gtk_init(NULL, NULL);
	
	Gtk::Main kit(NULL, NULL); 
	
	//Me conecto al servidor
	if ((*cliente).conect(hostname, puerto) < 0){
		std::cout << "Problema en conect \n";
		printf("%s \n", strerror(errno));
		return 0;
	}

	char buffer[4];
	cliente->send("Hola", 4);
	cliente->receive(buffer, 4);

	std::cout << buffer << "\n";

	//Aca va el ciclo del cliente
	argc = 1; //SIN ESTO NO ANDA EL Gtk::Application::create!!!!
	Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc, argv, "Ventana.Megaman.Juego");

	Gtk::Window window;
	window.set_title("Megaman");
	window.set_default_size(200, 200);

	Gtk::Box *vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));

	Accion_uno uno(cliente);
	Accion_uno dos(cliente);

	vbox->add(*uno.devolver_boton());
	vbox->add(*dos.devolver_boton());

	window.add(*vbox);

	vbox->show_all();

	app->run(window);

	(*cliente).shutdown(SHUT_RDWR);
	delete cliente;
	return 0;
}
