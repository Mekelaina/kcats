#ifndef KCATS_OPCODE_H
#define KCATS_OPCODE_H

typedef enum Opcode{
    NO_OP = 0, // No operation
    HALT,      // Halt the program
    HALT_W_EXITCODE, // Halt the program with an exit code
    
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

    // Swap X and Y
    SWP_XY,    // Swaps values in X and Y

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
    JMP,      // No arg, pops the val off top of the stack and jumps there
    JMP_L,    // No arg, pops the top 2 vals off of the stack and jumps there (low byte poped first)
    JMP_IM,   // Jumps to the address speciffied by the immediate val (1 byte) 
    JMP_IM_L, // Jumps to the address speciffied by the immediate val (2 bytes)
    JMP_X,    // Jumps to the address using the val in X 
    JMP_Y,    // Jumps to the address using the val in Y
    JMP_XY,   // Jumps to the address using the vals in X and Y. X is high byte, Y is low byte

    JNZ,      // No arg, if the zero flag is NOT set, pops the val off top of the stack and jumps there
    JNZ_L,    // No arg, if the zero flag is NOT set, pops the top 2 vals off of the stack and jumps there (low byte poped first)
    JNZ_IM,   // if the zero flag is NOT set, Jumps to the address speciffied by the immediate val (1 byte)  
    JNZ_IM_L, // if the zero flag is NOT set, Jumps to the address speciffied by the immediate val (2 bytes)
    JNZ_X,    // if the zero flag is NOT set, Jumps to the address using the val in X  
    JNZ_Y,    // if the zero flag is NOT set, Jumps to the address using the val in Y
    JNZ_XY,   // if the zero flag is NOT set, Jumps to the address using the vals in X and Y. X is high byte, Y is low byte

    JZR,      // No arg, if the zero flag IS set, pops the val off top of the stack and jumps there
    JZR_L,    // No arg, if the zero flag IS set, pops the top 2 vals off of the stack and jumps there (low byte poped first)
    JZR_IM,   // if the zero flag IS set, Jumps to the address speciffied by the immediate val (1 byte) 
    JZR_IM_L, // if the zero flag IS set, Jumps to the address speciffied by the immediate val (2 bytes)
    JZR_X,    // if the zero flag IS set, Jumps to the address using the val in X  
    JZR_Y,    // if the zero flag IS set, Jumps to the address using the val in Y
    JZR_XY,   // if the zero flag IS set, Jumps to the address using the vals in X and Y. X is high byte, Y is low byte

    JFC,      // No arg, if carry flag is set, pops the val off top of the stack and jumps there
    JFC_L,    // No arg, if carry flag is set, pops the top 2 vals off of the stack and jumps there (low byte poped first)
    JFC_IM,   // if carry flag is set, Jumps to the address speciffied by the immediate val (1 byte) 
    JFC_IM_L, // if carry flag is set, Jumps to the address speciffied by the immediate val (2 bytes)
    JFC_X,    // if carry flag is set, Jumps to the address using the val in X  
    JFC_Y,    // if carry flag is set, Jumps to the address using the val in Y
    JFC_XY,   // if carry flag is set, Jumps to the address using the vals in X and Y. X is high byte, Y is low byte

    JIF,      // No arg, if boolean flag IS set, pops the val off top of the stack and jumps there
    JIF_L,    // No arg, if boolean flag IS set, pops the top 2 vals off of the stack and jumps there (low byte poped first)
    JIF_IM,   // if boolean flag IS set, Jumps to the address speciffied by the immediate val (1 byte) 
    JIF_IM_L, // if boolean flag IS set, Jumps to the address speciffied by the immediate val (2 bytes)
    JIF_X,    // if boolean flag IS set, Jumps to the address using the val in X  
    JIF_Y,    // if boolean flag IS set, Jumps to the address using the val in Y
    JIF_XY,   // if boolean flag IS set, Jumps to the address using the vals in X and Y. X is high byte, Y is low byte

    JEL,      // No arg, if boolean flag is NOT set, pops the val off top of the stack and jumps there
    JEL_L,    // No arg, if boolean flag is NOT set, pops the top 2 vals off of the stack and jumps there (low byte poped first)
    JEL_IM,   // if boolean flag is NOT set, Jumps to the address speciffied by the immediate val (1 byte) 
    JEL_IM_L, // if boolean flag is NOT set, Jumps to the address speciffied by the immediate val (2 bytes)
    JEL_X,    // if boolean flag is NOT set, Jumps to the address using the val in X  
    JEL_Y,    // if boolean flag is NOT set, Jumps to the address using the val in Y
    JEL_XY,   // if boolean flag is NOT set, Jumps to the address using the vals in X and Y. X is high byte, Y is low byte

    JDZ,      // No arg, if the div by 0 flag is set, pops the val off top of the stack and jumps there
    JDZ_L,    // No arg, if the div by 0 flag is set, pops the top 2 vals off of the stack and jumps there (low byte poped first)
    JDZ_IM,   // if the div by 0 flag is set, Jumps to the address speciffied by the immediate val (1 byte)  
    JDZ_IM_L, // if the div by 0 flag is set, Jumps to the address speciffied by the immediate val (2 bytes)
    JDZ_X,    // if the div by 0 flag is set, Jumps to the address using the val in X  
    JDZ_Y,    // if the div by 0 flag is set, Jumps to the address using the val in Y
    JDZ_XY,   // if the div by 0 flag is set, Jumps to the address using the vals in X and Y. X is high byte, Y is low byte

    JRM,      // No arg, if the remainder flag is set, pops the val off top of the stack and jumps there
    JRM_L,    // No arg, if the remainder flag is set, pops the top 2 vals off of the stack and jumps there (low byte poped first)
    JRM_IM,   // if the remainder flag is set, Jumps to the address speciffied by the immediate val (1 byte) 
    JRM_IM_L, // if the remainder flag is set, Jumps to the address speciffied by the immediate val (2 bytes)
    JRM_X,    // if the remainder flag is set, Jumps to the address using the val in X  
    JRM_Y,    // if the remainder flag is set, Jumps to the address using the val in Y
    JRM_XY,   // if the remainder flag is set, Jumps to the address using the vals in X and Y. X is high byte, Y is low byte

    // Arithmatic
    ADD,      // pops top 2 vals on stack, adds them, pushes the result (1st off + 2nd off)
    ADD_IM,   // pops the top value on the stack, adds the immediate value to it, pushes the result
    ADD_IM_L, // adds the two immediate vals and pushes the result
    ADD_X,    // pops top val on stack, adds val in X, pushes result
    ADD_Y,    // pops top val on stack, adds val in Y, pushes result
    ADD_XY,   // adds X and Y, pushes the result

    SUB,      // pops top 2 vals on stack, subtracts them, pushes the result (2nd off - 1st off)
    SUB_IM,   // pops the top value on the stack, subtracts the immediate value from it, pushes the result
    SUB_IM_L, // subtracts the two immediate vals and pushes the result (a - b)
    SUB_X,    // pops top val on stack, subtracts val in X from it, pushes result
    SUB_Y,    // pops top val on stack, subtracts val in Y from it, pushes result
    SUB_XY,   // subtracts X from Y and pushes the result
    
    MUL,      // pops top 2 vals on stack, multiplies them, pushes the result (1st off * 2nd off)
    MUL_IM,   // pops the top value on the stack, multiplies the immediate value to it, pushes the result
    MUL_IM_L, // multiplies the two immediate vals and pushes the result
    MUL_X,    // pops top val on stack, multiplies it by the val in X, pushes result
    MUL_Y,    // pops top val on stack, multiplies it by the val in Y, pushes result
    MUL_XY,   // multiplies X and Y and pushes the result
    
    DIV,      // pops top 2 vals on stack, divides them, pushes the result (1st off / 2nd off)
    DIV_IM,   // pops the top value on the stack, divides it by the immediate value, pushes the result
    DIV_IM_L, // divides the two immediate vals and pushes the result (a / b)
    DIV_X,    // pops top val on stack, divides it by val in X, pushes result
    DIV_Y,    // pops top val on stack, divides it by val in Y, pushes result
    DIV_XY,   // divides X by Y and pushes the result
    
    MOD,      // pops top 2 vals on stack, takes the modulus of them, pushes the result (1st off % 2nd off)
    MOD_IM,   // pops the top value on the stack, takes the modulus of it and the immediate value, pushes the result
    MOD_IM_L, // takes the modulus of the two immediate vals and pushes the result (a % b)
    MOD_X,    // pops top val on stack, modulo by val in X, pushes result
    MOD_Y,    // pops top val on stack, modulo by val in Y, pushes result
    MOD_XY,   // takes modulus of X and Y and pushes the result
    
    ROL,      // pops top val on stack, rotates bits left, pushes result
    ROL_IM,   // rotates immediate val's bits left, pushes result
    ROL_X,    // rotates val of X bits left, pushes result
    ROL_Y,    // rotates val of Y bits left, pushes result
    
    ROR,      // pops top val on stack, rotates bits right, pushes result
    ROR_IM,   // rotates immediate val's bits right, pushes result
    ROR_X,    // rotates val of X bits right, pushes result
    ROR_Y,    // rotates val of Y bits right, pushes result
    
    SHR,      // pops top val on stack, shifts bits left, pushes result
    SHR_IM,   // shifts immediate val's bits left, pushes result
    SHR_X,    // shifts val of X bits left, pushes result
    SHR_Y,    // shifts val of Y bits left, pushes result
    
    SHL,      // pops top val on stack, shifts bits right, pushes result
    SHL_IM,   // shifts immediate val's bits right, pushes result
    SHL_X,    // shifts val of X bits right, pushes result
    SHL_Y,    // shifts val of Y bits right, pushes result
    
    AND,      // pops top 2 vals on stack, preforms bitwise AND on them, pushes result
    AND_IM,   // pops top val on stack, preforms bitwise AND on it and immediate val, pushes result.
    AND_IM_L, // preforms bitwise AND on two immediate vals, pushes result
    AND_X,    // pops top val on stack, preforms bitwise AND on it and X, pushes result
    AND_Y,    // pops top val on stack, preforms bitwise AND on it and Y, pushes result
    AND_XY,   // preforms bitwise AND on X and Y, pushes result
    
    OR,       // pops top 2 vals on stack, preforms bitwise OR on them, pushes result
    OR_IM,    // pops top val on stack, preforms bitwise OR on it and immediate val, pushes result.
    OR_IM_L,  // preforms bitwise OR on two immediate vals, pushes result
    OR_X,     // pops top val on stack, preforms bitwise OR on it and X, pushes result
    OR_Y,     // pops top val on stack, preforms bitwise OR on it and Y, pushes result
    OR_XY,    // preforms bitwise OR on X and Y, pushes result
    
    XOR,      // pops top 2 vals on stack, preforms bitwise XOR on them, pushes result
    XOR_IM,   // pops top val on stack, preforms bitwise XOR on it and immediate val, pushes result.
    XOR_IM_L, // preforms bitwise XOR on two immediate vals, pushes result
    XOR_X,    // pops top val on stack, preforms bitwise XOR on it and X, pushes result
    XOR_Y,    // pops top val on stack, preforms bitwise XOR on it and Y, pushes result
    XOR_XY,   // preforms bitwise XOR on X and Y, pushes result
    
    NOT,      // pops top val on stack, inverts bits, pushes result
    NOT_IM,   // inverts bits of immediate val, pushes result.
    NOT_X,    // inverts bits of X, pushes result
    NOT_Y,    // inverts bits of Y, pushes result

    // Boolean Operations
    LTH,      // pops top 2 vals on stack, evals if(1st off < 2nd off) sets bool flag if true, clears it if false
    LTH_IM,   // pops top val on stack, evals if(off < immediate val) sets bool flag if true, clears it if false
    LTH_X,    // pops top val on stack, evals if(off < val in X) sets bool flag if true, clears it if false
    LTH_Y,    // pops top val on stack, evals if(off < val in Y) sets bool flag if true, clears it if false
    LTH_Z,    // pops top val on stack, evals if(off < val in Z) sets bool flag if true, clears it if false
    LTH_X_IM, // evals if(val in X < immediate val) sets bool flag if true, clears it if false
    LTH_X_Y,  // evals if(val in X < val in Y) sets bool flag if true, clears it if false
    LTH_X_Z,  // evals if(val in X < val in Z) sets bool flag if true, clears it if false
    LTH_Y_IM, // evals if(val in Y < immediate val) sets bool flag if true, clears it if false
    LTH_Y_X,  // evals if(val in Y < val in X) sets bool flag if true, clears it if false
    LTH_Y_Z,  // evals if(val in Y < val in Z) sets bool flag if true, clears it if false

    GTH,      // pops top 2 vals on stack, evals if(1st off > 2nd off) sets bool flag if true, clears it if false
    GTH_IM,   // pops top val on stack, evals if(off > immediate val) sets bool flag if true, clears it if false
    GTH_X,    // pops top val on stack, evals if(off > val in X) sets bool flag if true, clears it if false
    GTH_Y,    // pops top val on stack, evals if(off > val in Y) sets bool flag if true, clears it if false
    GTH_Z,    // pops top val on stack, evals if(off > val in Z) sets bool flag if true, clears it if false
    GTH_X_IM, // evals if(val in X > immediate val) sets bool flag if true, clears it if false
    GTH_X_Y,  // evals if(val in X > val in Y) sets bool flag if true, clears it if false
    GTH_X_Z,  // evals if(val in X > val in Z) sets bool flag if true, clears it if false
    GTH_Y_IM, // evals if(val in Y > immediate val) sets bool flag if true, clears it if false
    GTH_Y_X,  // evals if(val in Y > val in X) sets bool flag if true, clears it if false
    GTH_Y_Z,  // evals if(val in Y > val in Z) sets bool flag if true, clears it if false

    LEQ,      // pops top 2 vals on stack, evals if(1st off <= 2nd off) sets bool flag if true, clears it if false
    LEQ_IM,   // pops top val on stack, evals if(off <= immediate val) sets bool flag if true, clears it if false
    LEQ_X,    // pops top val on stack, evals if(off <= val in X) sets bool flag if true, clears it if false
    LEQ_Y,    // pops top val on stack, evals if(off <= val in Y) sets bool flag if true, clears it if false
    LEQ_Z,    // pops top val on stack, evals if(off <= val in Z) sets bool flag if true, clears it if false
    LEQ_X_IM, // evals if(val in X <= immediate val) sets bool flag if true, clears it if false
    LEQ_X_Y,  // evals if(val in X <= val in Y) sets bool flag if true, clears it if false
    LEQ_X_Z,  // evals if(val in X <= val in Z) sets bool flag if true, clears it if false
    LEQ_Y_IM, // evals if(val in Y <= immediate val) sets bool flag if true, clears it if false
    LEQ_Y_X,  // evals if(val in Y <= val in X) sets bool flag if true, clears it if false
    LEQ_Y_Z,  // evals if(val in Y <= val in Z) sets bool flag if true, clears it if false

    GEQ,      // pops top 2 vals on stack, evals if(1st off >= 2nd off) sets bool flag if true, clears it if false
    GEQ_IM,   // pops top val on stack, evals if(off >= immediate val) sets bool flag if true, clears it if false
    GEQ_X,    // pops top val on stack, evals if(off >= val in X) sets bool flag if true, clears it if false
    GEQ_Y,    // pops top val on stack, evals if(off >= val in Y) sets bool flag if true, clears it if false
    GEQ_Z,    // pops top val on stack, evals if(off >= val in Z) sets bool flag if true, clears it if false
    GEQ_X_IM, // evals if(val in X >= immediate val) sets bool flag if true, clears it if false
    GEQ_X_Y,  // evals if(val in X >= val in Y) sets bool flag if true, clears it if false
    GEQ_X_Z,  // evals if(val in X >= val in Z) sets bool flag if true, clears it if false
    GEQ_Y_IM, // evals if(val in Y >= immediate val) sets bool flag if true, clears it if false
    GEQ_Y_X,  // evals if(val in Y >= val in X) sets bool flag if true, clears it if false
    GEQ_Y_Z,  // evals if(val in Y >= val in Z) sets bool flag if true, clears it if false

    EQU,      // pops top 2 vals on stack, evals if(1st off == 2nd off) sets bool flag if true, clears it if false
    EQU_IM,   // pops top val on stack, evals if(off == immediate val) sets bool flag if true, clears it if false
    EQU_X,    // pops top val on stack, evals if(off == val in X) sets bool flag if true, clears it if false
    EQU_Y,    // pops top val on stack, evals if(off == val in Y) sets bool flag if true, clears it if false
    EQU_Z,    // pops top val on stack, evals if(off == val in Z) sets bool flag if true, clears it if false
    EQU_X_IM, // evals if(val in X == immediate val) sets bool flag if true, clears it if false
    EQU_X_Y,  // evals if(val in X == val in Y) sets bool flag if true, clears it if false
    EQU_X_Z,  // evals if(val in X == val in Z) sets bool flag if true, clears it if false
    EQU_Y_IM, // evals if(val in Y == immediate val) sets bool flag if true, clears it if false
    EQU_Y_X,  // evals if(val in Y == val in X) sets bool flag if true, clears it if false
    EQU_Y_Z,  // evals if(val in Y == val in Z) sets bool flag if true, clears it if false

    NEQ,      // pops top 2 vals on stack, evals if(1st off != 2nd off) sets bool flag if true, clears it if false
    NEQ_IM,   // pops top val on stack, evals if(off != immediate val) sets bool flag if true, clears it if false
    NEQ_X,    // pops top val on stack, evals if(off != val in X) sets bool flag if true, clears it if false
    NEQ_Y,    // pops top val on stack, evals if(off != val in Y) sets bool flag if true, clears it if false
    NEQ_Z,    // pops top val on stack, evals if(off != val in Z) sets bool flag if true, clears it if false
    NEQ_X_IM, // evals if(val in X != immediate val) sets bool flag if true, clears it if false
    NEQ_X_Y,  // evals if(val in X != val in Y) sets bool flag if true, clears it if false
    NEQ_X_Z,  // evals if(val in X != val in Z) sets bool flag if true, clears it if false
    NEQ_Y_IM, // evals if(val in Y != immediate val) sets bool flag if true, clears it if false
    NEQ_Y_X,  // evals if(val in Y != val in X) sets bool flag if true, clears it if false
    NEQ_Y_Z,  // evals if(val in Y != val in Z) sets bool flag if true, clears it if false
    



    // just here to be able to know the count of opcodes. is NOT actually an opcode and should never be used 
    OPCODE_COUNT
};

#endif