#ifndef __BFREADER_H__
#define __BFREADER_H__

typedef struct BF_READER
{
    char * bf_program;
} BF_reader;

BF_reader * createReader(const char * fname);
void destroyReader(BF_reader * bf);

#endif