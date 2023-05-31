#include <stdio.h>

#include "alu.h"
#include "flags.h"

int main(){

    uint8_t a = 80;
    uint8_t b = 80;
    Flags flags;
    flags.Carry = 0;

    addCarry(&a, &flags, b);

    printf("Value: %hhu\n", a);
    printf("Carry: %u\n", flags.Carry);
    printf("Negative: %u\n", flags.Negative);
    printf("Overflow: %u\n", flags.Overflow);

    a = 80;
    b = 176;
    
    SubtractBorrow(&a, &flags, b);

    printf("Value: %hhu\n", a);
    printf("Carry: %u\n", flags.Carry);
    printf("Negative: %u\n", flags.Negative);
    printf("Overflow: %u\n", flags.Overflow);

    return 0;
}