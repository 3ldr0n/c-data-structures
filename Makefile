CC=clang
CFLAGS+=-Wall -Wextra -Werror -I./include
SRC=src
BIN=bin

all: linked_list doubly_linked_list

%:
	mkdir -p $(BIN)
	$(CC) $(CFLAGS) $(SRC)/$@.c $(SRC)/test_$@.c -o ./$(BIN)/test_$@

.PHONY: clean

clean:
	rm $(BIN)/*
