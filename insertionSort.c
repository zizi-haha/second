//插入排序
#include<stdio.h>
void insertionSort(int arr[],int n){
	int i,j,k;
	for(i=1;i<n;i++){
		k=arr[i];
		j=i-1;
		while(j>=0&&k<arr[j]){
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=k;
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
	int arr[]={3,5,6,7,3,8,2,3,1};
	int n=sizeof(arr)/sizeof(arr[0]);
	printf("初始数组：\n");
	printArry(arr,n);
	insertionSort(arr,n);
	printf("排序后的数组：\n");
	printArry(arr,n);
	return 0;
}