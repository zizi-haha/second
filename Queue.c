#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct {
    int data[100];
    int front;
    int rear;
}Queue;
//��ʼ��
void init(Queue*q){
    q->front=0;
    q->rear=-1;
}
//�������Ƿ�Ϊ��
bool isEmpty(Queue* q){
    return (q->front)>(q->rear);
}
//�������Ƿ�Ϊ��
bool isFull(Queue* q){
    return q->rear==99;
}
//���
void enqueue(Queue* q,int value){
    if(isFull(q)){
        printf("��������\n");

    }
    q->data[++(q->rear)]=value;
}
//����
int dequeue(Queue* q){
    if(isEmpty(q)){
        printf("����Ϊ��\n");
        return -1;
    }
    return q->data[(q->front)++];
}
//��ȡ����Ԫ��
int front(Queue* q){
    if(isEmpty(q)){
        printf("����Ϊ��\n");
        return -1;
    }
    return q->data[q->front];
}
//��ӡ
void printQueue(Queue* q){
	int i=0;
    if(isEmpty(q)){
        printf("����Ϊ��\n");
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
    printf("����Ԫ��: %d\n",front(&q));
    printf("����Ԫ��: %d\n",dequeue(&q));
    printQueue(&q);
    return 0;
}