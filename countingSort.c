#include<stdio.h>
#include<stdlib.h>
//��������
void countingSort(int arr[],int n){
	//�ҳ������е����ֵ����Сֵ
	int max=arr[0],min=arr[0]; 
	int i=0;
	for(;i<n;i++){
		if(arr[i]<min){
			min=arr[i];
		}
		if(arr[i]>max){
			max=arr[i];
		}
	} 
	//�����������Ĵ�С
	int range=max-min+1;
	//������������
	int* count=(int*)calloc(range,sizeof(int));//? 
	//�����������
	int* output=(int*)malloc(n*sizeof(int));
	//ͳ��ÿ��Ԫ�س��ֵĴ���
	for(i=0;i<n;i++){
		count[arr[i]-min]++;
	}
	//����count[i]��ʹ�����С�ڵ���i��Ԫ�ظ���
	for(i=1;i<range;i++){
		count[i]+=count[i-1];
	} 
	//�����������,arr-min������λ�� 
	for(i=n-1;i>=0;i--){
		output[count[arr[i]-min]-1]=arr[i];
		count[arr[i]-min]--;
	} 
	for(i=0;i<n;i++){
		arr[i]=output[i];
	}
	free(count);
	free(output);
	 
} 

void printArry(int arr[],int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}
int main(){
	int arr[]={99,93,95,92,96,90};
	int n=sizeof(arr)/sizeof(int);
	printf("��ʼ���飺\n");
	printArry(arr,n);
	printf("�����\n");
	countingSort(arr,n);
	printArry(arr,n);
	return 0;
}