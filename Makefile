SRC=./src
BIN=./bin

CFLAGS=-O2

main: 001 002 003

%.dir:
	test -d $(BIN) || mkdir -p $(BIN)

001: %.dir
	gcc $(CFLAGS) $(SRC)/euler001.c -o $(BIN)/euler001

002: %.dir
	gcc $(CFLAGS) $(SRC)/euler002.c -o $(BIN)/euler002

003: %.dir
	gcc $(CFLAGS) $(SRC)/euler003.c -o $(BIN)/euler003
