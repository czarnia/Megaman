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
include src/Servidor/CMakeFiles/servidor.dir/depend.make

# Include the progress variables for this target.
include src/Servidor/CMakeFiles/servidor.dir/progress.make

# Include the compile flags for this target's objects.
include src/Servidor/CMakeFiles/servidor.dir/flags.make

src/Servidor/CMakeFiles/servidor.dir/celda_aire.cpp.o: src/Servidor/CMakeFiles/servidor.dir/flags.make
src/Servidor/CMakeFiles/servidor.dir/celda_aire.cpp.o: ../src/Servidor/celda_aire.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/eugenia/Documents/TALLER/Megaman/bin/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/Servidor/CMakeFiles/servidor.dir/celda_aire.cpp.o"
	cd /home/eugenia/Documents/TALLER/Megaman/bin/src/Servidor && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/servidor.dir/celda_aire.cpp.o -c /home/eugenia/Documents/TALLER/Megaman/src/Servidor/celda_aire.cpp

src/Servidor/CMakeFiles/servidor.dir/celda_aire.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/servidor.dir/celda_aire.cpp.i"
	cd /home/eugenia/Documents/TALLER/Megaman/bin/src/Servidor && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/eugenia/Documents/TALLER/Megaman/src/Servidor/celda_aire.cpp > CMakeFiles/servidor.dir/celda_aire.cpp.i

src/Servidor/CMakeFiles/servidor.dir/celda_aire.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/servidor.dir/celda_aire.cpp.s"
	cd /home/eugenia/Documents/TALLER/Megaman/bin/src/Servidor && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/eugenia/Documents/TALLER/Megaman/src/Servidor/celda_aire.cpp -o CMakeFiles/servidor.dir/celda_aire.cpp.s

src/Servidor/CMakeFiles/servidor.dir/celda_aire.cpp.o.requires:
.PHONY : src/Servidor/CMakeFiles/servidor.dir/celda_aire.cpp.o.requires

src/Servidor/CMakeFiles/servidor.dir/celda_aire.cpp.o.provides: src/Servidor/CMakeFiles/servidor.dir/celda_aire.cpp.o.requires
	$(MAKE) -f src/Servidor/CMakeFiles/servidor.dir/build.make src/Servidor/CMakeFiles/servidor.dir/celda_aire.cpp.o.provides.build
.PHONY : src/Servidor/CMakeFiles/servidor.dir/celda_aire.cpp.o.provides

src/Servidor/CMakeFiles/servidor.dir/celda_aire.cpp.o.provides.build: src/Servidor/CMakeFiles/servidor.dir/celda_aire.cpp.o

src/Servidor/CMakeFiles/servidor.dir/megaman.cpp.o: src/Servidor/CMakeFiles/servidor.dir/flags.make
src/Servidor/CMakeFiles/servidor.dir/megaman.cpp.o: ../src/Servidor/megaman.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/eugenia/Documents/TALLER/Megaman/bin/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/Servidor/CMakeFiles/servidor.dir/megaman.cpp.o"
	cd /home/eugenia/Documents/TALLER/Megaman/bin/src/Servidor && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/servidor.dir/megaman.cpp.o -c /home/eugenia/Documents/TALLER/Megaman/src/Servidor/megaman.cpp

src/Servidor/CMakeFiles/servidor.dir/megaman.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/servidor.dir/megaman.cpp.i"
	cd /home/eugenia/Documents/TALLER/Megaman/bin/src/Servidor && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/eugenia/Documents/TALLER/Megaman/src/Servidor/megaman.cpp > CMakeFiles/servidor.dir/megaman.cpp.i

src/Servidor/CMakeFiles/servidor.dir/megaman.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/servidor.dir/megaman.cpp.s"
	cd /home/eugenia/Documents/TALLER/Megaman/bin/src/Servidor && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/eugenia/Documents/TALLER/Megaman/src/Servidor/megaman.cpp -o CMakeFiles/servidor.dir/megaman.cpp.s

src/Servidor/CMakeFiles/servidor.dir/megaman.cpp.o.requires:
.PHONY : src/Servidor/CMakeFiles/servidor.dir/megaman.cpp.o.requires

