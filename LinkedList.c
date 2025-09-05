#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
//定义链表节点结构
typedef struct Node{
	int data;
	struct Node* next;
}Node;
//定义链表管理结构
typedef struct LinkedList{
	Node* head;//头指针 
	Node* tail;//尾指针
	int size;
}LinkedList; 
//初始化
LinkedList* createLinkedList(){
	LinkedList* list=(LinkedList*)malloc(sizeof(LinkedList));
	if(list==NULL){
		printf("内存分配失败\n");
		return NULL;
	}
	list->head=NULL;
	list->tail=NULL;
	list->size=0;
	return list;
}
//创建新节点
Node* createNode(int data){
	Node* newNode=(Node*)malloc(sizeof(Node));
	newNode->data=data;
	newNode->next=NULL;
	return newNode;
} 
//检查链表是否为空
bool isEmpty(LinkedList* list){
	return list->head==NULL;
} 
//在头部插入
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
//在尾部插入
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

//在指定位置插入
void insertAtIndex(LinkedList* list,int index,int data){
	//判断下标是否越界
	int i=0;
	if(index>list->size){
		printf("索引：%d\n",index);
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
	//移动
	for(i=0;i<index-1;i++){
		current=current->next;
	}

	newNode->next=current->next;
	current->next=newNode;
	list->size++;
}

//删除头节点
int deleteAtHead(LinkedList* list){
	if(isEmpty(list)){
		printf("链表为空");
		return -1;
	}
	Node* temp=list->head;
	int data=list->head->data;
	if(list->head==list->tail){
		//只有一个节点
		list->head=NULL;
		list->tail=NULL; 
	}else{
		list->head=list->head->next;
	}
	free(temp);
	list->size--;
	return data;

}
//删除尾节点
int deleteAtTail(LinkedList* list){
	int data;
	if(isEmpty(list)){
		printf("链表为空");
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
 
//删除指定位置节点 
int deleteAtIndex(LinkedList* list,int index){
	int data;
	int i;
	if(isEmpty(list)){
		printf("链表为空");
		return -1;
	}
	if(index>=list->size||index<0){
		printf("索引：%d超出范围",index);
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
//查找
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
//获取链表长度
int getSize(LinkedList* list){
	return list->size;
}
//获取节点数据
int getNode(Node* list){
	return list->data;
} 
//打印
void printList(LinkedList* list){
	if(isEmpty(list)){
		printf("当前列表为空\n");
		
	}
	printf("链表内容：\n");
	Node* current=list->head;
	while(current!=NULL){
		printf("%d",current->data);
		if(current->next!=NULL){
			printf("->");
		}
		current=current->next;
	}
	printf("->NULL\n");
	printf("链表长度：%d",getSize(list));
	
}
//反转链表
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
//测试
int main(){
	LinkedList* list=createLinkedList();
	printf("===单链表操作演示===\n");
	printf("插入：\n");
	insertAtHead(list,10);
	insertAtIndex(list,1,20);
	insertAtTail(list,30);
	insertAtTail(list,40);
	insertAtTail(list,50);
	insertAtIndex(list,2,50);
	printList(list);
	printf("查找：\n");
	Node* found=findNode(list,30);
	if(found!=NULL){
		printf("找到元素%d\n",found->data);
	}else{
		printf("未找到元素");
	}
		Node* founds=findNode(list,33);
	if(founds!=NULL){
		printf("找到元素%d\n",founds->data);
	}else{
		printf("未找到元素\n");
	}
	printf("删除：\n");
	printf("删除头节点：%d\n",deleteAtHead(list));
	printf("删除尾节点：%d\n",deleteAtTail(list));
	printf("删除1节点：%d\n",deleteAtIndex(list,1));
	printList(list);
	printf("反转：\n");
	reverseList(list);
	printList(list);
	free(list);
	return 0;
	
} 












