# Kcats VM Opcode Reference 



| Index | Instruction | Nmemonic | Addressing Mode | Opcode | Syntax | Description |
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
| 0 | No Op | NOP | Implied | 00 | `NOP` | No Operation. skips current clock cycle |
| 1 | Halt | HLT | Implied | 01 | `HLT` | Halts the program (implied successful/ zero exitcode) |
| 2 | Halt w/ Exitcode | HLT | Immediate | 02 | `HLT $val` | Halts the program with the specified exitcode |
| 3 | Load X | LDX | Implied | 03 | `LDX` | Pops top of the stack and stores it in X |
| 4 | Load X | LDX | Immediate | 04 | `LDX $val` | Loads X with the immediate value |
| 5 | Load X | LDX | Y Register | 05 | `LDX Y` | Loads X with the value in Y |
| 6 | Load X | LDX | Z Register | 06 | `LDX Z` | Loads X with the value of Z |
| 7 | Load Y | LDY | Implied | 07 | `LDY` | Pops top of the stack and stores it in Y |
| 8 | Load Y | LDY | Immediate | 08 | `LDY $val` | Loads Y with the immediate value |
| 9 | Load Y | LDY | X Register | 09 | `LDY X` | Loads Y with the value in X |
| 10 | Load Y | LDY | Z Register | 0A | `LDY Z` | Loads Y with the value of Z |
| 11 | Swap Y and X | SYX | Implied | 0B | `SYX` | Swaps the values in Y and X directly |
| 12 | Increment X | INX | Implied | 0C | `INX` | Increments the value of X |
| 13 | Decrement X | DEX | Implied | 0D | `DEX` | Decrements the value of X |
| 14 | Increment Y | INY | Implied | 0E | `INY` | Increments the value of Y |
| 15 | Decrement Y | DEY | Implied | 0F | `DEY` | Decrements the value of Y |
| 16 | Clear Carry Flag | CLC | Implied | 10 | `CLC` | Clears the Carry Flag |
| 17 | Clear Boolean Flag | CBL | Implied | 11 | `CBL` | Clears the Boolean Flag |
| 18 | Clear Zero Flag | CZR | Implied | 12 | `CZR` | Clears the Zero Flag |
| 19 | Clear Div By Zero Flag | CDZ | Implied | 13 | `CDZ` | Clears the Div By Zero Flag |
| 20 | Clear Remainder Flag | CRM | Implied | 14 | `CRM` | Clears the Remainder Flag |
| 21 | Pop from Stack | POP | Implied | 15 | `POP` | Discards the value on the top of the stack |
| 22 | Pop from Stack | POP | Immediate | 16 | `POP $val` | Discards the value on the top of the stackvalue times. |
| 23 | Pop from Stack | POP | X Register | 17 | `POP X` | Pops the value on the top of the stack and stores it in X |
| 24 | Pop from Stack | POP | Y Register | 18 | `POP Y` | Pops the value on the top of the stack and stores it in Y |
| 25 | Push to Stack | PSH | Implied | 19 | `PSH` | Duplicates the value on the top of the stack |
| 26 | Push to Stack | PSH | Immediate | 1A | `PSH $val` | Push the immediate value to the stack |
| 27 | Push to Stack | PSH | X Register | 1B | `PSH X` | Push the value of X to the stack |
| 28 | Push to Stack | PSH | Y Register | 1C | `PSH Y` | Push the value of Y to the stack |
| 29 | Output as Number | OUT | Implied | 1D | `OUT` | Prints the top value of the stack as a number |
| 30 | Output as Number | OUT | Immediate | 1E | `OUT $val` | Prints the immediate value as a number |
| 31 | Output as Number | OUT | X Register | 1F | `OUT X` | Print the value of X as a number |
| 32 | Output as Number | OUT | Y Register | 20 | `Out Y` | Print the value of Y as a number |
| 33 | Output as Number | Out | Z Register | 21 | `Out Z` | Print the value of Z as a number |
| 34 | Print as ASCII | PRT | Implied | 22 | `PRT` | Prints the top value of the stack as ASCII |
| 35 | Print as ASCII | PRT | Immediate | 23 | `PRT $val` | Prints the immediate value as ASCII |
| 36 | Print as ASCII | PRT | X Register | 24 | `PRT X` | Prints the value of X as ASCII |
| 37 | Print as ASCII | PRT | Y Register | 25 | `PRT Y` | Prints the value of Y as ASCII |
| 38 | Get Input from Console | INP | Implied | 26 | `INP` | Get input from console and push it to stack |
| 39 | Get Input from Console | INP | X Register | 27 | `INP X` | Get input from console and store it in X |
| 40 | Get Input from Console | INP | Y Register | 28 | `INP Y` | Get input from console and store it in Y |
| 41 | Unconditional Jump | JMP | Implied | 29 | `JMP` | Pops the value on top of the stack and jumps to that address |
| 42 | Unconditional Jump | JMP | Implied | 2A | `JMP` | Pops the top two values of the stack and jumps to that 16bit address.LB popped first. |
| 43 | Unconditional Jump | JMP | Immediate | 2B | `JMP $val` | Jumps to the address specified by the immediate val |
| 44 | Unconditional Jump | JMP | Immediate (2 byte) | 2C | `JMP $HBLB`/`JMP $HB $LB` | Jumps to the 16bit address specified by the immediate vals |
| 45 | Unconditional Jump | JMP | X Register | 2D | `JMP X` | Jumps to X's value as an address |
| 46 | Unconditional Jump | JMP | Y Register | 2E | `JMP Y` | Jumps to Y's value as an address |
| 47 | Unconditional Jump | JMP | X and Y Registers | 2F | `JMP X Y` | Jumps to X and Y's values as a single 16bit address.X is HB Y is LB |
| 48 | Jump if Not Zero | JNZ | Implied | 30 | `JNZ` | If the Zero Flag is NOT set,Pops the value on top of the stack and jumps to that address |
| 49 | Jump if Not Zero | JNZ | Implied | 31 | `JNZ` | If the Zero Flag is NOT set,Pops the top two values of the stack and jumps to that 16bit address.LB popped first. |
| 50 | Jump if Not Zero | JNZ | Immediate | 32 | `JNZ $val` | If the Zero Flag is NOT set,Jumps to the address specified by the immediate val |
| 51 | Jump if Not Zero | JNZ | Immediate (2 byte) | 33 | `JNZ $HBLB`/`JNZ $HB $LB` | If the Zero Flag is NOT set,Jumps to the 16bit address specified by the immediate vals |
| 52 | Jump if Not Zero | JNZ | X Register | 34 | `JNZ X` | If the Zero Flag is NOT set,Jumps to X's value as an address |
| 53 | Jump if Not Zero | JNZ | Y Register | 35 | `JNZ Y` | If the Zero Flag is NOT set,Jumps to Y's value as an address |
| 54 | Jump if Not Zero | JNZ | X and Y Registers | 36 | `JNZ X Y` | If the Zero Flag is NOT set,Jumps to X and Y's values as a single 16bit address.X is HB Y is LB |
| 55 | Jump if Zero | JZR | Implied | 37 | `JZR` | If the Zero Flag IS set,Pops the value on top of the stack and jumps to that address |
| 56 | Jump if Zero | JZR | Implied | 38 | `JZR` | If the Zero Flag IS set,Pops the top two values of the stack and jumps to that 16bit address.LB popped first. |
| 57 | Jump if Zero | JZR | Immediate | 39 | `JZR $val` | If the Zero Flag IS set,Jumps to the address specified by the immediate val |
| 58 | Jump if Zero | JZR | Immediate (2 byte) | 3A | `JZR $HBLB`/`JZR $HB $LB` | If the Zero Flag IS set,Jumps to the 16bit address specified by the immediate vals |
| 59 | Jump if Zero | JZR | X Register | 3B | `JZR X` | If the Zero Flag IS set,Jumps to X's value as an address |
| 60 | Jump if Zero | JZR | Y Register | 3C | `JZR Y` | If the Zero Flag IS set,Jumps to Y's value as an address |
| 61 | Jump if Zero | JZR | X and Y Registers | 3D | `JZR X Y` | If the Zero Flag IS set,Jumps to X and Y's values as a single 16bit address.X is HB Y is LB |
| 62 | Jump if Carry | JFC | Implied | 3E | `JFC` | If the Carry Flag IS set,Pops the value on top of the stack and jumps to that address |
| 63 | Jump if Carry | JFC | Implied | 3F | `JFC` | If the Carry Flag IS set,Pops the top two values of the stack and jumps to that 16bit address.LB popped first. |
| 64 | Jump if Carry | JFC | Immediate | 40 | `JFC $val` | If the Carry Flag IS set,Jumps to the address specified by the immediate val |
| 65 | Jump if Carry | JFC | Immediate (2 byte) | 41 | `JFC $HBLB`/`JFC $HB $LB` | If the Carry Flag IS set,Jumps to the 16bit address specified by the immediate vals |
| 66 | Jump if Carry | JFC | X Register | 42 | `JFC X` | If the Carry Flag IS set,Jumps to X's value as an address |
| 67 | Jump if Carry | JFC | Y Register | 43 | `JFC Y` | If the Carry Flag IS set,Jumps to Y's value as an address |
| 68 | Jump if Carry | JFC | X and Y Registers | 44 | `JFC X Y` | If the Carry Flag IS set,Jumps to X and Y's values as a single 16bit address.X is HB Y is LB |
| 69 | Jump if True | JIF | Implied | 45 | `JIF` | If the Boolean Flag IS set,Pops the value on top of the stack and jumps to that address |
| 70 | Jump if True | JIF | Implied | 46 | `JIF` | If the Boolean Flag IS set,Pops the top two values of the stack and jumps to that 16bit address.LB popped first. |
| 71 | Jump if True | JIF | Immediate | 47 | `JIF $val` | If the Boolean Flag IS set,Jumps to the address specified by the immediate val |
| 72 | Jump if True | JIF | Immediate (2 byte) | 48 | `JIF $HBLB`/`JIF $HB $LB` | If the Boolean Flag IS set,Jumps to the 16bit address specified by the immediate vals |
| 73 | Jump if True | JIF | X Register | 49 | `JIF X` | If the Boolean Flag IS set,Jumps to X's value as an address |
| 74 | Jump if True | JIF | Y Register | 4A | `JIF Y` | If the Boolean Flag IS set,Jumps to Y's value as an address |
| 75 | Jump if True | JIF | X and Y Registers | 4B | `JIF X Y` | If the Boolean Flag IS set,Jumps to X and Y's values as a single 16bit address.X is HB Y is LB |
| 76 | Jump if False | JEL | Implied | 4C | `JEL` | If the Boolean Flag is NOT set,Pops the value on top of the stack and jumps to that address |
| 77 | Jump if False | JEL | Implied | 4D | `JEL` | If the Boolean Flag is NOT set,Pops the top two values of the stack and jumps to that 16bit address.LB popped first. |
| 78 | Jump if False | JEL | Immediate | 4E | `JEL $val` | If the Boolean Flag is NOT set,Jumps to the address specified by the immediate val |
| 79 | Jump if False | JEL | Immediate (2 byte) | 4F | `JEL $HBLB`/`JEL $HB $LB` | If the Boolean Flag is NOT set,Jumps to the 16bit address specified by the immediate vals |
| 80 | Jump if False | JEL | X Register | 50 | `JEL X` | If the Boolean Flag is NOT set,Jumps to X's value as an address |
| 81 | Jump if False | JEL | Y Register | 51 | `JEL Y` | If the Boolean Flag is NOT set,Jumps to Y's value as an address |
| 82 | Jump if False | JEL | X and Y Registers | 52 | `JEL X Y` | If the Boolean Flag is NOT set,Jumps to X and Y's values as a single 16bit address.X is HB Y is LB |
| 83 | Jump if Div by Zero | JDZ | Implied | 53 | `JDZ` | If the Div by Zero Flag IS set,Pops the value on top of the stack and jumps to that address |
| 84 | Jump if Div by Zero | JDZ | Implied | 54 | `JDZ` | If the Div by Zero Flag IS set,Pops the top two values of the stack and jumps to that 16bit address.LB popped first. |
| 85 | Jump if Div by Zero | JDZ | Immediate | 55 | `JDZ $val` | If the Div by Zero Flag IS set,Jumps to the address specified by the immediate val |
| 86 | Jump if Div by Zero | JDZ | Immediate (2 byte) | 56 | `JDZ $HBLB`/`JDZ $HB $LB` | If the Div by Zero Flag IS set,Jumps to the 16bit address specified by the immediate vals |
| 87 | Jump if Div by Zero | JDZ | X Register | 57 | `JDZ X` | If the Div by Zero Flag IS set,Jumps to X's value as an address |
| 88 | Jump if Div by Zero | JDZ | Y Register | 58 | `JDZ Y` | If the Div by Zero Flag IS set,Jumps to Y's value as an address |
| 89 | Jump if Div by Zero | JDZ | X and Y Registers | 59 | `JDZ X Y` | If the Div by Zero Flag IS set,Jumps to X and Y's values as a single 16bit address.X is HB Y is LB |
| 90 | Jump if Remainder | JRM | Implied | 5A | `JDZ` | If the Remainder Flag IS set,Pops the value on top of the stack and jumps to that address |
| 91 | Jump if Remainder | JRM | Implied | 5B | `JDZ` | If the Remainder Flag IS set,Pops the top two values of the stack and jumps to that 16bit address.LB popped first. |
| 92 | Jump if Remainder | JRM | Immediate | 5C | `JDZ $val` | If the Remainder Flag IS set,Jumps to the address specified by the immediate val |
| 93 | Jump if Remainder | JRM | Immediate (2 byte) | 5D | `JDZ $HBLB`/`JDZ $HB $LB` | If the Remainder Flag IS set,Jumps to the 16bit address specified by the immediate vals |
| 94 | Jump if Remainder | JRM | X Register | 5E | `JDZ X` | If the Remainder Flag IS set,Jumps to X's value as an address |
| 95 | Jump if Remainder | JRM | Y Register | 5F | `JDZ Y` | If the Remainder Flag IS set,Jumps to Y's value as an address |
| 96 | Jump if Remainder | JRM | X and Y Registers | 60 | `JDZ X Y` | If the Remainder Flag IS set,Jumps to X and Y's values as a single 16bit address.X is HB Y is LB |
| 97 | Add<sup>1</sup> | ADD | Implied | 61 | `ADD` | Pops top two values off the stack stack, pushes their sum (2nd off + 1st off) |
| 98 | Add<sup>1</sup> | ADD | Immediate | 62 | `ADD $val` | Pops top value off the stack, sums it and immediate val, pushes result (Top + Val) |
| 99 | Add<sup>1</sup> | ADD | Immediate (2 byte) | 63 | `ADD $A $B` | Pushes the sum of two immediate values (A + B) |
| 100 | Add<sup>1</sup> | ADD | X Register | 64 | `ADD X` | Pops top value off the stack, sums it and X, pushes result (Top + X) |
| 101 | Add<sup>1</sup> | ADD | Y Register | 65 | `ADD Y` | Pops top value off the stack, sums it and Y, pushes result (Top + Y) |
| 102 | Add<sup>1</sup> | ADD | X and Y Registers | 66 | `ADD X Y` | Pushes the sum of X and Y (X + Y) |
| 103 | Subtract<sup>1</sup> | SUB | Implied | 67 | `SUB` | Pops top two values off the stack, pushes their difference. (2nd off - 1st off) |
| 104 | Subtract<sup>1</sup> | SUB | Immediate | 68 | `SUB $val` | Pops top value off the stack, subtracts immediate value from it, pushes result (Top - Val) |
| 105 | Subtract<sup>1</sup> | SUB | Immediate (2 byte) | 69 | `SUB $A $B` | Pushes the difference of two immediate values (A - B) |
| 106 | Subtract<sup>1</sup> | SUB | X Register | 6A | `SUB X` | Pops top value off the stack, subtracts X from it, pushes result (Top - X) |
| 107 | Subtract<sup>1</sup> | SUB | Y Register | 6B | `SUB Y` | Pops top value off the stack, subtracts Y from it, pushes result (Top - Y) |
| 108 | Subtract<sup>1</sup> | SUB | X and Y Registers | 6C | `SUB X Y` | Pushes the difference of X and Y (X - Y) |
| 109 | Multiply<sup>1</sup> | MUL | Implied | 6D | `MUL` | Pops top two values off the stack, pushes their product (2nd off * 1st off) |
| 110 | Multiply<sup>1</sup> | MUL | Immediate | 6E | `MUL $val` | Pops top value off the stack, multiplies it by the immediate val, pushes result (Top * Val) |
| 111 | Multiply<sup>1</sup> | MUL | Immediate (2 byte) | 6F | `MUL $A $B` | Pushes the product of two immediate values (A * B) |
| 112 | Multiply<sup>1</sup> | MUL | X Register | 70 | `MUL X` | Pops top value off the stack, multiplies it by X, pushes result (Top * X) |
| 113 | Multiply<sup>1</sup> | MUL | Y Register | 71 | `MUL Y` | Pops top value off the stack, multiplies it by Y, pushes result (Top * Y) |
| 114 | Multiply<sup>1</sup> | MUL | X and Y Registers | 72 | `MUL X Y` | Pushes the product of X and Y (X * Y) |
| 115 | Divide<sup>2</sup> | DIV | Implied | 73 | `DIV` | Pops top two values off the stack, pushes their quotient. sets Remainder Flag if the remainder is NOT 0. (2nd off / 1st off) |
| 116 | Divide<sup>2</sup> | DIV | Immediate | 74 | `DIV $val` | Pops top value off the stack, divides it by the immediate val, pushes result. sets Remainder Flag if the remainder is NOT 0 (Top / Val) |
| 117 | Divide<sup>2</sup> | DIV | Immediate (2 byte) | 75 | `DIV $A $B` | Pushes the quotient of two immediate values. sets Remainder Flag if the remainder is NOT 0 (A / B) |
| 118 | Divide<sup>2</sup> | DIV | X Register | 76 | `DIV X` | Pops top value off the stack, divides it by X, pushes result. sets Remainder Flag if the remainder is NOT 0 (Top / X) |
| 119 | Divide<sup>2</sup> | DIV | Y Register | 77 | `DIV Y` | Pops top value off the stack, divides it by Y, pushes result. sets Remainder Flag if the remainder is NOT 0 (Top / Y) |
| 120 | Divide<sup>2</sup> | DIV | X and Y Registers | 78 | `DIV X Y` | Pushes the quotient of X and Y. sets Remainder Flag if the remainder is NOT 0 (X / Y) |
| 121 | Modulus<sup>2</sup> | MOD | Implied | 79 | `MOD` | Pops top two values off the stack, pushes the modulus of the two. (2nd off % 1st off) |
| 122 | Modulus<sup>2</sup> | MOD | Immediate | 7A | `MOD $val` | Pops top value off the stack, does it modulo immediate val, pushes result. (Top % val) |
| 123 | Modulus<sup>2</sup> | MOD | Immediate (2 byte) | 7B | `MOD $A $B` | Pushes the modulus of two immediate values (A % B). |
| 124 | Modulus<sup>2</sup> | MOD | X Register | 7C | `MOD X` | Pops top value off the stack, takes It modulo X, pushes result. (Top % X) |
| 125 | Modulus<sup>2</sup> | MOD | Y Register | 7D | `MOD Y` | Pops top value off the stack, takes It modulo Y, pushes result. (Top % Y) |
| 126 | Modulus<sup>2</sup> | MOD | X and Y Registers | 7E | `MOD X Y` | Pushes the modulus of X and Y. (X % Y) |
| 127 | Rotate Left | ROL | Implied | 7F | `ROL` | Pops top value off the stack, rotates all bits to the left once. pushes result. (Most significant bit wrapping around to least significant bit) (0001 -> 1000) |
| 128 | Rotate Left | ROL | Immediate | 80 | `ROL $val` | rotates all bits of immediate value to the left once. pushes result. (Most significant bit wrapping around to least significant bit) (0001 -> 1000) |
| 129 | Rotate Left | ROL | X Register | 81 | `ROL X` | rotates all bits of X to the left once. pushes result. (Most significant bit wrapping around to least significant bit) (0001 -> 1000) |
| 130 | Rotate Left | ROL | Y Register | 82 | `ROL Y` | rotates all bits of Y to the left once. pushes result. (Most significant bit wrapping around to least significant bit) (0001 -> 1000) |
| 131 | Rotate Right | ROR | Implied | 83 | `ROR` | Pops top value off the stack, rotates all bits to the right once. pushes result. (Least significant bit wrapping around to most significant bit) (0001 -> 1000) |
| 132 | Rotate Right | ROR | Immediate | 84 | `ROR $val` | rotates all bits of immediate value to the right once. pushes result. (Most significant bit wrapping around to least significant bit) (0001 -> 1000) |
| 133 | Rotate Right | ROR | X Register | 85 | `ROR X` | rotates all bits of X to the right once. pushes result. (Most significant bit wrapping around to least significant bit) (0001 -> 1000) |
| 134 | Rotate Right | ROR | Y Register | 86 | `ROR Y` | rotates all bits of Y to the right once. pushes result. (Most significant bit wrapping around to least significant bit) (0001 -> 1000) |
| 135 | Shift Left | SHL | Implied | 87 | `SHL` | Pops top value off the stack, shifts all bits to the left once. pushes result. (vacent bits padded with zeros) (1001 -> 0010) |
| 136 | Shift Left | SHL | Immediate | 88 | `SHL $val` | Shifts all bits of immediate value to the left once. pushes result. (vacent bits padded with zeros) (1001 -> 0010) |
| 137 | Shift Left | SHL | X Register | 89 | `SHL X` | Shifts all bits of X to the left once. pushes result. (vacent bits padded with zeros) (1001 -> 0010) |
| 138 | Shift Left | SHL | Y Register | 8A | `SHL Y` | Shifts all bits of Y to the left once. pushes result. (vacent bits padded with zeros) (1001 -> 0010) |
| 139 | Shift Right | SHR | Implied | 8B | `SHR` | Pops top value off the stack, shifts all bits to the right once. pushes result. (vacent bits padded with zeros) (1001 -> 0100) |
| 140 | Shift Right | SHR | Immediate | 8C | `SHR $val` | Shifts all bits of immediate value to the right once. pushes result. (vacent bits padded with zeros) (1001 -> 0100) |
| 141 | Shift Right | SHR | X Register | 8D | `SHR X` | Shifts all bits of X to the right once. pushes result. (vacent bits padded with zeros) (1001 -> 0100) |
| 142 | Shift Right | SHR | Y Register | 8E | `SHR Y` | Shifts all bits of Y to the right once. pushes result. (vacent bits padded with zeros) (1001 -> 0100) |
| 143 | Bitwise And | AND | Implied | 8F | `AND` | Pops the top two values off the stack, preforms bitwise/binary and on them (2nd off & 1st off), pushes result |
| 144 | Bitwise And | AND | Immediate | 90 | `AND $val` | Pops top value off the stack, preforms bitwise/binary and on it and the immediate value (Top & Val), pushes result |
| 145 | Bitwise And | AND | Immediate (2 byte) | 91 | `AND $A $B` | Pushes the bitwise/binary and of the two immediate values (A & B) |
| 146 | Bitwise And | AND | X Register | 92 | `AND X` | Pops top value off the stack, preforms bitwise/binary and on it and X (Top & X), pushes result |
| 147 | Bitwise And | AND | Y Register | 93 | `AND Y` | Pops top value off the stack, preforms bitwise/binary and on it and Y (Top & Y), pushes result |
| 148 | Bitwise And | AND | X and Y Registers | 94 | `AND X Y` | Pushes the bitwise/binary and of X and Y (X & Y) |
| 149 | Bitwise Or | OR | Implied | 95 | `OR` | Pops the top two values off the stack, preforms bitwise/binary or on them (2nd off \| 1st off), pushes result |
| 150 | Bitwise Or | OR | Immediate | 96 | `OR $val` | Pops top value off the stack, preforms bitwise/binary or on it and the immediate value (Top \| Val), pushes result |
| 151 | Bitwise Or | OR | Immediate (2 byte) | 97 | `OR $A $B` | Pushes the bitwise/binary or of the two immediate values (A \| B) |
| 152 | Bitwise Or | OR | X Register | 98 | `OR X` | Pops top value off the stack, preforms bitwise/binary or on it and X (Top \| X), pushes result |
| 153 | Bitwise Or | OR | Y Register | 99 | `OR Y` | Pops top value off the stack, preforms bitwise/binary or on it and Y (Top \| Y), pushes result |
| 154 | Bitwise Or | OR | X and Y Registers | 9A | `OR X Y` | Pushes the bitwise/binary or of X and Y (X \| Y) |
| 155 | Bitwise Xor | XOR | Implied | 9B | `XOR` | Pops the top two values off the stack, preforms bitwise/binary xor on them (2nd off \^ 1st off), pushes result |
| 156 | Bitwise Xor | XOR | Immediate | 9C | `XOR $val` | Pops top value off the stack, preforms bitwise/binary xor on it and the immediate value (Top \^ Val), pushes result |
| 157 | Bitwise Xor | XOR | Immediate (2 byte) | 9D | `XOR $A $B` | Pushes the bitwise/binary xor of the two immediate values (A \^ B) |
| 158 | Bitwise Xor | XOR | X Register | 9E | `XOR X` | Pops top value off the stack, preforms bitwise/binary xor on it and X (Top \^ X), pushes result |
| 159 | Bitwise Xor | XOR | Y Register | 9F | `XOR Y` | Pops top value off the stack, preforms bitwise/binary xor on it and Y (Top \^ Y), pushes result |
| 160 | Bitwise Xor | XOR | X and Y Registers | A0 | `XOR X Y` | Pushes the bitwise/binary xor of X and Y (X \^ Y) |
| 161 | Not/Invert/Complement | NOT | Implied | A1 | `NOT` | Pops the top value off the stack,  inverts each bit (~Top ei 1001 -> 0110), pushes result |
| 162 | Not/Invert/Complement | NOT | Immediate | A2 | `NOT $val` | Inverts each bit of immediate value (~Val ei 1001 -> 0110), pushes result |
| 163 | Not/Invert/Complement | NOT | X Register | A3 | `NOT X` | Inverts each bit of X (~X ei 1001 -> 0110), pushes result |
| 164 | Not/Invert/Complement | NOT | Y Register | A4 | `NOT Y` | Inverts each bit of Y (~Y ei 1001 -> 0110), pushes result |
| 165 | Is Less Than | LTH | Implied | A5 | `LTH` | Peaks at the top two values off the stack. checks if 2nd off is less than the 1st off. sets the Boolean Flag if true, clears it if false. (2nd off < 1st off) |
| 166 | Is Less Than | LTH | Immediate | A6 | `LTH $val` | Peaks at the top value off the stack. checks if it is less than the immediate value. sets the Boolean Flag if true, clears it if false. (Top < Val) |
| 167 | Is Less Than | LTH | X Register | A7 | `LTH X` | Peaks at the top value off the stack. checks if it is less than the value in X. sets the Boolean Flag if true, clears it if false. (Top < Val) |
| 168 | Is Less Than | LTH | Y Register | A8 | `LTH Y` | Peaks at the top value off the stack. checks if it is less than the value in Y. sets the Boolean Flag if true, clears it if false. (Top < Val) |
| 169 | Is Less Than | LTH | Z Register | A9 | `LTH Z` | Peaks at the top value off the stack. checks if it is less than the value in Z. sets the Boolean Flag if true, clears it if false. (Top < Val) |
| 170 | Is Less Than | LTH | X Register and Immediate | AA | `LTH X $val` | Checks if the value in X is less than the immediate value. sets the Boolean Flag if true, clears it if false. (X < Val) |
| 171 | Is Less Than | LTH | X and Y Registers | AB | `LTH X Y` | Checks if the value in X is less than the value in Y. sets the Boolean Flag if true, clears it if false. (X < Y) |
| 172 | Is Less Than | LTH | X and Z Registers | AC | `LTH X Z` | Checks if the value in X is less than the value in Z. sets the Boolean Flag if true, clears it if false. (X < Z) |
| 173 | Is Less Than | LTH | Y Register and Immediate | AD | `LTH Y $val` | Checks if the value in Y is less than the immediate value. sets the Boolean Flag if true, clears it if false. (Y < Val) |
| 174 | Is Less Than | LTH | Y and X Registers | AE | `LTH Y X` | Checks if the value in Y is less than the value in X. sets the Boolean Flag if true, clears it if false. (Y < X) |
| 175 | Is Less Than | LTH | Y and Z Registers | AF | `LTH Y Z` | Checks if the value in Y is less than the value in Z. sets the Boolean Flag if true, clears it if false. (Y < Z) |
| 176 | Is Less Than | LTH | Z Register and Immediate | B0 | `LTH Z $val` | Checks if the value in Z is less than the immediate value. sets the Boolean Flag if true, clears it if false. (Z < Val) |
| 177 | Is Less Than | LTH | Z and X Registers | B1 | `LTH Z X` | Checks if the value in Z is less than the value in X. sets the Boolean Flag if true, clears it if false. (Z < X) |
| 178 | Is Less Than | LTH | Z and Y Registers | B2 | `LTH Z Y` | Checks if the value in Z is less than the value in Z. sets the Boolean Flag if true, clears it if false. (Z < Y) |
| 179 | Is Greater Than | GTH | Implied | B3 | `GTH` | Peaks at the top two values off the stack. checks if 2nd off is greater than the 1st off. sets the Boolean Flag if true, clears it if false. (2nd off > 1st off) |
| 180 | Is Greater Than | GTH | Immediate | B4 | `GTH $val` | Peaks at the top value off the stack. checks if it is greater than the immediate value. sets the Boolean Flag if true, clears it if false. (Top > Val) |
| 181 | Is Greater Than | GTH | X Register | B5 | `GTH X` | Peaks at the top value off the stack. checks if it is greater than the value in X. sets the Boolean Flag if true, clears it if false. (Top > Val) |
| 182 | Is Greater Than | GTH | Y Register | B6 | `GTH Y` | Peaks at the top value off the stack. checks if it is greater than the value in Y. sets the Boolean Flag if true, clears it if false. (Top > Val) |
| 183 | Is Greater Than | GTH | Z Register | B7 | `GTH Z` | Peaks at the top value off the stack. checks if it is greater than the value in Z. sets the Boolean Flag if true, clears it if false. (Top > Val) |
| 184 | Is Greater Than | GTH | X Register and Immediate | B8 | `GTH X $val` | Checks if the value in X is greater than the immediate value. sets the Boolean Flag if true, clears it if false. (X > Val) |
| 185 | Is Greater Than | GTH | X and Y Registers | B9 | `GTH X Y` | Checks if the value in X is greater than the value in Y. sets the Boolean Flag if true, clears it if false. (X > Y) |
| 186 | Is Greater Than | GTH | X and Z Registers | BA | `GTH X Z` | Checks if the value in X is greater than the value in Z. sets the Boolean Flag if true, clears it if false. (X > Z) |
| 187 | Is Greater Than | GTH | Y Register and Immediate | BB | `GTH Y $val` | Checks if the value in Y is greater than the immediate value. sets the Boolean Flag if true, clears it if false. (Y > Val) |
| 188 | Is Greater Than | GTH | Y and X Registers | BC | `GTH Y X` | Checks if the value in Y is greater than the value in X. sets the Boolean Flag if true, clears it if false. (Y > X) |
| 189 | Is Greater Than | GTH | Y and Z Registers | BD | `GTH Y Z` | Checks if the value in Y is greater than the value in Z. sets the Boolean Flag if true, clears it if false. (Y > Z) |
| 190 | Is Greater Than | GTH | Z Register and Immediate | BE | `GTH Z $val` | Checks if the value in Z is greater than the immediate value. sets the Boolean Flag if true, clears it if false. (Z > Val) |
| 191 | Is Greater Than | GTH | Z and X Registers | BF | `GTH Z X` | Checks if the value in Z is greater than the value in X. sets the Boolean Flag if true, clears it if false. (Z > X) |
| 192 | Is Greater Than | GTH | Z and Y Registers | C0 | `GTH Z Y` | Checks if the value in Z is greater than the value in Z. sets the Boolean Flag if true, clears it if false. (Z > Y) |
| 193 | Is Less Than or Equal To | LEQ | Implied | C1 | `LEQ` | Peaks at the top two values off the stack. checks if 2nd off is less than or equals the 1st off. sets the Boolean Flag if true, clears it if false. (2nd off <= 1st off) |
| 194 | Is Less Than or Equal To | LEQ | Immediate | C2 | `LEQ $val` | Peaks at the top value off the stack. checks if it is less than or equals the immediate value. sets the Boolean Flag if true, clears it if false. (Top <= Val) |
| 195 | Is Less Than or Equal To | LEQ | X Register | C3 | `LEQ X` | Peaks at the top value off the stack. checks if it is less than or equals the value in X. sets the Boolean Flag if true, clears it if false. (Top <= Val) |
| 196 | Is Less Than or Equal To | LEQ | Y Register | C4 | `LEQ Y` | Peaks at the top value off the stack. checks if it is less than or equals the value in Y. sets the Boolean Flag if true, clears it if false. (Top <= Val) |
| 197 | Is Less Than or Equal To | LEQ | Z Register | C5 | `LEQ Z` | Peaks at the top value off the stack. checks if it is less than or equals the value in Z. sets the Boolean Flag if true, clears it if false. (Top <= Val) |
| 198 | Is Less Than or Equal To | LEQ | X Register and Immediate | C6 | `LEQ X $val` | Checks if the value in X is less than or equals the immediate value. sets the Boolean Flag if true, clears it if false. (X <= Val) |
| 199 | Is Less Than or Equal To | LEQ | X and Y Registers | C7 | `LEQ X Y` | Checks if the value in X is less than or equals the value in Y. sets the Boolean Flag if true, clears it if false. (X <= Y) |
| 200 | Is Less Than or Equal To | LEQ | X and Z Registers | C8 | `LEQ X Z` | Checks if the value in X is less than or equals the value in Z. sets the Boolean Flag if true, clears it if false. (X <= Z) |
| 201 | Is Less Than or Equal To | LEQ | Y Register and Immediate | C9 | `LEQ Y $val` | Checks if the value in Y is less than or equals the immediate value. sets the Boolean Flag if true, clears it if false. (Y <= Val) |
| 202 | Is Less Than or Equal To | LEQ | Y and X Registers | CA | `LEQ Y X` | Checks if the value in Y is less than or equals the value in X. sets the Boolean Flag if true, clears it if false. (Y <= X) |
| 203 | Is Less Than or Equal To | LEQ | Y and Z Registers | CB | `LEQ Y Z` | Checks if the value in Y is less than or equals the value in Z. sets the Boolean Flag if true, clears it if false. (Y <= Z) |
| 204 | Is Less Than or Equal To | LEQ | Z Register and Immediate | CC | `LEQ Z $val` | Checks if the value in Z is less than or equals the immediate value. sets the Boolean Flag if true, clears it if false. (Z <= Val) |
| 205 | Is Less Than or Equal To | LEQ | Z and X Registers | CD | `LEQ Z X` | Checks if the value in Z is less than or equals the value in X. sets the Boolean Flag if true, clears it if false. (Z <= X) |
| 206 | Is Less Than or Equal To | LEQ | Z and Y Registers | CE | `LEQ Z Y` | Checks if the value in Z is less than or equals the value in Z. sets the Boolean Flag if true, clears it if false. (Z <= Y) |
| 207 | Is Greater Than or Equal To | GEQ | Implied | CF | `GEQ` | Peaks at the top two values off the stack. checks if 2nd off is greater than or equals the 1st off. sets the Boolean Flag if true, clears it if false. (2nd off >= 1st off) |
| 208 | Is Greater Than or Equal To | GEQ | Immediate | D0 | `GEQ $val` | Peaks at the top value off the stack. checks if it is greater than or equals the immediate value. sets the Boolean Flag if true, clears it if false. (Top >= Val) |
| 209 | Is Greater Than or Equal To | GEQ | X Register | D1 | `GEQ X` | Peaks at the top value off the stack. checks if it is greater than or equals the value in X. sets the Boolean Flag if true, clears it if false. (Top >= Val) |
| 210 | Is Greater Than or Equal To | GEQ | Y Register | D2 | `GEQ Y` | Peaks at the top value off the stack. checks if it is greater than or equals the value in Y. sets the Boolean Flag if true, clears it if false. (Top >= Val) |
| 211 | Is Greater Than or Equal To | GEQ | Z Register | D3 | `GEQ Z` | Peaks at the top value off the stack. checks if it is greater than or equals the value in Z. sets the Boolean Flag if true, clears it if false. (Top >= Val) |
| 212 | Is Greater Than or Equal To | GEQ | X Register and Immediate | D4 | `GEQ X $val` | Checks if the value in X is greater than or equals the immediate value. sets the Boolean Flag if true, clears it if false. (X >= Val) |
| 213 | Is Greater Than or Equal To | GEQ | X and Y Registers | D5 | `GEQ X Y` | Checks if the value in X is greater than or equals the value in Y. sets the Boolean Flag if true, clears it if false. (X >= Y) |
| 214 | Is Greater Than or Equal To | GEQ | X and Z Registers | D6 | `GEQ X Z` | Checks if the value in X is greater than or equals the value in Z. sets the Boolean Flag if true, clears it if false. (X >= Z) |
| 215 | Is Greater Than or Equal To | GEQ | Y Register and Immediate | D7 | `GEQ Y $val` | Checks if the value in Y is greater than or equals the immediate value. sets the Boolean Flag if true, clears it if false. (Y >= Val) |
| 216 | Is Greater Than or Equal To | GEQ | Y and X Registers | D8 | `GEQ Y X` | Checks if the value in Y is greater than or equals the value in X. sets the Boolean Flag if true, clears it if false. (Y >= X) |
| 217 | Is Greater Than or Equal To | GEQ | Y and Z Registers | D9 | `GEQ Y Z` | Checks if the value in Y is greater than or equals the value in Z. sets the Boolean Flag if true, clears it if false. (Y >= Z) |
| 218 | Is Greater Than or Equal To | GEQ | Z Register and Immediate | DA | `GEQ Z $val` | Checks if the value in Z is greater than or equals the immediate value. sets the Boolean Flag if true, clears it if false. (Z >= Val) |
| 219 | Is Greater Than or Equal To | GEQ | Z and X Registers | DB | `GEQ Z X` | Checks if the value in Z is greater than or equals the value in X. sets the Boolean Flag if true, clears it if false. (Z >= X) |
| 220 | Is Greater Than or Equal To | GEQ | Z and Y Registers | DC | `GEQ Z Y` | Checks if the value in Z is greater than or equals the value in Z. sets the Boolean Flag if true, clears it if false. (Z >= Y) |
| 221 | Is Equal To | EQU | Implied | DD | `EQU` | Peaks at the top two values off the stack. checks if 2nd off IS equal to the 1st off. sets the Boolean Flag if true, clears it if false. (2nd off == 1st off) |
| 222 | Is Equal To | EQU | Immediate | DE | `EQU $val` | Peaks at the top value off the stack. checks if it IS equal to the immediate value. sets the Boolean Flag if true, clears it if false. (Top == Val) |
| 223 | Is Equal To | EQU | X Register | DF | `EQU X` | Peaks at the top value off the stack. checks if it IS equal to the value in X. sets the Boolean Flag if true, clears it if false. (Top == Val) |
| 224 | Is Equal To | EQU | Y Register | E0 | `EQU Y` | Peaks at the top value off the stack. checks if it IS equal to the value in Y. sets the Boolean Flag if true, clears it if false. (Top == Val) |
| 225 | Is Equal To | EQU | Z Register | E1 | `EQU Z` | Peaks at the top value off the stack. checks if it IS equal to the value in Z. sets the Boolean Flag if true, clears it if false. (Top == Val) |
| 226 | Is Equal To | EQU | X Register and Immediate | E2 | `EQU X $val` | Checks if the value in X IS equal to the immediate value. sets the Boolean Flag if true, clears it if false. (X == Val) |
| 227 | Is Equal To | EQU | X and Y Registers | E3 | `EQU X Y` | Checks if the value in X IS equal to the value in Y. sets the Boolean Flag if true, clears it if false. (X == Y) |
| 228 | Is Equal To | EQU | X and Z Registers | E4 | `EQU X Z` | Checks if the value in X IS equal to the value in Z. sets the Boolean Flag if true, clears it if false. (X == Z) |
| 229 | Is Equal To | EQU | Y Register and Immediate | E5 | `EQU Y $val` | Checks if the value in Y IS equal to the immediate value. sets the Boolean Flag if true, clears it if false. (Y == Val) |
| 230 | Is Equal To | EQU | Y and X Registers | E6 | `EQU Y X` | Checks if the value in Y IS equal to the value in X. sets the Boolean Flag if true, clears it if false. (Y == X) |
| 231 | Is Equal To | EQU | Y and Z Registers | E7 | `EQU Y Z` | Checks if the value in Y IS equal to the value in Z. sets the Boolean Flag if true, clears it if false. (Y == Z) |
| 232 | Is Equal To | EQU | Z Register and Immediate | E8 | `EQU Z $val` | Checks if the value in Z IS equal to the immediate value. sets the Boolean Flag if true, clears it if false. (Z == Val) |
| 233 | Is Equal To | EQU | Z and X Registers | E9 | `EQU Z X` | Checks if the value in Z IS equal to the value in X. sets the Boolean Flag if true, clears it if false. (Z == X) |
| 234 | Is Equal To | EQU | Z and Y Registers | EA | `EQU Z Y` | Checks if the value in Z IS equal to the value in Z. sets the Boolean Flag if true, clears it if false. (Z == Y) |
| 235 | Is Not Equal | NEQ | Implied | EB | `NEQ` | Peaks at the top two values off the stack. checks if 2nd off is NOT equal to the 1st off. sets the Boolean Flag if true, clears it if false. (2nd off != 1st off) |
| 236 | Is Not Equal | NEQ | Immediate | EC | `NEQ $val` | Peaks at the top value off the stack. checks if it is NOT equal to the immediate value. sets the Boolean Flag if true, clears it if false. (Top != Val) |
| 237 | Is Not Equal | NEQ | X Register | ED | `NEQ X` | Peaks at the top value off the stack. checks if it is NOT equal to the value in X. sets the Boolean Flag if true, clears it if false. (Top != Val) |
| 238 | Is Not Equal | NEQ | Y Register | EE | `NEQ Y` | Peaks at the top value off the stack. checks if it is NOT equal to the value in Y. sets the Boolean Flag if true, clears it if false. (Top != Val) |
| 239 | Is Not Equal | NEQ | Z Register | EF | `NEQ Z` | Peaks at the top value off the stack. checks if it is NOT equal to the value in Z. sets the Boolean Flag if true, clears it if false. (Top != Val) |
| 240 | Is Not Equal | NEQ | X Register and Immediate | F0 | `NEQ X $val` | Checks if the value in X is NOT equal to the immediate value. sets the Boolean Flag if true, clears it if false. (X != Val) |
| 241 | Is Not Equal | NEQ | X and Y Registers | F1 | `NEQ X Y` | Checks if the value in X is NOT equal to the value in Y. sets the Boolean Flag if true, clears it if false. (X != Y) |
| 242 | Is Not Equal | NEQ | X and Z Registers | F2 | `NEQ X Z` | Checks if the value in X is NOT equal to the value in Z. sets the Boolean Flag if true, clears it if false. (X != Z) |
| 243 | Is Not Equal | NEQ | Y Register and Immediate | F3 | `NEQ Y $val` | Checks if the value in Y is NOT equal to the immediate value. sets the Boolean Flag if true, clears it if false. (Y != Val) |
| 244 | Is Not Equal | NEQ | Y and X Registers | F4 | `NEQ Y X` | Checks if the value in Y is NOT equal to the value in X. sets the Boolean Flag if true, clears it if false. (Y != X) |
| 245 | Is Not Equal | NEQ | Y and Z Registers | F5 | `NEQ Y Z` | Checks if the value in Y is NOT equal to the value in Z. sets the Boolean Flag if true, clears it if false. (Y != Z) |
| 246 | Is Not Equal | NEQ | Z Register and Immediate | F6 | `NEQ Z $val` | Checks if the value in Z is NOT equal to the immediate value. sets the Boolean Flag if true, clears it if false. (Z != Val) |
| 247 | Is Not Equal | NEQ | Z and X Registers | F7 | `NEQ Z X` | Checks if the value in Z is NOT equal to the value in X. sets the Boolean Flag if true, clears it if false. (Z != X) |
| 248 | Is Not Equal | NEQ | Z and Y Registers | F8 | `NEQ Z Y` | Checks if the value in Z is NOT equal to the value in Z. sets the Boolean Flag if true, clears it if false. (Z != Y) |
| 249 | Unused. (treated like No Op) | N/A | Implied | F9 | N/A | See No Op |
| 250 | Unused. (treated like No Op) | N/A | Implied | FA | N/A | See No Op |
| 251 | Unused. (treated like No Op) | N/A | Implied | FB | N/A | See No Op |
| 252 | Unused. (treated like No Op) | N/A | Implied | FC | N/A | See No Op |
| 253 | Unused. (treated like No Op) | N/A | Implied | FD | N/A | See No Op |
| 254 | Unused. (treated like No Op) | N/A | Implied | FE | N/A | See No Op |
| 255 | Unused. (treated like No Op) | N/A | Implied | FF | N/A | See No Op |



<hr><br><br>

## Notes:


| | |
|---|---|
| **1** | If the result of this operation is outside the range of an unsigned 8bit integer (0-255) it will roll over and set the carry flag |
| **2** | This operation involves division, as such there is the potential for a division by zero error to occur if the divisor is 0, then the calculation will not happen. the values will be pushed back to the stack in the order they were removed, and the Divide by Zero Flag will be set. |

<hr><br><br>

Made using [TableGenerator.com's](https://www.tablesgenerator.com/markdown_tables#) Markdown Table Generator.