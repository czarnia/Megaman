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
			"${INCLUDE_SERVER}/puas.cpp"
			"${INCLUDE_SERVER}/megaman.cpp"
			"${INCLUDE_SERVER}/escalera.cpp"
			"${INCLUDE_SERVER}/bloque.cpp"
			"${INCLUDE_SERVER}/puas_asesinas.cpp"
			"${INCLUDE_SERVER}/personaje.cpp"
			"${INCLUDE_SERVER}/evento_mover.cpp"
			"${INCLUDE_SERVER}/evento_parar.cpp"
			"${INCLUDE_SERVER}/creador_mover.cpp"
			"${INCLUDE_SERVER}/creador_parar.cpp"
			"${INCLUDE_SERVER}/megaman.cpp"
			"${INCLUDE_SERVER}/vida.cpp"
			"${INCLUDE_SERVER}/servidor.cpp"
			"${INCLUDE_SERVER}/juego.cpp"
			"${INCLUDE_SERVER}/entrada_estandar.cpp"
			"${INCLUDE_SERVER}/conexion_cliente.cpp"
			"${INCLUDE_SERVER}/receiver_cliente.cpp"
			"${INCLUDE_SERVER}/observable.cpp"
			"${INCLUDE_SERVER}/procesador_eventos.cpp"
			"${INCLUDE_SERVER}/manejador_eventos.cpp"
			"${INCLUDE_SERVER}/creador_atacar.cpp"
			"${INCLUDE_SERVER}/creador_cambiar_arma.cpp"
			"${INCLUDE_SERVER}/creador_mover.cpp"
			"${INCLUDE_SERVER}/evento_atacar.cpp"
			"${INCLUDE_SERVER}/evento_cambiar_arma.cpp"
			"${INCLUDE_SERVER}/evento_mover.cpp"
			"${INCLUDE_SERVER}/observador_personaje.cpp"
			"${INCLUDE_SERVER}/megaman_factory.cpp"
			"${INCLUDE_SERVER}/arma_megaman.cpp"
			"${INCLUDE_SERVER}/arma_met.cpp"
			"${INCLUDE_SERVER}/bala.cpp"
			"${INCLUDE_SERVER}/bala_normal.cpp"
			"${INCLUDE_SERVER}/observador.cpp"
			"${INCLUDE_SERVER}/observador_personaje.cpp"
			"${INCLUDE_SERVER}/bala_met.cpp"
			"${INCLUDE_SERVER}/met.cpp"

			)
file (GLOB COM "${INCLUDE_COM}/*")

#Creates an executable with all files found
#by file command.
add_executable (tests ${SRCS} ${COM} ${SERVER})
target_link_libraries (tests Megaman -pthread)
