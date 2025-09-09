#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct {
    int data[100];
    int front;
    int rear;
}Queue;
//初始化
void init(Queue*q){
    q->front=0;
    q->rear=-1;
}
//检查队列是否为空
bool isEmpty(Queue* q){
    return (q->front)>(q->rear);
}
//检查队列是否为满
bool isFull(Queue* q){
    return q->rear==99;
}
//入队
void enqueue(Queue* q,int value){
    if(isFull(q)){
        printf("队列已满\n");

    }
    q->data[++(q->rear)]=value;
}
//出队
int dequeue(Queue* q){
    if(isEmpty(q)){
        printf("队列为空\n");
        return -1;
    }
    return q->data[(q->front)++];
}
//获取队首元素
int front(Queue* q){
    if(isEmpty(q)){
        printf("队列为空\n");
        return -1;
    }
    return q->data[q->front];
}
//打印
void printQueue(Queue* q){
	int i=0;
    if(isEmpty(q)){
        printf("队列为空\n");
        return;
    }
    for(i=q->front;i<=q->rear;i++){
        printf("%d ",q->data[i]);
    }
    printf("\n");
}

int main(){
    Queue q;
    init(&q);
    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);
    printQueue(&q);
    printf("队首元素: %d\n",front(&q));
    printf("出队元素: %d\n",dequeue(&q));
    printQueue(&q);
    return 0;
}