#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

#include "bfreader/bfreader.h"

char * readProgramName(int argc, char *argv[]);
void runBF(BF_reader * bf);

int main(int argc, char *argv[])
{
    char * programName = readProgramName(argc, argv);

    BF_reader * bf = createReader(programName);

    if (!bf)
    {
        fprintf(stderr, "Failed read file: %s.\n", programName);
        exit(EXIT_FAILURE);
    }

    runBF(bf);
   
    destroyReader(bf);

    printf("\nEnd of line.\n");
    return 0;
}

char * readProgramName(int argc, char *argv[])
{
    if (argc == 2)
    {
        return argv[1];
    }
    else
    {
        fprintf(stderr, "Invalid arguments supplied.\n");
        exit(EXIT_FAILURE);
    }
}

void runBF(BF_reader * bf)
{
    // - fork and exec -
    pid_t pid = fork();
    int status;

    if (pid < 0)
    {
        fprintf(stderr, "Failed to start child process.\n");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0) // child process
    {
        execl("./bf", "./bf", bf->bf_program, (char*) NULL);

        fprintf(stderr, "Something went wrong before BF compiler execution.\n");
        exit(EXIT_FAILURE);
    }
    else // parent process
    {
        waitpid(pid, &status, 0);

        if (WTERMSIG(status) == SIGSEGV)
        {
            fprintf(stderr, "BF Compiler segmentation fault.\n");
        }  
    }
}
