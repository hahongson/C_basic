#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include <limits.h>

void intialize(StackType *pStack){
    pStack->top=-1;
}

int isFull(StackType stack){
    return stack.top==MAX-1;
}

int isEmpty(StackType stack){
    return stack.top==-1;
}


void push(StackType *pStack,Eltype el){
    if(isFull(*pStack)){
        printf("StackOverFlow!\n");
        return;
    }
    (*pStack).storage[++(*pStack).top]=el;
}

Eltype pop (StackType *pStack){
    if(isEmpty(*pStack)){
        printf("StackUnderFlow\n");
        return INT_MIN;
    }
    return (*pStack).storage[(*pStack).top--];
}