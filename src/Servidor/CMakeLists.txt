#Setting compilation flags:
set (CMAKE_C_FLAGS "-Wall -q -pedantic")

#Declare variable that combines all *.cpp  and *.h files
#in this directory.
file (GLOB SRCS  *.cpp *.h)

#Creates an executable with all files found
#by file command.
add_executable (servidor ${SRCS})

target_link_libraries (servidor Megaman -pthread)
