#include "vm.h"
#include "opcode.h"
#include "alu.h"
#include <stdio.h>



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

uint8_t popStack(VM *vm){
    vm->Z--;
    uint8_t val = vm->stack[vm->Z];
    return val;
}

void pushStack(VM *vm, uint8_t value){
    vm->stack[vm->Z] = value;
    vm->Z++;
}

void dumpStack(VM *vm){
    printf("DEBUG:\n       -----  Stack Dump  -----\n");
    printf("             Stack Top: %d\n", vm->Z);
    int c = 0;
    printf("       ");
    for(int i = 0; i < STACK_SIZE; ++i){
        if(c == 8){
            printf("\n       ");
            c = 0;
        }
        printf("%02x: %03d", i, (vm->stack)[i]);
        printf(", ");
        c++;
    }
    printf("\n");
}

static void executeInstruction(VM *vm);

void init_vm(VM *vm, uint8_t *program, uint16_t programSize){
    vm->program = program;
    vm->programSize = programSize;

    vm->flags.Negative = 0;
    vm->flags.Overflow = 0;
    vm->flags.Carry = 0;
    vm->flags.Halt = 0;
    vm->flags.Zero = 0;

    vm->PC = 0;
    vm->RTN = 0;
    vm->OP = 0;
    vm->A = 0;
    vm->X = 0;
    vm->Y = 0;
    vm->Z = 0;
    vm->R0 = 0;
    vm->R1 = 0;
    vm->R2 = 0;
    vm->R3 = 0;
}

void clock(VM *vm){
    fetchInstruction(vm);
    executeInstruction(vm);
}

