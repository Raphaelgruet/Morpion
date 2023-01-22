
CC=gcc -I. 

CFLAGS1=-DCONFIG_TEXTUI -DCONFIG_PLAYER_MANAGER_MOCK
CFLAGS2=-DCONFIG_TEXTUI -DCONFIG_PLAYER_MANAGER_SCANF 
CFLAGS3=$(SDLF) -DCONFIG_SDLUI   -DCONFIG_PLAYER_MANAGER_SDL `sdl2-config --cflags --libs` -lpng16 -lSDL2 -lSDL2_image 

DEPS=board.h game.h player_manager.h tictactoe_errors.h board_view.h checkEndOfGame.h  

OBJS1=board.o game.o player_manager_mock.o tictactoe_errors.o board_view_text.o main.o 
OBJS2=board.o game.o player_manager_scanf.o tictactoe_errors.o board_view_text.o main.o 
OBJS3=board.o game.o player_manager_sdl.o tictactoe_errors.o board_view_sdl.o main.o 

#TEST=../test_tictactoe/checkEndOfGame.o  ../test_tictactoe/main.o 
TEST1=checkSteps.o 
TEST0 = checkEndOfGame.o  main.o board.o

$(OBJS1): CFLAGS := $(CFLAGS1)
$(OBJS2): CFLAGS := $(CFLAGS2)
$(OBJS3): CFLAGS := $(CFLAGS3)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS)  -c -o $@ $< 

morpion: $(OBJS3) 
	$(CC) $^ $(CFLAGS3)  -o $@ 

step2: $(OBJS2) 
	$(CC) $(CFLAGS2) $(SDLF) -o $@ $^ 

test0: $(TEST0)
	$(CC) $(CFLAGS)  $^ -o $@

test1: $(TEST1) $(OBJS1) 
	$(CC) $(CFLAGS1)  $^ -o $@

clean:
	rm -f test0 test1 step2 morpion $(OBJS1) $(TEST0) $(OBJS2) $(TEST1) $(OBJS3)