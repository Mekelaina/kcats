#ifndef OPCODE_KCATS_H
#define OPCODE_KCATS_H

typedef enum opcode {

    NO_OP,                          // NO Operation. Skip current Cycle
    LOAD_A,                         // Pop value from stack and load into Accumulator
    LOAD_A_IM,                      // Load Accumulator with immediate value
    LOAD_A_X,                       // Load Accumulator with value in X
    LOAD_A_Y,                       // Load Accumulator with value in Y
    LOAD_A_Z,                       // Load Accumulator with value in Z (Stack Pointer)
    LOAD_A_R0,                      // Load Accumulator with value in R0
    LOAD_A_R1,                      // Load Accumulator with value in R1
    LOAD_A_R2,                      // Load Accumulator with value in R2
    LOAD_A_R3,                      // Load Accumulator with value in R3
    STORE_A,                        // Push value in Accumulator to stack
  //STORE_A_IM,                     //
    STORE_A_X,                      // Store value in Accumulator into X
    STORE_A_Y,                      // Store value in Accumulator into Y
    STORE_A_Z,                      // Store value in Accumulator into Z (Stack Pointer)
    STORE_A_R0,                     // Store value in Accumulator into R0
    STORE_A_R1,                     // Store value in Accumulator into R1
    STORE_A_R2,                     // Store value in Accumulator into R2
    STORE_A_R3,                     // Store value in Accumulator into R3
    LOAD_X,                         // Pop value from stack and load into X
    LOAD_X_IM,                      // Load X with immediate value
    LOAD_X_R0,                      // Load X with value in R0
    LOAD_X_R1,                      // Load X with value in R1
    LOAD_X_R2,                      // Load X with value in R2
    LOAD_X_R3,                      // Load X with value in R3
    LOAD_Y,                         // Pop value from stack and load into Y
    LOAD_Y_IM,                      // Load Y with immediate value
    LOAD_Y_R0,                      // Load Y with value in R0
    LOAD_Y_R1,                      // Load Y with value in R1
    LOAD_Y_R2,                      // Load Y with value in R2
    LOAD_Y_R3,                      // Load Y with value in R3
    INC_X,                          // Increment X
    INC_Y,                          // Increment Y
    INC_Z,                          // Increment Z (Stack Pointer)
    DEC_X,                          // Decrement X
    DEC_Y,                          // Decrement Y
    DEC_Z,                          // Decrement Z (Stack Pointer)
    ADD,                            // Pop value from stack and add it into Accumulator with Carry
    ADD_IM,                         // Add immediate value into Accumulator with Carry
    ADD_X,                          // Add value in X into Accumulator with Carry
    ADD_Y,                          // Add value in Y into Accumulator with Carry
    ADD_Z,                          // Add value in Z (Stack Pointer) into Accumulator with Carry
    ADD_R0,                         // Add value in R0 into Accumulator with Carry
    ADD_R1,                         // Add value in R1 into Accumulator with Carry
    ADD_R2,                         // Add value in R2 into Accumulator with Carry 
    ADD_R3,                         // Add value in R3 into Accumulator with Carry
    SUBTRACT,                       // Pop value from stack and subtract it from Accumulator with Borrow (Carry)
    SUBTRACT_IM,                    // Subtract immediate value from Accumulator with Borrow (Carry)
    SUBTRACT_X,                     // Subtract value in X from Accumulator with Borrow (Carry)
    SUBTRACT_Y,                     // Subtract value in Y from Accumulator with Borrow (Carry)
    SUBTRACT_Z,                     // Subtract value in Z (Stack Pointer) from Accumulator with Borrow (Carry)
    SUBTRACT_R0,                    // Subtract value in R0 from Accumulator with Borrow (Carry)
    SUBTRACT_R1,                    // Subtract value in R1 from Accumulator with Borrow (Carry)
    SUBTRACT_R2,                    // Subtract value in R2 from Accumulator with Borrow (Carry)
    SUBTRACT_R3,                    // Subtract value in R3 from Accumulator with Borrow (Carry)
    
    MULTIPLY,
    MULTIPLY_IM,
    MULTIPLY_X,
    MULTIPLY_Y,
    MULTIPLY_L,
    MULTIPLY_L_IM,
    MULTIPLY_L_X,
    MULTIPLY_L_Y,

    DIVIDE,
    DIVIDE_IM,
    DIVIDE_X,
    DIVIDE_Y,
    DIVIDE_L,
    DIVIDE_L_IM,
    DIVIDE_L_X,
    DIVIDE_L_Y,

    MODULO,
    MODULO_IM,
    MODULO_X,
    MODULO_Y,
    MODULO_L,
    MODULO_L_IM,
    MODULO_L_X,
    MODULO_L_Y,


    SIGN_SHIFT_LEFT,                // Shift bits in Accumulator left by 1, preserving sign bit.
    SIGN_SHIFT_RIGHT,               // Shift bits in Accumulator right by 1, preserving sign bit.
    LOGICAL_SHIFT_LEFT,             // Shift bits in Accumulator left by 1.
    LOGICAL_SHIFT_RIGHT,            // Shift bits in Accumulator right by 1.
    ROTATE_LEFT,                    // Rotates/Circular Shifts bits in Accumulator left by 1.  MSB -> Carry. Carry -> LSB
    ROTATE_RIGHT,                   // Rotates/Circular Shifts bits in Accumulator right by 1. LSB -> Carry. Carry -> MSB
    BIT_AND,                        // Pops value from stack and ANDs it with Accumulator. (A & V) -> A
    BIT_AND_IM,                     // ANDs Accumulator and immediate value (A & V) -> A
    BIT_AND_X,                      // ANDs Accumulator and value in X (A & X) -> A
    BIT_AND_Y,                      // ANDs Accumulator and value in Y (A & Y) -> A 
    BIT_AND_Z,                      // ANDs Accumulator and value in Z (A & Z) -> A
    BIT_AND_R0,                     // ANDs Accumulator and value in R0 (A & R0) -> A
    BIT_AND_R1,                     // ANDs Accumulator and value in R1 (A & R1) -> A
    BIT_AND_R2,                     // ANDs Accumulator and value in R2 (A & R2) -> A
    BIT_AND_R3,                     // ANDs Accumulator and value in R3 (A & R3) -> A
    BIT_OR,                         // Pops value from stack and ORs it with Accumulator. (A | V) -> A
    BIT_OR_IM,                      // ORs Accumulator and immediate value (A | V) -> A
    BIT_OR_X,                       // ORs Accumulator and value in X (A | X) -> A
    BIT_OR_Y,                       // ORs Accumulator and value in Y (A | Y) -> A
    BIT_OR_Z,                       // ORs Accumulator and value in Z (A | Z) -> A
    BIT_OR_R0,                      // ORs Accumulator and value in R0 (A | R0) -> A
    BIT_OR_R1,                      // ORs Accumulator and value in R1 (A | R1) -> A
    BIT_OR_R2,                      // ORs Accumulator and value in R2 (A | R2) -> A
    BIT_OR_R3,                      // ORs Accumulator and value in R3 (A | R3) -> A
    BIT_XOR,                        // Pops value from stack and XORs it with Accumulator. (A ^ V) -> A
    BIT_XOR_IM,                     // XORs Accumulator and immediate value (A ^ V) -> A
    BIT_XOR_X,                      // XORs Accumulator and value in X (A ^ X) -> A
    BIT_XOR_Y,                      // XORs Accumulator and value in Y (A ^ Y) -> A
    BIT_XOR_Z,                      // XORs Accumulator and value in Z (A ^ Z) -> A
    BIT_XOR_R0,                     // XORs Accumulator and value in R0 (A ^ R0) -> A
    BIT_XOR_R1,                     // XORs Accumulator and value in R1 (A ^ R1) -> A
    BIT_XOR_R2,                     // XORs Accumulator and value in R2 (A ^ R2) -> A
    BIT_XOR_R3,                     // XORs Accumulator and value in R3 (A ^ R3) -> A
    SET_CARRY,                      // Sets the Carry Flag
    SET_NEG,                        // Sets the Negative Flag
    CLEAR_CARRY,                    // Clears the Carry Flag
    CLEAR_OVERFLOW,                 // Clears the Overflow Flag
    CLEAR_NEG,                      // Clears the Negative Flag
    BRANCH_PLUS,                    // If Negative is clear, pops two values from stack and uses them as an address to jump to. HB is poped first, then LB. pushed Little Endian 
    BRANCH_PLUS_IM,                 // If Negative is clear,  uses immediate 2 values as an address to jump to. LB, HB. Little Endian.
    BRANCH_PLUS_XY,                 //
    BRANCH_PLUS_R0R1,               //
    BRANCH_PLUS_R2R3,               //
    BRANCH_MINUS,                   //
    BRANCH_MINUS_IM,                //
    BRANCH_MINUS_XY,                //
    BRANCH_MINUS_R0R1,              //
    BRANCH_MINUS_R2R3,              //
    BRANCH_OVERFLOW_SET,            //
    BRANCH_OVERFLOW_SET_IM,         //
    BRANCH_OVERFLOW_SET_XY,         //
    BRANCH_OVERFLOW_SET_R0R1,       //
    BRANCH_OVERFLOW_SET_R2R3,       //
    BRANCH_OVERFLOW_CLEAR,          //
    BRANCH_OVERFLOW_CLEAR_IM,       //
    BRANCH_OVERFLOW_CLEAR_XY,       //
    BRANCH_OVERFLOW_CLEAR_R0R1,     //
    BRANCH_OVERFLOW_CLEAR_R2R3,     //
    BRANCH_CARRY_SET,               //
    BRANCH_CARRY_SET_IM,            //
    BRANCH_CARRY_SET_XY,            //
    BRANCH_CARRY_SET_R0R1,          //
    BRANCH_CARRY_SET_R2R3,          //
    BRANCH_CARRY_CLEAR,             //
    BRANCH_CARRY_CLEAR_IM,          //
    BRANCH_CARRY_CLEAR_XY,          //
    BRANCH_CARRY_CLEAR_R0R1,        //
    BRANCH_CARRY_CLEAR_R2R3,        //
    BRANCH_EQUAL,                   //
    BRANCH_EQUAL_IM,                //
    BRANCH_EQUAL_XY,                //
    BRANCH_EQUAL_R0R1,              //
    BRANCH_EQUAL_R2R3,              //
    BRANCH_NOT_EQUAL,               //
    BRANCH_NOT_EQUAL_IM,            //
    BRANCH_NOT_EQUAL_XY,            //
    BRANCH_NOT_EQUAL_R0R1,          //
    BRANCH_NOT_EQUAL_R2R3,          //
    JUMP,                           //
    JUMP_IM,                        //
    JUMP_XY,                        //
    JUMP_R0R1,                      //
    JUMP_R2R3,                      //
    JUMP_SUBROUTINE,                //
    JUMP_SUBROUTINE_IM,             //
    // JUMP_SUBROUTINE_XY           //,
    // JUMP_SUBROUTINE_R0R1         //,
    // JUMP_SUBROUTINE_R2R3         //,
    PRINT_SIGNED,                   //
    PRINT_SIGNED_IM,                //
    PRINT_SIGNED_X,                 //
    PRINT_SIGNED_Y,                 //
    PRINT_SIGNED_Z,                 //
    PRINT_SIGNED_R0,                //
    PRINT_SIGNED_R1,                //
    PRINT_SIGNED_R2,                //
    PRINT_SIGNED_R3,                //
    PRINT_UNSIGNED,                 //
    PRINT_UNSIGNED_IM,              //
    PRINT_UNSIGNED_X,               //
    PRINT_UNSIGNED_Y,               //
    PRINT_UNSIGNED_Z,               //
    PRINT_UNSIGNED_R0,              //
    PRINT_UNSIGNED_R1,              //
    PRINT_UNSIGNED_R2,              //
    PRINT_UNSIGNED_R3,              //
    PRINT_ASCII,                    //
    PRINT_ASCII_IM,                 //
    PRINT_ASCII_X,                  //
    PRINT_ASCII_Y,                  //
    PRINT_ASCII_Z,                  //
    PRINT_ASCII_R0,                 //
    PRINT_ASCII_R1,                 //
    PRINT_ASCII_R2,                 //
    PRINT_ASCII_R3,                 //
    INPUT_NUMBER,                   //
    INPUT_ASCII,                    //
    READ_A,                         //
    READ_A_IM,                      //
    READ_A_XY,                      //
    READ_A_R0R1,                    //
    READ_A_R2R3,                    //    
    WRITE_A,                        //
    WRITE_A_IM,                     //
    WRITE_A_XY,                     //
    WRITE_A_R0R1,                   //
    WRITE_A_R2R3,                   //

    HALT = 255                      //

} Opcode;

#endif