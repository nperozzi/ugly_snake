CC = gcc
PROG = main.exe 
SRC = main.c
CFLAGS=-Wall -Werror -g -Iinclude

SRC_DIR = src
SRC = $(SRC_DIR)/*.c

all: $(PROG)
$(PROG): $(SRC)
	$(CC) -o $@ $(CFLAGS) $(SRC)
clean:
	rm -f $(PROG)
.PHONY: all clean
