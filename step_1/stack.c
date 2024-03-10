#include <stdio.h>
#include "macrofiles.h"

int stack[CAPACITY];
int top = -1;

void push(int x){
    if(top == CAPACITY - 1){
        return;
    } else {
        stack[++top] = x;
    }
}

int pop(void){
    if(top == -1){
        return 0;
    } else {
        return stack[top--];
    }
}