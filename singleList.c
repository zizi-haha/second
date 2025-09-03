#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h> 
typedef struct{
	int *data;//��������
	int capicity;//��󴢴����� 
	int length;//�����Ԫ�ظ��� 
}SequList;
//����Ԫ��
bool setInt(SequList *L,int e,int pos);
//�����ͳ�ʼ�� 
bool CreatList(SequList *L,int e);
//����
bool ExpandList(SequList *L);
//ɾ��Ԫ��:����ֵɾ�� 
bool deleteInt(SequList *L,int e);
//ɾ��Ԫ�أ���λɾ�� 
bool Delete(SequList *L,int pos,int *e);
//����Ԫ�أ���ֵ���� 
bool findInt(SequList *L,int e);
//����Ԫ�أ���λ����
int  find(SequList *L,int pos);
void printList(SequList *L);
void freeList(SequList *L);
int main(){
	SequList L;
	int i=0;
	int e;
	printf("�������ԣ�\n");
	CreatList(&L,10);
	for(i=0;i<8;i++){
		L.data[i]=i*10;
		L.length++;
	}
	printList(&L);
	printf("������ԣ�\n");
	setInt(&L,90,3);
	printList(&L);
	printf("ɾ�����ԣ�\n");
	Delete(&L,3,&e);
	printf("ɾ����Ԫ��Ϊ%d(90)\n",e);
	deleteInt(&L,10);
	printList(&L); 

	printf("����Ԫ�ز��ԣ�\n");
	find(&L,2);
	findInt(&L,30);
	printf("���ݲ��ԣ�");
	ExpandList(&L);
	printf("\n���Խ���");
	freeList(&L);
	return 0;
	
}



//�����ͳ�ʼ�� 
bool CreatList(SequList *L,int e){//e������ 
	if(e<=0){
		printf("����������С�ڵ���0");
		return false;
	}
	L->capicity=e;
	L->data=(int*)malloc(e*sizeof(int));
	if(L->data==NULL){
		printf("�ڴ����ʧ��");
		return false;
	}
	L->length=0;
	return true;
}
//����Ԫ��
bool setInt(SequList *L,int e,int pos){
	//�ж����� 
	int i=0;
	if(L->capicity==L->length){
		printf("����������������");
		return false;
	}
	if(pos+1>=L->capicity){
		printf("λ�ò�����");
		return false;
	}
		//Ԫ�غ���
	for(i=L->capicity-1;i>pos;i--){
		L->data[i]=L->data[i-1];
	} 
	//����Ԫ��
	L->data[pos]=e;
	L->length++; 

	printf("Ԫ��%d��ӳɹ�",e);
	return true;
} 
//ɾ��Ԫ��:����ֵɾ�� 
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
		printf("û�����ֵ");
		return false;
	}
	//��ʣ�µ�Ԫ��Ǩ�� 
	for(;i<L->length-1;i++){
		L->data[i]=L->data[i+1];
	}
	L->length--;
	printf("Ԫ��ɾ���ɹ�");
	return true;
} 
//ɾ��Ԫ�أ���λɾ�� 
bool Delete(SequList *L,int pos,int *e){
	int i=0;
	if(pos>=L->length){
		printf("���λ�ò��Ϸ�");
		return false;
	}
	*e=L->data[pos];
	//��ʣ�µ�Ԫ��ǰ��
	for(i=pos;i<L->length-1;i++){
		L->data[i]=L->data[i+1];
	} 
	L->length--;
	printf("��λɾ���ɹ�");
	return true;
}
//����Ԫ�أ���ֵ���� 
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
		printf("û�����Ԫ��");
		return false;
	}
	else{
		printf("Ԫ��%d��%dλ��",e,i);
	}
	return true;
} 
//����Ԫ�أ���λ����
int  find(SequList *L,int pos){
	//�ж�λ�õĺϷ���
	 if(pos>=L->length){
		printf("���λ�ò��Ϸ�");
		return -1;
	}
	return L->data[pos];
} 
//����
bool ExpandList(SequList *L){
	printf("��ʼ���ݣ���ǰ����Ϊ��%d����ǰ����Ϊ��%d\n",L->capicity,L->length);
	if(L->capicity<=0){
		printf("��Ч\n");
		return false;
	}
	int newc=2*L->capicity; 
	int *newdata=(int *)realloc(L->data,newc*sizeof(int));
	if(newdata==NULL){
		printf("�ڴ����ʧ��\n");
		return false;
	}
	L->data=newdata;
	L->capicity=newc;
	printf("�ڴ������ɹ����µ��ڴ�Ϊ%d",L->capicity);
	return true;
	}
//��ӡ
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