src/Servidor/CMakeFiles/servidor.dir/megaman.cpp.o.provides: src/Servidor/CMakeFiles/servidor.dir/megaman.cpp.o.requires
	$(MAKE) -f src/Servidor/CMakeFiles/servidor.dir/build.make src/Servidor/CMakeFiles/servidor.dir/megaman.cpp.o.provides.build
.PHONY : src/Servidor/CMakeFiles/servidor.dir/megaman.cpp.o.provides

src/Servidor/CMakeFiles/servidor.dir/megaman.cpp.o.provides.build: src/Servidor/CMakeFiles/servidor.dir/megaman.cpp.o

src/Servidor/CMakeFiles/servidor.dir/personaje.cpp.o: src/Servidor/CMakeFiles/servidor.dir/flags.make
src/Servidor/CMakeFiles/servidor.dir/personaje.cpp.o: ../src/Servidor/personaje.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/eugenia/Documents/TALLER/Megaman/bin/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/Servidor/CMakeFiles/servidor.dir/personaje.cpp.o"
	cd /home/eugenia/Documents/TALLER/Megaman/bin/src/Servidor && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/servidor.dir/personaje.cpp.o -c /home/eugenia/Documents/TALLER/Megaman/src/Servidor/personaje.cpp

src/Servidor/CMakeFiles/servidor.dir/personaje.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/servidor.dir/personaje.cpp.i"
	cd /home/eugenia/Documents/TALLER/Megaman/bin/src/Servidor && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/eugenia/Documents/TALLER/Megaman/src/Servidor/personaje.cpp > CMakeFiles/servidor.dir/personaje.cpp.i

src/Servidor/CMakeFiles/servidor.dir/personaje.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/servidor.dir/personaje.cpp.s"
	cd /home/eugenia/Documents/TALLER/Megaman/bin/src/Servidor && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/eugenia/Documents/TALLER/Megaman/src/Servidor/personaje.cpp -o CMakeFiles/servidor.dir/personaje.cpp.s

src/Servidor/CMakeFiles/servidor.dir/personaje.cpp.o.requires:
.PHONY : src/Servidor/CMakeFiles/servidor.dir/personaje.cpp.o.requires

src/Servidor/CMakeFiles/servidor.dir/personaje.cpp.o.provides: src/Servidor/CMakeFiles/servidor.dir/personaje.cpp.o.requires
	$(MAKE) -f src/Servidor/CMakeFiles/servidor.dir/build.make src/Servidor/CMakeFiles/servidor.dir/personaje.cpp.o.provides.build
.PHONY : src/Servidor/CMakeFiles/servidor.dir/personaje.cpp.o.provides

src/Servidor/CMakeFiles/servidor.dir/personaje.cpp.o.provides.build: src/Servidor/CMakeFiles/servidor.dir/personaje.cpp.o

src/Servidor/CMakeFiles/servidor.dir/conexion_cliente.cpp.o: src/Servidor/CMakeFiles/servidor.dir/flags.make
src/Servidor/CMakeFiles/servidor.dir/conexion_cliente.cpp.o: ../src/Servidor/conexion_cliente.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/eugenia/Documents/TALLER/Megaman/bin/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/Servidor/CMakeFiles/servidor.dir/conexion_cliente.cpp.o"
	cd /home/eugenia/Documents/TALLER/Megaman/bin/src/Servidor && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/servidor.dir/conexion_cliente.cpp.o -c /home/eugenia/Documents/TALLER/Megaman/src/Servidor/conexion_cliente.cpp

src/Servidor/CMakeFiles/servidor.dir/conexion_cliente.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/servidor.dir/conexion_cliente.cpp.i"
	cd /home/eugenia/Documents/TALLER/Megaman/bin/src/Servidor && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/eugenia/Documents/TALLER/Megaman/src/Servidor/conexion_cliente.cpp > CMakeFiles/servidor.dir/conexion_cliente.cpp.i

