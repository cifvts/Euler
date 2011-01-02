SRC=./src
BIN=./bin

CFLAGS=-O2 -lm

main: 001 002 003 004

clean:
	rm -rf $(BIN)

%.dir:
	test -d $(BIN) || mkdir -p $(BIN)

001: %.dir
	gcc $(CFLAGS) $(SRC)/euler001.c -o $(BIN)/euler001

002: %.dir
	gcc $(CFLAGS) $(SRC)/euler002.c -o $(BIN)/euler002

003: %.dir
	gcc $(CFLAGS) $(SRC)/euler003.c -o $(BIN)/euler003

004: %.dir
	gcc $(CFLAGS) $(SRC)/euler004.c -o $(BIN)/euler004
