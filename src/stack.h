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

// pop and discard the top value on the stack
void drop(Stack *s);

// print out the whole stack for debugging
void dump(Stack *s);


#endif