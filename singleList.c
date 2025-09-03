#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h> 
typedef struct{
	int *data;//储存数据
	int capicity;//最大储存容量 
	int length;//储存的元素个数 
}SequList;
//插入元素
bool setInt(SequList *L,int e,int pos);
//创建和初始化 
bool CreatList(SequList *L,int e);
//扩容
bool ExpandList(SequList *L);
//删除元素:按照值删除 
bool deleteInt(SequList *L,int e);
//删除元素：按位删除 
bool Delete(SequList *L,int pos,int *e);
//查找元素：按值查找 
bool findInt(SequList *L,int e);
//查找元素：按位查找
int  find(SequList *L,int pos);
void printList(SequList *L);
void freeList(SequList *L);
int main(){
	SequList L;
	int i=0;
	int e;
	printf("创建测试：\n");
	CreatList(&L,10);
	for(i=0;i<8;i++){
		L.data[i]=i*10;
		L.length++;
	}
	printList(&L);
	printf("插入测试：\n");
	setInt(&L,90,3);
	printList(&L);
	printf("删除测试：\n");
	Delete(&L,3,&e);
	printf("删除的元素为%d(90)\n",e);
	deleteInt(&L,10);
	printList(&L); 

	printf("查找元素测试：\n");
	find(&L,2);
	findInt(&L,30);
	printf("扩容测试：");
	ExpandList(&L);
	printf("\n测试结束");
	freeList(&L);
	return 0;
	
}



//创建和初始化 
bool CreatList(SequList *L,int e){//e是容量 
	if(e<=0){
		printf("容量不可以小于等于0");
		return false;
	}
	L->capicity=e;
	L->data=(int*)malloc(e*sizeof(int));
	if(L->data==NULL){
		printf("内存分配失败");
		return false;
	}
	L->length=0;
	return true;
}
//插入元素
bool setInt(SequList *L,int e,int pos){
	//判断容量 
	int i=0;
	if(L->capicity==L->length){
		printf("容量已满，请扩容");
		return false;
	}
	if(pos+1>=L->capicity){
		printf("位置不合适");
		return false;
	}
		//元素后移
	for(i=L->capicity-1;i>pos;i--){
		L->data[i]=L->data[i-1];
	} 
	//插入元素
	L->data[pos]=e;
	L->length++; 

	printf("元素%d添加成功",e);
	return true;
} 
//删除元素:按照值删除 
bool deleteInt(SequList *L,int e){
	int i=0;
	int j=0;
	for(i=0;i<L->length;i++){
		if(L->data[i]==e){
			j=1;
			break;
			
		}
	}
	if(j==0){
		printf("没有这个值");
		return false;
	}
	//将剩下的元素迁移 
	for(;i<L->length-1;i++){
		L->data[i]=L->data[i+1];
	}
	L->length--;
	printf("元素删除成功");
	return true;
} 
//删除元素：按位删除 
bool Delete(SequList *L,int pos,int *e){
	int i=0;
	if(pos>=L->length){
		printf("这个位置不合法");
		return false;
	}
	*e=L->data[pos];
	//将剩下的元素前移
	for(i=pos;i<L->length-1;i++){
		L->data[i]=L->data[i+1];
	} 
	L->length--;
	printf("按位删除成功");
	return true;
}
//查找元素：按值查找 
bool findInt(SequList *L,int e){
	int i;
	int k=0;
	for(i=0;i<L->length;i++){
		if(L->data[i]==e){
			k=1;
			break;
		}
	}
	if(k=0){
		printf("没有这个元素");
		return false;
	}
	else{
		printf("元素%d在%d位置",e,i);
	}
	return true;
} 
//查找元素：按位查找
int  find(SequList *L,int pos){
	//判断位置的合法性
	 if(pos>=L->length){
		printf("这个位置不合法");
		return -1;
	}
	return L->data[pos];
} 
//扩容
bool ExpandList(SequList *L){
	printf("开始扩容，当前容量为：%d，当前长度为：%d\n",L->capicity,L->length);
	if(L->capicity<=0){
		printf("无效\n");
		return false;
	}
	int newc=2*L->capicity; 
	int *newdata=(int *)realloc(L->data,newc*sizeof(int));
	if(newdata==NULL){
		printf("内存分配失败\n");
		return false;
	}
	L->data=newdata;
	L->capicity=newc;
	printf("内存扩增成功，新的内存为%d",L->capicity);
	return true;
	}
//打印
void printList(SequList *L){
	int i=0;
	printf("[ ");
	for(i=0;i<L->length;i++){
		printf("%d ",L->data[i]); 
	}
	printf("]");
	
} 
void freeList(SequList *L){
	free(L->data);
	L->data=NULL;
	L->length=0;
	L->capicity=0;
}

