CC=clang
CFLAGS+=-Wall -Wextra -Werror -I./include
SRC=src
BIN=bin

all: linked_list doubly_linked_list

%: $(SRC)/%.o
	mkdir -p $(BIN)
	$(CC) $(CFLAGS) $(SRC)/$@.o -o ./$(BIN)/$@

.PRECIOUS: %.o

.PHONY: clean

clean:
	rm $(BIN)/*
	rm $(SRC)/*.o
