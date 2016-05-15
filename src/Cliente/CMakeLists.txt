#Setting compilation flags:
set (CMAKE_C_FLAGS "-Wall -q -pedantic")

#Use the package PkgConfig to detect GTK+ headers/library files.
find_package (PkgConfig REQUIRED)

#Set up CMake to use GTK+, tell the compiler where to look
#for headers and to the linker where to look for libraries.
pkg_check_modules (GTK3 REQUIRED gtk+-3.0)
include_directories (${GTK3_INCLUDE_DIRS})
link_directories (${GTK3_LIBRARY_DIRS})

#Set up CMake to use GTKMM, tell the compiler where to look
#for headers and to the linker where to look for libraries.
pkg_check_modules(GTKMM REQUIRED gtkmm-3.0)
link_directories(${GTKMM_INCLUDE_DIRS})
include_directories(${GTKMM_LIBRARY_DIRS})

#Declare variable that combines all *.cpp  and *.h files
#in this directory.
file (GLOB SRCS  *.cpp *.h)

#Creates an executable with all files found
#by file command.
add_executable (cliente ${SRCS})

target_link_libraries (cliente Megaman glibmm-2.4)
