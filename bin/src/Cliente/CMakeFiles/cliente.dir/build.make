# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/cmake-gui

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/eugenia/Documents/TALLER/Megaman

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/eugenia/Documents/TALLER/Megaman/bin

# Include any dependencies generated for this target.
include src/Cliente/CMakeFiles/cliente.dir/depend.make

# Include the progress variables for this target.
include src/Cliente/CMakeFiles/cliente.dir/progress.make

# Include the compile flags for this target's objects.
include src/Cliente/CMakeFiles/cliente.dir/flags.make

src/Cliente/CMakeFiles/cliente.dir/client.cpp.o: src/Cliente/CMakeFiles/cliente.dir/flags.make
src/Cliente/CMakeFiles/cliente.dir/client.cpp.o: ../src/Cliente/client.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/eugenia/Documents/TALLER/Megaman/bin/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/Cliente/CMakeFiles/cliente.dir/client.cpp.o"
	cd /home/eugenia/Documents/TALLER/Megaman/bin/src/Cliente && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/cliente.dir/client.cpp.o -c /home/eugenia/Documents/TALLER/Megaman/src/Cliente/client.cpp

src/Cliente/CMakeFiles/cliente.dir/client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cliente.dir/client.cpp.i"
	cd /home/eugenia/Documents/TALLER/Megaman/bin/src/Cliente && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/eugenia/Documents/TALLER/Megaman/src/Cliente/client.cpp > CMakeFiles/cliente.dir/client.cpp.i

src/Cliente/CMakeFiles/cliente.dir/client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cliente.dir/client.cpp.s"
	cd /home/eugenia/Documents/TALLER/Megaman/bin/src/Cliente && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/eugenia/Documents/TALLER/Megaman/src/Cliente/client.cpp -o CMakeFiles/cliente.dir/client.cpp.s

src/Cliente/CMakeFiles/cliente.dir/client.cpp.o.requires:
.PHONY : src/Cliente/CMakeFiles/cliente.dir/client.cpp.o.requires

src/Cliente/CMakeFiles/cliente.dir/client.cpp.o.provides: src/Cliente/CMakeFiles/cliente.dir/client.cpp.o.requires
	$(MAKE) -f src/Cliente/CMakeFiles/cliente.dir/build.make src/Cliente/CMakeFiles/cliente.dir/client.cpp.o.provides.build
.PHONY : src/Cliente/CMakeFiles/cliente.dir/client.cpp.o.provides

src/Cliente/CMakeFiles/cliente.dir/client.cpp.o.provides.build: src/Cliente/CMakeFiles/cliente.dir/client.cpp.o

src/Cliente/CMakeFiles/cliente.dir/ventana.cpp.o: src/Cliente/CMakeFiles/cliente.dir/flags.make
src/Cliente/CMakeFiles/cliente.dir/ventana.cpp.o: ../src/Cliente/ventana.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/eugenia/Documents/TALLER/Megaman/bin/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/Cliente/CMakeFiles/cliente.dir/ventana.cpp.o"
	cd /home/eugenia/Documents/TALLER/Megaman/bin/src/Cliente && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/cliente.dir/ventana.cpp.o -c /home/eugenia/Documents/TALLER/Megaman/src/Cliente/ventana.cpp

src/Cliente/CMakeFiles/cliente.dir/ventana.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cliente.dir/ventana.cpp.i"
	cd /home/eugenia/Documents/TALLER/Megaman/bin/src/Cliente && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/eugenia/Documents/TALLER/Megaman/src/Cliente/ventana.cpp > CMakeFiles/cliente.dir/ventana.cpp.i

src/Cliente/CMakeFiles/cliente.dir/ventana.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cliente.dir/ventana.cpp.s"
	cd /home/eugenia/Documents/TALLER/Megaman/bin/src/Cliente && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/eugenia/Documents/TALLER/Megaman/src/Cliente/ventana.cpp -o CMakeFiles/cliente.dir/ventana.cpp.s

src/Cliente/CMakeFiles/cliente.dir/ventana.cpp.o.requires:
.PHONY : src/Cliente/CMakeFiles/cliente.dir/ventana.cpp.o.requires

src/Cliente/CMakeFiles/cliente.dir/ventana.cpp.o.provides: src/Cliente/CMakeFiles/cliente.dir/ventana.cpp.o.requires
	$(MAKE) -f src/Cliente/CMakeFiles/cliente.dir/build.make src/Cliente/CMakeFiles/cliente.dir/ventana.cpp.o.provides.build
.PHONY : src/Cliente/CMakeFiles/cliente.dir/ventana.cpp.o.provides

src/Cliente/CMakeFiles/cliente.dir/ventana.cpp.o.provides.build: src/Cliente/CMakeFiles/cliente.dir/ventana.cpp.o

