#include<stdio.h>
//ϣ������ 
void shellSort(int arr[],int n){
	int gap=n/2;
	int i;
	while(gap>0){
		//��gapλ�ÿ�ʼ��ÿ����в�������
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
	printf("��ʼ����:\n");
	printArry(arr,n);
	shellSort(arr,n);
	printf("����֮��:\n");
	printArry(arr,n);
	return 0;
}