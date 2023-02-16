#include <stdio.h>

enum {TRUE, FALSE};

static int N;
static int top;
typedef int data_t;

/*
   push();
   pop();
   top();
   isEmpty();
   isFull();
   isSize();
*/
int isFull() {
    return top == N-1;
}

int isEmpty() {
    return top == -1;
}

data_t push(data_t stack[], data_t data) {
    if(isFull()){
        printf("Stack full, stack-over!\n");
        return FALSE;
    }
    top += 1;
    stack[top] = data;
    return TRUE;
}

data_t isTop(data_t stack[]){
    if (isEmpty(stack)){
        printf("stack is empty!\n");
        return FALSE;
    }
    return stack[top];
}

data_t pop(data_t stack[]){
    if(isEmpty()){
        printf("Can't pop data NULL: ");
        return FALSE;
    }
    int num = stack[top];
    stack[top] = -1;
    top -= 1;
    return num;
}


void travesal(data_t stack[]){
    for(int i = 0; i <= top; i++) printf("%d ",stack[i]);
    printf("\n");
}

int main(){
    N = 10;
    data_t stack[N];
    pop(stack);
    push(stack, 5);
    push(stack, 3);
    push(stack, 10);
    push(stack, 100);
    travesal(stack);
    printf("%d ;\n",pop(stack)/pop(stack));
    printf("Top is: %d\n",isTop(stack));
}