src/Servidor/CMakeFiles/servidor.dir/conexion_cliente.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/servidor.dir/conexion_cliente.cpp.s"
	cd /home/eugenia/Documents/TALLER/Megaman/bin/src/Servidor && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/eugenia/Documents/TALLER/Megaman/src/Servidor/conexion_cliente.cpp -o CMakeFiles/servidor.dir/conexion_cliente.cpp.s

src/Servidor/CMakeFiles/servidor.dir/conexion_cliente.cpp.o.requires:
.PHONY : src/Servidor/CMakeFiles/servidor.dir/conexion_cliente.cpp.o.requires

src/Servidor/CMakeFiles/servidor.dir/conexion_cliente.cpp.o.provides: src/Servidor/CMakeFiles/servidor.dir/conexion_cliente.cpp.o.requires
	$(MAKE) -f src/Servidor/CMakeFiles/servidor.dir/build.make src/Servidor/CMakeFiles/servidor.dir/conexion_cliente.cpp.o.provides.build
.PHONY : src/Servidor/CMakeFiles/servidor.dir/conexion_cliente.cpp.o.provides

src/Servidor/CMakeFiles/servidor.dir/conexion_cliente.cpp.o.provides.build: src/Servidor/CMakeFiles/servidor.dir/conexion_cliente.cpp.o

src/Servidor/CMakeFiles/servidor.dir/coordenada.cpp.o: src/Servidor/CMakeFiles/servidor.dir/flags.make
src/Servidor/CMakeFiles/servidor.dir/coordenada.cpp.o: ../src/Servidor/coordenada.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/eugenia/Documents/TALLER/Megaman/bin/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/Servidor/CMakeFiles/servidor.dir/coordenada.cpp.o"
	cd /home/eugenia/Documents/TALLER/Megaman/bin/src/Servidor && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/servidor.dir/coordenada.cpp.o -c /home/eugenia/Documents/TALLER/Megaman/src/Servidor/coordenada.cpp

src/Servidor/CMakeFiles/servidor.dir/coordenada.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/servidor.dir/coordenada.cpp.i"
	cd /home/eugenia/Documents/TALLER/Megaman/bin/src/Servidor && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/eugenia/Documents/TALLER/Megaman/src/Servidor/coordenada.cpp > CMakeFiles/servidor.dir/coordenada.cpp.i

src/Servidor/CMakeFiles/servidor.dir/coordenada.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/servidor.dir/coordenada.cpp.s"
	cd /home/eugenia/Documents/TALLER/Megaman/bin/src/Servidor && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/eugenia/Documents/TALLER/Megaman/src/Servidor/coordenada.cpp -o CMakeFiles/servidor.dir/coordenada.cpp.s

src/Servidor/CMakeFiles/servidor.dir/coordenada.cpp.o.requires:
.PHONY : src/Servidor/CMakeFiles/servidor.dir/coordenada.cpp.o.requires

src/Servidor/CMakeFiles/servidor.dir/coordenada.cpp.o.provides: src/Servidor/CMakeFiles/servidor.dir/coordenada.cpp.o.requires
	$(MAKE) -f src/Servidor/CMakeFiles/servidor.dir/build.make src/Servidor/CMakeFiles/servidor.dir/coordenada.cpp.o.provides.build
.PHONY : src/Servidor/CMakeFiles/servidor.dir/coordenada.cpp.o.provides

src/Servidor/CMakeFiles/servidor.dir/coordenada.cpp.o.provides.build: src/Servidor/CMakeFiles/servidor.dir/coordenada.cpp.o

src/Servidor/CMakeFiles/servidor.dir/main_server.cpp.o: src/Servidor/CMakeFiles/servidor.dir/flags.make
src/Servidor/CMakeFiles/servidor.dir/main_server.cpp.o: ../src/Servidor/main_server.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/eugenia/Documents/TALLER/Megaman/bin/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/Servidor/CMakeFiles/servidor.dir/main_server.cpp.o"
	cd /home/eugenia/Documents/TALLER/Megaman/bin/src/Servidor && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/servidor.dir/main_server.cpp.o -c /home/eugenia/Documents/TALLER/Megaman/src/Servidor/main_server.cpp

