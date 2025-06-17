#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct Stack{
    int top;
    unsigned capacity;
    int* array;
};

struct Stack* createStack(unsigned cap){
    struct Stack* newStack=(struct Stack*) malloc(sizeof(struct Stack));
    newStack->capacity =cap;
    newStack->top=-1;
    newStack->array=(int*)malloc(newStack->capacity*sizeof(int));
    return newStack;
}

int isFull(struct Stack* stack){
    return (stack->top==stack->capacity-1);
}

int isEmpty(struct Stack* stack){
    return(stack->top==-1);
}

void push(struct Stack* stack,int val){
    if(isFull(stack)){
        printf("Stack Overflow");
        return;
    }
    stack->array[++stack->top]=val;
    printf("%d Pushed to Stack \n",val);
}

int pop(struct Stack* stack){
    if(isEmpty(stack)){
        printf("Stack Underflow");
        return INT_MIN;
    }
    int pval=stack->array[stack->top--];
    return pval;
}

int Peek(struct Stack*stack){
    if(isEmpty(stack)){
        printf("Stack Underflow can't peek");
        return INT_MIN;
    }
    return stack->array[stack->top];
}

int main(){
    struct Stack* stack=createStack(5);
    push(stack, 10);
    push(stack,20);
    push(stack,30);
    push(stack,40);
    int peek=Peek(stack);
    printf("Current top of the stack is %d\n",peek);
    int a=pop(stack);
    printf("%d popped\n",a);
    int b=pop(stack);
    printf("%d popped\n",b);
    peek=Peek(stack);
    printf("Current top of the stack is %d\n",peek);
    return 0;
}

