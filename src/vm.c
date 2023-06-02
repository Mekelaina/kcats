#include "vm.h"
#include "opcode.h"
#include "alu.h"
#include <stdio.h>



static void fetchInstruction(VM *vm){
    if(vm->PC < vm->programSize){
        vm->OP = *((vm->program)+vm->PC);
        vm->PC++;
    }
}

static uint8_t fetchArg(VM *vm){
    uint8_t x = 0;
    if(vm->PC < vm->programSize){
        x = *((vm->program)+vm->PC);
        vm->PC++;
    }
    return x;
}

uint8_t popStack(VM *vm){
    vm->Z--;
    uint8_t val = vm->stack[vm->Z];
    return val;
}

void pushStack(VM *vm, uint8_t value){
    vm->stack[vm->Z] = value;
    vm->Z++;
}

void dumpStack(VM *vm){
    printf("DEBUG:\n       -----  Stack Dump  -----\n");
    printf("             Stack Top: %d\n", vm->Z);
    int c = 0;
    printf("       ");
    for(int i = 0; i < STACK_SIZE; ++i){
        if(c == 8){
            printf("\n       ");
            c = 0;
        }
        printf("%02x: %03d", i, (vm->stack)[i]);
        printf(", ");
        c++;
    }
    printf("\n");
}

static void executeInstruction(VM *vm);

void init_vm(VM *vm, uint8_t *program, uint16_t programSize){
    vm->program = program;
    vm->programSize = programSize;

    vm->flags.Negative = 0;
    vm->flags.Overflow = 0;
    vm->flags.Carry = 0;
    vm->flags.Halt = 0;
    vm->flags.Zero = 0;
    vm->flags.Flipped = 0;

    vm->PC = 0;
    vm->RTN = 0;
    vm->OP = 0;
    vm->A = 0;
    vm->X = 0;
    vm->Y = 0;
    vm->Z = 0;
    vm->R0 = 0;
    vm->R1 = 0;
    vm->R2 = 0;
    vm->R3 = 0;
}

void clock(VM *vm){
    fetchInstruction(vm);
    executeInstruction(vm);
}

static void executeInstruction(VM *vm){
    
}