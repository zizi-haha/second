#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct TreeNode{
	int data;
	struct TreeNode* firstChoild;
	struct TreeNode* nextSibling;
}TreeNode;
//ɭ�ֽṹ�嶨�� 
typedef struct{
	TreeNode** trees;//ָ�������ڵ��ָ������
	int count; //�������� 
	
}Forest;

//�����½ڵ�
TreeNode* creatNode(int data){
	TreeNode* newNode=(TreeNode*)malloc(sizeof(TreeNode));
	if(newNode==NULL){
		printf("�ڴ����ʧ��\n");
		exit(1);
	}
	newNode->data=data;
	newNode->firstChoild=NULL;
	newNode->nextSibling=NULL;
	return newNode;
} 
//����ɭ��
  //10           20  	     	 30
//5   15  		25  	   28    40
//  12  18       26       29  35
Forest createSampleForest(){
	Forest forest;
	forest.count=3;
	forest.trees=(TreeNode**)malloc(forest.count*sizeof(TreeNode*));
	//������һ����
	TreeNode* tree1=creatNode(10);
	tree1->firstChoild=creatNode(5);
	tree1->firstChoild->nextSibling=creatNode(15);
	tree1->firstChoild->nextSibling->firstChoild=creatNode(12);
	tree1->firstChoild->nextSibling->firstChoild->nextSibling=creatNode(18);
	//�����ڶ�����
	TreeNode* tree2=creatNode(20);
	tree2->firstChoild=creatNode(25);
	tree2->firstChoild->nextSibling=creatNode(26);
	//�����������ڵ�
	TreeNode* tree3=creatNode(30);
	tree3->firstChoild=creatNode(28);
	tree3->firstChoild->nextSibling=creatNode(40);
	tree3->firstChoild->firstChoild=creatNode(29);
	tree3->firstChoild->firstChoild->nextSibling=creatNode(35);
	forest.trees[0]=tree1;
	forest.trees[1]=tree2;
	forest.trees[2]=tree3;
	return forest;
	 
} 
//������� ��������������������ͷҪ�ٿ�һ�� 
void preOrderTraversal(TreeNode** root,int depth){
	if(root==NULL){
		return;
		
	}
	int i=0;
	//��ӡ��������ʾ��νṹ 
	for(;i<depth;i++){
		printf(" ");
	}
	printf("%d\n",(*root)->data);
	TreeNode* child=(*root)->firstChoild;
	while(child!=NULL){
		preOrderTraversal(&child,depth+1);
		child=child->nextSibling;
	}
}
//��������ɭ��
void traverseFroest(Forest forest){
	printf("===ɭ�ֱ���===\n");
	int i=0;
	for(;i<forest.count;i++){
		printf("��%d����������\n",i+1);
		preOrderTraversal(&forest.trees[i],0);
		printf("\n");
	}
}
//��ɭ���в��ҽڵ�!!!!!!!��Ҫ�ٶ�һ�� 
TreeNode* findNodeInTree(TreeNode* root,int target){
	if(root==NULL)return NULL;
	if(root->data==target){
		return root;
	}
	TreeNode* result=NULL;
	TreeNode* child=root->firstChoild;
	while(child!=NULL&&result==NULL){
		result=findNodeInTree(child,target);
		child=child->nextSibling; 
	}
	return result;
} 
TreeNode* findNodeInForest(Forest forest,int target){
	int i=0;
	for(;i<forest.count;i++){
		TreeNode* result=findNodeInTree(forest.trees[i],target);
		if(result!=NULL)return result;
	}
	return NULL;
}
//����������ӽڵ�//�ֵ��� 
void addChildToNode(TreeNode* parent,int data){
	if(parent==NULL)return;
	TreeNode* newchild=creatNode(data);
	if(parent->firstChoild==NULL){
		parent->firstChoild=newchild;
	}else{
		TreeNode* lastchild=parent->firstChoild;
		while(lastchild->nextSibling!=NULL){
			lastchild=lastchild->nextSibling;
			
		}
		lastchild->nextSibling=newchild;
	}
} 
//��ɭ�����������
void addTreeToForest(Forest* forest,int rootData){
	TreeNode* newTree=creatNode(rootData);
	forest->trees=(TreeNode**)realloc(forest->trees,(forest->count+1)*sizeof(TreeNode*));
	forest->trees[forest->count]=newTree;
	forest->count++;
} 
//�������ĸ߶�!!!!!!��ͷ�ؿ� (�����ޣ��ޣ��������ˣ� 
int treeHeight(TreeNode* root){
	if(root==NULL)return 0;
	int max=0;
	TreeNode* node=root->firstChoild;
	while(node!=NULL){
		int h=treeHeight(node);
		if(h>max)max=h;
		node=node->nextSibling; 
	}
	return max+1;
} 
//�������Ľڵ�
int TreeNodeCount(TreeNode* root){
	if(root==NULL)return 0;
	int count=1;//���㵱ǰ�ڵ�
	TreeNode*  child=root->firstChoild;
	while(child!=NULL){
		count+=TreeNodeCount(child);
		child=child->nextSibling; 
	} 
	return count;
} 
//��ʾɭ��ͳ����Ϣ
void showForestStats(Forest forest){
	printf("====ɭ��ͳ��===\n");
	printf("ɭ���а���%d����\n",forest.count);
	int total=0;
	int i=0;
	for(;i<forest.count;i++){
		int h=treeHeight(forest.trees[i]);
		int k=TreeNodeCount(forest.trees[i]);
		printf("��%d:�ڵ���=%d,�߶�=%d\n",i+1,k,h);
		total+=k;
	}
	printf("�ܽ����=%d\n",total);
} 
//�ͷŵ��������ڴ�
void freeTree(TreeNode* root){
	if(root==NULL)return;
	TreeNode* current=root->firstChoild;
	TreeNode* n;
	while(current!=NULL){
		n=current->nextSibling;
		freeTree(current);
		current=n;
	}
	free(root);
} 
//�ͷ�����ɭ�ֵ��ڴ�
void freeForest(Forest forest){
	int i=0;
		for(;i<forest.count;i++){
			freeTree(forest.trees[i]);
}
	free(forest.trees); 
}
//����ʽ�˵�
void display(){
	printf("\n====ɭ�ֲ����˵�====\n");
	printf("1.��ʾɭ�ֽṹ\n");
	printf("2.��ʾɭ��ͳ����Ϣ\n");
	printf("3.���ҽڵ�\n");
	printf("4.����ӽڵ�\n");
	printf("5.�������\n");
	printf("6.�˳�\n");
	printf("��ѡ��:\n");
} 

