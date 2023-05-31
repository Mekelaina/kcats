#include "alu.h"
#include <stdio.h>


// Shift all bits to the left by one if direction is zero, to the right if not.
// preserves sign bit
void signedShift(uint8_t *Accumulator, Flags *flags, uint8_t direction){
    uint8_t z = 0;
    uint8_t val = *Accumulator;
    if(direction == 0){
        z = (val << 1);
        if(val & BIT_7){
            z |= (1 << 7);
        } 
    } else {
        z = (val >> 1);
        if(val & BIT_7){
            z |= (1 << 7);
        }
    }

    if(z == 0){
        flags->Zero = 1;
    } else {
        flags->Zero = 0;
    }

    flags->Negative = ((z & BIT_7) >> 7);
    *Accumulator = z;
}

// Shift all bits to the left by one if direction is zero, to the right if not.
// does NOT preserve sign bit
void unsignedShift(uint8_t *Accumulator, Flags *flags ,uint8_t direction){
    uint8_t z = 0;
    uint8_t val = *Accumulator;
    if(direction == 0){
        z = (val << 1);
    } else {
        z = (val >> 1);
    }

    if(z == 0){
    flags->Zero = 1;
    } else {
        flags->Zero = 0;
    }

    flags->Negative = ((z & BIT_7) >> 7);
    *Accumulator = z;
}

// Rotate/circular shift all bits by 1. left if 0, right otherwise.
// out bit is set in carry flag and carry flag is shifted in.
void rotateBits(uint8_t *Accumulator, Flags *flags, uint8_t direction){
    uint8_t z = 0;
    uint8_t val = *Accumulator;
    if(direction == 0){
        z = (val << 1);   
        z |= (flags->Carry) << 0;
        flags->Carry = ((val & BIT_7) >> 7);
    } else {
        z = (val >> 1);   
        z |= (flags->Carry) << 7;
        flags->Carry = ((val & BIT_0) >> 0);
    }

    if(z == 0){
    flags->Zero = 1;
    } else {
        flags->Zero = 0;
    }

    flags->Negative = ((z & BIT_7) >> 7);
    *Accumulator = z;
}

// Adds argument and carry to Accumulator, updates flags.
// Carry set: sum + 1
// Carry clear: sum
void addCarry(uint8_t *Accumulator, Flags *flags, uint8_t argument){
    uint8_t z = 0;
    uint8_t carryIn = (0 | ((flags->Carry) << 0));
    uint8_t val = *Accumulator;
    if((val + argument + carryIn) > 255){
        flags->Carry = 1;
    } else {
        flags->Carry = 0; 
    }
    z = (val + argument + carryIn);
    
    if((val ^ z) & (argument ^ z) & 0x80){
        flags->Overflow = 1;
    } else {
        flags->Overflow = 0;
    }
    
    if(z == 0){
    flags->Zero = 1;
    } else {
        flags->Zero = 0;
    }

    flags->Negative = ((z & BIT_7) >> 7);
    *Accumulator = z; 
}

// Subtracts argument and borrow from Accumulator, updates flags.
// Carry clear: difference
// Carry set: difference - 1
void SubtractBorrow(uint8_t *Accumulator, Flags *flags, uint8_t argument){
    uint8_t val = *Accumulator;
    flags->Carry = ~(flags->Carry);
    addCarry(&val, flags, ~argument);
    *Accumulator = val;
}


// preforms bitwise AND on accumulator and argument.
// updates sign (Negative) and Zero flags
void bitAND(uint8_t *Accumulator, Flags *flags, uint8_t argument){
    uint8_t z = 0;
    uint8_t val = *Accumulator;
    z = (val & argument);

    if(z == 0){
    flags->Zero = 1;
    } else {
        flags->Zero = 0;
    }

    flags->Negative = ((z & BIT_7) >> 7);
    *Accumulator = z;
}

// preforms bitwise OR on accumulator and argument.
// updates sign (Negative) and Zero flags
void bitOR(uint8_t *Accumulator, Flags *flags, uint8_t argument){
    uint8_t z = 0;
    uint8_t val = *Accumulator;
    z = (val | argument);

    if(z == 0){
    flags->Zero = 1;
    } else {
        flags->Zero = 0;
    }

    flags->Negative = ((z & BIT_7) >> 7);
    *Accumulator = z;
}

// preforms bitwise XOR on accumulator and argument.
// updates sign (Negative) and Zero flags
void bitXOR(uint8_t *Accumulator, Flags *flags, uint8_t argument){
    uint8_t z = 0;
    uint8_t val = *Accumulator;
    z = (val ^ argument);

    if(z == 0){
    flags->Zero = 1;
    } else {
        flags->Zero = 0;
    }

    flags->Negative = ((z & BIT_7) >> 7);
    *Accumulator = z;
}

// compares value in Accumulator with argument. updates Carry, Zero, and Negative
// Accumulator > argument Carry = 1, rest 0
// Accumulator = argument Zero = 1, rest 0
// Accumulator < argument Negative = 1, rest 0
void compare(uint8_t *Accumulator, Flags *flags, uint8_t argument){
    uint8_t val = *Accumulator;
    if(val > argument){
        flags->Carry = 1;
        flags->Zero = 0;
        flags->Negative = 0;
    } else if(val == argument){
        flags->Carry = 0;
        flags->Zero = 1;
        flags->Negative = 0;
    } else {
        flags->Carry = 0;
        flags->Zero = 0;
        flags->Negative = 1;
    }
}