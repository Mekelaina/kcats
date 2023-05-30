#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "input.h"



static int getInputSize(char c[]){
    int size = 0;
    for(int i = 0; i < BUFFER_SIZE; ++i){
        if(c[i] == NULL || c[i] == '\n'){
            break;
        }
        size++;
    }
    return size;
}


static int checkForNums(char c[]){
    int length = getInputSize(c);
    int rtn = 0;

    if(c[0] == '$'){
        for (int i = 0; i < length; ++i){
            if(isxdigit(c[i]) != 0){
                rtn = 1;
            } else {
                rtn = 0;
            }
            return rtn;   
        }
        
    } else if (c[0] == '&'){
        for (int i = 0; i < length; ++i){
            if(c[i] == '0' || c[i] == '1'){
                rtn = 3;
            } else {
                rtn = 0;
            }
            return rtn;   
        }
    }

    if(length < 3){
        for(int i = 0; i < length; ++i){
            if(isxdigit(c[i]) != 0){
                rtn = 1;
            }
        }
    } else if (length == 3) {
        for(int i = 0; i < length; ++i){
            if(isdigit(c[i]) != 0){
                rtn = 2;
            }
        }
    } else {
        for(int i = 0; i < length; ++i){
            if(c[i] == '0' || c[i] == '1'){
                rtn = 3;
            } 
        }
    }

    return rtn;
    
}


uint8_t getNumber(){
    char buffer[BUFFER_SIZE];
    unsigned long ul;
    fgets(buffer, BUFFER_SIZE, stdin);

    int numtype = checkForNums(buffer);
    switch(numtype) {
    case 0: ul = 0; break;
    case 1: ul = strtoul(buffer, NULL, 16); break;
    case 2: ul = strtoul(buffer, NULL, 10); break;
    case 3: ul = strtoul(buffer, NULL, 02); break;
    
    default:
        printf("what?\n");
        break;
    }

    uint8_t rtn = (uint8_t) ul;

    return rtn;
}

char*  getString(){
    return 0;
}
