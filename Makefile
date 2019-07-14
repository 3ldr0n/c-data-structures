CC=clang
CFLAGS+=-Wall -Wextra -Werror -I./include

all: linked_list singly_linked_list

%: src/%.c
	mkdir -p bin
	$(CC) $(CFLAGS) src/$@.c src/tests/test_$@.c -o bin/test_$@

tests:
	./scripts/run_tests.sh

.PHONY: clean

clean:
	rm bin/*
