#include <stdio.h>
#include <stdint.h>

//#include "stack.h"
#include "vm.h"


int main(int argc, char *argv[]){


    //simple test program to get infrastructure working
    uint8_t program[] = {
        0x03, 0x0A, // Push Immediate value [10] to stack
        0x0F, // Pop top of the stack into X 
        0x17, // Increment X
        0x17, // Increment X
        0x17, // Increment X
        0x04, // Push val of X to stack
        0x1B, // Output top of stack to console as number (should be 13)
        0xFF  // Halt
        };
    VM vm;
    init_vm(&vm, &program[0], (sizeof(program) / sizeof(program[0])));


    while(vm.flags.H == 0){
        clock(&vm);
    }

    return 0;
}