#include<stdio.h>
void swap(int *a,int *b){
	int t=*a;
	*a=*b;
	*b=t; 
}
int partition(int arr[],int low,int high){
	int pivot=arr[(low+high)/2];
	//ѡ���м�Ԫ��Ϊ����
	int i=low-1;
	int j=high+1;
	
	while(1){
		do{
			i++;
		}while(arr[i]<pivot);//���������ҵ���һ�����ڵ��ڻ�׼��Ԫ��
		do{
			j--;
		} while(arr[j]>pivot);
		if(i>=j){
			return j;
		}//���ָ�����������ط�����
		swap(&arr[i],&arr[j]);
		//����������������������Ԫ�� 
	} 
} 

void quickSort(int arr[],int low,int high){
	if(low<high){
		//pi�Ƿ�������
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
	printf("ԭʼ����:\n");
	printArry(arr,n);
	quickSort(arr,0,n-1);
	printf("����������:\n");
	printArry(arr,n);
	return 0; 
}
