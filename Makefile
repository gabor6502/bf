
# compiles the bf interpreter
bf:
	gcc -m32 brainfuck.c -o bf

# compiles a main program to launch bf interpreter with code from a .bf file
all:
	gcc main.c -o main

clean-bf:
	rm -f bf

clean:
	rm -f main