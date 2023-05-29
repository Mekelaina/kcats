# Kcats VM Opcode Reference 



| Instruction | Nmemonic | Addressing Mode | Opcode | Syntax | Description |
|:---:|:---:|:---:|:---:|:---:|:---:|
| No OP | NOP | Implied | 00 | `NOP` | No Operation. skips current clock cycle |
| Pop from Stack | POP | Implied | 01 | `POP` | Discards the value on the top of the stack |
| Push to Stack | PSH | Implied | 02 | `PSH` | Duplicates the value on the top of the stack |
| Push to Stack | PSH | Immediate | 03 | `PSH $val` | Push the immediate value to the stack |
| Push to Stack | PSH | X Register | 04 | `PSH X` | Push the value of X to the stack |
| Push to Stack | PSH | Y Register | 05 | `PSH Y` | Push the value of Y to the stack |
| Stack Swap | SWP | Implied | 06 | `SWP` | Swaps the Top two values on the stack (a b -- b a) |
| Stack Over | OVR | Implied | 07 | `OVR` | Duplicates the value under the Top of the stack and pushes it to the top. (a b -- a b a) |
| Stack Rotate | ROT | Implied | 08 | `ROT` | Rotates the Top 3 values on the stack. (a b c -- c a b) |
| Stack Rotate | ROT | Immediate | 09 | `ROT $val` | Rotates the Top (immediate value) values on the stack. if the value is greater than the number of items on the stack, nothing is rotated and a 0 is pushed. |
| Stack Rotate | ROT | X Register | 0A | `ROT X` | Rotates the Top (value in X) values on the stack. if the value is greater than the number of items on the stack, nothing is rotated and a 0 is pushed. |
| Stack Rotate | ROT | Y Register | 0B | `ROT Y` | Rotates the Top (value in Y) values on the stack. if the value is greater than the number of items on the stack, nothing is rotated and a 0 is pushed. |
| Clear Carry Flag | CLC | Implied | 0C | `CLC` | Clears the Carry Flag |
| Clear Boolean Flag | CBL | Implied | 0D | `CBL` | Clears the Boolean Flag |
| Clear Div By Zero Flag | CDZ | Implied | 0E | `CDZ` | Clears the Div By Zero Flag |
| Load X | LDX | Implied | 0F | `LDX` | Pops top of the stack and stores it in X |
| Load X | LDX | Immediate | 10 | `LDX $val` | Loads X with the immediate value |
| Load X | LDX | Y Register | 11 | `LDX Y` | Loads X with the value in Y |
| Load X | LDX | Z Register | 12 | `LDX Z` | Loads X with the value of Z |
| Load Y | LDY | Implied | 13 | `LDY` | Pops top of the stack and stores it in Y |
| Load Y | LDY | Immediate | 14 | `LDY $val` | Loads Y with the immediate value |
| Load Y | LDY | X Register | 15 | `LDY X` | Loads Y with the value in X |
| Load Y | LDY | Z Register | 16 | `LDY Z` | Loads Y with the value of Z |
| Increment X | INX | Implied | 17 | `INX` | Increments the value of X |
| Decrement X | DEX | Implied | 18 | `DEX` | Decrements the value of X |
| Increment Y | INY | Implied | 19 | `INY` | Increments the value of Y |
| Decrement Y | DEY | Implied | 1A | `DEY` | Decrements the value of Y |
| Output as Number | OUT | Implied | 1B | `OUT` | Prints the top value of the stack as a number |
| Output as Number | OUT | X Register | 1C | `OUT X` | Print the value of X as a number |
| Output as Number | OUT | Y Register | 1D | `Out Y` | Print the value of Y as a number |
| Output as Number | Out | Z Register | 1E | `Out Z` | Print the value of Z as a number |
| Print as ASCII | PRT | Implied | 1F | `PRT` | Prints the top value of the stack as ASCII |
| Print as ASCII | PRT | X Register | 20 | `PRT X` | Prints the value of X as ASCII |
| Print as ASCII | PRT | Y Register | 21 | `PRT Y` | Prints the value of Y as ASCII |
| Get Input from Console | INP | Implied | 22 | `INP` | Get input from console and push it to stack |
| Unconditional Jump | JMP | Implied | 23 | `JMP` | Pops the value on top of the stack and jumps to that address |
| Unconditional Jump | JMP | Immediate | 24 | `JMP $val` | Jumps to the address specified by the immediate val |
| Unconditional Jump | JMP | X Register | 25 | `JMP X` | Jumps to X's value as an address |
| Unconditional Jump | JMP | Y Register | 26 | `JMP Y` | Jumps to Y's value as an address |
| Unconditional Long Jump | LJMP | Implied | 27 | `LJMP` | Pops the top two values of the stack and jumps to that 16bit address.LB popped first. |
| Unconditional Long Jump | LJMP | Immediate (2 byte) | 28 | `LJMP $HBLB`/`LJMP $HB $LB` | Jumps to the 16bit address specified by the immediate values |
| Unconditional Long Jump | LJMP | X and Y Registers | 29 | `LJMP X Y` | Jumps to X and Y's values as a single 16bit address.X is HB Y is LB |
| Jump If Carry | JFC | Implied | 2A | `JFC` | If the Carry Flag IS set,Pops the top two values of the stack and jumps to that 16bit address.LB popped first. |
| Jump If Carry | JFC | Immediate | 2B | `JFC $val` | If the Carry Flag IS set,Jumps to the address specified by the immediate value |
| Jump If Carry | JFC | X Register | 2C | `JFC X` | If the Carry Flag IS set,Jumps to X's value as an address |
| Jump If Carry | JFC | Y Register | 2D | `JFC Y` | If the Carry Flag IS set,Jumps to Y's value as an address |
| Long Jump If Carry | LJFC | Implied | 2E | `LJFC` | Pops the top two values of the stack and jumps to that 16bit address.LB popped first. |
| Long Jump If Carry | LJFC | Immediate (2 byte) | 2F | `LJFC $HBLB`/`LJFC $HB $LB` | Jumps to the 16bit address specified by the immediate values |
| Long Jump If Carry | LJFC | X and Y Registers | 30 | `LJFC X Y` | Jumps to X and Y's values as a single 16bit address.X is HB Y is LB |
| Jump If True | JIF | Implied | 31 | `JIF` | If the Boolean Flag IS set,Pops the value on top of the stack and jumps to that address |
| Jump If True | JIF | Immediate | 32 | `JIF $val` | If the Boolean Flag IS set,Jumps to the address specified by the immediate val |
| Jump If True | JIF | X Register | 33 | `JIF X` | If the Boolean Flag IS set,Jumps to X's value as an address |
| Jump If True | JIF | Y Register | 34 | `JIF Y` | If the Boolean Flag IS set,Jumps to Y's value as an address |
| Long Jump If True | LJIF | Implied | 35 | `LJIF` | If the Boolean Flag IS set,Pops the top two values of the stack and jumps to that 16bit address.LB popped first. |
| Long Jump If True | LJIF | Immediate (2 byte) | 36 | `LJIF $HBLB`/`LJIF $HB $LB` | If the Boolean Flag IS set,Jumps to the 16bit address specified by the immediate vals |
| Long Jump If True | LJIF | X and Y Registers | 37 | `LJIF X Y` | If the Boolean Flag IS set, Jumps to X and Y's values as a single 16bit address. X is HB Y is LB |
| Jump If Div by Zero | JDZ | Implied | 38 | `JDZ` | If the Div by Zero Flag IS set,Pops the value on top of the stack and jumps to that address |
| Jump If Div by Zero | JDZ | Immediate | 39 | `JDZ $val` | If the Div by Zero Flag IS set,Jumps to the address specified by the immediate val |
| Jump If Div by Zero | JDZ | X Register | 3A | `JDZ X` | If the Div by Zero Flag IS set,Jumps to X's value as an address |
| Jump If Div by Zero | JDZ | Y Register | 3B | `JDZ Y` | If the Div by Zero Flag IS set,Jumps to Y's value as an address |
| Long Jump If Div by Zero | LJDZ | Implied | 3C | `LJDZ` | If the Div by Zero Flag IS set,Pops the top two values of the stack and jumps to that 16bit address.LB popped first. |
| Long Jump If Div by Zero | LJDZ | Immediate (2 byte) | 3D | `LJDZ $HBLB`/`LJDZ $HB $LB` | If the Div by Zero Flag IS set,Jumps to the 16bit address specified by the immediate vals |
| Long Jump If Div by Zero | LJDZ | X and Y Registers | 3E | `LJDZ X Y` | If the Div by Zero Flag IS set, Jumps to X and Y's values as a single 16bit address. X is HB Y is LB |
| Add<sup>1</sup> | ADD | Implied | 3F | `ADD` | Pops top two values off the stack stack, pushes their sum (2nd off + 1st off) |
| Add<sup>1</sup> | ADD | Immediate | 40 | `ADD $val` | Pops top value off the stack, sums it and immediate val, pushes result (Top + Val) |
| Add<sup>1</sup> | ADD | Immediate (2 byte) | 41 | `ADD $A $B` | Pushes the sum of two immediate values (A + B) |
| Add<sup>1</sup> | ADD | X Register | 42 | `ADD X` | Pops top value off the stack, sums it and X, pushes result (Top + X) |
| Add<sup>1</sup> | ADD | Y Register | 43 | `ADD Y` | Pops top value off the stack, sums it and Y, pushes result (Top + Y) |
| Add<sup>1</sup> | ADD | X and Y Registers | 44 | `ADD X Y` | Pushes the sum of X and Y (X + Y) |
| Subtract<sup>1</sup> | SUB | Implied | 45 | `SUB` | Pops top two values off the stack, pushes their difference. (2nd off - 1st off) |
| Subtract<sup>1</sup> | SUB | Immediate | 46 | `SUB $val` | Pops top value off the stack, subtracts immediate value from it, pushes result (Top - Val) |
| Subtract<sup>1</sup> | SUB | Immediate (2 byte) | 47 | `SUB $A $B` | Pushes the difference of two immediate values (A - B) |
| Subtract<sup>1</sup> | SUB | X Register | 48 | `SUB X` | Pops top value off the stack, subtracts X from it, pushes result (Top - X) |
| Subtract<sup>1</sup> | SUB | Y Register | 49 | `SUB Y` | Pops top value off the stack, subtracts Y from it, pushes result (Top - Y) |
| Subtract<sup>1</sup> | SUB | X and Y Registers | 4A | `SUB X Y` | Pushes the difference of X and Y (X - Y) |
| Multiply<sup>1</sup> | MUL | Implied | 4B | `MUL` | Pops top two values off the stack, pushes their product (2nd off * 1st off) |
| Multiply<sup>1</sup> | MUL | Immediate | 4C | `MUL $val` | Pops top value off the stack, multiplies it by the immediate val, pushes result (Top * Val) |
| Multiply<sup>1</sup> | MUL | Immediate (2 byte) | 4D | `MUL $A $B` | Pushes the product of two immediate values (A * B) |
| Multiply<sup>1</sup> | MUL | X Register | 4E | `MUL X` | Pops top value off the stack, multiplies it by X, pushes result (Top * X) |
| Multiply<sup>1</sup> | MUL | Y Register | 4F | `MUL Y` | Pops top value off the stack, multiplies it by Y, pushes result (Top * Y) |
| Multiply<sup>1</sup> | MUL | X and Y Registers | 50 | `MUL X Y` | Pushes the product of X and Y (X * Y) |
| Divide<sup>2</sup> | DIV | Implied | 51 | `DIV` | Pops top two values off the stack, pushes their quotient. then remainder (2nd off / 1st off) |
| Divide<sup>2</sup> | DIV | Immediate | 52 | `DIV $val` | Pops top value off the stack, divides it by the immediate val, pushes quotient then remainder. (Top / Val) |
| Divide<sup>2</sup> | DIV | Immediate (2 byte) | 53 | `DIV $A $B` | Pushes the quotient, then remainder, of two immediate values. (A / B) |
| Divide<sup>2</sup> | DIV | X Register | 54 | `DIV X` | Pops top value off the stack, divides it by X, pushes the quotient, then remainder. (Top / X) |
| Divide<sup>2</sup> | DIV | Y Register | 55 | `DIV Y` | Pops top value off the stack, divides it by Y, then pushes the quotient, then remainder. (Top / Y) |
| Divide<sup>2</sup> | DIV | X and Y Registers | 56 | `DIV X Y` | Pushes the quotient, then remainder, of X and Y. (X / Y) |
| Bitwise Rotate Left | RTL | Implied | 57 | `RTL` | Pops top value off the stack, rotates all bits to the left once. pushes result. (Most significant bit wrapping around to least significant bit) (0001 -> 1000) |
| Bitwise Rotate Left | RTL | Immediate | 58 | `RTL $val` | rotates all bits of immediate value to the left once. pushes result. (Most significant bit wrapping around to least significant bit) (0001 -> 1000) |
| Bitwise Rotate Left | RTL | X Register | 59 | `RTL X` | rotates all bits of X to the left once. pushes result. (Most significant bit wrapping around to least significant bit) (0001 -> 1000) |
| Bitwise Rotate Left | RTL | Y Register | 5A | `RTL Y` | rotates all bits of Y to the left once. pushes result. (Most significant bit wrapping around to least significant bit) (0001 -> 1000) |
| Bitwise Rotate Right | RTR | Implied | 5B | `RTR` | Pops top value off the stack, rotates all bits to the right once. pushes result. (Least significant bit wrapping around to most significant bit) (0001 -> 1000) |
| Bitwise Rotate Right | RTR | Immediate | 5C | `RTR $val` | rotates all bits of immediate value to the right once. pushes result. (Most significant bit wrapping around to least significant bit) (0001 -> 1000) |
| Bitwise Rotate Right | RTR | X Register | 5D | `RTR X` | rotates all bits of X to the right once. pushes result. (Most significant bit wrapping around to least significant bit) (0001 -> 1000) |
| Bitwise Rotate Right | RTR | Y Register | 5E | `RTR Y` | rotates all bits of Y to the right once. pushes result. (Most significant bit wrapping around to least significant bit) (0001 -> 1000) |
| Bitwise Shift Left | SHL | Implied | 5F | `SHL` | Pops top value off the stack, shifts all bits to the left once. pushes result. (vacent bits padded with zeros) (1001 -> 0010) |
| Bitwise Shift Left | SHL | Immediate | 60 | `SHL $val` | Shifts all bits of immediate value to the left once. pushes result. (vacent bits padded with zeros) (1001 -> 0010) |
| Bitwise Shift Left | SHL | X Register | 61 | `SHL X` | Shifts all bits of X to the left once. pushes result. (vacent bits padded with zeros) (1001 -> 0010) |
| Bitwise Shift Left | SHL | Y Register | 62 | `SHL Y` | Shifts all bits of Y to the left once. pushes result. (vacent bits padded with zeros) (1001 -> 0010) |
| Bitwise Shift Right | SHR | Implied | 63 | `SHR` | Pops top value off the stack, shifts all bits to the right once. pushes result. (vacent bits padded with zeros) (1001 -> 0100) |
| Bitwise Shift Right | SHR | Immediate | 64 | `SHR $val` | Shifts all bits of immediate value to the right once. pushes result. (vacent bits padded with zeros) (1001 -> 0100) |
| Bitwise Shift Right | SHR | X Register | 65 | `SHR X` | Shifts all bits of X to the right once. pushes result. (vacent bits padded with zeros) (1001 -> 0100) |
| Bitwise Shift Right | SHR | Y Register | 66 | `SHR Y` | Shifts all bits of Y to the right once. pushes result. (vacent bits padded with zeros) (1001 -> 0100) |
| Bitwise And | AND | Implied | 67 | `AND` | Pops the top two values off the stack, preforms bitwise/binary and on them (2nd off & 1st off), pushes result |
| Bitwise And | AND | Immediate | 68 | `AND $val` | Pops top value off the stack, preforms bitwise/binary and on it and the immediate value (Top & Val), pushes result |
| Bitwise And | AND | Immediate (2 byte) | 69 | `AND $A $B` | Pushes the bitwise/binary and of the two immediate values (A & B) |
| Bitwise And | AND | X Register | 6A | `AND X` | Pops top value off the stack, preforms bitwise/binary and on it and X (Top & X), pushes result |
| Bitwise And | AND | Y Register | 6B | `AND Y` | Pops top value off the stack, preforms bitwise/binary and on it and Y (Top & Y), pushes result |
| Bitwise And | AND | X and Y Registers | 6C | `AND X Y` | Pushes the bitwise/binary and of X and Y (X & Y) |
| Bitwise Or | OR | Implied | 6D | `OR` | Pops the top two values off the stack, preforms bitwise/binary or on them (2nd off \| 1st off), pushes result |
| Bitwise Or | OR | Immediate | 6E | `OR $val` | Pops top value off the stack, preforms bitwise/binary or on it and the immediate value (Top \| Val), pushes result |
| Bitwise Or | OR | Immediate (2 byte) | 6F | `OR $A $B` | Pushes the bitwise/binary or of the two immediate values (A \| B) |
| Bitwise Or | OR | X Register | 70 | `OR X` | Pops top value off the stack, preforms bitwise/binary or on it and X (Top \| X), pushes result |
| Bitwise Or | OR | Y Register | 71 | `OR Y` | Pops top value off the stack, preforms bitwise/binary or on it and Y (Top \| Y), pushes result |
| Bitwise Or | OR | X and Y Registers | 72 | `OR X Y` | Pushes the bitwise/binary or of X and Y (X \| Y) |
| Bitwise Xor | XOR | Implied | 73 | `XOR` | Pops the top two values off the stack, preforms bitwise/binary xor on them (2nd off \^ 1st off), pushes result |
| Bitwise Xor | XOR | Immediate | 74 | `XOR $val` | Pops top value off the stack, preforms bitwise/binary xor on it and the immediate value (Top \^ Val), pushes result |
| Bitwise Xor | XOR | Immediate (2 byte) | 75 | `XOR $A $B` | Pushes the bitwise/binary xor of the two immediate values (A \^ B) |
| Bitwise Xor | XOR | X Register | 76 | `XOR X` | Pops top value off the stack, preforms bitwise/binary xor on it and X (Top \^ X), pushes result |
| Bitwise Xor | XOR | Y Register | 77 | `XOR Y` | Pops top value off the stack, preforms bitwise/binary xor on it and Y (Top \^ Y), pushes result |
| Bitwise Xor | XOR | X and Y Registers | 78 | `XOR X Y` | Pushes the bitwise/binary xor of X and Y (X \^ Y) |
| Not/Invert/Complement | NOT | Implied | 79 | `NOT` | Pops the top value off the stack,  inverts each bit (~Top ei 1001 > 0110), pushes result |
| Not/Invert/Complement | NOT | Immediate | 7A | `NOT $val` | Inverts each bit of immediate value (~Val ei 1001 > 0110), pushes result |
| Not/Invert/Complement | NOT | X Register | 7B | `NOT X` | Inverts each bit of X (~X ei 1001 > 0110), pushes result |
| Not/Invert/Complement | NOT | Y Register | 7C | `NOT Y` | Inverts each bit of Y (~Y ei 1001 > 0110), pushes result |
| Is Less Than | LTH | Implied | 7D | `LTH` | Peaks at the top two values off the stack. checks if 2nd off is less than the 1st off. sets the Boolean Flag if true, clears it if false. (2nd off < 1st off) |
| Is Less Than | LTH | Immediate | 7E | `LTH $val` | Peaks at the top value off the stack. checks if it is less than the immediate value. sets the Boolean Flag if true, clears it if false. (Top < Val) |
| Is Less Than | LTH | X Register | 7F | `LTH X` | Peaks at the top value off the stack. checks if it is less than the value in X. sets the Boolean Flag if true, clears it if false. (Top < Val) |
| Is Less Than | LTH | Y Register | 80 | `LTH Y` | Peaks at the top value off the stack. checks if it is less than the value in Y. sets the Boolean Flag if true, clears it if false. (Top < Val) |
| Is Less Than | LTH | Z Register | 81 | `LTH Z` | Peaks at the top value off the stack. checks if it is less than the value in Z. sets the Boolean Flag if true, clears it if false. (Top < Val) |
| Is Less Than | LTH | X Register and Immediate | 82 | `LTH X $val` | Checks if the value in X is less than the immediate value. sets the Boolean Flag if true, clears it if false. (X < Val) |
| Is Less Than | LTH | X and Y Registers | 83 | `LTH X Y` | Checks if the value in X is less than the value in Y. sets the Boolean Flag if true, clears it if false. (X < Y) |
| Is Less Than | LTH | X and Z Registers | 84 | `LTH X Z` | Checks if the value in X is less than the value in Z. sets the Boolean Flag if true, clears it if false. (X < Z) |
| Is Less Than | LTH | Y Register and Immediate | 85 | `LTH Y $val` | Checks if the value in Y is less than the immediate value. sets the Boolean Flag if true, clears it if false. (Y < Val) |
| Is Less Than | LTH | Y and X Registers | 86 | `LTH Y X` | Checks if the value in Y is less than the value in X. sets the Boolean Flag if true, clears it if false. (Y < X) |
| Is Less Than | LTH | Y and Z Registers | 87 | `LTH Y Z` | Checks if the value in Y is less than the value in Z. sets the Boolean Flag if true, clears it if false. (Y < Z) |
| Is Less Than | LTH | Z Register and Immediate | 88 | `LTH Z $val` | Checks if the value in Z is less than the immediate value. sets the Boolean Flag if true, clears it if false. (Z < Val) |
| Is Less Than | LTH | Z and X Registers | 89 | `LTH Z X` | Checks if the value in Z is less than the value in X. sets the Boolean Flag if true, clears it if false. (Z < X) |
| Is Less Than | LTH | Z and Y Registers | 8A | `LTH Z Y` | Checks if the value in Z is less than the value in Z. sets the Boolean Flag if true, clears it if false. (Z < Y) |
| Is Greater Than | GTH | Implied | 8B | `GTH` | Peaks at the top two values off the stack. checks if 2nd off is greater than the 1st off. sets the Boolean Flag if true, clears it if false. (2nd off > 1st off) |
| Is Greater Than | GTH | Immediate | 8C | `GTH $val` | Peaks at the top value off the stack. checks if it is greater than the immediate value. sets the Boolean Flag if true, clears it if false. (Top > Val) |
| Is Greater Than | GTH | X Register | 8D | `GTH X` | Peaks at the top value off the stack. checks if it is greater than the value in X. sets the Boolean Flag if true, clears it if false. (Top > Val) |
| Is Greater Than | GTH | Y Register | 8E | `GTH Y` | Peaks at the top value off the stack. checks if it is greater than the value in Y. sets the Boolean Flag if true, clears it if false. (Top > Val) |
| Is Greater Than | GTH | Z Register | 8F | `GTH Z` | Peaks at the top value off the stack. checks if it is greater than the value in Z. sets the Boolean Flag if true, clears it if false. (Top > Val) |
| Is Greater Than | GTH | X Register and Immediate | 90 | `GTH X $val` | Checks if the value in X is greater than the immediate value. sets the Boolean Flag if true, clears it if false. (X > Val) |
| Is Greater Than | GTH | X and Y Registers | 91 | `GTH X Y` | Checks if the value in X is greater than the value in Y. sets the Boolean Flag if true, clears it if false. (X > Y) |
| Is Greater Than | GTH | X and Z Registers | 92 | `GTH X Z` | Checks if the value in X is greater than the value in Z. sets the Boolean Flag if true, clears it if false. (X > Z) |
| Is Greater Than | GTH | Y Register and Immediate | 93 | `GTH Y $val` | Checks if the value in Y is greater than the immediate value. sets the Boolean Flag if true, clears it if false. (Y > Val) |
| Is Greater Than | GTH | Y and X Registers | 94 | `GTH Y X` | Checks if the value in Y is greater than the value in X. sets the Boolean Flag if true, clears it if false. (Y > X) |
| Is Greater Than | GTH | Y and Z Registers | 95 | `GTH Y Z` | Checks if the value in Y is greater than the value in Z. sets the Boolean Flag if true, clears it if false. (Y > Z) |
| Is Greater Than | GTH | Z Register and Immediate | 96 | `GTH Z $val` | Checks if the value in Z is greater than the immediate value. sets the Boolean Flag if true, clears it if false. (Z > Val) |
| Is Greater Than | GTH | Z and X Registers | 97 | `GTH Z X` | Checks if the value in Z is greater than the value in X. sets the Boolean Flag if true, clears it if false. (Z > X) |
| Is Greater Than | GTH | Z and Y Registers | 98 | `GTH Z Y` | Checks if the value in Z is greater than the value in Z. sets the Boolean Flag if true, clears it if false. (Z > Y) |
| Is Equal To | EQU | Implied | 99 | `EQU` | Peaks at the top two values off the stack. checks if 2nd off IS equal to the 1st off. sets the Boolean Flag if true, clears it if false. (2nd off == 1st off) |
| Is Equal To | EQU | Immediate | 9A | `EQU $val` | Peaks at the top value off the stack. checks if it IS equal to the immediate value. sets the Boolean Flag if true, clears it if false. (Top == Val) |
| Is Equal To | EQU | X Register | 9B | `EQU X` | Peaks at the top value off the stack. checks if it IS equal to the value in X. sets the Boolean Flag if true, clears it if false. (Top == Val) |
| Is Equal To | EQU | Y Register | 9C | `EQU Y` | Peaks at the top value off the stack. checks if it IS equal to the value in Y. sets the Boolean Flag if true, clears it if false. (Top == Val) |
| Is Equal To | EQU | Z Register | 9D | `EQU Z` | Peaks at the top value off the stack. checks if it IS equal to the value in Z. sets the Boolean Flag if true, clears it if false. (Top == Val) |
| Is Equal To | EQU | X Register and Immediate | 9E | `EQU X $val` | Checks if the value in X IS equal to the immediate value. sets the Boolean Flag if true, clears it if false. (X == Val) |
| Is Equal To | EQU | X and Y Registers | 9F | `EQU X Y` | Checks if the value in X IS equal to the value in Y. sets the Boolean Flag if true, clears it if false. (X == Y) |
| Is Equal To | EQU | X and Z Registers | A0 | `EQU X Z` | Checks if the value in X IS equal to the value in Z. sets the Boolean Flag if true, clears it if false. (X == Z) |
| Is Equal To | EQU | Y Register and Immediate | A1 | `EQU Y $val` | Checks if the value in Y IS equal to the immediate value. sets the Boolean Flag if true, clears it if false. (Y == Val) |
| Is Equal To | EQU | Y and X Registers | A2 | `EQU Y X` | Checks if the value in Y IS equal to the value in X. sets the Boolean Flag if true, clears it if false. (Y == X) |
| Is Equal To | EQU | Y and Z Registers | A3 | `EQU Y Z` | Checks if the value in Y IS equal to the value in Z. sets the Boolean Flag if true, clears it if false. (Y == Z) |
| Is Equal To | EQU | Z Register and Immediate | A4 | `EQU Z $val` | Checks if the value in Z IS equal to the immediate value. sets the Boolean Flag if true, clears it if false. (Z == Val) |
| Is Equal To | EQU | Z and X Registers | A5 | `EQU Z X` | Checks if the value in Z IS equal to the value in X. sets the Boolean Flag if true, clears it if false. (Z == X) |
| Is Equal To | EQU | Z and Y Registers | A6 | `EQU Z Y` | Checks if the value in Z IS equal to the value in Z. sets the Boolean Flag if true, clears it if false. (Z == Y) |



<hr><br><br>

## Notes:


| | |
|---|---|
| **1** | If the result of this operation is outside the range of an unsigned 8bit integer (0-255) it will roll over and set the carry flag |
| **2** | This operation involves division, as such there is the potential for a division by zero error to occur. If the divisor is 0, then the calculation will not happen. the values will be pushed back to the stack in the order they were removed, and the Divide by Zero Flag will be set. |

<hr><br><br>

Made using [TableGenerator.com's](https://www.tablesgenerator.com/markdown_tables#) Markdown Table Generator.