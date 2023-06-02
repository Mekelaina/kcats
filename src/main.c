#include <stdio.h>

#include "vm.h"
#include "alu.h"

int main(){

     VM vm;
     uint8_t program[] = {0};
     init_vm(&vm, program, 1);

    vm.A = 50;

    vm.flags.Carry = 0;

    // multiply(&(vm.A), &(vm.flags), 3);

    
    //multiply(&(vm.A), &(vm.flags), 5);

    //multiplyLong(&(vm.R0), &(vm.R1), &(vm.flags), vm.A, 55);

    divide(&(vm.A), &(vm.flags), 5);

    printf("%d\n", vm.A);
    printf("N%d O%d H%d F%d Z%d C%d\n", vm.flags.Negative, vm.flags.Overflow, vm.flags.Halt, vm.flags.Flipped, vm.flags.Zero, vm.flags.Carry);    
    //printf("LB: %d, HB: %d\n", vm.R0, vm.R1);

    return 0;
}