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

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ana/Desktop/Megaman/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ana/Desktop/Megaman

# Include any dependencies generated for this target.
include Cliente/CMakeFiles/cliente.dir/depend.make

# Include the progress variables for this target.
include Cliente/CMakeFiles/cliente.dir/progress.make

# Include the compile flags for this target's objects.
include Cliente/CMakeFiles/cliente.dir/flags.make

Cliente/CMakeFiles/cliente.dir/receiver.cpp.o: Cliente/CMakeFiles/cliente.dir/flags.make
Cliente/CMakeFiles/cliente.dir/receiver.cpp.o: src/Cliente/receiver.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ana/Desktop/Megaman/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object Cliente/CMakeFiles/cliente.dir/receiver.cpp.o"
	cd /home/ana/Desktop/Megaman/Cliente && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/cliente.dir/receiver.cpp.o -c /home/ana/Desktop/Megaman/src/Cliente/receiver.cpp

Cliente/CMakeFiles/cliente.dir/receiver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cliente.dir/receiver.cpp.i"
	cd /home/ana/Desktop/Megaman/Cliente && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/ana/Desktop/Megaman/src/Cliente/receiver.cpp > CMakeFiles/cliente.dir/receiver.cpp.i

Cliente/CMakeFiles/cliente.dir/receiver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cliente.dir/receiver.cpp.s"
	cd /home/ana/Desktop/Megaman/Cliente && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/ana/Desktop/Megaman/src/Cliente/receiver.cpp -o CMakeFiles/cliente.dir/receiver.cpp.s

Cliente/CMakeFiles/cliente.dir/receiver.cpp.o.requires:
.PHONY : Cliente/CMakeFiles/cliente.dir/receiver.cpp.o.requires

Cliente/CMakeFiles/cliente.dir/receiver.cpp.o.provides: Cliente/CMakeFiles/cliente.dir/receiver.cpp.o.requires
	$(MAKE) -f Cliente/CMakeFiles/cliente.dir/build.make Cliente/CMakeFiles/cliente.dir/receiver.cpp.o.provides.build
.PHONY : Cliente/CMakeFiles/cliente.dir/receiver.cpp.o.provides

Cliente/CMakeFiles/cliente.dir/receiver.cpp.o.provides.build: Cliente/CMakeFiles/cliente.dir/receiver.cpp.o

Cliente/CMakeFiles/cliente.dir/window.cpp.o: Cliente/CMakeFiles/cliente.dir/flags.make
Cliente/CMakeFiles/cliente.dir/window.cpp.o: src/Cliente/window.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ana/Desktop/Megaman/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object Cliente/CMakeFiles/cliente.dir/window.cpp.o"
	cd /home/ana/Desktop/Megaman/Cliente && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/cliente.dir/window.cpp.o -c /home/ana/Desktop/Megaman/src/Cliente/window.cpp

Cliente/CMakeFiles/cliente.dir/window.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cliente.dir/window.cpp.i"
	cd /home/ana/Desktop/Megaman/Cliente && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/ana/Desktop/Megaman/src/Cliente/window.cpp > CMakeFiles/cliente.dir/window.cpp.i

Cliente/CMakeFiles/cliente.dir/window.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cliente.dir/window.cpp.s"
	cd /home/ana/Desktop/Megaman/Cliente && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/ana/Desktop/Megaman/src/Cliente/window.cpp -o CMakeFiles/cliente.dir/window.cpp.s

Cliente/CMakeFiles/cliente.dir/window.cpp.o.requires:
.PHONY : Cliente/CMakeFiles/cliente.dir/window.cpp.o.requires

Cliente/CMakeFiles/cliente.dir/window.cpp.o.provides: Cliente/CMakeFiles/cliente.dir/window.cpp.o.requires
	$(MAKE) -f Cliente/CMakeFiles/cliente.dir/build.make Cliente/CMakeFiles/cliente.dir/window.cpp.o.provides.build
.PHONY : Cliente/CMakeFiles/cliente.dir/window.cpp.o.provides

Cliente/CMakeFiles/cliente.dir/window.cpp.o.provides.build: Cliente/CMakeFiles/cliente.dir/window.cpp.o

Cliente/CMakeFiles/cliente.dir/client.cpp.o: Cliente/CMakeFiles/cliente.dir/flags.make
Cliente/CMakeFiles/cliente.dir/client.cpp.o: src/Cliente/client.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ana/Desktop/Megaman/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object Cliente/CMakeFiles/cliente.dir/client.cpp.o"
	cd /home/ana/Desktop/Megaman/Cliente && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/cliente.dir/client.cpp.o -c /home/ana/Desktop/Megaman/src/Cliente/client.cpp

Cliente/CMakeFiles/cliente.dir/client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cliente.dir/client.cpp.i"
	cd /home/ana/Desktop/Megaman/Cliente && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/ana/Desktop/Megaman/src/Cliente/client.cpp > CMakeFiles/cliente.dir/client.cpp.i

