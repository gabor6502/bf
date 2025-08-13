#include <stdlib.h>
#include <stdio.h>

char * readFile(const char * bfFile);
char * getProgramName(int argc, char *argv[]);

int main(int argc, char *argv[])
{
    char * programName = getProgramName(argc, argv);
    char * program = readFile(programName);

    // test
    printf("%s\n", program);

    free(program);

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