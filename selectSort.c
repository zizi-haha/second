//ѡ������
#include<stdio.h>
void selectionSort(int arr[],int n){
	int i,j,min_idx,temp;
	for(i=0;i<n-1;i++){
		min_idx=i;
		for(j=i+1;j<n;j++){
			if(arr[j]<arr[min_idx]){
				min_idx=j;//
			}
			
		}
		if(min_idx!=i){
			temp=arr[i];
			arr[i]=arr[min_idx];
			arr[min_idx]=temp;
		}
	}
} 
void printArry(int arr[],int n){
	int i=0;
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
		
	}
	printf("\n");
}
int main(){
	int arr[]={4,5,2,6,2,9,8,0};
	int n=sizeof(arr)/sizeof(arr[0]);
	printf("��ӡԭ����:\n");
	printArry(arr,n);
	selectionSort(arr,n);
	printf("����������:\n");
	printArry(arr,n);
	return 0;
}