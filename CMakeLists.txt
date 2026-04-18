cmake_minimum_required(VERSION 3.10)
project(game)

# Använd C++ 17.
set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.5.1
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

# Välj vilka moduler i SFML som ska användas.
set(SFML_MODULES network graphics window system )

# Lägg till lämpliga bibliotek till kompileringen. Man kan använda 'find_package',
# men det kräver att SFML är installerat på ett annat sätt.
foreach (i ${SFML_MODULES})
  list( APPEND SFML_LIBRARIES "sfml-${i}")
endforeach(i)

# Ange källfiler, lägg till de filer som ni behöver!
set(SOURCE_FILES
  src/main.cc
  src/game_engine.cc
  src/entity.cc
  src/world.cc
  src/turret.cc
  src/enemy.cc
  src/pepe.cc
  src/frost_pepe.cc
  src/user_interface.cc
  src/button.cc
  src/projectile.cc
  src/fly.cc
  src/mcfly.cc
  )

add_compile_options("-g")

add_executable(game ${SOURCE_FILES})
target_link_libraries(game ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