src/Cliente/CMakeFiles/cliente.dir/accion_uno.cpp.o: src/Cliente/CMakeFiles/cliente.dir/flags.make
src/Cliente/CMakeFiles/cliente.dir/accion_uno.cpp.o: ../src/Cliente/accion_uno.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/eugenia/Documents/TALLER/Megaman/bin/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/Cliente/CMakeFiles/cliente.dir/accion_uno.cpp.o"
	cd /home/eugenia/Documents/TALLER/Megaman/bin/src/Cliente && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/cliente.dir/accion_uno.cpp.o -c /home/eugenia/Documents/TALLER/Megaman/src/Cliente/accion_uno.cpp

src/Cliente/CMakeFiles/cliente.dir/accion_uno.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cliente.dir/accion_uno.cpp.i"
	cd /home/eugenia/Documents/TALLER/Megaman/bin/src/Cliente && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/eugenia/Documents/TALLER/Megaman/src/Cliente/accion_uno.cpp > CMakeFiles/cliente.dir/accion_uno.cpp.i

src/Cliente/CMakeFiles/cliente.dir/accion_uno.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cliente.dir/accion_uno.cpp.s"
	cd /home/eugenia/Documents/TALLER/Megaman/bin/src/Cliente && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/eugenia/Documents/TALLER/Megaman/src/Cliente/accion_uno.cpp -o CMakeFiles/cliente.dir/accion_uno.cpp.s

src/Cliente/CMakeFiles/cliente.dir/accion_uno.cpp.o.requires:
.PHONY : src/Cliente/CMakeFiles/cliente.dir/accion_uno.cpp.o.requires

src/Cliente/CMakeFiles/cliente.dir/accion_uno.cpp.o.provides: src/Cliente/CMakeFiles/cliente.dir/accion_uno.cpp.o.requires
	$(MAKE) -f src/Cliente/CMakeFiles/cliente.dir/build.make src/Cliente/CMakeFiles/cliente.dir/accion_uno.cpp.o.provides.build
.PHONY : src/Cliente/CMakeFiles/cliente.dir/accion_uno.cpp.o.provides

src/Cliente/CMakeFiles/cliente.dir/accion_uno.cpp.o.provides.build: src/Cliente/CMakeFiles/cliente.dir/accion_uno.cpp.o

src/Cliente/CMakeFiles/cliente.dir/receiver.cpp.o: src/Cliente/CMakeFiles/cliente.dir/flags.make
src/Cliente/CMakeFiles/cliente.dir/receiver.cpp.o: ../src/Cliente/receiver.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/eugenia/Documents/TALLER/Megaman/bin/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/Cliente/CMakeFiles/cliente.dir/receiver.cpp.o"
	cd /home/eugenia/Documents/TALLER/Megaman/bin/src/Cliente && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/cliente.dir/receiver.cpp.o -c /home/eugenia/Documents/TALLER/Megaman/src/Cliente/receiver.cpp

src/Cliente/CMakeFiles/cliente.dir/receiver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cliente.dir/receiver.cpp.i"
	cd /home/eugenia/Documents/TALLER/Megaman/bin/src/Cliente && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/eugenia/Documents/TALLER/Megaman/src/Cliente/receiver.cpp > CMakeFiles/cliente.dir/receiver.cpp.i

src/Cliente/CMakeFiles/cliente.dir/receiver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cliente.dir/receiver.cpp.s"
	cd /home/eugenia/Documents/TALLER/Megaman/bin/src/Cliente && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/eugenia/Documents/TALLER/Megaman/src/Cliente/receiver.cpp -o CMakeFiles/cliente.dir/receiver.cpp.s

src/Cliente/CMakeFiles/cliente.dir/receiver.cpp.o.requires:
.PHONY : src/Cliente/CMakeFiles/cliente.dir/receiver.cpp.o.requires

src/Cliente/CMakeFiles/cliente.dir/receiver.cpp.o.provides: src/Cliente/CMakeFiles/cliente.dir/receiver.cpp.o.requires
	$(MAKE) -f src/Cliente/CMakeFiles/cliente.dir/build.make src/Cliente/CMakeFiles/cliente.dir/receiver.cpp.o.provides.build
.PHONY : src/Cliente/CMakeFiles/cliente.dir/receiver.cpp.o.provides

src/Cliente/CMakeFiles/cliente.dir/receiver.cpp.o.provides.build: src/Cliente/CMakeFiles/cliente.dir/receiver.cpp.o

src/Cliente/CMakeFiles/cliente.dir/accion_dos.cpp.o: src/Cliente/CMakeFiles/cliente.dir/flags.make
src/Cliente/CMakeFiles/cliente.dir/accion_dos.cpp.o: ../src/Cliente/accion_dos.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/eugenia/Documents/TALLER/Megaman/bin/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/Cliente/CMakeFiles/cliente.dir/accion_dos.cpp.o"
	cd /home/eugenia/Documents/TALLER/Megaman/bin/src/Cliente && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/cliente.dir/accion_dos.cpp.o -c /home/eugenia/Documents/TALLER/Megaman/src/Cliente/accion_dos.cpp

