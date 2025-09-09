#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct Stack{
    int top;
    int s[100];
}Stack;
//�ж��Ƿ�Ϊ��
bool isEmpty(Stack*stack){
    return stack->top==-1;
}
//�ж��Ƿ�����
bool isFull(Stack* stack){
    return stack->top==99;
}
//��ջ
bool push(Stack* stack,int data){
    //�ж��Ƿ�����
    if(isFull(stack)){
        printf("isfull");
        return false;
    }
    else{
        stack->s[++stack->top]=data;
    return true;return true;   }


}
//��ջ
bool pop(Stack* stack){
    //�ж�
    if(isEmpty(stack)){
        printf("is Empty");
        return false;
    }
    stack->top--;
}
//��ȡջ��Ԫ��
int peek(Stack* stack){
    if(isEmpty(stack)){
        printf("is empty");
        return -1;
    }
    return stack->s[stack->top];
}
//��ӡջ
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
    printf("ջ��Ԫ��Ϊ%d\n",peek(stack));
    pop(stack);
    printStack(stack);
    printf("ջ��Ԫ��Ϊ%d\n",peek(stack));
    return 0;
}
