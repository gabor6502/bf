all:
	gcc -m32 brainfuck.c -o bf
	gcc main.c -o main

clean:
	rm -f bf
	rm -f main