#include "stack.h"
#include <stdio.h>

int main(){
    StackType stack ;
    intialize(&stack);
    char ch;
    printf("Input String: ");
    while((ch=getchar())!='\n'){
        push(&stack,ch);
    }
    while(!isEmpty(stack)){
        ch=pop(&stack);
        printf("%c",ch);
    }
    printf("\n");
    return 0;
}