src/Servidor/CMakeFiles/servidor.dir/main_server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/servidor.dir/main_server.cpp.i"
	cd /home/eugenia/Documents/TALLER/Megaman/bin/src/Servidor && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/eugenia/Documents/TALLER/Megaman/src/Servidor/main_server.cpp > CMakeFiles/servidor.dir/main_server.cpp.i

src/Servidor/CMakeFiles/servidor.dir/main_server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/servidor.dir/main_server.cpp.s"
	cd /home/eugenia/Documents/TALLER/Megaman/bin/src/Servidor && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/eugenia/Documents/TALLER/Megaman/src/Servidor/main_server.cpp -o CMakeFiles/servidor.dir/main_server.cpp.s

src/Servidor/CMakeFiles/servidor.dir/main_server.cpp.o.requires:
.PHONY : src/Servidor/CMakeFiles/servidor.dir/main_server.cpp.o.requires

src/Servidor/CMakeFiles/servidor.dir/main_server.cpp.o.provides: src/Servidor/CMakeFiles/servidor.dir/main_server.cpp.o.requires
	$(MAKE) -f src/Servidor/CMakeFiles/servidor.dir/build.make src/Servidor/CMakeFiles/servidor.dir/main_server.cpp.o.provides.build
.PHONY : src/Servidor/CMakeFiles/servidor.dir/main_server.cpp.o.provides

src/Servidor/CMakeFiles/servidor.dir/main_server.cpp.o.provides.build: src/Servidor/CMakeFiles/servidor.dir/main_server.cpp.o

src/Servidor/CMakeFiles/servidor.dir/servidor.cpp.o: src/Servidor/CMakeFiles/servidor.dir/flags.make
src/Servidor/CMakeFiles/servidor.dir/servidor.cpp.o: ../src/Servidor/servidor.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/eugenia/Documents/TALLER/Megaman/bin/CMakeFiles $(CMAKE_PROGRESS_7)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/Servidor/CMakeFiles/servidor.dir/servidor.cpp.o"
	cd /home/eugenia/Documents/TALLER/Megaman/bin/src/Servidor && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/servidor.dir/servidor.cpp.o -c /home/eugenia/Documents/TALLER/Megaman/src/Servidor/servidor.cpp

src/Servidor/CMakeFiles/servidor.dir/servidor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/servidor.dir/servidor.cpp.i"
	cd /home/eugenia/Documents/TALLER/Megaman/bin/src/Servidor && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/eugenia/Documents/TALLER/Megaman/src/Servidor/servidor.cpp > CMakeFiles/servidor.dir/servidor.cpp.i

src/Servidor/CMakeFiles/servidor.dir/servidor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/servidor.dir/servidor.cpp.s"
	cd /home/eugenia/Documents/TALLER/Megaman/bin/src/Servidor && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/eugenia/Documents/TALLER/Megaman/src/Servidor/servidor.cpp -o CMakeFiles/servidor.dir/servidor.cpp.s

src/Servidor/CMakeFiles/servidor.dir/servidor.cpp.o.requires:
.PHONY : src/Servidor/CMakeFiles/servidor.dir/servidor.cpp.o.requires

src/Servidor/CMakeFiles/servidor.dir/servidor.cpp.o.provides: src/Servidor/CMakeFiles/servidor.dir/servidor.cpp.o.requires
	$(MAKE) -f src/Servidor/CMakeFiles/servidor.dir/build.make src/Servidor/CMakeFiles/servidor.dir/servidor.cpp.o.provides.build
.PHONY : src/Servidor/CMakeFiles/servidor.dir/servidor.cpp.o.provides

src/Servidor/CMakeFiles/servidor.dir/servidor.cpp.o.provides.build: src/Servidor/CMakeFiles/servidor.dir/servidor.cpp.o

src/Servidor/CMakeFiles/servidor.dir/escalera.cpp.o: src/Servidor/CMakeFiles/servidor.dir/flags.make
src/Servidor/CMakeFiles/servidor.dir/escalera.cpp.o: ../src/Servidor/escalera.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/eugenia/Documents/TALLER/Megaman/bin/CMakeFiles $(CMAKE_PROGRESS_8)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/Servidor/CMakeFiles/servidor.dir/escalera.cpp.o"
	cd /home/eugenia/Documents/TALLER/Megaman/bin/src/Servidor && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/servidor.dir/escalera.cpp.o -c /home/eugenia/Documents/TALLER/Megaman/src/Servidor/escalera.cpp

