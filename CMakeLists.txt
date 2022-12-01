cmake_minimum_required(VERSION 3.10)
project(sfml_lab)

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
  main.cc)

add_executable(sfml_lab ${SOURCE_FILES})
target_link_libraries(sfml_lab ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
