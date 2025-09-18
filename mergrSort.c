#include<stdlib.h>
void merge(int arr[],int left,int mid,int right){
	int i,j,k;
	int n1=mid-left+1;
	int n2=right-mid;
	//������ʱ����
	int* L=(int*)malloc(n1*sizeof(int));
	int *R=(int*)malloc(n2*sizeof(int));
	
	//�������ݵ���ʱ����
	for(i=0;i<n1;i++){
		L[i]=arr[i+left]; 
	} 
	for(i=0;i<n2;i++){
		R[i]=arr[1+mid+i];
		
	}
	//�ϲ���ԭ��������
	i=0,j=0,k=left;
	while(i<n1 && j<n2){
		if(L[i]<=R[j]){
			arr[k]=L[i];
			i++;
		}else{
			arr[k]=R[j];
			j++;
		}
		k++;
		}
		while(i<n1){
			arr[k]=L[i];
			i++;
			k++;
		}
		while(j<n2){
			arr[k]=R[j];
			j++;
			k++;
		}
	free(L);
	free(R);
}
void mergrSort(int arr[],int left,int right){
	if(left<right){
		int mid=left+(right-left)/2;//?
		mergrSort(arr,left,mid);
		mergrSort(arr,mid+1,right);
		//�ϲ�
		merge(arr,left,mid,right); 
	}
	
} 
void printArry(int arr[],int n){
	int i=0;
	while(i<n){
		printf("%d ",arr[i]);
		i++;
	}
	printf("\n");
}
int main(){
	int arr[]={5,6,8,3,0,8,9,9,2};
	int n=(sizeof(arr))/sizeof(int);
	printf("��ʼ����:\n");
	printArry(arr,n);
	printf("�����\n");
	mergrSort(arr,0,n-1);
	printArry(arr,n);
	return 0;
}