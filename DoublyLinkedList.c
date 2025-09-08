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
//创建新节点
Node* creatNode(int data){
	Node* newNode=(Node*)malloc(sizeof(Node));
	if(!newNode){
		printf("内存分配失败");
		exit(1);//让整个程序终止 
	}
	newNode->data=data;
	newNode->next=NULL;
	newNode->prev=NULL;
	return newNode;
} 
//初始化双链表
void  initList(DoublyLinkedList* list){
	list->head=NULL;
	list->size=0;
	list->tail=NULL;
} 
//在链表头部插入
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
//在链表尾部插入
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
//在指定位置插入
void insertAtPosition(DoublyLinkedList* list,int data,int pos){
	int i=0;
	if(pos>list->size||pos<0){
		printf("位置无效\n");
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
//删除头部节点
void deleteAtHead(DoublyLinkedList* list){
	if(list->size==0){
		printf("该链表为空");
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
//删除尾部节点
void deleteAtTail(DoublyLinkedList* list){
	if(list->size==0){
		printf("该链表为空");
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
//删除指定位置节点
void deletAtPosition(DoublyLinkedList* list,int pos){
	int i=0;
	Node* current=list->head;
	if(pos>list->size-1||pos<0){
		printf("位置不合法");
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
//查找
int search(DoublyLinkedList* list,int data){
	int i=0;
	Node* current=list->head;
	if(list->size==0){
		printf("该链表为空\n");
		return -1;
	}
	for(i=0;i<list->size;i++){
			if(current->data==data){
				return i;
			}
		current=current->next;
	
	}
	printf("未找到\n");
	return -1;
} 
//打印
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
//清空链表
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
	//插入
	insertAtHead(&list,10);
	insertAtHead(&list,20);
	insertAtTail(&list,30);
	insertAtTail(&list,40);
	insertAtPosition(&list,50,2);
	printf("链表操作演示\n");
	printList(&list);
	printf("链表长度：%d \n",getSize(&list));
	//搜索
	int searchdata=30;
	int pos=search(&list,30);
	printf("数据%d 在%d位置上\n",searchdata,pos);
	//删除测试
	deleteAtTail(&list);
	deleteAtHead(&list);
	deletAtPosition(&list,2);
	printList(&list);
	freeLinkdeList(&list);
		printf("%d",list.size);
	return 0; 
}