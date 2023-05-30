#ifndef KCATS_VM_H
#define KCATS_VM_H

#include <stdint.h>
#include "stack.h"
//#include "opcode.h"


typedef struct flags{
    unsigned C : 1; // carry flag
    unsigned B : 1; // boolean flag
    unsigned D : 1; // divide by zero flag
    unsigned H : 1; // Halting flag
 // unsigned Z : 1; // zero flag
 // unsigned R : 1; // remainder flag (unsigned integer subtraction and division)
} Flags;

typedef struct machine{
    Stack    stack;
    Flags    flags;
    uint8_t  REG_X;
    uint8_t  REG_Y;
    uint8_t  REG_Z;
    uint16_t PC;
    uint8_t  OP;
    uint8_t *program;
    uint16_t programSize;
} VM;

void init_vm(VM *vm, uint8_t *program, uint16_t programSize);

void clock(VM *vm);


#endif