#Setting compilation flags:
#set (CMAKE_C_FLAGS "-g -o0 -Wall -pedantic -pthread")
add_definitions("-g -o0 -Wall -pedantic")
#Declare variable that combines all *.cpp and *.h files
#in this directory.

file (GLOB CLIENTE ../../Cliente/*.cpp ../../Cliente/*.h)
file (GLOB SRCS *.cpp *.h)

#Creates an executable with all files found
#by file command.
add_executable (editor ${CLIENTE} ${SRCS})
target_link_libraries (editor Megaman)
