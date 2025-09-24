#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define maxsize 100
//串的基本表示和初始化 
typedef struct {
	char data[maxsize];
	int length;
}String;
//初始化串
void initString(String *str,const char *chars){
	int len=strlen(chars);
	if(len>=maxsize){
		len=maxsize-1;
	}
	strncpy(str->data,chars,len);
	str->data[len]='\0';
	str->length=len;
} 
//打印�?
void printString(const String *str){
	printf("%s 长度�?%d",str->data,str->length);
} 
//串连�?
String concatString(String *str1,String* str2){
	String r;
	r.length=0;
	int i,j;
	for(i=0;i<str1->length&&i<maxsize;i++){
		r.data[i]=str1->data[i];
		r.length++;
	}
	for(j=0;j<str2->length&&j<maxsize;j++,i++){
		r.data[i]=str2->data[j];
		r.length++;
	}
	r.data[i]='\0';
	return r;
} 
//字串查找
int findSubString(String* str,String* subString){
	if(str->length<subString->length)return -1;
	int i,j;
	for(i=0;i<maxsize&&i<str->length;i++){
		for(j=0;j<subString->length;j++){
			if(str->data[i+j]!=subString->data[j]){
				break;
			}
			
			}
			if(j==subString->length){
				return i;
			
		}
		
	}
	return -1;
}
//串比�?
int compareString(String *str1,String *str2){
	int min=(str1->length<str2->length)?str1->length:str2->length;
	int i=0;
	for(;i<min;i++){
		if(str1->data[i]!=str2->data[i]){
			return str1->data[i]-str2->data[i];
		}
	}
	return str1->length-str2->length;
} 


//=====数组======
//一维数组基本操�?
 void printArray(int arr[],int size){
 	printf("数组元素:");
 	int i=0;
 	for(;i<size;i++){
 		printf("%d ",arr[i]);
	 }
	 printf("\n");
 }
 
 //二维数组基本操作
 void print2DArry(int row,int cols,int arr[row][cols]){
 	printf("二维数组：\n");
 	int i,j;
 	for(i=0;i<row;i++){
 		for(j=0;j<cols;j++){
 			printf("%d ",arr[i][j]);
		 } 
		 printf("\n");
 }} 
 //矩阵转置
 void transposeMatrix(int row,int cols,int src[row][cols],int dest[row][cols]){
 	int i,j;
 	for(i=0;i<row;i++){
 		for(j=0;j<cols;j++){
 			dest[i][j]=src[j][i];
		 }
	 }
 } 
 //稀疏矩阵的压缩储存
 typedef struct{
 	int row,col,value;
 	
 }Triple;
 
 typedef struct{
 	Triple data[maxsize];
 	int row,cols,num;//行数，列数，非零元素个数 
 }SpareMstrix;
 
 //创建稀疏矩�?
 void creatSpareMstrix(int row,int cols,int matrix[row][cols],SpareMstrix *spare){
 	spare->row=row;
 	spare->cols=cols;
 	spare->num=0;
 	int i,j;
 	for(i=0;i<row;i++){
 		for(j=0;j<cols;j++){
 			if(matrix[i][j]!=0){
 				spare->data[spare->num].row=i;
 					spare->data[spare->num].col=j;
 						spare->data[spare->num].value=matrix[i][j];
 				spare->num++;
			 }
		 }
	 }
 } 
 //打印
 void printSpaeMatrix(SpareMstrix*spare){
 	printf("稀疏矩阵（%d%d,非零元素:\n",spare->row,spare->cols,spare->num);
 	printf("行\t列\t值\n");
 	int i;
 	for(i=0;i<spare->num;i++){
 		printf("%d\t%d\t\%d\n",spare->data[i].row,spare->data[i].col,spare->data[i].value);
 }
}
 
 
 
 
 //字符串反�?
 void reserve(String *str){
 	int i,j;
 	char k; 
 	i=0;j=str->length-1;
 	while(i<j){
 		k=str->data[i];
 		str->data[i]=str->data[j];
 		str->data[j]=k;
 		i++;
 		j--;
	 }
 } 
 //判断回文字符�?
 bool isPalindrom(String*str){
 	int i=0,j=str->length-1;
 	while(i<j){
 		if(str->data[i]!=str->data[j])return false;
 		i++;
 		j--;
	 }
	 return true;
 } 
 //数组元素查找
 int search(int arr[],int size,int target){
 	int i; 
 	for ( i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
 } 
 //冒泡排序
 void bubbleSort(int arr[],int size){
 	int i;
 	int j,k;
 	for(i=0;i<size;i++){
 		for(j=0;j<size-i;j++){
 			if(arr[j]>arr[j+1]){
 				k=arr[j+1];
 				arr[j+1]=arr[j];
 				arr[j]=k;
			 }
		 }
	 }
 } 
 
 int main(){
 	printf("=======数据结构：串与数组演�?======\n");
 	//�?
	 printf("串操作演�?==\n");
	 printf("---------------\n");
	 String str1,str2,str3;
	 initString(&str1,"hello");
	 initString(&str2,"world"); 
	 printf("原始字符串\n");
	 printString(&str1);
	 printString(&str2);
	 //字符串链�?
	 str3=concatString(&str1,&str2);
	 printf("连接后的：\n");
	 printString(&str3);
	 //字串查找
	 String subStr;
	 initString(&subStr,"llo");
	 int pos=findSubString(&str1,&subStr);
	 printf("\n字串'%s'�?'%s'中的位置�?%d\n",subStr.data,str1.data,pos);
	  
	  // 字符串比�?
    String str4;
    initString(&str4, "Hello");
    int cmpResult = compareString(&str1, &str4);
    printf("字符串比�? '%s' �? '%s': %d (0表示相等)\n", str1.data, str4.data, cmpResult);
    
    // 字符串反�?
    reserve(&str1);
    printf("反转后的字符�?: %s\n", str1.data);
    reserve(&str1); // 恢复原状
    
    // 判断回文
    String palindromeStr;
    initString(&palindromeStr, "racecar");
    printf("'%s' 是回文字符串�?? %s\n", palindromeStr.data, 
           isPalindrom(&palindromeStr) ? "�?" : "�?");
    
    // ==================== 数组操作演示 ====================
    printf("\n2. 数组操作演示:\n");
    printf("----------------\n");
    
    // 一维数�?
    int arr[] = {5, 2, 8, 1, 9, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    printf("原始数组:\n");
    printArray(arr, size);
    
    // 数组查找
    int target = 8;
    int index = search(arr, size, target);
    printf("元素 %d 在数组中的位�?: %d\n", target, index);
    
    // 数组排序
    bubbleSort(arr, size);
    printf("排序后的数组:\n");
    printArray(arr, size);
    
    // 二维数组和矩阵操�?
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    printf("\n原始矩阵:\n");
    print2DArry(3, 3, matrix);
    
    // 矩阵转置
    int transposed[3][3];
    transposeMatrix(3, 3, matrix, transposed);
    printf("\n转置后的矩阵:\n");
    print2DArry(3, 3, transposed);
    
    // 稀疏矩�?
    int sparseMatrix[4][5] = {
        {0, 0, 3, 0, 4},
        {0, 0, 5, 7, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 6, 0, 0}
    };
    
    printf("\n原始矩阵（稀疏）:\n");
    print2DArry(4, 5, sparseMatrix);
    
    SpareMstrix sparse;
    creatSpareMstrix(4, 5, sparseMatrix, &sparse);
    printSpaeMatrix(&sparse);
    
    printf("\n========== 演示结束 ==========\n");
    
    return 0;
}
 