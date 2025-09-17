#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int data;
	struct Node* next;
}Node;

//�����½ڵ�
Node* creatNode(int data){
	Node* newNode=(Node*)malloc(sizeof(Node));
	if(!newNode)exit(1);
	newNode->data=data;
	newNode->next=NULL;
	return newNode;

}
//��ͷ�����룬ʹ�ö���ָ��
void insertAtHead(Node** head_ref,int data){
	Node* newNode=creatNode(data);
	newNode->next=*head_ref;
	*head_ref=newNode;
} 
//������β������
void insertAtTail(Node** head,int data){
	Node* newNode=creatNode(data);
	if(*head==NULL){
		*head=newNode;
		return; 
	}
	Node* current=*head;
	while(current->next!=NULL){
		current=current->next;
	}
	current->next=newNode;
} 
//ɾ���ڵ�
void deleteNode(Node** head,int data){
	if(*head==NULL)return;
	if(data==(*head)->data){
		Node* temp=*head;
		*head=(*head)->next;
		free(temp);
	}
	Node* current=*head;
	while(current!=NULL&&current->next->data!=data){
		current=current->next;
	}
	if(current->next->data==data){
		Node* temp=current->next;
		current->next=temp->next;
		free(temp);
		return;
	}
	printf("û�ҵ�\n");
	
} 

//���ҽڵ�
Node* searchNode(Node** head,int data){
	Node* current=*head;
	while(current!=NULL&&current->data!=data){
		current=current->next;
	}
	if(current->data==data){
		return current;
	}
	return NULL;
} 
//��ӡ���� 
void printNode(Node** head){
		Node* current=*head;
	while(current!=NULL){
		printf("%d ",current->data);
		current=current->next;
	}
	printf("\n");
}
void freeNode(Node** head){
	Node* current=*head;
	Node* next;
	while(current!=NULL){
		next=current->next;
		free(current);
		current=next;
	}
	*head=NULL;
}
///
int main(){
	Node* head=NULL;
	insertAtHead(&head,3);
		insertAtHead(&head,2);
			insertAtHead(&head,1);
	insertAtTail(&head,4);
	insertAtTail(&head,5);
	printf("��ʼ����:\n");
	printNode(&head);
	deleteNode(&head,3);
	printf("ɾ��3��:\n");
	printNode(&head);
	printf("���ҽ��:\n");
	Node* n=searchNode(&head,4);
	if(n!=NULL){
		printf("�ҵ��ڵ�%d \n",n->data);
	}
	else{
		printf("û�ҵ�");
		
	}
	freeNode(&head);
	if(head==NULL){
		printf("null");
	}
	
}