src/Servidor/CMakeFiles/servidor.dir/escalera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/servidor.dir/escalera.cpp.i"
	cd /home/eugenia/Documents/TALLER/Megaman/bin/src/Servidor && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/eugenia/Documents/TALLER/Megaman/src/Servidor/escalera.cpp > CMakeFiles/servidor.dir/escalera.cpp.i

src/Servidor/CMakeFiles/servidor.dir/escalera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/servidor.dir/escalera.cpp.s"
	cd /home/eugenia/Documents/TALLER/Megaman/bin/src/Servidor && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/eugenia/Documents/TALLER/Megaman/src/Servidor/escalera.cpp -o CMakeFiles/servidor.dir/escalera.cpp.s

src/Servidor/CMakeFiles/servidor.dir/escalera.cpp.o.requires:
.PHONY : src/Servidor/CMakeFiles/servidor.dir/escalera.cpp.o.requires

src/Servidor/CMakeFiles/servidor.dir/escalera.cpp.o.provides: src/Servidor/CMakeFiles/servidor.dir/escalera.cpp.o.requires
	$(MAKE) -f src/Servidor/CMakeFiles/servidor.dir/build.make src/Servidor/CMakeFiles/servidor.dir/escalera.cpp.o.provides.build
.PHONY : src/Servidor/CMakeFiles/servidor.dir/escalera.cpp.o.provides

src/Servidor/CMakeFiles/servidor.dir/escalera.cpp.o.provides.build: src/Servidor/CMakeFiles/servidor.dir/escalera.cpp.o

src/Servidor/CMakeFiles/servidor.dir/celda_tierra.cpp.o: src/Servidor/CMakeFiles/servidor.dir/flags.make
src/Servidor/CMakeFiles/servidor.dir/celda_tierra.cpp.o: ../src/Servidor/celda_tierra.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/eugenia/Documents/TALLER/Megaman/bin/CMakeFiles $(CMAKE_PROGRESS_9)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/Servidor/CMakeFiles/servidor.dir/celda_tierra.cpp.o"
	cd /home/eugenia/Documents/TALLER/Megaman/bin/src/Servidor && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/servidor.dir/celda_tierra.cpp.o -c /home/eugenia/Documents/TALLER/Megaman/src/Servidor/celda_tierra.cpp

src/Servidor/CMakeFiles/servidor.dir/celda_tierra.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/servidor.dir/celda_tierra.cpp.i"
	cd /home/eugenia/Documents/TALLER/Megaman/bin/src/Servidor && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/eugenia/Documents/TALLER/Megaman/src/Servidor/celda_tierra.cpp > CMakeFiles/servidor.dir/celda_tierra.cpp.i

src/Servidor/CMakeFiles/servidor.dir/celda_tierra.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/servidor.dir/celda_tierra.cpp.s"
	cd /home/eugenia/Documents/TALLER/Megaman/bin/src/Servidor && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/eugenia/Documents/TALLER/Megaman/src/Servidor/celda_tierra.cpp -o CMakeFiles/servidor.dir/celda_tierra.cpp.s

src/Servidor/CMakeFiles/servidor.dir/celda_tierra.cpp.o.requires:
.PHONY : src/Servidor/CMakeFiles/servidor.dir/celda_tierra.cpp.o.requires

src/Servidor/CMakeFiles/servidor.dir/celda_tierra.cpp.o.provides: src/Servidor/CMakeFiles/servidor.dir/celda_tierra.cpp.o.requires
	$(MAKE) -f src/Servidor/CMakeFiles/servidor.dir/build.make src/Servidor/CMakeFiles/servidor.dir/celda_tierra.cpp.o.provides.build
.PHONY : src/Servidor/CMakeFiles/servidor.dir/celda_tierra.cpp.o.provides

