#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int data;
	struct Node* next;
}Node;
//����
Node* creatNode(int data){
	Node* newNode=(Node*)malloc(sizeof(Node));
	if(newNode==NULL){
		printf("�ڴ����ʧ��");
		exit(1);
	}
	newNode->data=data;
	newNode->next=NULL;
	return newNode;
} 
//��ѭ���б�β������ڵ�
void insertAtEnd(Node** head,int data){
	Node* newNode=creatNode(data);
	Node* temp=*head;
	if(*head==NULL){
		*head=newNode;
		newNode->next=newNode;
	}
	else{
		while(temp->next!=*head){
			temp=temp->next;
		}
		temp->next=newNode;
		newNode->next=*head;
	}
} 
//��ѭ���б�ͷ����
void insertAtHead(Node** head,int data){
	Node* newNode=creatNode(data);
	Node* temp=*head;
	if(*head==NULL){
		*head=newNode;
		newNode->next=*head;
	}
	else{
	     while(temp->next!=*head){
	     	temp=temp->next;
		 }
		 temp->next=newNode;
		 newNode->next=*head;
		 *head=newNode;
	}
} 
//ɾ��ͷ�ڵ�
void deleteAtHead(Node** head){
	Node* temp=*head;
	if(*head==NULL){
		printf("�б�Ϊ��\n");
		return;
	}
	else{
		while(temp->next!=*head){
			temp=temp->next;
		}
		temp->next=(*head)->next;
		*head=(*head)->next;
	}
	free(temp);
} 
//ɾ���ڵ�

void deleteNode(Node** head,int data){
	if(*head==NULL){
		printf("�б�Ϊ��\n");
		return;
	}
	Node* current=*head,*prev=NULL;
	if(current->data==data){
		deleteAtHead(head);
	}
	do{
		prev=current;
		current=current->next;
	}while(current!=*head&&current->data!=data);
	if(current->data==data){
		prev->next=current->next;
		free(current);
	}else{
		printf("δ�ҵ��ڵ�%d\n",data);
	}
	
} 
//��ӡ
void displayList(Node* head){
	if(head==NULL){
		printf("����Ϊ��\n");
		return;
	}
	Node* current=head;
	
		do{
			printf("%d ->",current->data);
			current=current->next;
		}while(current!=head);
		printf("ͷ�ڵ�\n");
	
} 
//�ͷ�
void freeList(Node** head){
	if(*head==NULL)return;
	Node* current=*head;
	Node* next;
	do{
		next=current->next;
		free(current);
		current=next;
	}while(current!=*head);
	*head=NULL;
} 
//����
int main(){
	Node* head=NULL;
	//����
	insertAtEnd(&head,10);
	insertAtEnd(&head,20);
	insertAtEnd(&head,30);
	insertAtHead(&head,5);
	displayList(head);
	printf("ɾ��\n");
	deleteNode(&head,20);
	displayList(head);
	freeList(&head);
	if(!head){
		printf("�����\n");
		
	} 
	return 0;
} 