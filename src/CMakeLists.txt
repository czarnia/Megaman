project (Megaman)
cmake_minimum_required (VERSION 2.8.7)

find_package (PkgConfig REQUIRED)

#GTK, GTKMM, GLIB:
#pkg_check_modules (GTK3 REQUIRED gtk+-3.0)
#pkg_check_modules(GTKMM REQUIRED gtkmm-3.0)
#pkg_check_modules(GLIB_PKG REQUIRED glibmm-2.4)

#Go into indicated subdirectory and look
#for another CMakeLists.txt file:
add_subdirectory(Cliente)
add_subdirectory(Comun)
add_subdirectory(Servidor)