static void executeInstruction(VM *vm){
    
    switch(vm->OP){
        case NO_OP: {

        } break;
        case LOAD_A: {
            uint8_t val = popStack(vm);
            vm->A = val;
        } break;
        case LOAD_A_IM: {
            uint8_t val = fetchArg(vm);
            vm->A = val;
        } break;
        case LOAD_A_X: {
            vm->A = vm->X;
        } break;
        case LOAD_A_Y: {
            vm->A = vm->Y;
        } break;
        case LOAD_A_Z: {
            vm->A = vm->Z;
        } break;
        case LOAD_A_R0: {
            vm->A = vm->R0;
        } break;
        case LOAD_A_R1: {
            vm->A = vm->R1;
        } break;
        case LOAD_A_R2: {
            vm->A = vm->R2;
        } break;
        case LOAD_A_R3: {
            vm->A = vm->R3;
        } break;
        case STORE_A: {
            pushStack(vm, vm->A);
        } break;
        case STORE_A_IM: {
            // TODO
        } break;
        case STORE_A_X: {
            vm->X = vm->A;
        } break;
        case STORE_A_Y: {
            vm->Y = vm->A;
        } break;
        case STORE_A_Z: {
            vm->Z = vm->A;
        } break;
        case STORE_A_R0: {
            vm->R0 = vm->A;
        } break;
        case STORE_A_R1: {
            vm->R1 = vm->A;
        } break;
        case STORE_A_R2: {
            vm->R2 = vm->A;
        } break;
        case STORE_A_R3: {
            vm->R3 = vm->A;
        } break;
        case LOAD_X: {
            uint8_t val = popStack(vm);
            vm->X = val;
        } break;
        case LOAD_X_IM: {
            uint8_t val = fetchArg(vm);
            vm->X = val;
        } break;
        case LOAD_X_R0: {
            vm->X = vm->R0;
        } break;
        case LOAD_X_R1: {
            vm->X = vm->R1;
        } break;
        case LOAD_X_R2: {
            vm->X = vm->R2;
        } break;
        case LOAD_X_R3: {
            vm->X = vm->R3;
        } break;
        case LOAD_Y: {
            uint8_t val = popStack(vm);
            vm->Y = val;
        } break;
        case LOAD_Y_IM: {
            uint8_t val = fetchArg(vm);
            vm->Y = val;
        } break;
        case LOAD_Y_R0: {
            vm->Y = vm->R0;
        } break;
        case LOAD_Y_R1: {
            vm->Y = vm->R1;
        } break;
        case LOAD_Y_R2: {
            vm->Y = vm->R2;
        } break;
        case LOAD_Y_R3: {
            vm->Y = vm->R3;
        } break;
        case INC_X: {
            vm->X++;
        } break;
        case INC_Y: {
            vm->Y++;
        } break;
        case INC_Z: {
            vm->Z++;
        } break;
        case DEC_X: {
            vm->X--;
        } break;
        case DEC_Y: {
            vm->Y--;
        } break;
        case DEC_Z: {
            vm->Z--;
        } break;
        case ADD: {
            uint8_t val = popStack(vm);
            addCarry(&(vm->A), &(vm->flags), val);
        } break;
        case ADD_IM: {
            uint8_t val = fetchArg(vm);
            addCarry(&(vm->A), &(vm->flags), val);
        } break;
        case ADD_X: {
            addCarry(&(vm->A), &(vm->flags), &(vm->X));
        } break;
        case ADD_Y: {
            addCarry(&(vm->A), &(vm->flags), &(vm->Y));
        } break;
        case ADD_Z: {
            addCarry(&(vm->A), &(vm->flags), &(vm->Z));
        } break;
        case ADD_R0: {
            addCarry(&(vm->A), &(vm->flags), &(vm->R0));
        } break;
        case ADD_R1: {
            addCarry(&(vm->A), &(vm->flags), &(vm->R1));
        } break;
        case ADD_R2: {
            addCarry(&(vm->A), &(vm->flags), &(vm->R2));
        } break;
        case ADD_R3: {
            addCarry(&(vm->A), &(vm->flags), &(vm->R3));
        } break;
        case SUBTRACT: {
            uint8_t val = popStack(vm);
            SubtractBorrow(&(vm->A), &(vm->flags), val);
        } break;
        case SUBTRACT_IM: {
            uint8_t val = fetchArg(vm);
            SubtractBorrow(&(vm->A), &(vm->flags), val);
        } break;
        case SUBTRACT_X: {
            SubtractBorrow(&(vm->A), &(vm->flags), &(vm->X));
        } break;
        case SUBTRACT_Y: {
            SubtractBorrow(&(vm->A), &(vm->flags), &(vm->Y));
        } break;
        case SUBTRACT_Z: {
            SubtractBorrow(&(vm->A), &(vm->flags), &(vm->Z));
        } break;
        case SUBTRACT_R0: {
            SubtractBorrow(&(vm->A), &(vm->flags), &(vm->R0));
        } break;
        case SUBTRACT_R1: {
            SubtractBorrow(&(vm->A), &(vm->flags), &(vm->R1));
        } break;
        case SUBTRACT_R2: {
            SubtractBorrow(&(vm->A), &(vm->flags), &(vm->R2));
        } break;
        case SUBTRACT_R3: {
            SubtractBorrow(&(vm->A), &(vm->flags), &(vm->R3));
        } break;
        case SIGN_SHIFT_LEFT: {
            signedShift(&(vm->A), &(vm->flags), 0);
        } break;
        case SIGN_SHIFT_RIGHT: {
            signedShift(&(vm->A), &(vm->flags), 1);
        } break;
        case LOGICAL_SHIFT_LEFT: {
            unsignedShift(&(vm->A), &(vm->flags), 0);
        } break;
        case LOGICAL_SHIFT_RIGHT: {
            unsignedShift(&(vm->A), &(vm->flags), 1);
        } break;
        case ROTATE_LEFT: {
            rotateBits(&(vm->A), &(vm->flags), 0);
        } break;
        case ROTATE_RIGHT: {
            rotateBits(&(vm->A), &(vm->flags), 1);
        } break;
        case BIT_AND: {
            uint8_t val = popStack(vm);
            bitAND(&(vm->A), &(vm->flags), val);
        } break;
        case BIT_AND_IM: {
            uint8_t val = fetchArg(vm);
            bitAND(&(vm->A), &(vm->flags), val);
        } break;
        case BIT_AND_X: {
            bitAND(&(vm->A), &(vm->flags), &(vm->X));
        } break;
        case BIT_AND_Y: {
            bitAND(&(vm->A), &(vm->flags), &(vm->Y));
        } break;
        case BIT_AND_Z: {
            bitAND(&(vm->A), &(vm->flags), &(vm->Z));
        } break;
        case BIT_AND_R0: {
            bitAND(&(vm->A), &(vm->flags), &(vm->R0));
        } break;
        case BIT_AND_R1: {
            bitAND(&(vm->A), &(vm->flags), &(vm->R1));
        } break;
        case BIT_AND_R2: {
            bitAND(&(vm->A), &(vm->flags), &(vm->R2));
        } break;
        case BIT_AND_R3: {
            bitAND(&(vm->A), &(vm->flags), &(vm->R3));
        } break;
        case BIT_OR: {
            uint8_t val = popStack(vm);
            bitOR(&(vm->A), &(vm->flags), val);
        } break;
        case BIT_OR_IM: {
            uint8_t val = fetchArg(vm);
            bitOR(&(vm->A), &(vm->flags), val);
        } break;
        case BIT_OR_X: {
            bitOR(&(vm->A), &(vm->flags), &(vm->X));
        } break;
        case BIT_OR_Y: {
            bitOR(&(vm->A), &(vm->flags), &(vm->Y));
        } break;
        case BIT_OR_Z: {
            bitOR(&(vm->A), &(vm->flags), &(vm->Z));
        } break;
        case BIT_OR_R0: {
            bitOR(&(vm->A), &(vm->flags), &(vm->R0));
        } break;
        case BIT_OR_R1: {
            bitOR(&(vm->A), &(vm->flags), &(vm->R1));
        } break;
        case BIT_OR_R2: {
            bitOR(&(vm->A), &(vm->flags), &(vm->R2));
        } break;
        case BIT_OR_R3: {
            bitOR(&(vm->A), &(vm->flags), &(vm->R3));
        } break;
        case BIT_XOR: {
            uint8_t val = popStack(vm);
            bitXOR(&(vm->A), &(vm->flags), val);
        } break;
        case BIT_XOR_IM: {
            uint8_t val = fetchArg(vm);
            bitXOR(&(vm->A), &(vm->flags), val);
        } break;
        case BIT_XOR_X: {
            bitXOR(&(vm->A), &(vm->flags), &(vm->X));
        } break;
        case BIT_XOR_Y: {
            bitXOR(&(vm->A), &(vm->flags), &(vm->Y));
        } break;
        case BIT_XOR_Z: {
            bitXOR(&(vm->A), &(vm->flags), &(vm->Z));
        } break;
        case BIT_XOR_R0: {
            bitXOR(&(vm->A), &(vm->flags), &(vm->R0));
        } break;
        case BIT_XOR_R1: {
            bitXOR(&(vm->A), &(vm->flags), &(vm->R1));
        } break;
        case BIT_XOR_R2: {
            bitXOR(&(vm->A), &(vm->flags), &(vm->R2));
        } break;
        case BIT_XOR_R3: {
            bitXOR(&(vm->A), &(vm->flags), &(vm->R3));
        } break;
        case SET_CARRY: {
            vm->flags.Carry = 1;
        } break;
        case SET_NEG: {
            vm->flags.Negative = 1;
        } break;
        case CLEAR_CARRY: {
            vm->flags.Carry = 0;
        } break;
        case CLEAR_OVERFLOW: {
            vm->flags.Overflow = 0;
        } break;
        case CLEAR_NEG: {
            vm->flags.Negative = 0;
        } break;
        case BRANCH_PLUS: {
            if(vm->flags.Negative == 0){
                uint8_t low = popStack(vm);
                uint8_t high = popStack(vm);
                uint16_t addr = (high << 8) | low;
                vm->PC = addr;
            } break;
        } break;
        case BRANCH_PLUS_IM: {
            if(vm->flags.Negative == 0){
                uint8_t low = fetchArg(vm);
                uint8_t high = fetchArg(vm);
                uint16_t addr = (high << 8) | low;
                vm->PC = addr;
            } break;
        } break;
        case BRANCH_PLUS_XY: {
            if(vm->flags.Negative == 0){
                uint16_t addr = ((vm->Y) << 8) | (vm->X);
                vm->PC = addr;
            } break;
        } break;
        case BRANCH_PLUS_R0R1: {
            if(vm->flags.Negative == 0){
                uint16_t addr = ((vm->R1) << 8) | (vm->R0);
                vm->PC = addr;
            } break;
        } break;
        case BRANCH_PLUS_R2R3: {
            if(vm->flags.Negative == 0){
                uint16_t addr = ((vm->R3) << 8) | (vm->R2);
                vm->PC = addr;
            } break;
        } break;
        case BRANCH_MINUS: {
            if(vm->flags.Negative == 1){
                uint8_t low = popStack(vm);
                uint8_t high = popStack(vm);
                uint16_t addr = (high << 8) | low;
                vm->PC = addr;
            } break;
        } break;
        case BRANCH_MINUS_IM: {
            if(vm->flags.Negative == 1){
                uint8_t low = fetchArg(vm);
                uint8_t high = fetchArg(vm);
                uint16_t addr = (high << 8) | low;
                vm->PC = addr;
            } break;
        } break;
        case BRANCH_MINUS_XY: {
            if(vm->flags.Negative == 1){
                uint16_t addr = ((vm->Y) << 8) | (vm->X);
                vm->PC = addr;
            } break;
        } break;
        case BRANCH_MINUS_R0R1: {
            if(vm->flags.Negative == 1){
                uint16_t addr = ((vm->R1) << 8) | (vm->R0);
                vm->PC = addr;
            } break;
        } break;
        case BRANCH_MINUS_R2R3: {
            if(vm->flags.Negative == 1){
                uint16_t addr = ((vm->R3) << 8) | (vm->R2);
                vm->PC = addr;
            } break;
        } break;
        case BRANCH_OVERFLOW_SET: {
            if(vm->flags.Overflow == 1){
                uint8_t low = popStack(vm);
                uint8_t high = popStack(vm);
                uint16_t addr = (high << 8) | low;
                vm->PC = addr;
            } break;
        } break;
        case BRANCH_OVERFLOW_SET_IM: {
            if(vm->flags.Overflow == 1){
                uint8_t low = fetchArg(vm);
                uint8_t high = fetchArg(vm);
                uint16_t addr = (high << 8) | low;
                vm->PC = addr;
            } break;
        } break;
        case BRANCH_OVERFLOW_SET_XY: {
            if(vm->flags.Overflow == 1){
                uint16_t addr = ((vm->Y) << 8) | (vm->X);
                vm->PC = addr;
            } break;
        } break;
        case BRANCH_OVERFLOW_SET_R0R1: {
            if(vm->flags.Overflow == 1){
                uint16_t addr = ((vm->R1) << 8) | (vm->R0);
                vm->PC = addr;
            } break;
        } break;
        case BRANCH_OVERFLOW_SET_R2R3: {
            if(vm->flags.Overflow == 1){
                uint16_t addr = ((vm->R3) << 8) | (vm->R2);
                vm->PC = addr;
            } break;
        } break;
        case BRANCH_OVERFLOW_CLEAR: {
            if(vm->flags.Overflow == 0){
                uint8_t low = popStack(vm);
                uint8_t high = popStack(vm);
                uint16_t addr = (high << 8) | low;
                vm->PC = addr;
            } break;
        } break;
        case BRANCH_OVERFLOW_CLEAR_IM: {
            if(vm->flags.Overflow == 0){
                uint8_t low = fetchArg(vm);
                uint8_t high = fetchArg(vm);
                uint16_t addr = (high << 8) | low;
                vm->PC = addr;
            } break;
        } break;
        case BRANCH_OVERFLOW_CLEAR_XY: {
            if(vm->flags.Overflow == 0){
                uint16_t addr = ((vm->Y) << 8) | (vm->X);
                vm->PC = addr;
            } break;
        } break;
        case BRANCH_OVERFLOW_CLEAR_R0R1: {
            if(vm->flags.Overflow == 0){
                uint16_t addr = ((vm->R1) << 8) | (vm->R0);
                vm->PC = addr;
            } break;
        } break;
        case BRANCH_OVERFLOW_CLEAR_R2R3: {
            if(vm->flags.Overflow == 0){
                uint16_t addr = ((vm->R3) << 8) | (vm->R2);
                vm->PC = addr;
            } break;
        } break;
        case BRANCH_CARRY_SET: {
            if(vm->flags.Overflow == 1){
                uint8_t low = popStack(vm);
                uint8_t high = popStack(vm);
                uint16_t addr = (high << 8) | low;
                vm->PC = addr;
            } break;
        } break;
        case BRANCH_CARRY_SET_IM: {
            if(vm->flags.Overflow == 1){
                uint8_t low = fetchArg(vm);
                uint8_t high = fetchArg(vm);
                uint16_t addr = (high << 8) | low;
                vm->PC = addr;
            } break;
        } break;
        case BRANCH_CARRY_SET_XY: {
            if(vm->flags.Overflow == 1){
                uint16_t addr = ((vm->Y) << 8) | (vm->X);
                vm->PC = addr;
            } break;
        } break;
        case BRANCH_CARRY_SET_R0R1: {
            if(vm->flags.Overflow == 1){
                uint16_t addr = ((vm->R1) << 8) | (vm->R0);
                vm->PC = addr;
            } break;
        } break;
        case BRANCH_CARRY_SET_R2R3: {
            if(vm->flags.Overflow == 1){
                uint16_t addr = ((vm->R3) << 8) | (vm->R2);
                vm->PC = addr;
            } break;
        } break;
        case BRANCH_CARRY_CLEAR: {
            if(vm->flags.Overflow == 0){
                uint8_t low = popStack(vm);
                uint8_t high = popStack(vm);
                uint16_t addr = (high << 8) | low;
                vm->PC = addr;
            } break;
        } break;
        case BRANCH_CARRY_CLEAR_IM: {
            if(vm->flags.Overflow == 0){
                uint8_t low = fetchArg(vm);
                uint8_t high = fetchArg(vm);
                uint16_t addr = (high << 8) | low;
                vm->PC = addr;
            } break;
        } break;
        case BRANCH_CARRY_CLEAR_XY: {
            if(vm->flags.Overflow == 0){
                uint16_t addr = ((vm->Y) << 8) | (vm->X);
                vm->PC = addr;
            } break;
        } break;
        case BRANCH_CARRY_CLEAR_R0R1: {
            if(vm->flags.Overflow == 0){
                uint16_t addr = ((vm->R1) << 8) | (vm->R0);
                vm->PC = addr;
            } break;
        } break;
        case BRANCH_CARRY_CLEAR_R2R3: {
            if(vm->flags.Overflow == 0){
                uint16_t addr = ((vm->R3) << 8) | (vm->R2);
                vm->PC = addr;
            } break;
        } break;
        case BRANCH_EQUAL: {
            if(vm->flags.Zero == 1){
                uint8_t low = popStack(vm);
                uint8_t high = popStack(vm);
                uint16_t addr = (high << 8) | low;
                vm->PC = addr;
            } break;
        } break;
        case BRANCH_EQUAL_IM: {
            if(vm->flags.Zero == 1){
                uint8_t low = fetchArg(vm);
                uint8_t high = fetchArg(vm);
                uint16_t addr = (high << 8) | low;
                vm->PC = addr;
            } break;
        } break;
        case BRANCH_EQUAL_XY: {
            if(vm->flags.Zero == 1){
                uint16_t addr = ((vm->Y) << 8) | (vm->X);
                vm->PC = addr;
            } break;
        } break;
        case BRANCH_EQUAL_R0R1: {
            if(vm->flags.Zero == 1){
                uint16_t addr = ((vm->R1) << 8) | (vm->R0);
                vm->PC = addr;
            } break;
        } break;
        case BRANCH_EQUAL_R2R3: {
            if(vm->flags.Zero == 1){
                uint16_t addr = ((vm->R3) << 8) | (vm->R2);
                vm->PC = addr;
            } break;
        } break;
        case JUMP: {
            uint8_t low = popStack(vm);
            uint8_t high = popStack(vm);
            uint16_t addr = (high << 8) | low;
            vm->PC = addr;
        } break;
        case JUMP_IM: {
            uint8_t low = fetchArg(vm);
            uint8_t high = fetchArg(vm);
            uint16_t addr = (high << 8) | low;
            vm->PC = addr;
        } break;
        case JUMP_XY: {
            uint16_t addr = ((vm->Y) << 8) | (vm->X);
            vm->PC = addr;
        } break;
        case JUMP_R0R1: {
            uint16_t addr = ((vm->R1) << 8) | (vm->R0);
            vm->PC = addr;
        } break;
        case JUMP_R2R3: {
            uint16_t addr = ((vm->R3) << 8) | (vm->R2);
            vm->PC = addr;
        } break;
        case JUMP_SUBROUTINE: {
            uint8_t low = popStack(vm);
            uint8_t high = popStack(vm);
            vm->RTN = vm->PC;
            uint16_t addr = (high << 8) | low;
            vm->PC = addr;
        } break;
        case JUMP_SUBROUTINE_IM: {
            uint8_t low  = fetchArg(vm);
            uint8_t high = fetchArg(vm);
            vm->RTN = vm->PC;
            uint16_t addr = (high << 8) | low;
            vm->PC = addr;
        } break;
        /* case JUMP_SUBROUTINE_XY: {
            uint16_t addr = ((vm->Y) << 8) | (vm->X);
            vm->PC = addr;
        } break;
        case JUMP_SUBROUTINE_R0R1: {

        } break;
        case JUMP_SUBROUTINE_R2R3: {

        } break; */
        case PRINT_SIGNED: {
            int8_t val = (int8_t) popStack(vm);
            printf("%d\n", val);
        } break;
        case PRINT_SIGNED_IM: {
            int8_t val = (int8_t) fetchArg(vm);
            printf("%d\n", val);
        } break;
        case PRINT_SIGNED_X: {
            int8_t val = (int8_t) vm->X;
            printf("%d\n", val);
        } break;
        case PRINT_SIGNED_Y: {
            int8_t val = (int8_t) vm->Y;
            printf("%d\n", val);
        } break;
        case PRINT_SIGNED_Z: {
            int8_t val = (int8_t) vm->Z;
            printf("%d\n", val);
        } break;
        case PRINT_SIGNED_R0: {
            int8_t val = (int8_t) vm->R0;
            printf("%d\n", val);
        } break;
        case PRINT_SIGNED_R1: {
            int8_t val = (int8_t) vm->R1;
            printf("%d\n", val);
        } break;
        case PRINT_SIGNED_R2: {
            int8_t val = (int8_t) vm->R2;
            printf("%d\n", val);
        } break;
        case PRINT_SIGNED_R3: {
            int8_t val = (int8_t) vm->R3;
            printf("%d\n", val);
        } break;
        case PRINT_UNSIGNED: {
            uint8_t val = popStack(vm);
            printf("%hhu\n", val);
        } break;
        case PRINT_UNSIGNED_IM: {
            uint8_t val = fetchArg(vm);
            printf("%hhu\n", val);
        } break;
        case PRINT_UNSIGNED_X: {
            printf("%hhu\n", vm->X);
        } break;
        case PRINT_UNSIGNED_Y: {
            printf("%hhu\n", vm->Y);
        } break;
        case PRINT_UNSIGNED_Z: {
            printf("%hhu\n", vm->Z);
        } break;
        case PRINT_UNSIGNED_R0: {
            printf("%hhu\n", vm->R0);
        } break;
        case PRINT_UNSIGNED_R1: {
            printf("%hhu\n", vm->R1);
        } break;
        case PRINT_UNSIGNED_R2: {
            printf("%hhu\n", vm->R2);
        } break;
        case PRINT_UNSIGNED_R3: {
            printf("%hhu\n", vm->R3);
        } break;
        case PRINT_ASCII: {
            char val = (char) popStack(vm);
            printf("%c", val);
        } break;
        case PRINT_ASCII_IM: {
            char val = (char) popStack(vm);
            printf("%c", val);
        } break;
        case PRINT_ASCII_X: {
            char val = (char) vm->X;
            printf("%c", val);
        } break;
        case PRINT_ASCII_Y: {
            char val = (char) vm->Y;
            printf("%c", val);
        } break;
        case PRINT_ASCII_Z: {
            char val = (char) vm->Z;
            printf("%c", val);
        } break;
        case PRINT_ASCII_R0: {
            char val = (char) vm->R0;
            printf("%c", val);
        } break;
        case PRINT_ASCII_R1: {
            char val = (char) vm->R1;
            printf("%c", val);
        } break;
        case PRINT_ASCII_R2: {
            char val = (char) vm->R2;
            printf("%c", val);
        } break;
        case PRINT_ASCII_R3: {
            char val = (char) vm->R3;
            printf("%c", val);
        } break;
        case INPUT_NUMBER: {

        } break;
        case INPUT_ASCII: {

        } break;
        case HALT: {
            vm->flags.Halt = 1;
        } break;

        default:
            break;

    }
}