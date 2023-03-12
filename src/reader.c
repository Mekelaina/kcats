#include "reader.h"

#include <malloc.h>
#include <linux/limits.h>
#include <stdlib.h>

static int getFileSize(FILE *fp){
    int prev = ftell(fp);
    fseek(fp, 0L, SEEK_END);
    int sz = ftell(fp);
    fseek(fp, prev, SEEK_SET);
    return sz;
}


static char* resolvepath(char *relitivepath){
    //char buf[PATH_MAX];
    char *res = realpath(relitivepath, NULL);
    if(res){
        return res;
    } else {
        printf("Error: could not resolve file [%s]", relitivepath);
        return NULL;
    }
}


void initReader(Reader *reader){
    reader->file = NULL;
    reader->filepath = NULL;
    reader->filesize = 0;
    reader->content = NULL;
}

void freeReader(Reader *reader){
    free(reader->filepath);
    free(reader->content);
}

bool setFile(Reader *reader, char *filepath){
    char *path = resolvepath(filepath);
    if(path != NULL){
        reader->filepath = path;
        return true;
    } else {
        printf("%s", "path null");
        reader->filepath = NULL;
        return false;
    }
}

bool readFile(Reader *reader){

    if(reader->filepath == NULL){
        return false;
    }

    FILE *fp = fopen(reader->filepath, "r");

    if(fp == NULL){
        printf("%s:%s", "Error opening file", reader->filepath);
        return false;
    }

    int fsize = getFileSize(fp);
    char *content = malloc(sizeof(char) * (fsize + 1));

    for(int i = 0; i < fsize + 1; i++){
        int c = fgetc(fp);
        if(feof(fp)){
            break;
        }
        content[i] = c;
    }

    fclose(fp);
    
    reader->file = fp;
    reader->filesize = fsize;
    reader->content = content;

    return true;
}

bool readFileFromPath(Reader *reader, char *filepath){
    if(!setFile(reader, filepath)) return false;
    if(!readFile(reader)) return false;
    return true;
}




