#ifndef KCATS_OPCODE_H
#define KCATS_OPCODE_H

typedef enum Opcode{
    NO_OP = 0,
    HALT,
    HALT_W_EXITCODE,
    
    // Load X
    LOAD_X,    // No argument, pops from stack stores in X
    LOAD_X_IM, // Loads from immediate value
    LOAD_X_Y,  // Loads X with val in Y
    LOAD_X_Z,  // Loads X with val in Z (num in elements in stack)

    // Load Y
    LOAD_Y,    // No argument, pops from stack stores in Y
    LOAD_Y_IM, // Loads from immediate value
    LOAD_Y_X,  // Loads Y with val in X
    LOAD_Y_Z,  // Loads Y with val in Z (num in elements in stack)

    // Inc/Dec
    INC_X, // Increment X
    DEC_X, // Decrement X
    INC_Y, // Increment Y
    DEC_Y, // Decrement Y

    // Clear Flags
    CLR_C, // No args, clears carry flag
    CLR_B, // No args, clears boolean flag
    CLR_Z, // No args, clears zero flag
    CLR_D, // No args, clears Div by 0 flag
    CLR_R, // No args, clears remainder flag

    // Pop
    POP,    // No arg, discards val on top of the stack
    POP_IM, // Discards top value on stack (args) of times
    POP_X,  // Pops top value on stack and puts it in X
    POP_Y,  // Pops top value on stack and puts it in Y

    // Push
    PUSH,    // No arg, duplicates val on top of stack
    PUSH_IM, // Pushes immediate val onto stack
    PUSH_X,  // Pushes value of X onto stack
    PUSH_Y,  // Pushes value of Y onto stack

    // I/O
    OUT,    // No arg, pops top val of stack and prints it as a number
    OUT_IM, // Prints immediate value as a number
    OUT_X,  // Prints val of X as number
    OUT_Y,  // Prints val of Y as number
    OUT_Z,  // Prints val of Z as number

    PRT,    // No arg, pops top val of stack and prints as ascii
    PRT_IM, // Prints immediate val as ascii
    PRT_X,  // Prints val of X as ascii
    PRT_Y,  // Prints val of Y as ascii

    INP,    // Get input from console and push to stack
    INP_X,  // Get input from console and store in X
    INP_Y,  // Get input from console and store in Y

    // JUMPS
    JUMP,
};

#endif