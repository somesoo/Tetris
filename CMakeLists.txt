cmake_minimum_required(VERSION 3.16)

project(TETRIS)

add_executable(${PROJECT_NAME} main.cpp board.cpp tetromino.cpp game.cpp)

set(CURSES_NEED_NCURSES TRUE)
find_package(Curses REQUIRED)
if (CURSES_FOUND AND CURSES_HAVE_NCURSES_H)
    include_directories(${CURSES_INCLUDE_DIR})
    target_link_libraries (TETRIS ${CURSES_LIBRARIES}) 
endif()