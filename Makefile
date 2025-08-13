CC=gcc

# requires gcc-multilib to be installed
BFFLAGS = -m32 
BFSOURCE = brainfuck.c
BFTARGET = bf

INTERPSOURCE = main.c
INTERPTARGET = brain

all:
	$(CC) $(BFFLAGS) $(BFSOURCE) -o $(BFTARGET)
	$(CC) $(INTERPSOURCE) -o $(INTERPTARGET)

clean:
	$(RM) -f $(BFTARGET)
	$(RM) -f $(INTERPTARGET)