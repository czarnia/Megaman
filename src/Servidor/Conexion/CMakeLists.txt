project (Megaman)
cmake_minimum_required (VERSION 2.8.7)

find_package (PkgConfig REQUIRED)

#Go into indicated subdirectory and look
#for another CMakeLists.txt file:
add_subdirectory(Arquitectura)
add_subdirectory(Lobby)
add_subdirectory(Partida)
