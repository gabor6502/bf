CC=gcc
CFLAGS=-Wall

# requires gcc-multilib to be installed
BFFLAGS = -m32 -w 
BFSOURCE = brainfuck.c
BFTARGET = bf

INTERPSOURCE = main.c
INTERPTARGET = brain

OBJS = bfreader.o

BFREADER__H = ./bfreader/bfreader.h
BFREADER_C = ./bfreader/bfreader.c

all: brain

brain: $(OBJS)
	$(CC) $(CFLAGS) $(INTERPSOURCE) $(OBJS) -o $(INTERPTARGET) 

bfreader.o: $(BFREADER_H) $(BFREADER_C)
	$(CC) $(CFLAGS) -c $(BFREADER_C)

clean:
	$(RM) -f $(INTERPTARGET) $(OBJS)

# for brainfuck compiler
bfcompiler:
	$(CC) $(BFFLAGS) $(BFSOURCE) -o $(BFTARGET)

clean-bfcompiler:
	$(RM) -f $(BFTARGET)

	