CC=gcc
CFLAGS=-Wall

# requires gcc-multilib to be installed
BFFLAGS = -m32 -w 
BFSOURCE = brainfuck.c
BFTARGET = bf

INTERPSOURCE = main.c
INTERPTARGET = brain

all:
	$(CC) $(BFFLAGS) $(BFSOURCE) -o $(BFTARGET)
	$(CC) $(CFLAGS) $(INTERPSOURCE) -o $(INTERPTARGET)

clean:
	$(RM) -f $(BFTARGET)
	$(RM) -f $(INTERPTARGET)