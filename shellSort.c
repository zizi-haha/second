#include<stdio.h>
//希尔排序 
void shellSort(int arr[],int n){
	int gap=n/2;
	int i;
	while(gap>0){
		//从gap位置开始，每组进行插入排序
		 for(i=gap;i<n;i++){
		 	int temp=arr[i];
		 	int j=i;
		 	while(j>=gap&&arr[j-gap]>temp){
		 		arr[j]=arr[j-gap];
		 		j-=gap;
		}
		arr[j]=temp;
			
		 }
		 gap/=2;
	}


}

void printArry(int arr[],int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}

int main(){
	int arr[]={3,5,6,2,9,1};
	int n=sizeof(arr)/sizeof(int);
	printf("初始数组:\n");
	printArry(arr,n);
	shellSort(arr,n);
	printf("排序之后:\n");
	printArry(arr,n);
	return 0;
}