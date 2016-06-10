#Setting compilation flags:
#set (CMAKE_C_FLAGS "-g -o0 -Wall -pedantic -pthread")
add_definitions("-g -o0 -Wall -pedantic")
#Declare variable that combines all *.cpp and *.h files
#in this directory.
file (GLOB MODELO ../../Modelo/*.cpp ../../Modelo/*.h)
file (GLOB COMUN ../../../Comun/*.cpp ../../../Comun/*.h)
file (GLOB SRCS *.cpp *.h)
