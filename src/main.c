#include <stdio.h>

#include "reader.h"

int main(int argc, char *argv[]){

    if(argc < 1){
        printf("Please provide a .kcats file to run.");
        return 0;
    }

    readfile(argv[1]);
    return 0;
}