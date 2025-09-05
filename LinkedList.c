#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
//��������ڵ�ṹ
typedef struct Node{
	int data;
	struct Node* next;
}Node;
//�����������ṹ
typedef struct LinkedList{
	Node* head;//ͷָ�� 
	Node* tail;//βָ��
	int size;
}LinkedList; 
//��ʼ��
LinkedList* createLinkedList(){
	LinkedList* list=(LinkedList*)malloc(sizeof(LinkedList));
	if(list==NULL){
		printf("�ڴ����ʧ��\n");
		return NULL;
	}
	list->head=NULL;
	list->tail=NULL;
	list->size=0;
	return list;
}
//�����½ڵ�
Node* createNode(int data){
	Node* newNode=(Node*)malloc(sizeof(Node));
	newNode->data=data;
	newNode->next=NULL;
	return newNode;
} 
//��������Ƿ�Ϊ��
bool isEmpty(LinkedList* list){
	return list->head==NULL;
} 
//��ͷ������
void insertAtHead(LinkedList* list,int data){
	Node* newNode=createNode(data);
	if(isEmpty(list)){
		list->head=newNode;
		list->tail=newNode;
	}else{
		newNode->next=list->head;
		list->head=newNode;
	}
	list->size++;
}
//��β������
void insertAtTail(LinkedList* list,int data){
	Node* newNode=createNode(data);
	if(isEmpty(list)){
		list->head=newNode;
		list->tail=newNode;
	}else{
		list->tail->next=newNode;
		list->tail=newNode; 
		
	}
	list->size++;
} 

//��ָ��λ�ò���
void insertAtIndex(LinkedList* list,int index,int data){
	//�ж��±��Ƿ�Խ��
	int i=0;
	if(index>list->size){
		printf("������%d\n",index);
		return;
	} 
	if(index==0){
		insertAtHead(list,data);
		return;
	}
	if(index==list->size){
		insertAtTail(list,data);
		return;
	}
	Node* newNode=createNode(data);
	Node* current=list->head;
	//�ƶ�
	for(i=0;i<index-1;i++){
		current=current->next;
	}

	newNode->next=current->next;
	current->next=newNode;
	list->size++;
}

//ɾ��ͷ�ڵ�
int deleteAtHead(LinkedList* list){
	if(isEmpty(list)){
		printf("����Ϊ��");
		return -1;
	}
	Node* temp=list->head;
	int data=list->head->data;
	if(list->head==list->tail){
		//ֻ��һ���ڵ�
		list->head=NULL;
		list->tail=NULL; 
	}else{
		list->head=list->head->next;
	}
	free(temp);
	list->size--;
	return data;

}
//ɾ��β�ڵ�
int deleteAtTail(LinkedList* list){
	int data;
	if(isEmpty(list)){
		printf("����Ϊ��");
		return -1; 
	}
	if(list->head==list->tail){
		list->head=NULL;
		list->tail=NULL;
	}else{
		Node* current=list->head;
		while(current->next!=list->tail){
			current=current->next;
		}
		data=list->tail->data;
		current->next=NULL;
		list->tail=current;
		
	}
	list->size--;
	return data;
}
 
//ɾ��ָ��λ�ýڵ� 
int deleteAtIndex(LinkedList* list,int index){
	int data;
	int i;
	if(isEmpty(list)){
		printf("����Ϊ��");
		return -1;
	}
	if(index>=list->size||index<0){
		printf("������%d������Χ",index);
		return -1;
	}
	if(index==0){
		return deleteAtHead(list);
	}
	if(index==list->size){
		return deleteAtTail(list);
	}
	Node* node=list->head;
	for(i=0;i<index-1;i++){
		node=node->next;
	}
	Node* temp=node->next;
	data=temp->data;
	node->next=temp->next;
	free(temp);

	return data;
}
//����
Node* findNode(LinkedList* list,int data){
	Node* current=list->head;
	while(current->next!=NULL){
		if(current->data==data){
			return current;
		}
		current=current->next; 
	}
	return NULL;
}
//��ȡ������
int getSize(LinkedList* list){
	return list->size;
}
//��ȡ�ڵ�����
int getNode(Node* list){
	return list->data;
} 
//��ӡ
void printList(LinkedList* list){
	if(isEmpty(list)){
		printf("��ǰ�б�Ϊ��\n");
		
	}
	printf("�������ݣ�\n");
	Node* current=list->head;
	while(current!=NULL){
		printf("%d",current->data);
		if(current->next!=NULL){
			printf("->");
		}
		current=current->next;
	}
	printf("->NULL\n");
	printf("�����ȣ�%d",getSize(list));
	
}
//��ת����
void reverseList(LinkedList* list){
	Node* prev=NULL;
	Node* current=list->head;
	Node* next=NULL;
	list->tail=list->head;
	while(current!=NULL){
		next=current->next;
		current->next=prev;
		prev=current;
		current=next;
	}
	list->head=prev;
} 
//����
int main(){
	LinkedList* list=createLinkedList();
	printf("===�����������ʾ===\n");
	printf("���룺\n");
	insertAtHead(list,10);
	insertAtIndex(list,1,20);
	insertAtTail(list,30);
	insertAtTail(list,40);
	insertAtTail(list,50);
	insertAtIndex(list,2,50);
	printList(list);
	printf("���ң�\n");
	Node* found=findNode(list,30);
	if(found!=NULL){
		printf("�ҵ�Ԫ��%d\n",found->data);
	}else{
		printf("δ�ҵ�Ԫ��");
	}
		Node* founds=findNode(list,33);
	if(founds!=NULL){
		printf("�ҵ�Ԫ��%d\n",founds->data);
	}else{
		printf("δ�ҵ�Ԫ��\n");
	}
	printf("ɾ����\n");
	printf("ɾ��ͷ�ڵ㣺%d\n",deleteAtHead(list));
	printf("ɾ��β�ڵ㣺%d\n",deleteAtTail(list));
	printf("ɾ��1�ڵ㣺%d\n",deleteAtIndex(list,1));
	printList(list);
	printf("��ת��\n");
	reverseList(list);
	printList(list);
	free(list);
	return 0;
	
} 












