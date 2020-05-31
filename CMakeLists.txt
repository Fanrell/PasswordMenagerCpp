cmake_minimum_required(VERSION 3.10)
project(PasswordMenager)

set(EXECUTABLE_OUTPUT_PATH "./bin")

find_package(Curses REQUIRED)

include_directories(${CURSES_INCLUDE_DIR})

include_directories("includes")
file(GLOB SOURCES "src/main.cc")

add_library(lib src/Menu.cc src/mainWindow.cc src/Account.cc src/stringer.cc src/FileLister.cc src/PassList.cc src/RSA.cc)
target_link_libraries(lib)

add_executable(PasswordMenager ${SOURCES})
target_link_libraries(PasswordMenager lib)
target_link_libraries(PasswordMenager ${CURSES_LIBRARIES})

install (TARGETS lib DESTINATION "./bin")	
install (TARGETS PasswordMenager DESTINATION "./bin")