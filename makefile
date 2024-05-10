CC = gcc
CFLAGS = -W -Werror -std=c11 -pedantic -Wall -Wextra -Wno-unused-parameter -Wno-unused-variable
UNLINK_FLAGS = -fpic -shared

BUILD = ./build
SRC = ./src

unlink = $(BUILD)/unlink.so
unlinkc = $(SRC)/unlink.c
bin = $(BUILD)/bin

MAIN_OBJ = ./obj/main.o
BINLIB_OBJ = ./obj/binlib.o
HEADER = $(SRC)/binlib.h

.PHONY: all clean

all: $(unlink) $(bin)

$(unlink): $(unlinkc)
	$(CC) $(UNLINK_FLAGS) $(CFLAGS) $(unlinkc) -o $(unlink)

$(bin): $(MAIN_OBJ) $(BINLIB_OBJ)
	$(CC) $(CFLAGS) $(MAIN_OBJ) $(BINLIB_OBJ) -o $(bin)

./obj/main.o: $(SRC)/main.c $(HEADER)
	$(CC) $(CFLAGS) -c $(SRC)/main.c -o $(MAIN_OBJ)

./obj/binlib.o: $(SRC)/binlib.c $(HEADER)
	$(CC) $(CFLAGS) -c $(SRC)/binlib.c -o $(BINLIB_OBJ)

clean:
	rm -f $(unlink) $(bin) $(MAIN_OBJ) $(BINLIB_OBJ) coursework.pdf