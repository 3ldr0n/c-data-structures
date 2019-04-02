CC=clang
CFLAGS+=-Wall -Wextra -Werror -I./include
SRC=src
BIN=bin

all: list

%: $(SRC)/%.o
	mkdir -p $(BIN)
	$(CC) $(CFLAGS) $(SRC)/$@.o -o ./$(BIN)/$@

.PRECIOUS: %.o

.PHONY: clean

clean:
	rm $(BIN)/*
	rm $(SRC)/*.o