src/Servidor/CMakeFiles/servidor.dir/celda_tierra.cpp.o.provides.build: src/Servidor/CMakeFiles/servidor.dir/celda_tierra.cpp.o

src/Servidor/CMakeFiles/servidor.dir/puas.cpp.o: src/Servidor/CMakeFiles/servidor.dir/flags.make
src/Servidor/CMakeFiles/servidor.dir/puas.cpp.o: ../src/Servidor/puas.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/eugenia/Documents/TALLER/Megaman/bin/CMakeFiles $(CMAKE_PROGRESS_10)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/Servidor/CMakeFiles/servidor.dir/puas.cpp.o"
	cd /home/eugenia/Documents/TALLER/Megaman/bin/src/Servidor && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/servidor.dir/puas.cpp.o -c /home/eugenia/Documents/TALLER/Megaman/src/Servidor/puas.cpp

src/Servidor/CMakeFiles/servidor.dir/puas.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/servidor.dir/puas.cpp.i"
	cd /home/eugenia/Documents/TALLER/Megaman/bin/src/Servidor && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/eugenia/Documents/TALLER/Megaman/src/Servidor/puas.cpp > CMakeFiles/servidor.dir/puas.cpp.i

src/Servidor/CMakeFiles/servidor.dir/puas.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/servidor.dir/puas.cpp.s"
	cd /home/eugenia/Documents/TALLER/Megaman/bin/src/Servidor && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/eugenia/Documents/TALLER/Megaman/src/Servidor/puas.cpp -o CMakeFiles/servidor.dir/puas.cpp.s

src/Servidor/CMakeFiles/servidor.dir/puas.cpp.o.requires:
.PHONY : src/Servidor/CMakeFiles/servidor.dir/puas.cpp.o.requires

src/Servidor/CMakeFiles/servidor.dir/puas.cpp.o.provides: src/Servidor/CMakeFiles/servidor.dir/puas.cpp.o.requires
	$(MAKE) -f src/Servidor/CMakeFiles/servidor.dir/build.make src/Servidor/CMakeFiles/servidor.dir/puas.cpp.o.provides.build
.PHONY : src/Servidor/CMakeFiles/servidor.dir/puas.cpp.o.provides

src/Servidor/CMakeFiles/servidor.dir/puas.cpp.o.provides.build: src/Servidor/CMakeFiles/servidor.dir/puas.cpp.o

src/Servidor/CMakeFiles/servidor.dir/met.cpp.o: src/Servidor/CMakeFiles/servidor.dir/flags.make
src/Servidor/CMakeFiles/servidor.dir/met.cpp.o: ../src/Servidor/met.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/eugenia/Documents/TALLER/Megaman/bin/CMakeFiles $(CMAKE_PROGRESS_11)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/Servidor/CMakeFiles/servidor.dir/met.cpp.o"
	cd /home/eugenia/Documents/TALLER/Megaman/bin/src/Servidor && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/servidor.dir/met.cpp.o -c /home/eugenia/Documents/TALLER/Megaman/src/Servidor/met.cpp

src/Servidor/CMakeFiles/servidor.dir/met.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/servidor.dir/met.cpp.i"
	cd /home/eugenia/Documents/TALLER/Megaman/bin/src/Servidor && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/eugenia/Documents/TALLER/Megaman/src/Servidor/met.cpp > CMakeFiles/servidor.dir/met.cpp.i

src/Servidor/CMakeFiles/servidor.dir/met.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/servidor.dir/met.cpp.s"
	cd /home/eugenia/Documents/TALLER/Megaman/bin/src/Servidor && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/eugenia/Documents/TALLER/Megaman/src/Servidor/met.cpp -o CMakeFiles/servidor.dir/met.cpp.s

src/Servidor/CMakeFiles/servidor.dir/met.cpp.o.requires:
.PHONY : src/Servidor/CMakeFiles/servidor.dir/met.cpp.o.requires

src/Servidor/CMakeFiles/servidor.dir/met.cpp.o.provides: src/Servidor/CMakeFiles/servidor.dir/met.cpp.o.requires
	$(MAKE) -f src/Servidor/CMakeFiles/servidor.dir/build.make src/Servidor/CMakeFiles/servidor.dir/met.cpp.o.provides.build
