#include "reader.h"
#include <malloc.h>
#include <stdlib.h>
#include <linux/limits.h>
#include <stdio.h>

static int fsize(FILE *fp){
    int prev = ftell(fp);
    fseek(fp, 0L, SEEK_END);
    int sz = ftell(fp);
    fseek(fp, prev, SEEK_SET);
    return sz;
}


static char* resolvepath(char *relitivepath){
    char buf[PATH_MAX];
    char *res = realpath(relitivepath, buf);
    if(res){
        return *buf;
    } else {
        printf("Error: could not resolve file [%s]", relitivepath);
        exit(1);
    }
}

void readfile(char *path_in){

    FILE *fp;
    char *filepath = resolvepath(path_in);

    fp = fopen(filepath, "r");
    
    if(fp == NULL){
        printf("%s:%s", "Error opening file", filepath);
        exit(1);
    }
    
    int filesize = fsize(fp);
    char *buff = malloc(sizeof(char) * (filesize + 1));
    for(int i = 0; i < filesize + 1; i++){
        int c = fgetc(fp);
        if(feof(fp)){
            break;
        }

        buff[i] = c;
    }

    fclose(fp);
    
    printf("%s",buff);
    printf("\n");

    free(buff);
}