src/Cliente/CMakeFiles/cliente.dir/accion_dos.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cliente.dir/accion_dos.cpp.i"
	cd /home/eugenia/Documents/TALLER/Megaman/bin/src/Cliente && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/eugenia/Documents/TALLER/Megaman/src/Cliente/accion_dos.cpp > CMakeFiles/cliente.dir/accion_dos.cpp.i

src/Cliente/CMakeFiles/cliente.dir/accion_dos.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cliente.dir/accion_dos.cpp.s"
	cd /home/eugenia/Documents/TALLER/Megaman/bin/src/Cliente && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/eugenia/Documents/TALLER/Megaman/src/Cliente/accion_dos.cpp -o CMakeFiles/cliente.dir/accion_dos.cpp.s

src/Cliente/CMakeFiles/cliente.dir/accion_dos.cpp.o.requires:
.PHONY : src/Cliente/CMakeFiles/cliente.dir/accion_dos.cpp.o.requires

src/Cliente/CMakeFiles/cliente.dir/accion_dos.cpp.o.provides: src/Cliente/CMakeFiles/cliente.dir/accion_dos.cpp.o.requires
	$(MAKE) -f src/Cliente/CMakeFiles/cliente.dir/build.make src/Cliente/CMakeFiles/cliente.dir/accion_dos.cpp.o.provides.build
.PHONY : src/Cliente/CMakeFiles/cliente.dir/accion_dos.cpp.o.provides

src/Cliente/CMakeFiles/cliente.dir/accion_dos.cpp.o.provides.build: src/Cliente/CMakeFiles/cliente.dir/accion_dos.cpp.o

# Object files for target cliente
cliente_OBJECTS = \
"CMakeFiles/cliente.dir/client.cpp.o" \
"CMakeFiles/cliente.dir/ventana.cpp.o" \
"CMakeFiles/cliente.dir/accion_uno.cpp.o" \
"CMakeFiles/cliente.dir/receiver.cpp.o" \
"CMakeFiles/cliente.dir/accion_dos.cpp.o"

# External object files for target cliente
cliente_EXTERNAL_OBJECTS =

src/Cliente/cliente: src/Cliente/CMakeFiles/cliente.dir/client.cpp.o
src/Cliente/cliente: src/Cliente/CMakeFiles/cliente.dir/ventana.cpp.o
src/Cliente/cliente: src/Cliente/CMakeFiles/cliente.dir/accion_uno.cpp.o
src/Cliente/cliente: src/Cliente/CMakeFiles/cliente.dir/receiver.cpp.o
src/Cliente/cliente: src/Cliente/CMakeFiles/cliente.dir/accion_dos.cpp.o
src/Cliente/cliente: src/Cliente/CMakeFiles/cliente.dir/build.make
src/Cliente/cliente: src/Comun/libMegaman.a
src/Cliente/cliente: src/Cliente/CMakeFiles/cliente.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable cliente"
	cd /home/eugenia/Documents/TALLER/Megaman/bin/src/Cliente && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cliente.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/Cliente/CMakeFiles/cliente.dir/build: src/Cliente/cliente
.PHONY : src/Cliente/CMakeFiles/cliente.dir/build

src/Cliente/CMakeFiles/cliente.dir/requires: src/Cliente/CMakeFiles/cliente.dir/client.cpp.o.requires
src/Cliente/CMakeFiles/cliente.dir/requires: src/Cliente/CMakeFiles/cliente.dir/ventana.cpp.o.requires
src/Cliente/CMakeFiles/cliente.dir/requires: src/Cliente/CMakeFiles/cliente.dir/accion_uno.cpp.o.requires
src/Cliente/CMakeFiles/cliente.dir/requires: src/Cliente/CMakeFiles/cliente.dir/receiver.cpp.o.requires
src/Cliente/CMakeFiles/cliente.dir/requires: src/Cliente/CMakeFiles/cliente.dir/accion_dos.cpp.o.requires
.PHONY : src/Cliente/CMakeFiles/cliente.dir/requires

src/Cliente/CMakeFiles/cliente.dir/clean:
	cd /home/eugenia/Documents/TALLER/Megaman/bin/src/Cliente && $(CMAKE_COMMAND) -P CMakeFiles/cliente.dir/cmake_clean.cmake
.PHONY : src/Cliente/CMakeFiles/cliente.dir/clean

src/Cliente/CMakeFiles/cliente.dir/depend:
	cd /home/eugenia/Documents/TALLER/Megaman/bin && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/eugenia/Documents/TALLER/Megaman /home/eugenia/Documents/TALLER/Megaman/src/Cliente /home/eugenia/Documents/TALLER/Megaman/bin /home/eugenia/Documents/TALLER/Megaman/bin/src/Cliente /home/eugenia/Documents/TALLER/Megaman/bin/src/Cliente/CMakeFiles/cliente.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/Cliente/CMakeFiles/cliente.dir/depend

