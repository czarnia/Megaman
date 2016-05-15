#include <gtkmm.h>
#include <iostream>
#include <ostream>

void on_button_clicked1()
{
    std::cout << "Me hicieron un click (1)!" << std::endl;
}

void on_button_clicked2()
{
    std::cout << "Me hicieron un click (2)!" << std::endl;
}

int main(int argc, char *argv[])
{
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

  return app->run(window);
}
