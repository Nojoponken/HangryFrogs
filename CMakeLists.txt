cmake_minimum_required(VERSION 3.10)
project(game)

# Använd C++ 17.
set(CMALE_CXX_STANDARD 17)

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
  src/game_engine.h
  src/game_engine.cc
  src/entity.h
  src/entity.cc
  src/world.h
  src/world.cc
  src/turret.h
  src/turret.cc
  src/enemy.h
  src/enemy.cc
  src/pepe.h
  src/pepe.cc
  src/frost_pepe.h
  src/frost_pepe.cc
  src/user_interface.h
  src/user_interface.cc
  src/button.h
  src/button.cc
  src/projectile.h
  src/projectile.cc
  src/fly.h 
  src/fly.cc
  src/mcfly.h
  src/mcfly.cc
  )

add_compile_options("-g")

add_executable(game ${SOURCE_FILES})
target_link_libraries(game ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
