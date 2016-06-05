#Setting compilation flags:
#set (CMAKE_C_FLAGS "-g -o0 -Wall -pedantic -pthread")
add_definitions("-g -o0 -Wall -pedantic")
#Declare variable that combines all *.cpp and *.h files
#in this directory.

file (GLOB CLIENTE	../Cliente/Sprite.cpp ../Cliente/Sprite.h
			../Cliente/window.cpp ../Cliente/window.h
			../Cliente/Renderer.cpp ../Cliente/Renderer.h
			../Cliente/block_sprite.cpp ../Cliente/block_sprite.h
			../Cliente/character_sprite.cpp ../Cliente/character_sprite.h
)

file (GLOB MODELO	../Servidor/Modelo/*.cpp ../Servidor/Modelo/*.h
)

#Set up CMake to use SDL, SDL_image:
include(FindPkgConfig)
pkg_search_module(SDL2 REQUIRED sdl2)
pkg_search_module(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)
include_directories(
	${SDL2_INCLUDE_DIRS}
	${SDL2IMAGE_INCLUDE_DIRS}
	${SDL_MIXER_INCLUDE_DIRS}
)
file (GLOB SRCS *.cpp *.h)

#Creates an executable with all files found
#by file command.
add_executable (editor ${MODELO} ${CLIENTE} ${SRCS})
target_link_libraries (editor Megaman ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES} ${SDL_MIXER_LIBRARIES})
