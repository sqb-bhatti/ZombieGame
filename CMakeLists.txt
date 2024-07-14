cmake_minimum_required(VERSION 3.28)
project(ZombieGame)

set(CMAKE_CXX_STANDARD 17)

add_executable(ZombieGame main.cpp
        Player.cpp
        Player.h
        CreateBackground.cpp
        CreateBackground.h
        TextureHolder.cpp
        TextureHolder.h
        Zombie.cpp
        Zombie.h
        CreateHorde.cpp
        Bullet.cpp
        Bullet.h
)
include_directories(/usr/local/include)

find_package(SFML 2.6.1 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(ZombieGame sfml-system sfml-window sfml-graphics sfml-audio sfml-network)