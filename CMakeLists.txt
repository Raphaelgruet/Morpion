cmake_minimum_required(VERSION 3.23)
project(Morpion C)

set(CMAKE_C_STANDARD 23)

add_compile_definitions(CONFIG_TEXTUI CONFIG_PLAYER_MANAGER_SCANF)
add_executable(Morpion main.c board.c board.h checkEndOfGame.c checkEndOfGame.h game.h game.c board_view.h board_view_text.c player_manager_scanf.c)
