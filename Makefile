SRC=./src
BIN=./bin

CFLAGS=-O2

main: 001 002

%.dir:
	test -d $(BIN) || mkdir -p $(BIN)

001: %.dir
	gcc $(CFLAGS) $(SRC)/euler001.c -o $(BIN)/euler001

002: %.dir
	gcc $(CFLAGS) $(SRC)/euler002.c -o $(BIN)/euler002
