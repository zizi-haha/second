#include<stdio.h>
#include<stdlib.h>
//计数排序
void countingSort(int arr[],int n){
	//找出数组中的最大值和最小值
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
	//计算计数数组的大小
	int range=max-min+1;
	//创建技术数组
	int* count=(int*)calloc(range,sizeof(int));//? 
	//创建输出数组
	int* output=(int*)malloc(n*sizeof(int));
	//统计每个元素出现的次数
	for(i=0;i<n;i++){
		count[arr[i]-min]++;
	}
	//更改count[i]，使其包含小于等于i的元素个数
	for(i=1;i<range;i++){
		count[i]+=count[i-1];
	} 
	//构建输出数组,arr-min是索引位置 
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
	printf("初始数组：\n");
	printArry(arr,n);
	printf("排序后：\n");
	countingSort(arr,n);
	printArry(arr,n);
	return 0;
}