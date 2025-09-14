#include<stdio.h>
void swap(int *a,int *b){
	int t=*a;
	*a=*b;
	*b=t; 
}
int partition(int arr[],int low,int high){
	int pivot=arr[(low+high)/2];
	//选择中间元素为集中
	int i=low-1;
	int j=high+1;
	
	while(1){
		do{
			i++;
		}while(arr[i]<pivot);//从左往右找到第一个大于等于基准的元素
		do{
			j--;
		} while(arr[j]>pivot);
		if(i>=j){
			return j;
		}//如果指针相遇，返回分区点
		swap(&arr[i],&arr[j]);
		//交换这两个不符合条件的元素 
	} 
} 

void quickSort(int arr[],int low,int high){
	if(low<high){
		//pi是分区索引
		int pi=partition(arr,low,high);
		
		quickSort(arr,low,pi);
		quickSort(arr,pi+1,high); 
	}
}

//print

void printArry(int arr[],int size){
	int i=0;
	for(i=0;i<size;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}

int main(){
	int arr[]={10,8,9,3,7,4,2,1};
	int n=sizeof(arr)/sizeof(arr[0]);
	printf("原始数组:\n");
	printArry(arr,n);
	quickSort(arr,0,n-1);
	printf("排序后的数组:\n");
	printArry(arr,n);
	return 0; 
}
