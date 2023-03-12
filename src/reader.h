#ifndef KCATS_READER_H
#define KCATS_READER_H

#include <stdio.h>
#include <stdbool.h>


typedef struct {
    FILE *file;
    char *filepath;
    int filesize;
    char *content
} Reader;

void initReader(Reader *reader);
void freeReader(Reader *reader);
bool setFile(Reader *reader, char *filepath);
bool readFile(Reader *reader);
bool readFileFromPath(Reader *reader, char *filepath);

#endif