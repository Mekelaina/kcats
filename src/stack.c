#include "stack.h"
#include <stdio.h>

// intialize stack to default values
void init_stack(Stack *s){
    s->top = STACK_MAX;
    s->count = 0;
}


// push a value onto the stack
void push(Stack *s, uint8_t value){
    s->data[s->top] = value;
    
    if(s->top > 0){
        s->top--;
        s->count++;
    }
}

// pop a value off the stack
uint8_t pop(Stack *s){ 
    if(s->top > STACK_MAX){
        s->top++;
        s->count--;    
    } 

    uint8_t x = s->data[s->top];
    s->data[s->top] = 0;

    return x;
}

// peak at the top value on the stack without removing it
uint8_t peak(Stack *s){
    if(s->top > STACK_MAX){
        return s->data[s->top+1];
    }
    return s->data[s->top];
}

// pop and discard the top value on the stack
void drop(Stack *s){
    if(s->top > STACK_MAX){
        s->top++;
        s->count--;    
    } 

    s->data[s->top] = 0;
}

// print out the whole stack for debugging
void dump(Stack *s){
    printf("DEBUG:\n       -----  Stack Dump  -----\n");
    printf("       Stack Top: %d  Stack Count: %d\n", s->top, s->count);
    int c = 0;
    printf("       ");
    for(int i = STACK_MAX; i >= 0; --i){
        if(c == 8){
            printf("\n       ");
            c = 0;
        }
        printf("%02x: %03d", i, s->data[i]);
        printf(", ");
        c++;
    }
    printf("\n");
}

//Swaps the top two values on the stack. otherwise does nothing.
// (a b -- b a)
void swap(Stack *s){
    if(s->count < 2){
        return;
    }

    uint8_t a, b;
    a = s->data[s->top+2];
    b = s->data[s->top+1];
    s->data[s->top+2] = b;
    s->data[s->top+1] = a;
}

void over(Stack *s){

}

void rotate(Stack *s){

}

void rotateNumberOfItems(Stack *s, uint16_t count){

}