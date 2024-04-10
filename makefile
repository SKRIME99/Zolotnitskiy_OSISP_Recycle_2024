CC = gcc
CFLAGS = -W -Werror -std=c11 -pedantic -Wall -Wextra -Wno-unused-parameter -Wno-unused-variable
UNLINK_FLAGS = -fpic -shared

BUILD = ./build
SRC = ./src

trash = $(BUILD)/trash
trashc = $(SRC)/trash.c

.PHONY: clean 

all:  $(trash)

$(trash): $(trashc)
	$(CC) $(CFLAGS) $(trashc) -o $(trash)
	
clean:
	rm -f  $(trash) coursework.pdf
