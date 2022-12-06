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
  main.cc
  game_engine.h
  game_engine.cc
  entity.h
  entity.cc
  world.h
  world.cc
  turret.h
  turret.cc
  enemy.h
  enemy.cc
  pepe.h
  pepe.cc
  actionbar.h
  actionbar.cc
  button.h
  button.cc
  )

add_compile_options("-g")

add_executable(game ${SOURCE_FILES})
target_link_libraries(game ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
