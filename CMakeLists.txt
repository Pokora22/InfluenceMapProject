cmake_minimum_required(VERSION 3.17)
project(InfluenceMapDemo)

set(CMAKE_CXX_STANDARD 14)

add_executable(InfluenceMapDemo main.cpp Enemy.cpp Entity.cpp evilPlayer.cpp Game.cpp Input.cpp Level.cpp Object.cpp Player.cpp TextureManager.cpp TileMap.cpp Window.cpp)

## If you want to link SFML statically
set(SFML_STATIC_LIBRARIES TRUE)

## In most cases better set in the CMake cache
set(SFML_DIR "G:/Dokumenty/WIT/Cpp/SFML-2.5.1/lib/cmake/SFML")
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)
target_link_libraries(InfluenceMapDemo sfml-graphics sfml-window sfml-system)