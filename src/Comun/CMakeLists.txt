#Declare variable that combines all *.cpp  and *.h files
#in this directory.
file (GLOB SRCS  *.cpp *.h)

add_library (Megaman ${SRCS})
