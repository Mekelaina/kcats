#include <stdio.h>
#include <stdint.h>

//#include "stack.h"
#include "vm.h"
#include "opcode.h"

int main(int argc, char *argv[]){


    // Stack s;
    // init_stack(&s);
    // uint8_t data[] = {10, 12, 30, 40, 50};
    // push(&s, 5);
    // dump(&s);



    // return 0;


    //simple test program to get infrastructure working
    uint8_t program[] = {
        NO_OP,
        PUSH_IM, 0x0A, // Push Immediate value [10] to stack
        LOAD_X, // Pop top of the stack into X 
        INC_X, // Increment X
        INC_X, // Increment X
        INC_X, // Increment X
        PUSH_X, // Push val of X to stack
        NUM_OUT, // Output top of stack to console as number (should be 13)
        HALT  // Halt
        };
    VM vm;
    init_vm(&vm, &program[0], (sizeof(program) / sizeof(program[0])));


    for(int x = 0; x < vm.programSize; ++x){
        clock(&vm);
        //dump(&(vm.stack));
    }


    // while(vm.flags.H == 0){
    //     clock(&vm);
    // }

    return 0;
}