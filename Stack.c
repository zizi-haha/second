#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct Stack{
    int top;
    int s[100];
}Stack;
//判断是否为空
bool isEmpty(Stack*stack){
    return stack->top==-1;
}
//判断是否已满
bool isFull(Stack* stack){
    return stack->top==99;
}
//入栈
bool push(Stack* stack,int data){
    //判断是否已满
    if(isFull(stack)){
        printf("isfull");
        return false;
    }
    else{
        stack->s[++stack->top]=data;
    return true;return true;   }


}
//出栈
bool pop(Stack* stack){
    //判断
    if(isEmpty(stack)){
        printf("is Empty");
        return false;
    }
    stack->top--;
}
//获取栈顶元素
int peek(Stack* stack){
    if(isEmpty(stack)){
        printf("is empty");
        return -1;
    }
    return stack->s[stack->top];
}
//打印栈
void printStack(Stack* stack){
    if(isEmpty(stack)){
        printf("is empty");
        return;
    }
    for(int i=stack->top;i>=0;i--){
        printf("%d ",stack->s[i]);
    }
    printf("\n");
}
int main(){
    Stack* stack=(Stack*)malloc(sizeof(Stack));
    stack->top=-1;
    push(stack,1);
    push(stack,2);
    push(stack,3);
    printStack(stack);
    printf("栈顶元素为%d\n",peek(stack));
    pop(stack);
    printStack(stack);
    printf("栈顶元素为%d\n",peek(stack));
    return 0;
}
