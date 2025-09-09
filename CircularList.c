#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int data;
	struct Node* next;
}Node;
//创建
Node* creatNode(int data){
	Node* newNode=(Node*)malloc(sizeof(Node));
	if(newNode==NULL){
		printf("内存分配失败");
		exit(1);
	}
	newNode->data=data;
	newNode->next=NULL;
	return newNode;
} 
//在循环列表尾部插入节点
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
//再循环列表开头插入
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
//删除头节点
void deleteAtHead(Node** head){
	Node* temp=*head;
	if(*head==NULL){
		printf("列表为空\n");
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
//删除节点

void deleteNode(Node** head,int data){
	if(*head==NULL){
		printf("列表为空\n");
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
		printf("未找到节点%d\n",data);
	}
	
} 
//打印
void displayList(Node* head){
	if(head==NULL){
		printf("链表为空\n");
		return;
	}
	Node* current=head;
	
		do{
			printf("%d ->",current->data);
			current=current->next;
		}while(current!=head);
		printf("头节点\n");
	
} 
//释放
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
//测试
int main(){
	Node* head=NULL;
	//插入
	insertAtEnd(&head,10);
	insertAtEnd(&head,20);
	insertAtEnd(&head,30);
	insertAtHead(&head,5);
	displayList(head);
	printf("删除\n");
	deleteNode(&head,20);
	displayList(head);
	freeList(&head);
	if(!head){
		printf("清空了\n");
		
	} 
	return 0;
} 