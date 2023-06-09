#ifndef KCATS_OPCODE_H
#define KCATS_OPCODE_H

//TODO: Update Docs with INPUT_ASCII and INPUT_NUMBER change

typedef enum Opcode {
    NO_OP,
    POP,
    PUSH,
    PUSH_IM,
    PUSH_X,
    PUSH_Y,
    SWAP,
    OVER,
    ROT,
    ROT_IM,
    ROT_X,
    ROT_Y,
    CLEAR_CARRY,
    CLEAR_BOOL,
    CLEAR_DBZ,
    LOAD_X,    
    LOAD_X_IM, 
    LOAD_X_Y,  
    LOAD_X_Z,  
    LOAD_Y,    
    LOAD_Y_IM, 
    LOAD_Y_X,  
    LOAD_Y_Z,
    INC_X,
    DEC_X,
    INC_Y,
    DEC_Y,
    NUM_OUT,
    NUM_OUT_X,
    NUM_OUT_Y,
    NUM_OUT_Z,
    PRINT,
    PRINT_X,
    PRINT_Y,
    INPUT_NUMBER,
    INPUT_ASCII,  
    JUMP,    
    JUMP_IM, 
    JUMP_X,  
    JUMP_Y,  
    LJUMP,   
    LJUMP_IM,
    LJUMP_XY,      
    JUMP_CARRY,    
    JUMP_CARRY_IM, 
    JUMP_CARRY_X,  
    JUMP_CARRY_Y,  
    LJUMP_CARRY,   
    LJUMP_CARRY_IM,
    LJUMP_CARRY_XY,
    JUMP_TRUE,    
    JUMP_TRUE_IM, 
    JUMP_TRUE_X,  
    JUMP_TRUE_Y,  
    LJUMP_TRUE,   
    LJUMP_TRUE_IM,
    LJUMP_TRUE_XY,
    JUMP_DBZ,
    JUMP_DBZ_IM,
    JUMP_DBZ_X,
    JUMP_DBZ_Y,
    LJUMP_DBZ,
    LJUMP_DBZ_IM,
    LJUMP_DBZ_XY,
    ADD,
    ADD_IM,
    ADD_IM_L,
    ADD_X,
    ADD_Y,
    ADD_X_Y,
    SUBTRACT,
    SUBTRACT_IM,
    SUBTRACT_IM_L,
    SUBTRACT_X,
    SUBTRACT_Y,
    SUBTRACT_X_Y,
    MULTIPLY,
    MULTIPLY_IM,
    MULTIPLY_IM_L,
    MULTIPLY_X,
    MULTIPLY_Y,
    MULTIPLY_X_Y,
    DIVIDE,
    DIVIDE_IM,
    DIVIDE_IM_L,
    DIVIDE_X,
    DIVIDE_Y,
    DIVIDE_X_Y,
    BIT_ROT_LEFT,
    BIT_ROT_LEFT_IM,
    BIT_ROT_LEFT_X,
    BIT_ROT_LEFT_Y,
    BIT_ROT_RIGHT,
    BIT_ROT_RIGHT_IM,
    BIT_ROT_RIGHT_X,
    BIT_ROT_RIGHT_Y,
    BIT_SHIFT_LEFT,
    BIT_SHIFT_LEFT_IM,
    BIT_SHIFT_LEFT_X,
    BIT_SHIFT_LEFT_Y,
    BIT_SHIFT_RIGHT,
    BIT_SHIFT_RIGHT_IM,
    BIT_SHIFT_RIGHT_X,
    BIT_SHIFT_RIGHT_Y,
    BIT_AND,
    BIT_AND_IM,
    BIT_AND_IM_L,
    BIT_AND_X,
    BIT_AND_Y,
    BIT_AND_XY,
    BIT_OR,
    BIT_OR_IM,
    BIT_OR_IM_L,
    BIT_OR_X,
    BIT_OR_Y,
    BIT_OR_XY,
    BIT_XOR,
    BIT_XOR_IM,
    BIT_XOR_IM_L,
    BIT_XOR_X,
    BIT_XOR_Y,
    BIT_XOR_XY,
    BIT_NOT,
    BIT_NOT_IM,
    BIT_NOT_X,
    BIT_NOT_Y,
    IS_LT,
    IS_LT_IM,
    IS_LT_X,
    IS_LT_Y,
    IS_LT_Z,
    IS_LT_X_IM,
    IS_LT_X_Y,
    IS_LT_X_Z,
    IS_LT_Y_IM,
    IS_LT_Y_X,
    IS_LT_Y_Z,
    IS_LT_Z_IM,
    IS_LT_Z_X,
    IS_LT_Z_Y,
    IS_GT,
    IS_GT_IM,
    IS_GT_X,
    IS_GT_Y,
    IS_GT_Z,
    IS_GT_X_IM,
    IS_GT_X_Y,
    IS_GT_X_Z,
    IS_GT_Y_IM,
    IS_GT_Y_X,
    IS_GT_Y_Z,
    IS_GT_Z_IM,
    IS_GT_Z_X,
    IS_GT_Z_Y,
    IS_EQ,
    IS_EQ_IM,
    IS_EQ_X,
    IS_EQ_Y,
    IS_EQ_Z,
    IS_EQ_X_IM,
    IS_EQ_X_Y,
    IS_EQ_X_Z,
    IS_EQ_Y_IM,
    IS_EQ_Y_X,
    IS_EQ_Y_Z,
    IS_EQ_Z_IM,
    IS_EQ_Z_X,
    IS_EQ_Z_Y,
   

    HALT = 255



};
#endif