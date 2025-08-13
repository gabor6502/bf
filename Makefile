
# compiles the bf interpreter
all:
	gcc -m32 brainfuck.c -o bf

clean:
	rm -f bf