Cliente/CMakeFiles/cliente.dir/client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cliente.dir/client.cpp.s"
	cd /home/ana/Desktop/Megaman/Cliente && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/ana/Desktop/Megaman/src/Cliente/client.cpp -o CMakeFiles/cliente.dir/client.cpp.s

Cliente/CMakeFiles/cliente.dir/client.cpp.o.requires:
.PHONY : Cliente/CMakeFiles/cliente.dir/client.cpp.o.requires

Cliente/CMakeFiles/cliente.dir/client.cpp.o.provides: Cliente/CMakeFiles/cliente.dir/client.cpp.o.requires
	$(MAKE) -f Cliente/CMakeFiles/cliente.dir/build.make Cliente/CMakeFiles/cliente.dir/client.cpp.o.provides.build
.PHONY : Cliente/CMakeFiles/cliente.dir/client.cpp.o.provides

Cliente/CMakeFiles/cliente.dir/client.cpp.o.provides.build: Cliente/CMakeFiles/cliente.dir/client.cpp.o

Cliente/CMakeFiles/cliente.dir/sender.cpp.o: Cliente/CMakeFiles/cliente.dir/flags.make
Cliente/CMakeFiles/cliente.dir/sender.cpp.o: src/Cliente/sender.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ana/Desktop/Megaman/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object Cliente/CMakeFiles/cliente.dir/sender.cpp.o"
	cd /home/ana/Desktop/Megaman/Cliente && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/cliente.dir/sender.cpp.o -c /home/ana/Desktop/Megaman/src/Cliente/sender.cpp

Cliente/CMakeFiles/cliente.dir/sender.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cliente.dir/sender.cpp.i"
	cd /home/ana/Desktop/Megaman/Cliente && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/ana/Desktop/Megaman/src/Cliente/sender.cpp > CMakeFiles/cliente.dir/sender.cpp.i

Cliente/CMakeFiles/cliente.dir/sender.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cliente.dir/sender.cpp.s"
	cd /home/ana/Desktop/Megaman/Cliente && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/ana/Desktop/Megaman/src/Cliente/sender.cpp -o CMakeFiles/cliente.dir/sender.cpp.s

Cliente/CMakeFiles/cliente.dir/sender.cpp.o.requires:
.PHONY : Cliente/CMakeFiles/cliente.dir/sender.cpp.o.requires

Cliente/CMakeFiles/cliente.dir/sender.cpp.o.provides: Cliente/CMakeFiles/cliente.dir/sender.cpp.o.requires
	$(MAKE) -f Cliente/CMakeFiles/cliente.dir/build.make Cliente/CMakeFiles/cliente.dir/sender.cpp.o.provides.build
.PHONY : Cliente/CMakeFiles/cliente.dir/sender.cpp.o.provides

Cliente/CMakeFiles/cliente.dir/sender.cpp.o.provides.build: Cliente/CMakeFiles/cliente.dir/sender.cpp.o

Cliente/CMakeFiles/cliente.dir/Sprite.cpp.o: Cliente/CMakeFiles/cliente.dir/flags.make
Cliente/CMakeFiles/cliente.dir/Sprite.cpp.o: src/Cliente/Sprite.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ana/Desktop/Megaman/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object Cliente/CMakeFiles/cliente.dir/Sprite.cpp.o"
	cd /home/ana/Desktop/Megaman/Cliente && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/cliente.dir/Sprite.cpp.o -c /home/ana/Desktop/Megaman/src/Cliente/Sprite.cpp

Cliente/CMakeFiles/cliente.dir/Sprite.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cliente.dir/Sprite.cpp.i"
	cd /home/ana/Desktop/Megaman/Cliente && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/ana/Desktop/Megaman/src/Cliente/Sprite.cpp > CMakeFiles/cliente.dir/Sprite.cpp.i

Cliente/CMakeFiles/cliente.dir/Sprite.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cliente.dir/Sprite.cpp.s"
	cd /home/ana/Desktop/Megaman/Cliente && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/ana/Desktop/Megaman/src/Cliente/Sprite.cpp -o CMakeFiles/cliente.dir/Sprite.cpp.s

Cliente/CMakeFiles/cliente.dir/Sprite.cpp.o.requires:
.PHONY : Cliente/CMakeFiles/cliente.dir/Sprite.cpp.o.requires

Cliente/CMakeFiles/cliente.dir/Sprite.cpp.o.provides: Cliente/CMakeFiles/cliente.dir/Sprite.cpp.o.requires
	$(MAKE) -f Cliente/CMakeFiles/cliente.dir/build.make Cliente/CMakeFiles/cliente.dir/Sprite.cpp.o.provides.build
.PHONY : Cliente/CMakeFiles/cliente.dir/Sprite.cpp.o.provides

Cliente/CMakeFiles/cliente.dir/Sprite.cpp.o.provides.build: Cliente/CMakeFiles/cliente.dir/Sprite.cpp.o

