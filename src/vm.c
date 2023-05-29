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

        case POP: {
            pop(&(vm->stack));
        } break;
        case PUSH: {
            push(&(vm->stack), peak(&(vm->stack)));
        } break;
        case PUSH_IM: { 
            push(&(vm->stack), fetchArg(vm));
        } break;
        case PUSH_X: {
            push(&(vm->stack), vm->REG_X);
        } break;
        case PUSH_Y: {
            push(&(vm->stack), vm->REG_Y);
        } break;
        case LOAD_X: {
            vm->REG_X = pop(&(vm->stack));
        } break;
        case INC_X: {
            vm->REG_X++;

            if(vm->REG_X == 0){
                vm->flags.C = 1;
            }
        } break;

        case NUM_OUT: {
            printf("%d\n", pop(&(vm->stack)));
        } break;
        case HALT: {
            vm->flags.H = 1;
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