.PHONY : src/Servidor/CMakeFiles/servidor.dir/met.cpp.o.provides

src/Servidor/CMakeFiles/servidor.dir/met.cpp.o.provides.build: src/Servidor/CMakeFiles/servidor.dir/met.cpp.o

src/Servidor/CMakeFiles/servidor.dir/mapa.cpp.o: src/Servidor/CMakeFiles/servidor.dir/flags.make
src/Servidor/CMakeFiles/servidor.dir/mapa.cpp.o: ../src/Servidor/mapa.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/eugenia/Documents/TALLER/Megaman/bin/CMakeFiles $(CMAKE_PROGRESS_12)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/Servidor/CMakeFiles/servidor.dir/mapa.cpp.o"
	cd /home/eugenia/Documents/TALLER/Megaman/bin/src/Servidor && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/servidor.dir/mapa.cpp.o -c /home/eugenia/Documents/TALLER/Megaman/src/Servidor/mapa.cpp

src/Servidor/CMakeFiles/servidor.dir/mapa.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/servidor.dir/mapa.cpp.i"
	cd /home/eugenia/Documents/TALLER/Megaman/bin/src/Servidor && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/eugenia/Documents/TALLER/Megaman/src/Servidor/mapa.cpp > CMakeFiles/servidor.dir/mapa.cpp.i

src/Servidor/CMakeFiles/servidor.dir/mapa.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/servidor.dir/mapa.cpp.s"
	cd /home/eugenia/Documents/TALLER/Megaman/bin/src/Servidor && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/eugenia/Documents/TALLER/Megaman/src/Servidor/mapa.cpp -o CMakeFiles/servidor.dir/mapa.cpp.s

src/Servidor/CMakeFiles/servidor.dir/mapa.cpp.o.requires:
.PHONY : src/Servidor/CMakeFiles/servidor.dir/mapa.cpp.o.requires

src/Servidor/CMakeFiles/servidor.dir/mapa.cpp.o.provides: src/Servidor/CMakeFiles/servidor.dir/mapa.cpp.o.requires
	$(MAKE) -f src/Servidor/CMakeFiles/servidor.dir/build.make src/Servidor/CMakeFiles/servidor.dir/mapa.cpp.o.provides.build
.PHONY : src/Servidor/CMakeFiles/servidor.dir/mapa.cpp.o.provides

src/Servidor/CMakeFiles/servidor.dir/mapa.cpp.o.provides.build: src/Servidor/CMakeFiles/servidor.dir/mapa.cpp.o

# Object files for target servidor
servidor_OBJECTS = \
"CMakeFiles/servidor.dir/celda_aire.cpp.o" \
"CMakeFiles/servidor.dir/megaman.cpp.o" \
"CMakeFiles/servidor.dir/personaje.cpp.o" \
"CMakeFiles/servidor.dir/conexion_cliente.cpp.o" \
"CMakeFiles/servidor.dir/coordenada.cpp.o" \
"CMakeFiles/servidor.dir/main_server.cpp.o" \
"CMakeFiles/servidor.dir/servidor.cpp.o" \
"CMakeFiles/servidor.dir/escalera.cpp.o" \
"CMakeFiles/servidor.dir/celda_tierra.cpp.o" \
"CMakeFiles/servidor.dir/puas.cpp.o" \
"CMakeFiles/servidor.dir/met.cpp.o" \
"CMakeFiles/servidor.dir/mapa.cpp.o"

# External object files for target servidor
servidor_EXTERNAL_OBJECTS =

