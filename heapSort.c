#include<stdio.h>
#include<stdlib.h>
void swap(int* a,int *b){
	int t=*a;
	*a=*b;
	*b=t;
} 
//调整堆，使其满足堆的性质
//n:堆的大小
//i:当前需要调整的节点索引 
void heapify(int arr[],int n,int i){
	int largest=i;
	int left=2*i+1;
	int right=2*i+2;
	//如果左子节点存在且大于根节点
	if(left<n&&arr[left]>arr[largest]){
		largest=left;
	} 
	//如果右子节点存在大v
	if(right<n&&arr[right]>arr[largest]) {
		largest=right;
	}
	if(largest!=i){
		swap(&arr[i],&arr[largest]);
		heapify(arr,n,largest); 
	}
	
} 
//堆排序
void heapSort(int arr[],int n){
	//构建最大堆
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
	printf("初始数组:\n");
	printList(arr,n);
	heapSort(arr,n);
	printf("排序后：\n");
	printList(arr,n);
	return 0;
}