#Setting compilation flags:
set (CMAKE_C_FLAGS "-Wall -q -pedantic")

set(INCLUDE_SERVER "../Servidor")
set(INCLUDE_COM "../Comun")

include_directories(${INCLUDE_COM})
include_directories(${INCLUDE_SERVER})

#Declare variable that combines all *.cpp  and *.h files
#in these directories:
file (GLOB SRCS  *.cpp *.h)
file (GLOB	SERVER "${INCLUDE_SERVER}/*.h"

			"${INCLUDE_SERVER}/mapa.cpp" 
			"${INCLUDE_SERVER}/coordenada.cpp"
			"${INCLUDE_SERVER}/celda.cpp"
			"${INCLUDE_SERVER}/puas.cpp"
			"${INCLUDE_SERVER}/megaman.cpp"
			"${INCLUDE_SERVER}/escalera.cpp"
			"${INCLUDE_SERVER}/celda_tierra.cpp"
			"${INCLUDE_SERVER}/celda_aire.cpp"
			"${INCLUDE_SERVER}/personaje.cpp"
			"${INCLUDE_SERVER}/strategy_mover.cpp"
			"${INCLUDE_SERVER}/strategy_mover_con_gravedad.cpp"
			"${INCLUDE_SERVER}/strategy_mover_arriba.cpp"
			"${INCLUDE_SERVER}/strategy_mover_abajo.cpp"
			"${INCLUDE_SERVER}/strategy_mover_derecha.cpp"
			"${INCLUDE_SERVER}/strategy_mover_izquierda.cpp"
			"${INCLUDE_SERVER}/vida.cpp"
			)
file (GLOB COM "${INCLUDE_COM}/*")

#Creates an executable with all files found
#by file command.
add_executable (tests ${SRCS} ${COM} ${SERVER})
target_link_libraries (tests Megaman -pthread)
