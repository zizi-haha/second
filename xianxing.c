#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef int ElemType;
typedef struct {
    ElemType *data;
    int length;
    int capacity;
 }SeqList;
//初始化
bool InitList(SeqList *L){
    L->data=NULL;
    L->length=0;
    L->capacity=0;
    return true;
}
//创建顺序表,并指定容量
bool CreatList(SeqList *L,int initCapacity){
    if(initCapacity<=0){
        printf("初始容量必须大于0\n");
        return false;
    }
    L->data=(ElemType *)malloc(initCapacity*sizeof(ElemType));
    if(L->data==NULL){
        printf("内存分配失败\n");
        return false;
    }
    L->length=0;
    L->capacity=initCapacity;
    printf("顺序表创建成功\n");
    return true;
}
//扩容函数
bool ExpandList(SeqList *L){
  if(L->capacity==0){
    return CreatList(L,10);
  }
    int newCapacity=L->capacity*2;
    ElemType *newData=(ElemType *)realloc(L->data,newCapacity*sizeof(ElemType));
    if(newData==NULL){
        printf("内存分配失败\n");
        return false;
    }
    L->data=newData;
    L->capacity=newCapacity;
    printf("顺序表扩容成功,新容量为%d\n",L->capacity);
    return true;
  
}
//插入
bool ListInsert(SeqList *L,int pos,ElemType e){
    int i;
    //检查位置合法性
    if(pos<0||pos>L->length){
        printf("插入位置%d不合法,当前长度：%d\n",pos,L->length);
        return false;
    }
    //检查是否需要扩容
    if(L->capacity<L->length){
        if(!ExpandList(L)){
            return false;
        }
    }
    //将插入位置和之后的元素后移
    for(i=L->length;i>pos;i--){
        L->data[i]=L->data[i-1];
    }
    //插入新元素
    L->data[pos]=e;
    L->length++;
    return true;
}
//删除操作
bool ListDelete(SeqList *L,int pos,ElemType *e){
    int i=0;
    //检查位置的合法性
    if(pos<0||pos>=L->length){
        printf("删除位置%d不合法,当前长度：%d\n",pos,L->length);
        return false;
    }
    //保存删除元素
    *e=L->data[pos];
    //将删除之后的元素前移
    for(i=pos;i<L->length-1;i++){
        L->data[i]=L->data[i+1];
    }
    L->length--;
    return true;
}
//按值查找:查找e第一次出现的位置
int LocataElem(SeqList *L,ElemType e){
    int i;
    for(i=0;i<L->length;i++){
    	
        if(L->data[i]==e){
            return i;
        }
		}
        return -1;
}
//按位查找:查找第pos个位置的元素
bool GetElem(SeqList *L,int pos,ElemType *e){
    if(pos<0||pos>=L->length){
        printf("查找位置%d不合法,当前长度：%d\n",pos,L->length);
        return false;
    }
    *e=L->data[pos];
    return true;
}
//修改元素
bool ModifyElem(SeqList *L,int pos,ElemType e){
    //判断位置合法性
    if(pos<0||pos>=L->length){
        printf("修改位置%d不合法,当前长度：%d\n",pos,L->length);
        return false;
    }
    L->data[pos]=e;
    return true;
}
//获取顺序表长度
int GetLength(SeqList *L){
    return L->length;
}
//获取顺序表容量
int GetCapacity(SeqList *L){
    return L->capacity;
}
//判断顺序表是否为空
bool IsEmpty(SeqList *L){
    return L->length==0;
}
//判断顺序表是否已满
bool ListFull(SeqList *L){
    return L->length>=L->capacity;
}
//遍历打印顺序表
void PrintList(SeqList *L){
    int i=0;
  //判断顺序表是否为空
  if(IsEmpty(L)){
    printf("顺序表为空\n");
    return;
  }
  printf("顺序表内容（长度：=%d,容量：%d):",L->length,L->capacity);
  printf("[");
  for(i=0;i<L->length;i++){
    printf("%d ",L->data[i]);
    if(i<L->length-10){
        printf(", ");

  }
  
}
printf("]\n");}
//清空和销毁
bool DestoryList(SeqList *L){
    if(L->data!=NULL){
        free(L->data);
        L->data=NULL;
    }
    L->length=0;
    L->capacity=0;
    printf("顺序表销毁成功\n");
    return true;
}

//主函数
int main(){
    SeqList L;
    int i=0;
    ElemType temp;
    //新建
    InitList(&L);
    CreatList(&L,5);
    //增加内容
    printf("插入测试\n");
    for(i=0;i<8;i++){
        ListInsert(&L,i,i*10);
    }
     PrintList(&L);
    //删除测试
    printf("删除测试\n");
    ListDelete(&L,2,&temp);
    printf("删除的元素是：%d\n",temp);
    PrintList(&L);
    //查找测试
    printf("查找测试\n");
    int pos=LocataElem(&L,50);
    if(pos!=-1){
        printf("元素50的位置是：%d\n",pos);
    }else{
        printf("元素50不存在\n");
    }
    if(GetElem(&L,3,&temp)){
        printf("位置7的元素是：%d\n",temp);
    }

    //修改测试
    printf("修改测试\n");
    if(ModifyElem(&L,0,100)){
        PrintList(&L);
    }
    //信息获取
    printf("顺序表长度：%d\n",GetLength(&L));
    printf("顺序表容量：%d\n",GetCapacity(&L));
    printf("顺序表是否为空：%s\n",IsEmpty(&L)?"是":"否");
    printf("顺序表是否已满：%s\n",IsEmpty(&L)?"是":"否");    //销毁

    //销毁
    DestoryList(&L);
    return 0;
    }