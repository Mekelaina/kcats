#ifndef KCATS_FLAGS_H
#define KCATS_FLAGS_H 

typedef struct flags {
    unsigned Negative : 1; //b7
    unsigned Overflow : 1; //b6
    unsigned Halt     : 1; //b5
    unsigned Unused   : 3; //b2 - b4 
    unsigned Zero     : 1; //b1
    unsigned Carry    : 1; //b0
} Flags;


#endif