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
    
    if(s->top != 0){
        s->top--;
        s->count++;
    }
}

// fixed bug
// pop a value off the stack
uint8_t pop(Stack *s){ 
    if(s->top != STACK_MAX){
        s->top++;
        s->count--;    
    } 

    uint8_t x = s->data[s->top];
    s->data[s->top] = 0;

    return x;
}

// peak at the top value on the stack without removing it
uint8_t peak(Stack *s){
    if(s->top != STACK_MAX){
        return s->data[s->top+1];
    }
    return s->data[s->top];
}

// pop and discard the top value on the stack
void drop(Stack *s){
    if(s->top != STACK_MAX){
        s->top++;
        s->count--;    
    } 

    s->data[s->top] = 0;
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

//Copys the value under top and pushes it.
//(a b -- a b a)
void over(Stack *s){
    if(s->count < 2){
        return;
    }
    push(s, s->data[s->top+2]);
}

//(a b c -- c a b)
void rotate(Stack *s){
    if(s->count < 3){
        return;
    }
    uint8_t a = s->data[s->top+3];
    uint8_t b = s->data[s->top+2];
    uint8_t c = s->data[s->top+1];
    s->data[s->top+3] = c;
    s->data[s->top+2] = a;
    s->data[s->top+1] = b;
}


//rotate an arbtrary number of values. 
//this code is much slower bc it has to
//copy the specified section of the stack twice
//should look into optimizing it at some point.
void rotateNumberOfItems(Stack *s, uint16_t count){
    if(count > s->count){
        push(s, 0);
        return;
    }
    uint8_t buffer[count];
    
    for(int i = 0; i < count; ++i){
        buffer[i] = s->data[s->top+(count-i)];
    }  
    
    uint8_t back = s->data[s->top+1];

    for(int i = 1; i < count; ++i){
        s->data[s->top+(count-i)] = buffer[i-1];
    }
    s->data[s->top+count] = back;
}


uint8_t peak_back(Stack *s, uint8_t n){
    if(s->count < n){
        return s->data[s->top+s->count];
    }
    return s->data[s->top+(n+1)];
}


void push_ints(Stack *s, uint8_t values[], uint16_t count){
    for (int i = 0; i < count; ++i){
        push(s, values[i]);
    }
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