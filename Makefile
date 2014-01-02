CC := gcc
CFLAGS := -Wall
LIBS := -lSDL2 -llua.5.2

sdl_lua_test: main.o
	$(CC) $(LIBS) -o sdl_lua_test main.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c


