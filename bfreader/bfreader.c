#include "bfreader.h"
#include <stdio.h>
#include <stdlib.h>

static char * readFile(const char * bfFile)
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
        contents = NULL;
    }

    return contents;
}

BF_reader * createReader(const char * fname)
{
    BF_reader * reader = (BF_reader*) malloc(sizeof(BF_reader));

    reader->bf_program = readFile(fname);

    if (!reader->bf_program)
    {
        return NULL;
    }

    return reader;
}

void destroyReader(BF_reader * reader)
{
    free(reader->bf_program);
    free(reader);
}
