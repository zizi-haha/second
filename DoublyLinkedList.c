#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int data;
	Node* prev;
	Node* next;
}Node;
typedef struct{
	Node* head;
	Node* tail;
	int size;
}DoublyLinkedList;
//�����½ڵ�
Node* creatNode(int data){
	Node* newNode=(Node*)malloc(sizeof(Node));
	if(!newNode){
		printf("�ڴ����ʧ��");
		exit(1);//������������ֹ 
	}
	newNode->data=data;
	newNode->next=NULL;
	newNode->prev=NULL;
	return newNode;
} 
//��ʼ��˫����
void  initList(DoublyLinkedList* list){
	list->head=NULL;
	list->size=0;
	list->tail=NULL;
} 
//������ͷ������
void insertAtHead(DoublyLinkedList* list,int data){
	Node* newnode=creatNode(data);
	if(list->head==NULL){
		list->head=newnode;
		list->tail=newnode;
	}else{
		newnode->next=list->head;
		list->head->prev=newnode;
		list->head=newnode;
	}
	list->size++;
} 
//������β������
void insertAtTail(DoublyLinkedList* list,int data){
	Node* newnode=creatNode(data);
	if(list->head==NULL){
		list->head=newnode;
		list->tail=newnode;
		
	}else{
		list->tail->next=newnode;
		newnode->prev=list->tail;
		list->tail=newnode;
	}
	list->size++;
} 
//��ָ��λ�ò���
void insertAtPosition(DoublyLinkedList* list,int data,int pos){
	int i=0;
	if(pos>list->size||pos<0){
		printf("λ����Ч\n");
		return;
	}
	if(pos==0){
		insertAtHead(list,data);
	}
	if(pos==list->size){
		insertAtTail(list,data);
	}else{
		Node* newnode=creatNode(data);
		Node* current=list->head;
		for(i=0;i<pos;i++){
			current=current->next;
			
		}
		//?
		current->prev->next=newnode;
		newnode->prev=current->prev; 
		newnode->next=current;
		current->prev=newnode;
	}
	list->size++;
} 
//ɾ��ͷ���ڵ�
void deleteAtHead(DoublyLinkedList* list){
	if(list->size==0){
		printf("������Ϊ��");
		return;
	}
	Node* temp=list->head;
	list->head=temp->next;
	if(list->head!=NULL){
		list->head->prev=NULL; 
	}else{
		list->tail=NULL;
	}
	list->size--;
	free(temp);
	
	
} 
//ɾ��β���ڵ�
void deleteAtTail(DoublyLinkedList* list){
	if(list->size==0){
		printf("������Ϊ��");
		return;
	}
	Node* temp=list->tail;
	list->tail=temp->prev;
	if(list->tail!=NULL){
		list->tail->next=NULL;
	}else{
		list->head=NULL;
	} 
	free(temp);
	list->size--;
} 
//ɾ��ָ��λ�ýڵ�
void deletAtPosition(DoublyLinkedList* list,int pos){
	int i=0;
	Node* current=list->head;
	if(pos>list->size-1||pos<0){
		printf("λ�ò��Ϸ�");
		return;
	}
	if(pos==0){
		deleteAtHead(list);
		
	}
	if(pos==list->size-1){
		deleteAtTail(list);
		
	}
	else{
		for(i=0;i<pos-1;i++){
		current=current->next;
		}
		current->prev->next=current->next;
		current->next->prev=current->prev;
		
		
		free(current);
		list->size--;
	}
} 
//����
int search(DoublyLinkedList* list,int data){
	int i=0;
	Node* current=list->head;
	if(list->size==0){
		printf("������Ϊ��\n");
		return -1;
	}
	for(i=0;i<list->size;i++){
			if(current->data==data){
				return i;
			}
		current=current->next;
	
	}
	printf("δ�ҵ�\n");
	return -1;
} 
//��ӡ
void printList(DoublyLinkedList* list){
	int i=0;
	Node* current=list->head;
	for(i=0;i<list->size;i++){
		printf("%d ",current->data);
		current=current->next;
	}
	printf("\n");
} 
int getSize(DoublyLinkedList* list){
	return list->size;
}
int isEmpty(DoublyLinkedList* list){
	return list->size==0;
}
//�������
void freeLinkdeList(DoublyLinkedList* list){
	Node* current=list->head;
	Node* temp=NULL;
	int i=0;
	for(i=0;i<list->size;i++){
		temp=current->next;
		free(current);
		current=temp;
	}
	list->head=NULL;
	list->size=0;
	list->tail=NULL;
} 
int main(){
	DoublyLinkedList list;
	initList(&list);
	//����
	insertAtHead(&list,10);
	insertAtHead(&list,20);
	insertAtTail(&list,30);
	insertAtTail(&list,40);
	insertAtPosition(&list,50,2);
	printf("���������ʾ\n");
	printList(&list);
	printf("�����ȣ�%d \n",getSize(&list));
	//����
	int searchdata=30;
	int pos=search(&list,30);
	printf("����%d ��%dλ����\n",searchdata,pos);
	//ɾ������
	deleteAtTail(&list);
	deleteAtHead(&list);
	deletAtPosition(&list,2);
	printList(&list);
	freeLinkdeList(&list);
		printf("%d",list.size);
	return 0; 
}