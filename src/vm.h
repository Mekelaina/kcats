#ifndef KCATS_VM_H
#define KCATS_VM_H

#include <stdint.h>
#include "flags.h"

#define STACK_SIZE 256


typedef struct vm {
    Flags flags;
    uint16_t PC;                // Program Counter
    uint16_t RTN;               // Return address register for subroutines
    uint16_t programSize;       // Size of current program
    uint8_t *program;           // Program to execute
    uint8_t OP;                 // Curent Opcode to execute
    uint8_t A;                  // Accumulator
    uint8_t X;                  // X Index Register
    uint8_t Y;                  // Y Index Register
    uint8_t Z;                  // Stack pointer. is modified with any op that pushes or pops from stack
                                // can also be manually incremented or decremented.
    uint8_t R0, R1, R2, R3;     // Scratch registers. used to hold values while doing something. (especialy when moving around the stack often)
    uint8_t stack[STACK_SIZE];  // the stack itself. 
} VM;

void init_vm(VM *vm, uint8_t *program, uint16_t programSize);

void clock(VM *vm);

void dumpStack(VM *vm);

void pushStack(VM *vm, uint8_t value);

uint8_t popStack(VM *vm);

#endif