#Setting compilation flags:
#set (CMAKE_C_FLAGS "-g -o0 -Wall -pedantic -pthread")
add_definitions("-g -o0 -Wall -pedantic")
#Declare variable that combines all *.cpp and *.h files
#in this directory.
file (GLOB MODELO ../../Modelo/*.cpp ../../Modelo/*.h)
file (GLOB COMUN ../../../Comun/*.cpp ../../../Comun/*.h)
file (GLOB LOBBY ../Lobby/*.cpp ../Lobby/*.h)
file (GLOB PARTIDA ../Partida/*.cpp ../Partida/*.h)
file (GLOB SRCS *.cpp *.h)
file (GLOB EDITOR ../../Editor/cargador_mapa.h ../../../Editor/cargador_mapa.cpp)
#Creates an executable with all files found
#by file command.
add_executable (servidor ${COMUN} ${MODELO} ${SRCS} ${PARTIDA} ${LOBBY} ${EDITOR})
target_link_libraries (servidor Megaman -pthread)
