#include <stdio.h>
#include <stdint.h>

//#include "stack.h"
#include "vm.h"


int main(int argc, char *argv[]){


    //simple test program to get infrastructure working
    uint8_t program[] = {
        0x19, 0x0A, // Push Immediate value [10] to stack
        0x03, // Pop top of stack into X 
        0x0B, // Increment X
        0x0B, // Increment X
        0x0B, // Increment X
        0x1A, // Push val of X to stack
        0x1C, // Output top of stack to console as number (should be 13)
        0x01  // Halt
        };
    VM vm;
    init_vm(&vm, &program[0], (sizeof(program) / sizeof(program[0])));


    while(vm.flags.H == 0){
        clock(&vm);
    }

    return 0;
}