int main(){
	Forest forest= createSampleForest();
	int c;
	do{
		display();
		scanf("%d",&c);
		switch(c){
			case 1:traverseFroest(forest);
				break;
			case 2:showForestStats(forest);
				break;
			case 3:{
				int t;
				printf("������Ҫ���ҵĽڵ�ֵ��\n");
				scanf("%d",&t);
				TreeNode* n=findNodeInForest(forest,t);
				if(n!=NULL){
					printf("�ҵ��ڵ�%d",n->data);
					
				}else{
					printf("û�ҵ�\n");
				}
				break;
			}
			
			case 4:
				{
					int l,k;
					printf("�����븸�ڵ��ֵ:\n");
					scanf("%d",&l);
					printf("�������ӽڵ��ֵ:\n");
					scanf("%d",&k);
					TreeNode* h=findNodeInForest(forest,l);
					if(h!=NULL){
						addChildToNode(h,k);
						printf("�����\n");
					}else{
						printf("meizhaodao \n");
					}
					break;
				}
			case 5:{
				int rootdata;
				printf("�����������ĸ��ڵ�ֵ��\n");
				scanf("%d",&rootdata);
				addTreeToForest(&forest,rootdata);
				printf("�����%dΪ���ڵ����",rootdata);
				break;
			}
				
			case 6:
				printf("������");
				break;
			default:
				printf("��Ч\n");
				break;
				
	}}while(c!=6);



	freeForest(forest);
	return 0;
}