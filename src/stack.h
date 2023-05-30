#ifndef KCATS_STACK_H
#define KCATS_STACK_H

#include <stdint.h>

#define STACK_MAX 255 // keep value addressable by 8 bit number 

typedef struct stack {
    uint8_t data[STACK_MAX + 1];
    uint8_t top;
    uint8_t count;
} Stack;

// intialize stack to default values
void init_stack(Stack *s);

// push a value onto the stack
void push(Stack *s, uint8_t value);

// pop a value off the stack
uint8_t pop(Stack *s);

// peak at the top value on the stack without removing it
uint8_t peak(Stack *s);

//peak at the nth value down the stack
uint8_t peak_back(Stack *s, uint8_t n);

// pop and discard the top value on the stack
void drop(Stack *s);

//Swaps the top two values on the stack. otherwise does nothing. (a b -- b a)
void swap(Stack *s);

//Copys the value under top and pushes it. (a b -- a b a)
void over(Stack *s);

// rotates Top 3 values on stack. (a b c -- c a b)
void rotate(Stack *s);

// rotates Top specified number of values. if amount is less than 3
// pushes 0 to stack and returns. 
// slower than most other operations.
void rotateNumberOfItems(Stack *s, uint16_t count);

// print out the whole stack for debugging
void dump(Stack *s);

//push multiple ints at once for convienince.
void push_ints(Stack *s, uint8_t values[], uint16_t count);


#endif