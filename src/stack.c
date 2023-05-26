#include "stack.h"
#include <stdio.h>

// intialize stack to default values
void init(Stack *s){
    s->top = STACK_MAX;
    for(int i = 0; i <= STACK_MAX; ++i){
        s->data[i] = 0;
    }
}

// push a value onto the stack
void push(Stack *s, uint8_t value){
    s->data[s->top] = value;
    
    if(s->top != 0){
        s->top--;
    }
}

// pop a value off the stack
uint8_t pop(Stack *s){
    uint8_t x;
    
    if(s->top != STACK_MAX){
        s->top++;    
    } 

    x = s->data[s->top];
    s->data[s->top] = 0;

    return x;
}

// peak at the top value on the stack without removing it
uint8_t peak(Stack *s){
    uint8_t t = s->top;
    if(s->top != STACK_MAX){
        t++;
    }
    return s->data[t];

}

// pop and discard the top value on the stack
void drop(Stack *s){
    if(s->top != STACK_MAX){
        s->top++;    
    } 

    s->data[s->top] = 0;
}

// print out the whole stack for debugging
void dump(Stack *s){
    printf("DEBUG:\n       ----- Stack Dump -----\n");
    printf("       Stack Top: %d\n", s->top);
    int c = 0;
    printf("       ");
    for(int i = STACK_MAX; i >= 0; --i){
        if(c == 8){
            printf("\n       ");
            c = 0;
        }
        printf("%02x: %d", i, s->data[i]);
        printf(", ");
        c++;
    }
    printf("\n");
}