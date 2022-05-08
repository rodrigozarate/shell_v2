SHELL:=/bin/bash
OUT=hsh
SRC=*.c
CC=gcc
CFLAGS=-Wall -Werror -Wextra -pedantic

all:
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)