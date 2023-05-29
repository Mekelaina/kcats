#include "vm.h"
#include "opcode.h"

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

static void execute(VM *vm){
    uint8_t a, b = 0;
    
    switch(vm->OP){
        case NO_OP: break;
        case HALT: {
            vm->flags.H = 1;
        } break;
        case LOAD_X: {
            vm->REG_X = pop(&(vm->stack));
        } break;
        case INC_X: {
            a = vm->REG_X;
            a++;
            if(a == 0){
                vm->flags.C = 1;
            }
            vm->REG_X = a;
        } break;
        case PUSH_IM: {
            a = fetchArg(vm);
            push(&(vm->stack), a);
        } break;
        case PUSH_X: {
            push(&(vm->stack), vm->REG_X);
        } break;
        case NUM_OUT: {
            printf("%d\n", pop(&(vm->stack)));
        } break;
        default: {
            printf("unimplemented opcode: %d\n", vm->OP);
        } break;
    }
}

void init_vm(VM *vm, uint8_t *program, uint16_t programSize){
    init_stack(&(vm->stack));
    vm->flags.C = 0;
    //vm->flags.Z = 0;
    vm->flags.B = 0;
    vm->flags.D = 0;
    //vm->flags.R = 0;
    vm->flags.H = 0;

    vm->REG_X = 0;
    vm->REG_Y = 0;
    vm->REG_Z = 0;
    vm->PC = 0;
    vm->OP = 0;
    vm->program = program;
    vm->programSize = programSize;
}

void clock(VM *vm){
    fetchInstruction(vm);
    execute(vm);
}