#include<stdio.h>
#include<stdlib.h>
void swap(int* a,int *b){
	int t=*a;
	*a=*b;
	*b=t;
} 
//�����ѣ�ʹ������ѵ�����
//n:�ѵĴ�С
//i:��ǰ��Ҫ�����Ľڵ����� 
void heapify(int arr[],int n,int i){
	int largest=i;
	int left=2*i+1;
	int right=2*i+2;
	//������ӽڵ�����Ҵ��ڸ��ڵ�
	if(left<n&&arr[left]>arr[largest]){
		largest=left;
	} 
	//������ӽڵ���ڴ�v
	if(right<n&&arr[right]>arr[largest]) {
		largest=right;
	}
	if(largest!=i){
		swap(&arr[i],&arr[largest]);
		heapify(arr,n,largest); 
	}
	
} 
//������
void heapSort(int arr[],int n){
	//��������
	int i=n;
	for(i=n/2-1;i>=0;i--){
		heapify(arr,n,i);
	} 
	for(i=n-1;i>0;i--){
		swap(&arr[0],&arr[i]);
		heapify(arr,i,0);
	}
} 
//dayin
void printList(int arr[],int n){
	int i=0;
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	} 
	printf("\n");
}
int main(){
	int arr[]={4,6,3,8,9,10,10};
	int n=sizeof(arr)/sizeof(int);
	printf("��ʼ����:\n");
	printList(arr,n);
	heapSort(arr,n);
	printf("�����\n");
	printList(arr,n);
	return 0;
}