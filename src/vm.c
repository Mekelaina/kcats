#include "vm.h"
#include "opcode.h"

#include <stdio.h>
#include <limits.h>

static void fetchInstruction(VM *vm){
    if(vm->PC < vm->programSize){
        vm->OP = *((vm->program)+vm->PC);
        vm->PC++;
    }
}

static uint8_t fetchArg(VM *vm){
    uint8_t x = 0;
    if(vm->PC < vm->programSize){
        x = *((vm->program)+vm->PC);
        vm->PC++;
    }
    return x;
}

static int checkForOverflow_Add(uint8_t a, uint8_t b){
    if((a + b) < a || (a + b) < b){
        return 1;
    }
    return 0;
}

static int checkForOverflow_Subtract(uint8_t a, uint8_t b){
        if((a - b) > a || (a - b) > b){
        return 1;
    }
    return 0;
}

static int checkForOverflow_Multiply(uint8_t a, uint8_t b){
    if((a * b) < a || (a * b) < b){
        return 1;
    }
    return 0;
}

// circular shift/bit rotation by 1 bit.
// left if dir is 0 or positive. right if negitive
static uint8_t bitRotate(uint8_t in, int dir){
    size_t shift = 1;
    if(dir >= 0){
        return (in << shift) | (in >> ((sizeof(in) * CHAR_BIT - shift) % (sizeof(in) * CHAR_BIT)));
    } else {
        return (in >> shift) | (in << ((sizeof(in) * CHAR_BIT - shift) % (sizeof(in) * CHAR_BIT)));
    }
}

