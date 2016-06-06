#Setting compilation flags:
add_definitions("-g -o0 -Wall -pedantic")

#Use the package PkgConfig to detect GTK+ headers/library files.
#find_package (PkgConfig REQUIRED)

#Set up CMake to use GTK+, tell the compiler where to look
#for headers and to the linker where to look for libraries.
#link_directories (${GTK3_LIBRARY_DIRS})
#include_directories (${GTK3_INCLUDE_DIRS})

#Set up CMake to use GTKMM, tell the compiler where to look
#for headers and to the linker where to look for libraries.
#link_directories(${GTKMM_LIBRARY_DIRS})
#include_directories(${GTKMM_INCLUDE_DIRS})

#pkg_check_modules(GLIB_PKG REQUIRED glibmm-2.4)
#find_path(GLIB_INCLUDE_DIR NAMES glib.h PATH_SUFFIXES glib-2.4)
#link_directories(${GLIB_PKG_LIBRARY_DIRS})
#include_directories(${GLIB_PKG_INCLUDE_DIRS})

#Set up CMake to use SDL, SDL_image:
include(FindPkgConfig)
pkg_search_module(SDL2 REQUIRED sdl2)
find_package(SDL2_ttf REQUIRED)
pkg_search_module(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)
include_directories(
	${SDL2_INCLUDE_DIRS}
	${SDL2IMAGE_INCLUDE_DIRS}
	${SDL_MIXER_INCLUDE_DIRS}
	${SDL2_TTF_INCLUDE_DIR}
)

#Declare variable that combines all *.cpp  and *.h files
#in this directory.
file (GLOB SRCS  *.cpp *.h)

#Creates an executable with all files found
#by file command.
add_executable (cliente ${SRCS})
target_link_libraries (cliente Megaman -pthread ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES} ${SDL_MIXER_LIBRARIES}  ${SDL2_TTF_LIBRARIES})
