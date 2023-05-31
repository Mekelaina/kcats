#include <stdio.h>

#include "vm.h"

int main(){

    VM vm;
    uint8_t program[] = {0};
    init_vm(&vm, program, 1);
    
    pushStack(&vm, 2);
    pushStack(&vm, 4);
    pushStack(&vm, 8);
    pushStack(&vm, 16);
    pushStack(&vm, 32);
    pushStack(&vm, 64);

    uint8_t x = popStack(&vm);

    printf("tip tip: %d %d", x, vm.Z);

    dumpStack(&vm);    

    return 0;
}