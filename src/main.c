#include <stdio.h>
#include <stdint.h>

#include "stack.h"

int main(int argc, char *argv[]){

    Stack s;

    init(&s);

    push(&s, 5);

    dump(&s);

    drop(&s);

    //uint8_t x = pop(&s);
    //printf("%d\n", x);

    dump(&s);

    return 0;
}