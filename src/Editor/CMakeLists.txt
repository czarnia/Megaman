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
			../Cliente/background_sprite.cpp ../Cliente/background_sprite.h
)

file (GLOB COMUN ../Comun/*h ../Comun/*.cpp)

file (GLOB MODELO	../Servidor/Modelo/*.cpp ../Servidor/Modelo/*.h
			../Servidor/Conexion/Arquitectura/servidor.cpp 
			../Servidor/Conexion/Arquitectura/servidor.h
			../Servidor/Conexion/Arquitectura/almacenador_clientes.cpp 
			../Servidor/Conexion/Arquitectura/almacenador_clientes.h
			../Servidor/Conexion/Arquitectura/receiver_cliente.cpp 
			../Servidor/Conexion/Arquitectura/receiver_cliente.h
			../Servidor/Conexion/Arquitectura/conexion_cliente.cpp 
			../Servidor/Conexion/Arquitectura/conexion_cliente.h
			../Servidor/Conexion/Arquitectura/entrada_estandar.cpp 
			../Servidor/Conexion/Arquitectura/entrada_estandar.h
			../Servidor/Conexion/Arquitectura/log.cpp 
			../Servidor/Conexion/Arquitectura/log.h
			../Servidor/Conexion/Lobby/*.cpp 
			../Servidor/Conexion/Lobby/*.h
			../Servidor/Conexion/Partida/*.cpp 
			../Servidor/Conexion/Partida/*.h

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
add_executable (editor ${COMUN} ${MODELO} ${CLIENTE} ${SRCS})
target_link_libraries (editor Megaman -pthread ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES} ${SDL_MIXER_LIBRARIES})