src/Servidor/servidor: src/Servidor/CMakeFiles/servidor.dir/celda_aire.cpp.o
src/Servidor/servidor: src/Servidor/CMakeFiles/servidor.dir/megaman.cpp.o
src/Servidor/servidor: src/Servidor/CMakeFiles/servidor.dir/personaje.cpp.o
src/Servidor/servidor: src/Servidor/CMakeFiles/servidor.dir/conexion_cliente.cpp.o
src/Servidor/servidor: src/Servidor/CMakeFiles/servidor.dir/coordenada.cpp.o
src/Servidor/servidor: src/Servidor/CMakeFiles/servidor.dir/main_server.cpp.o
src/Servidor/servidor: src/Servidor/CMakeFiles/servidor.dir/servidor.cpp.o
src/Servidor/servidor: src/Servidor/CMakeFiles/servidor.dir/escalera.cpp.o
src/Servidor/servidor: src/Servidor/CMakeFiles/servidor.dir/celda_tierra.cpp.o
src/Servidor/servidor: src/Servidor/CMakeFiles/servidor.dir/puas.cpp.o
src/Servidor/servidor: src/Servidor/CMakeFiles/servidor.dir/met.cpp.o
src/Servidor/servidor: src/Servidor/CMakeFiles/servidor.dir/mapa.cpp.o
src/Servidor/servidor: src/Servidor/CMakeFiles/servidor.dir/build.make
src/Servidor/servidor: src/Comun/libMegaman.a
src/Servidor/servidor: src/Servidor/CMakeFiles/servidor.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable servidor"
	cd /home/eugenia/Documents/TALLER/Megaman/bin/src/Servidor && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/servidor.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/Servidor/CMakeFiles/servidor.dir/build: src/Servidor/servidor
.PHONY : src/Servidor/CMakeFiles/servidor.dir/build

src/Servidor/CMakeFiles/servidor.dir/requires: src/Servidor/CMakeFiles/servidor.dir/celda_aire.cpp.o.requires
src/Servidor/CMakeFiles/servidor.dir/requires: src/Servidor/CMakeFiles/servidor.dir/megaman.cpp.o.requires
src/Servidor/CMakeFiles/servidor.dir/requires: src/Servidor/CMakeFiles/servidor.dir/personaje.cpp.o.requires
src/Servidor/CMakeFiles/servidor.dir/requires: src/Servidor/CMakeFiles/servidor.dir/conexion_cliente.cpp.o.requires
src/Servidor/CMakeFiles/servidor.dir/requires: src/Servidor/CMakeFiles/servidor.dir/coordenada.cpp.o.requires
src/Servidor/CMakeFiles/servidor.dir/requires: src/Servidor/CMakeFiles/servidor.dir/main_server.cpp.o.requires
src/Servidor/CMakeFiles/servidor.dir/requires: src/Servidor/CMakeFiles/servidor.dir/servidor.cpp.o.requires
src/Servidor/CMakeFiles/servidor.dir/requires: src/Servidor/CMakeFiles/servidor.dir/escalera.cpp.o.requires
src/Servidor/CMakeFiles/servidor.dir/requires: src/Servidor/CMakeFiles/servidor.dir/celda_tierra.cpp.o.requires
src/Servidor/CMakeFiles/servidor.dir/requires: src/Servidor/CMakeFiles/servidor.dir/puas.cpp.o.requires
src/Servidor/CMakeFiles/servidor.dir/requires: src/Servidor/CMakeFiles/servidor.dir/met.cpp.o.requires
src/Servidor/CMakeFiles/servidor.dir/requires: src/Servidor/CMakeFiles/servidor.dir/mapa.cpp.o.requires
.PHONY : src/Servidor/CMakeFiles/servidor.dir/requires

src/Servidor/CMakeFiles/servidor.dir/clean:
	cd /home/eugenia/Documents/TALLER/Megaman/bin/src/Servidor && $(CMAKE_COMMAND) -P CMakeFiles/servidor.dir/cmake_clean.cmake
.PHONY : src/Servidor/CMakeFiles/servidor.dir/clean

src/Servidor/CMakeFiles/servidor.dir/depend:
	cd /home/eugenia/Documents/TALLER/Megaman/bin && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/eugenia/Documents/TALLER/Megaman /home/eugenia/Documents/TALLER/Megaman/src/Servidor /home/eugenia/Documents/TALLER/Megaman/bin /home/eugenia/Documents/TALLER/Megaman/bin/src/Servidor /home/eugenia/Documents/TALLER/Megaman/bin/src/Servidor/CMakeFiles/servidor.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/Servidor/CMakeFiles/servidor.dir/depend