static void execute(VM *vm){
    
    switch(vm->OP){
        case NO_OP: break;
        // stack ops
        case POP: {
            pop(&(vm->stack));
        } break;
        case PUSH: {
            uint8_t a = peak(&(vm->stack));
            push(&(vm->stack), a);
        } break;
        case PUSH_IM: { 
            uint8_t a = fetchArg(vm);
            push(&(vm->stack), a);
        } break;
        case PUSH_X: {
            push(&(vm->stack), vm->REG_X);
        } break;
        case PUSH_Y: {
            push(&(vm->stack), vm->REG_Y);
        } break;
        case SWAP: {
            swap(&(vm->stack));
        } break;
        case OVER: {
            over(&(vm->stack));
        } break;
        case ROT: {
            rotate(&(vm->stack));
        } break;
        case ROT_IM: {
            rotateNumberOfItems(&(vm->stack), (uint16_t)fetchArg(vm));
        } break;
        case ROT_X: {
            rotateNumberOfItems(&(vm->stack), vm->REG_X);
        } break;
        case ROT_Y: {
            rotateNumberOfItems(&(vm->stack), vm->REG_Y);
        } break;

        //clear flags
        case CLEAR_CARRY: {
            vm->flags.C = 0;
        } break;
        case CLEAR_BOOL: {
            vm->flags.B = 0;
        } break;
        case CLEAR_DBZ: {
            vm->flags.D = 0;
        } break;

        // register ops
        case LOAD_X: {
            uint8_t a = pop(&(vm->stack));
            vm->REG_X = a;
        } break;
        case LOAD_X_IM: {
            uint8_t a = fetchArg(vm);
            vm->REG_X = a;
        } break;
        case LOAD_X_Y: {
            vm->REG_X = vm->REG_Y;
        } break;
        case LOAD_X_Z: {
            vm->REG_X = vm->REG_Z;
        } break;
        case LOAD_Y: {
            vm->REG_Y = pop(&(vm->stack));
        } break;
        case LOAD_Y_IM: {
            vm->REG_Y = fetchArg(vm);
        } break;
        case LOAD_Y_X: {
            vm->REG_Y = vm->REG_X;
        } break;
        case LOAD_Y_Z: {
            vm->REG_Y = vm->REG_Z;
        } break;
        case INC_X: {
            vm->REG_X++;
            if(vm->REG_X == 0){
                vm->flags.C = 1;
            }
        } break;
        case DEC_X: {
            vm->REG_X--;
            if(vm->REG_X == 255){
                vm->flags.C = 1;
            }
        }
        case INC_Y: {
            vm->REG_Y++;
            if(vm->REG_Y == 0){
                vm->flags.C = 1;
            }
        } break;
        case DEC_Y: {
            vm->REG_Y--;
            if(vm->REG_Y == 255){
                vm->flags.C = 1;
            }
        }

        // I/O ops
        case NUM_OUT: {
            printf("%d\n", pop(&(vm->stack)));
        } break;
        case NUM_OUT_X: {
            printf("%d\n", vm->REG_X);
        } break;
        case NUM_OUT_Y: {
            printf("%d\n", vm->REG_Y);
        } break;
        case NUM_OUT_Z: {
            printf("%d\n", vm->REG_Z);
        } break;
        case PRINT: {
            printf("%c\n", pop(&(vm->stack)));
        } break;
        case PRINT_X: {
            printf("%c\n", vm->REG_X);
        } break;
        case PRINT_Y: {
            printf("%c\n", vm->REG_Y);
        } break;
        case INPUT_NUMBER: {
            printf("TODO: Input from console unimplemented\n");
        } break;
        case INPUT_ASCII: {
            printf("TODO: Input from console unimplemented\n");
        }
        // Jumps
        case JUMP: {
            vm->PC = (uint16_t) pop(&(vm->stack));
        } break;
        case JUMP_IM: {
            vm->PC = (uint16_t) fetchArg(vm);
        } break;
        case JUMP_X: {
            vm->PC = (uint16_t) vm->REG_X;
        } break;
        case JUMP_Y: {
            vm->PC = (uint16_t) vm->REG_Y;
        } break;
        case LJUMP: {
            uint8_t low, high;
            uint16_t addr;
            low  = pop(&(vm->stack));
            high = pop(&(vm->stack));
            addr = (high << 8) | low;
            vm->PC = addr;
        } break;
        case LJUMP_IM: {
            uint8_t low, high;
            uint16_t addr;
            high = fetchArg(vm);
            low  = fetchArg(vm);
            addr = (high << 8) | low;
            vm->PC = addr;
        } break;
        case LJUMP_XY: {
            vm->PC = (vm->REG_X << 8) | vm->REG_Y;
        } break;
        case JUMP_CARRY: {
            if(vm->flags.C){
                vm->PC = (uint16_t) pop(&(vm->stack));
            }
        } break;
        case JUMP_CARRY_IM: {
            if(vm->flags.C){
                vm->PC = (uint16_t) fetchArg(vm);
            }
        } break;
        case JUMP_CARRY_X: {
            if(vm->flags.C){
                vm->PC = (uint16_t) vm->REG_X;
            }
        } break;
        case JUMP_CARRY_Y: {
            if(vm->flags.C){
                vm->PC = (uint16_t) vm->REG_Y;
            }
        } break;
        case LJUMP_CARRY: {
            if(vm->flags.C){
                uint8_t low, high;
                uint16_t addr;
                low  = pop(&(vm->stack));
                high = pop(&(vm->stack));
                addr = (high << 8) | low;
                vm->PC = addr;
            }
        } break;
        case LJUMP_CARRY_IM: {
            if(vm->flags.C){
                uint8_t low, high;
                uint16_t addr;
                high = fetchArg(vm);
                low  = fetchArg(vm);
                addr = (high << 8) | low;
                vm->PC = addr;
            }
        } break;
        case LJUMP_CARRY_XY: {
            if(vm->flags.C){
                vm->PC = (vm->REG_X << 8) | vm->REG_Y;
            }
        } break;
        case JUMP_TRUE: {
            if(vm->flags.D){
                vm->PC = (uint16_t) pop(&(vm->stack));
            }
        } break;
        case JUMP_TRUE_IM: {
            if(vm->flags.D){
                vm->PC = (uint16_t) fetchArg(vm);
            }
        } break;
        case JUMP_TRUE_X: {
            if(vm->flags.D){
                vm->PC = (uint16_t) vm->REG_X;
            }
        } break;
        case JUMP_TRUE_Y: {
            if(vm->flags.D){
                vm->PC = (uint16_t) vm->REG_Y;
            }
        } break;
        case LJUMP_TRUE: {
            if(vm->flags.D){
                uint8_t low, high;
                uint16_t addr;
                low  = pop(&(vm->stack));
                high = pop(&(vm->stack));
                addr = (high << 8) | low;
                vm->PC = addr;
            }
        } break;
        case LJUMP_TRUE_IM: {
            if(vm->flags.D){
                uint8_t low, high;
                uint16_t addr;
                high = fetchArg(vm);
                low  = fetchArg(vm);
                addr = (high << 8) | low;
                vm->PC = addr;
            }
        } break;
        case LJUMP_TRUE_XY: {
            if(vm->flags.D){
                vm->PC = (vm->REG_X << 8) | vm->REG_Y;
            }
        } break;
        case JUMP_DBZ: {
            if(vm->flags.D){
                vm->PC = (uint16_t) pop(&(vm->stack));
            }
        } break;
        case JUMP_DBZ_IM: {
            if(vm->flags.D){
                vm->PC = (uint16_t) fetchArg(vm);
            }
        } break;
        case JUMP_DBZ_X: {
            if(vm->flags.D){
                vm->PC = (uint16_t) vm->REG_X;
            }
        } break;
        case JUMP_DBZ_Y: {
            if(vm->flags.D){
                vm->PC = (uint16_t) vm->REG_Y;
            }
        } break;
        case LJUMP_DBZ: {
            if(vm->flags.D){
                uint8_t low, high;
                uint16_t addr;
                low  = pop(&(vm->stack));
                high = pop(&(vm->stack));
                addr = (high << 8) | low;
                vm->PC = addr;
            }
        } break;
        case LJUMP_DBZ_IM: {
            if(vm->flags.D){
                uint8_t low, high;
                uint16_t addr;
                high = fetchArg(vm);
                low  = fetchArg(vm);
                addr = (high << 8) | low;
                vm->PC = addr;
            }
        } break;
        case LJUMP_DBZ_XY: {
            if(vm->flags.D){
                vm->PC = (vm->REG_X << 8) | vm->REG_Y;
            }
        } break;

        // artithmatic ops
        case ADD: {
            uint8_t a, b;
            a = pop(&(vm->stack));
            b = pop(&(vm->stack));
            if(checkForOverflow_Add(b, a) == 1){
                vm->flags.C = 1;
            }
            push(&(vm->stack), b + a);
        } break;
        case ADD_IM: {
            uint8_t a, b;
            b = pop(&(vm->stack));
            a = fetchArg(vm);
            if(checkForOverflow_Add(b, a) == 1){
                vm->flags.C = 1;
            }
            push(&(vm->stack), b + a);
        } break;
        case ADD_IM_L: {
            uint8_t a, b;
            b = fetchArg(vm);
            a = fetchArg(vm);
            if(checkForOverflow_Add(b, a) == 1){
                vm->flags.C = 1;
            }
            push(&(vm->stack), b + a);
        } break;
        case ADD_X: {
            uint8_t a;
            a = pop(&(vm->stack));
            if(checkForOverflow_Add(a, vm->REG_X) == 1){
                vm->flags.C = 1;
            }
            push(&(vm->stack), a + vm->REG_X);
        } break;
        case ADD_Y: {
            uint8_t a;
            a = pop(&(vm->stack));
            if(checkForOverflow_Add(a, vm->REG_Y) == 1){
                vm->flags.C = 1;
            }
            push(&(vm->stack), a + vm->REG_Y);
        } break;
        case ADD_X_Y: {
            if(checkForOverflow_Add(vm->REG_X, vm->REG_Y) == 1){
                vm->flags.C = 1;
            }
            push(&(vm->stack), vm->REG_X + vm->REG_Y);
        } break;
        case SUBTRACT: {
            uint8_t a, b;
            a = pop(&(vm->stack));
            b = pop(&(vm->stack));
            if(checkForOverflow_Subtract(b, a) == 1){
                vm->flags.C = 1;
            }
            push(&(vm->stack), b - a);
        } break;
        case SUBTRACT_IM: {
            uint8_t a, b;
            b = pop(&(vm->stack));
            a = fetchArg(vm);
            if(checkForOverflow_Subtract(b, a) == 1){
                vm->flags.C = 1;
            }
            push(&(vm->stack), b - a);
        } break;
        case SUBTRACT_IM_L: {
            uint8_t a, b;
            b = fetchArg(vm);
            a = fetchArg(vm);
            if(checkForOverflow_Add(b, a) == 1){
                vm->flags.C = 1;
            }
            push(&(vm->stack), b + a);
        } break;
        case SUBTRACT_X: {
            uint8_t a;
            a = pop(&(vm->stack));
            if(checkForOverflow_Subtract(a, vm->REG_X) == 1){
                vm->flags.C = 1;
            }
            push(&(vm->stack), a - vm->REG_X);
        } break;
        case SUBTRACT_Y: {
            uint8_t a;
            a = pop(&(vm->stack));
            if(checkForOverflow_Subtract(a, vm->REG_Y) == 1){
                vm->flags.C = 1;
            }
            push(&(vm->stack), a - vm->REG_Y);
        } break;
        case SUBTRACT_X_Y: {
            if(checkForOverflow_Subtract(vm->REG_X, vm->REG_Y) == 1){
                vm->flags.C = 1;
            }
            push(&(vm->stack), vm->REG_X - vm->REG_Y);
        } break;
        case MULTIPLY: {
            uint8_t a, b;
            a = pop(&(vm->stack));
            b = pop(&(vm->stack));
            if(checkForOverflow_Multiply(b, a) == 1){
                vm->flags.C = 1;
            }
            push(&(vm->stack), b * a);
        } break;
        case MULTIPLY_IM: {
            uint8_t a, b;
            b = pop(&(vm->stack));
            a = fetchArg(vm);
            if(checkForOverflow_Multiply(b, a) == 1){
                vm->flags.C = 1;
            }
            push(&(vm->stack), b * a); 
        } break;
        case MULTIPLY_IM_L: {
            uint8_t a, b;
            b = fetchArg(vm);
            a = fetchArg(vm);
            if(checkForOverflow_Multiply(b, a) == 1){
                vm->flags.C = 1;
            }
            push(&(vm->stack), b * a);
        } break;
        case MULTIPLY_X: {
            uint8_t a;
            a = pop(&(vm->stack));
            if(checkForOverflow_Multiply(a, vm->REG_X) == 1){
                vm->flags.C = 1;
            }
            push(&(vm->stack), a * vm->REG_X);
        } break;
        case MULTIPLY_Y: {
            uint8_t a;
            a = pop(&(vm->stack));
            if(checkForOverflow_Multiply(a, vm->REG_Y) == 1){
                vm->flags.C = 1;
            }
            push(&(vm->stack), a * vm->REG_Y);
        } break;
        case MULTIPLY_X_Y: {
            if(checkForOverflow_Multiply(vm->REG_X, vm->REG_Y) == 1){
                vm->flags.C = 1;
            }
            push(&(vm->stack), vm->REG_X * vm->REG_Y);
        } break;
        case DIVIDE: {
            uint8_t a, b;
            a = pop(&(vm->stack));
            b = pop(&(vm->stack));
            if(b == 0){
                vm->flags.D = 1;
                push(&(vm->stack), b);
                push(&(vm->stack), a);
            } else {
                push(&(vm->stack), (a / b));
                push(&(vm->stack), (a % b));
            }
        } break;
        case DIVIDE_IM: {
            uint8_t a, b;
            a = pop(&(vm->stack));
            b = fetchArg(vm);
            if(b == 0){
                vm->flags.D = 1;
                push(&(vm->stack), a);
            } else {
                push(&(vm->stack), (a / b));
                push(&(vm->stack), (a % b));
            }
        } break;
        case DIVIDE_IM_L: {
            uint8_t a, b;
            a = fetchArg(vm);
            b = fetchArg(vm);
            if(b == 0){
                vm->flags.D = 1;
            } else {
                push(&(vm->stack), (a / b));
                push(&(vm->stack), (a % b));
            }
        } break;
        case DIVIDE_X: {
            uint8_t a;
            a = pop(&(vm->stack));
            if(vm->REG_X == 0){
                vm->flags.D = 1;
                push(&(vm->stack), a);
            } else {
                push(&(vm->stack), (a / vm->REG_X));
                push(&(vm->stack), (a % vm->REG_X));
            }
        } break;
        case DIVIDE_Y: {
            uint8_t a;
            a = pop(&(vm->stack));
            if(vm->REG_Y == 0){
                vm->flags.D = 1;
                push(&(vm->stack), a);
            } else {
                push(&(vm->stack), (a / vm->REG_Y));
                push(&(vm->stack), (a % vm->REG_Y));
            }
        } break;
        case DIVIDE_X_Y: {
            if(vm->REG_Y == 0){
                vm->flags.D = 1;
            } else {
                push(&(vm->stack), (vm->REG_X / vm->REG_Y));
                push(&(vm->stack), (vm->REG_X % vm->REG_Y));
            }
        } break;

        // bitwise ops
        case BIT_ROT_LEFT: {
            uint8_t a = pop(&(vm->stack));
            push(&(vm->stack), bitRotate(a, 1));
        } break;
        case BIT_ROT_LEFT_IM: {
            uint8_t a = fetchArg(vm);
            push(&(vm->stack), bitRotate(a, 1));
        } break;
        case BIT_ROT_LEFT_X: {
            push(&(vm->stack), bitRotate(vm->REG_X, 1));
        } break;
        case BIT_ROT_LEFT_Y: {
            push(&(vm->stack), bitRotate(vm->REG_Y, 1)); 
        } break;
        case BIT_ROT_RIGHT: {
            uint8_t a = pop(&(vm->stack));
            push(&(vm->stack), bitRotate(a, -1));
        } break;
        case BIT_ROT_RIGHT_IM: {
            uint8_t a = fetchArg(vm);
            push(&(vm->stack), bitRotate(a, -1));
        } break;
        case BIT_ROT_RIGHT_X: {
            push(&(vm->stack), bitRotate(vm->REG_X, -1));
        } break;
        case BIT_ROT_RIGHT_Y: {
            push(&(vm->stack), bitRotate(vm->REG_Y, -1)); 
        } break;
        case BIT_SHIFT_LEFT: {
            uint8_t a = pop(&(vm->stack));
            push(&(vm->stack), (a << 1));
        } break;
        case BIT_SHIFT_LEFT_IM: {
            uint8_t a = fetchArg(vm);
            push(&(vm->stack), (a << 1));
        } break;
        case BIT_SHIFT_LEFT_X: {
            push(&(vm->stack), (vm->REG_X << 1));
        } break;
        case BIT_SHIFT_LEFT_Y: {
            push(&(vm->stack), (vm->REG_Y << 1));
        } break;
        case BIT_SHIFT_RIGHT: {
            uint8_t a = pop(&(vm->stack));
            push(&(vm->stack), (a >> 1));
        } break;
        case BIT_SHIFT_RIGHT_IM: {
            uint8_t a = fetchArg(vm);
            push(&(vm->stack), (a >> 1));
        } break;
        case BIT_SHIFT_RIGHT_X: {
            push(&(vm->stack), (vm->REG_X >> 1));
        } break;
        case BIT_SHIFT_RIGHT_Y: {
            push(&(vm->stack), (vm->REG_Y >> 1));
        } break;
        case BIT_AND: {
            uint8_t a, b;
            b = pop(&(vm->stack));
            a = pop(&(vm->stack));
            push(&(vm->stack), (a & b));
        } break;
        case BIT_AND_IM: {
            uint8_t a, b;
            b = fetchArg(vm);
            a = pop(&(vm->stack));
            push(&(vm->stack), (a & b));
        } break;
        case BIT_AND_IM_L: {
            uint8_t a, b;
            b = fetchArg(vm);
            a = fetchArg(vm);
            push(&(vm->stack), (a & b));
        } break;
        case BIT_AND_X: {
            uint8_t a;
            a = pop(&(vm->stack));
            push(&(vm->stack), (a & vm->REG_X));
        } break;
        case BIT_AND_Y: {
            uint8_t a;
            a = pop(&(vm->stack));
            push(&(vm->stack), (a & vm->REG_Y));
        } break;
        case BIT_AND_XY: {
            push(&(vm->stack), (vm->REG_X & vm->REG_Y));
        } break;
        case BIT_OR: {
            uint8_t a, b;
            b = pop(&(vm->stack));
            a = pop(&(vm->stack));
            push(&(vm->stack), (a | b));
        } break;
        case BIT_OR_IM: {
            uint8_t a, b;
            b = fetchArg(vm);
            a = pop(&(vm->stack));
            push(&(vm->stack), (a | b));
        } break;
        case BIT_OR_IM_L: {
            uint8_t a, b;
            b = fetchArg(vm);
            a = fetchArg(vm);
            push(&(vm->stack), (a | b));
        } break;
        case BIT_OR_X: {
            uint8_t a;
            a = pop(&(vm->stack));
            push(&(vm->stack), (a | vm->REG_X));
        } break;
        case BIT_OR_Y: {
            uint8_t a;
            a = pop(&(vm->stack));
            push(&(vm->stack), (a | vm->REG_Y));
        } break;
        case BIT_OR_XY: {
            push(&(vm->stack), (vm->REG_X | vm->REG_Y));
        } break;
        case BIT_XOR: {
            uint8_t a, b;
            b = pop(&(vm->stack));
            a = pop(&(vm->stack));
            push(&(vm->stack), (a ^ b));
        } break;
        case BIT_XOR_IM: {
            uint8_t a, b;
            b = fetchArg(vm);
            a = pop(&(vm->stack));
            push(&(vm->stack), (a ^ b));
        } break;
        case BIT_XOR_IM_L: {
            uint8_t a, b;
            b = fetchArg(vm);
            a = fetchArg(vm);
            push(&(vm->stack), (a ^ b));
        } break;
        case BIT_XOR_X: {
            uint8_t a;
            a = pop(&(vm->stack));
            push(&(vm->stack), (a ^ vm->REG_X));
        } break;
        case BIT_XOR_Y: {
            uint8_t a;
            a = pop(&(vm->stack));
            push(&(vm->stack), (a ^ vm->REG_Y));
        } break;
        case BIT_XOR_XY: {
            push(&(vm->stack), (vm->REG_X ^ vm->REG_Y));
        } break;
        case BIT_NOT: {
            uint8_t a = pop(&(vm->stack));
            push(&(vm->stack), ~a);
        } break;
        case BIT_NOT_IM: {
            uint8_t a = fetchArg(vm);
            push(&(vm->stack), ~a);
        } break;
        case BIT_NOT_X: {
            push(&(vm->stack), ~(vm->REG_X));
        } break;
        case BIT_NOT_Y: {
            push(&(vm->stack), ~(vm->REG_Y));
        } break;

        // logical ops
        case IS_LT: {
            //TODO: see about condensing this once verified working
            uint8_t a, b;
            b = peak_back(&(vm->stack), 1);
            a = peak(&(vm->stack));
            if(b < a){
                vm->flags.B = 1;
            }
        } break;
        case IS_LT_IM: {
            uint8_t a, b;
            b = peak(&(vm->stack));
            a = fetchArg(vm);
            if(b < a){
                vm->flags.B = 1;
            }
        } break;
        case IS_LT_X: {
            uint8_t a;
            a = peak(&(vm->stack));
            if(a < vm->REG_X){
                vm->flags.B = 1;
            }
        } break;
        case IS_LT_Y: {
            uint8_t a;
            a = peak(&(vm->stack));
            if(a < vm->REG_Y){
                vm->flags.B = 1;
            }
        } break;
        case IS_LT_Z: {
            uint8_t a;
            a = peak(&(vm->stack));
            if(a < vm->REG_Z){
                vm->flags.B = 1;
            }
        } break;
        case IS_LT_X_IM: {
            uint8_t a;
            a = fetchArg(vm);
            if(vm->REG_X < a){
                vm->flags.B = 1;
            }
        } break;
        case IS_LT_X_Y: {
            if(vm->REG_X < vm->REG_Y){
                vm->flags.B = 1;
            }
        } break;
        case IS_LT_X_Z: {
            if(vm->REG_X < vm->REG_Z){
                vm->flags.B = 1;
            }
        } break;
        case IS_LT_Y_IM: {
            uint8_t a;
            a = fetchArg(vm);
            if(vm->REG_Y < a){
                vm->flags.B = 1;
            }
        } break;
        case IS_LT_Y_X: {
            if(vm->REG_Y < vm->REG_X){
                vm->flags.B = 1;
            }
        } break;
        case IS_LT_Y_Z: {
            if(vm->REG_Y < vm->REG_Z){
                vm->flags.B = 1;
            }
        } break;
        case IS_LT_Z_IM: {
            uint8_t a;
            a = fetchArg(vm);
            if(vm->REG_Z < a){
                vm->flags.B = 1;
            }
        } break;
        case IS_LT_Z_X: {
            if(vm->REG_Z < vm->REG_X){
                vm->flags.B = 1;
            }
        } break;
        case IS_LT_Z_Y: {
            if(vm->REG_Z < vm->REG_Y){
                vm->flags.B = 1;
            }
        } break;
        case IS_GT: {
            //TODO: see about condensing this once verified working
            uint8_t a, b;
            b = peak_back(&(vm->stack), 1);
            a = peak(&(vm->stack));
            if(b > a){
                vm->flags.B = 1;
            }
        } break;
        case IS_GT_IM: {
            uint8_t a, b;
            b = peak(&(vm->stack));
            a = fetchArg(vm);
            if(b > a){
                vm->flags.B = 1;
            }
        } break;
        case IS_GT_X: {
            uint8_t a;
            a = peak(&(vm->stack));
            if(a > vm->REG_X){
                vm->flags.B = 1;
            }
        } break;
        case IS_GT_Y: {
            uint8_t a;
            a = peak(&(vm->stack));
            if(a > vm->REG_Y){
                vm->flags.B = 1;
            }
        } break;
        case IS_GT_Z: {
            uint8_t a;
            a = peak(&(vm->stack));
            if(a > vm->REG_Z){
                vm->flags.B = 1;
            }
        } break;
        case IS_GT_X_IM: {
            uint8_t a;
            a = fetchArg(vm);
            if(vm->REG_X > a){
                vm->flags.B = 1;
            }
        } break;
        case IS_GT_X_Y: {
            if(vm->REG_X > vm->REG_Y){
                vm->flags.B = 1;
            }
        } break;
        case IS_GT_X_Z: {
            if(vm->REG_X > vm->REG_Z){
                vm->flags.B = 1;
            }
        } break;
        case IS_GT_Y_IM: {
            uint8_t a;
            a = fetchArg(vm);
            if(vm->REG_Y > a){
                vm->flags.B = 1;
            }
        } break;
        case IS_GT_Y_X: {
            if(vm->REG_Y > vm->REG_X){
                vm->flags.B = 1;
            }
        } break;
        case IS_GT_Y_Z: {
            if(vm->REG_Y > vm->REG_Z){
                vm->flags.B = 1;
            }
        } break;
        case IS_GT_Z_IM: {
            uint8_t a;
            a = fetchArg(vm);
            if(vm->REG_Z > a){
                vm->flags.B = 1;
            }
        } break;
        case IS_GT_Z_X: {
            if(vm->REG_Z > vm->REG_X){
                vm->flags.B = 1;
            }
        } break;
        case IS_GT_Z_Y: {
            if(vm->REG_Z > vm->REG_Y){
                vm->flags.B = 1;
            }
        } break;
        case IS_EQ: {
            //TODO: see about condensing this once verified working
            uint8_t a, b;
            b = peak_back(&(vm->stack), 1);
            a = peak(&(vm->stack));
            if(b == a){
                vm->flags.B = 1;
            }
        } break;
        case IS_EQ_IM: {
            uint8_t a, b;
            b = peak(&(vm->stack));
            a = fetchArg(vm);
            if(b == a){
                vm->flags.B = 1;
            }
        } break;
        case IS_EQ_X: {
            uint8_t a;
            a = peak(&(vm->stack));
            if(a == vm->REG_X){
                vm->flags.B = 1;
            }
        } break;
        case IS_EQ_Y: {
            uint8_t a;
            a = peak(&(vm->stack));
            if(a == vm->REG_Y){
                vm->flags.B = 1;
            }
        } break;
        case IS_EQ_Z: {
            uint8_t a;
            a = peak(&(vm->stack));
            if(a == vm->REG_Z){
                vm->flags.B = 1;
            }
        } break;
        case IS_EQ_X_IM: {
            uint8_t a;
            a = fetchArg(vm);
            if(vm->REG_X == a){
                vm->flags.B = 1;
            }
        } break;
        case IS_EQ_X_Y: {
            if(vm->REG_X == vm->REG_Y){
                vm->flags.B = 1;
            }
        } break;
        case IS_EQ_X_Z: {
            if(vm->REG_X == vm->REG_Z){
                vm->flags.B = 1;
            }
        } break;
        case IS_EQ_Y_IM: {
            uint8_t a;
            a = fetchArg(vm);
            if(vm->REG_Y == a){
                vm->flags.B = 1;
            }
        } break;
        case IS_EQ_Y_X: {
            if(vm->REG_Y == vm->REG_X){
                vm->flags.B = 1;
            }
        } break;
        case IS_EQ_Y_Z: {
            if(vm->REG_Y == vm->REG_Z){
                vm->flags.B = 1;
            }
        } break;
        case IS_EQ_Z_IM: {
            uint8_t a;
            a = fetchArg(vm);
            if(vm->REG_Z == a){
                vm->flags.B = 1;
            }
        } break;
        case IS_EQ_Z_X: {
            if(vm->REG_Z == vm->REG_X){
                vm->flags.B = 1;
            }
        } break;
        case IS_EQ_Z_Y: {
            if(vm->REG_Z == vm->REG_Y){
                vm->flags.B = 1;
            }
        } break;


        //halt
        case HALT: {
            vm->flags.H = 1;
        } break;
        default: {
            printf("unimplemented opcode: %d\n", vm->OP);
        } break;
    }
}

void init_vm(VM *vm, uint8_t *program, uint16_t programSize){
    init_stack(&(vm->stack));
    vm->flags.C = 0;
    vm->flags.B = 0;
    vm->flags.D = 0;
    vm->flags.H = 0;

    vm->REG_X = 0;
    vm->REG_Y = 0;
    vm->REG_Z = 0;
    vm->PC = 0;
    vm->OP = 0;
    vm->program = program;
    vm->programSize = programSize;

}

void clock(VM *vm){
    fetchInstruction(vm);
    execute(vm);
}