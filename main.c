#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

char * readFile(const char * bfFile);
char * getProgramName(int argc, char *argv[]);

int main(int argc, char *argv[])
{
    char * programName = getProgramName(argc, argv);
    char * program = readFile(programName);

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
        execl("./bf", "./bf", program, (char*) NULL);

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
   
    free(program);

    printf("\nEnd of line.\n");
    return 0;
}

char * getProgramName(int argc, char *argv[])
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

char * readFile(const char * bfFile)
{
    char * contents;
    int length;
    FILE * file;

    file = fopen(bfFile, "rb");

    if (file)
    {
        fseek(file, 0, SEEK_END);
        length = ftell(file);
        
        contents = (char*) malloc(sizeof(char) * length);

        fseek(file, 0, SEEK_SET);
        fread(contents, 1, length, file);

        fclose(file);
    }
    else 
    {
        fprintf(stderr, "Couldn't open file %s\n", bfFile);
        exit(EXIT_FAILURE);
    }

    return contents;
}