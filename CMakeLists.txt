cmake_minimum_required(VERSION 3.23)
project(Morpion C)

set(CMAKE_C_STANDARD 23)

add_compile_definitions(CONFIG_TEXTUI CONFIG_PLAYER_MANAGER_SCANF)
add_executable(Morpion src/main.c src/board.c src/board.h src/checkEndOfGame.c src/checkEndOfGame.h src/game.h src/game.c src/board_view.h src/board_view_text.c src/player_manager_scanf.c)
