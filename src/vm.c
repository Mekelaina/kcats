#include "vm.h"



















void init_vm(VM *vm, uint8_t *program, uint16_t programSize){
    vm->program = program;
    vm->programSize = programSize;

    vm->flags.Negative = 0;
    vm->flags.Overflow = 0;
    vm->flags.Carry = 0;
    vm->flags.Halt = 0;

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

}