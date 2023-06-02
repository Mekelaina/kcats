#ifndef KCATS_ALU_H
#define KCATS_ALU_H

#include <stdint.h>
#include "flags.h"


#define BIT_0 00000001
#define BIT_1 00000010
#define BIT_2 00000100
#define BIT_3 00001000
#define BIT_4 00010000
#define BIT_5 00100000
#define BIT_6 01000000
#define BIT_7 10000000


/*
* Shift all bits to the left by one if direction is zero, to the right if not.
* preserves sign bit 
*/
void signedShift(uint8_t *Accumulator, Flags *flags, uint8_t direction);

/*
* Shift all bits to the left by one if direction is zero, to the right if not.
* does NOT preserve sign bit 
*/
void unsignedShift(uint8_t *Accumulator, Flags *flags, uint8_t direction);

/* 
* Rotate/circular shift all bits by 1. left if 0, right otherwise.
* out bit is set in carry flag and carry flag is shifted in.
*/
void rotateBits(uint8_t *Accumulator, Flags *flags, uint8_t direction);

/* 
* Adds argument and carry to Accumulator, updates flags.
* Carry set: sum + 1
* Carry clear: sum
*/
void addCarry(uint8_t *Accumulator, Flags *flags, uint8_t argument);



void multiply(uint8_t *Accumulator, Flags *flags, uint8_t argument);

void multiplyLong(uint8_t *R0, uint8_t *R1, Flags *flags, uint8_t Accumulator, uint8_t argument);

void divide(uint8_t *Accumulator, Flags *flags, uint8_t argument);

void divideLong(uint8_t *R0, uint8_t *R1, Flags *flags, uint8_t Accumulator, uint8_t argument);

void modulo(uint8_t *Accumulator, Flags *flags, uint8_t argument);

void moduloLong(uint8_t *R0, uint8_t *R1, Flags *flags, uint8_t Accumulator, uint8_t argument);


/*
* Subtracts argument and borrow from Accumulator, updates flags.
* Carry clear: difference
* Carry set: difference - 1
*/
void subtractBorrow(uint8_t *Accumulator, Flags *flags, uint8_t argument);

/* 
* preforms bitwise AND on accumulator and argument.
* updates sign (Negative) and Zero flags
*/
void bitAND(uint8_t *Accumulator, Flags *flags, uint8_t argument);

/* 
* preforms bitwise OR on accumulator and argument.
* updates sign (Negative) and Zero flags 
*/
void bitOR(uint8_t *Accumulator, Flags *flags, uint8_t argument);

/*
* preforms bitwise XOR on accumulator and argument.
* updates sign (Negative) and Zero flags
*/
void bitXOR(uint8_t *Accumulator, Flags *flags, uint8_t argument);

/*
* compares value in Accumulator with argument. updates Carry, Zero, and Negative
* Accumulator > argument Carry = 1, rest 0
* Accumulator = argument Zero = 1, rest 0
* Accumulator < argument Negative = 1, rest 0
*/
void compare(uint8_t *Accumulator, Flags *flags, uint8_t argument);

#endif