cmake_minimum_required(VERSION 3.23)
project(Morpion C)

set(CMAKE_C_STANDARD 23)

add_executable(Morpion main.c board.c board.h checkEndOfGame.c checkEndOfGame.h)
        #board_view_text.c board_view.h
        #game.c game.h
        #player_manager_mock.c player_manager.h
        #tictactoe_erros.c tictactoe_errors.h)
