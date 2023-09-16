CC = gcc

ARGS = -Wall -std=c99

DEPS = src/lexer/lexer.c src/nodes/nodes.c src/parser/parser.c src/parser/print.c src/tokens/token_array.c src/tokens/token.c src/utils/utils.c

all: output execute

output:
	$(CC) $(ARGS) src/main.c $(DEPS) -o build/main

execute:
	./build/main