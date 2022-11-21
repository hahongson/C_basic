#ifndef __STACK_H__

#define __STACK_H__

#define MAX 50

#include <stdio.h>

typedef int Eltype;

typedef struct {
    Eltype storage[MAX];
    int top;
}StackType;

void intialize(StackType *pStack);
int isFull(StackType pStack);
int isEmpty(StackType pStack);
void push(StackType *pStack,Eltype el);
Eltype pop(StackType *pStack);
#endif