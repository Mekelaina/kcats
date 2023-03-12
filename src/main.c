#include <stdio.h>

#include "reader.h"

int main(int argc, char *argv[]){

    if(argc < 1){
        printf("Please provide a .kcats file to run.");
        return 0;
    }

    Reader reader;
    initReader(&reader);
    setFile(&reader, argv[1]);
    readFile(&reader);
    printf("%s\n", reader.content);
    freeReader(&reader);

    return 0;
}