Cliente/CMakeFiles/cliente.dir/Renderer.cpp.o: Cliente/CMakeFiles/cliente.dir/flags.make
Cliente/CMakeFiles/cliente.dir/Renderer.cpp.o: src/Cliente/Renderer.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ana/Desktop/Megaman/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object Cliente/CMakeFiles/cliente.dir/Renderer.cpp.o"
	cd /home/ana/Desktop/Megaman/Cliente && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/cliente.dir/Renderer.cpp.o -c /home/ana/Desktop/Megaman/src/Cliente/Renderer.cpp

Cliente/CMakeFiles/cliente.dir/Renderer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cliente.dir/Renderer.cpp.i"
	cd /home/ana/Desktop/Megaman/Cliente && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/ana/Desktop/Megaman/src/Cliente/Renderer.cpp > CMakeFiles/cliente.dir/Renderer.cpp.i

Cliente/CMakeFiles/cliente.dir/Renderer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cliente.dir/Renderer.cpp.s"
	cd /home/ana/Desktop/Megaman/Cliente && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/ana/Desktop/Megaman/src/Cliente/Renderer.cpp -o CMakeFiles/cliente.dir/Renderer.cpp.s

Cliente/CMakeFiles/cliente.dir/Renderer.cpp.o.requires:
.PHONY : Cliente/CMakeFiles/cliente.dir/Renderer.cpp.o.requires

Cliente/CMakeFiles/cliente.dir/Renderer.cpp.o.provides: Cliente/CMakeFiles/cliente.dir/Renderer.cpp.o.requires
	$(MAKE) -f Cliente/CMakeFiles/cliente.dir/build.make Cliente/CMakeFiles/cliente.dir/Renderer.cpp.o.provides.build
.PHONY : Cliente/CMakeFiles/cliente.dir/Renderer.cpp.o.provides

Cliente/CMakeFiles/cliente.dir/Renderer.cpp.o.provides.build: Cliente/CMakeFiles/cliente.dir/Renderer.cpp.o

# Object files for target cliente
cliente_OBJECTS = \
"CMakeFiles/cliente.dir/receiver.cpp.o" \
"CMakeFiles/cliente.dir/window.cpp.o" \
"CMakeFiles/cliente.dir/client.cpp.o" \
"CMakeFiles/cliente.dir/sender.cpp.o" \
"CMakeFiles/cliente.dir/Sprite.cpp.o" \
"CMakeFiles/cliente.dir/Renderer.cpp.o"

# External object files for target cliente
cliente_EXTERNAL_OBJECTS =

Cliente/cliente: Cliente/CMakeFiles/cliente.dir/receiver.cpp.o
Cliente/cliente: Cliente/CMakeFiles/cliente.dir/window.cpp.o
Cliente/cliente: Cliente/CMakeFiles/cliente.dir/client.cpp.o
Cliente/cliente: Cliente/CMakeFiles/cliente.dir/sender.cpp.o
Cliente/cliente: Cliente/CMakeFiles/cliente.dir/Sprite.cpp.o
Cliente/cliente: Cliente/CMakeFiles/cliente.dir/Renderer.cpp.o
Cliente/cliente: Cliente/CMakeFiles/cliente.dir/build.make
Cliente/cliente: Comun/libMegaman.a
Cliente/cliente: Cliente/CMakeFiles/cliente.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable cliente"
	cd /home/ana/Desktop/Megaman/Cliente && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cliente.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Cliente/CMakeFiles/cliente.dir/build: Cliente/cliente
.PHONY : Cliente/CMakeFiles/cliente.dir/build

Cliente/CMakeFiles/cliente.dir/requires: Cliente/CMakeFiles/cliente.dir/receiver.cpp.o.requires
Cliente/CMakeFiles/cliente.dir/requires: Cliente/CMakeFiles/cliente.dir/window.cpp.o.requires
Cliente/CMakeFiles/cliente.dir/requires: Cliente/CMakeFiles/cliente.dir/client.cpp.o.requires
Cliente/CMakeFiles/cliente.dir/requires: Cliente/CMakeFiles/cliente.dir/sender.cpp.o.requires
Cliente/CMakeFiles/cliente.dir/requires: Cliente/CMakeFiles/cliente.dir/Sprite.cpp.o.requires
Cliente/CMakeFiles/cliente.dir/requires: Cliente/CMakeFiles/cliente.dir/Renderer.cpp.o.requires
.PHONY : Cliente/CMakeFiles/cliente.dir/requires

Cliente/CMakeFiles/cliente.dir/clean:
	cd /home/ana/Desktop/Megaman/Cliente && $(CMAKE_COMMAND) -P CMakeFiles/cliente.dir/cmake_clean.cmake
.PHONY : Cliente/CMakeFiles/cliente.dir/clean

Cliente/CMakeFiles/cliente.dir/depend:
	cd /home/ana/Desktop/Megaman && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ana/Desktop/Megaman/src /home/ana/Desktop/Megaman/src/Cliente /home/ana/Desktop/Megaman /home/ana/Desktop/Megaman/Cliente /home/ana/Desktop/Megaman/Cliente/CMakeFiles/cliente.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Cliente/CMakeFiles/cliente.dir/depend

