#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct TreeNode{
	int data;
	struct TreeNode* firstChoild;
	struct TreeNode* nextSibling;
}TreeNode;
//森林结构体定义 
typedef struct{
	TreeNode** trees;//指向树根节点的指针数组
	int count; //树的数量 
	
}Forest;

//创建新节点
TreeNode* creatNode(int data){
	TreeNode* newNode=(TreeNode*)malloc(sizeof(TreeNode));
	if(newNode==NULL){
		printf("内存分配失败\n");
		exit(1);
	}
	newNode->data=data;
	newNode->firstChoild=NULL;
	newNode->nextSibling=NULL;
	return newNode;
} 
//创建森林
  //10           20  	     	 30
//5   15  		25  	   28    40
//  12  18       26       29  35
Forest createSampleForest(){
	Forest forest;
	forest.count=3;
	forest.trees=(TreeNode**)malloc(forest.count*sizeof(TreeNode*));
	//创建第一棵树
	TreeNode* tree1=creatNode(10);
	tree1->firstChoild=creatNode(5);
	tree1->firstChoild->nextSibling=creatNode(15);
	tree1->firstChoild->nextSibling->firstChoild=creatNode(12);
	tree1->firstChoild->nextSibling->firstChoild->nextSibling=creatNode(18);
	//创建第二棵树
	TreeNode* tree2=creatNode(20);
	tree2->firstChoild=creatNode(25);
	tree2->firstChoild->nextSibling=creatNode(26);
	//创建第三个节点
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
//先序遍历 ！！！！！！！！！回头要再看一遍 
void preOrderTraversal(TreeNode** root,int depth){
	if(root==NULL){
		return;
		
	}
	int i=0;
	//打印缩进，显示层次结构 
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
//遍历整个森林
void traverseFroest(Forest forest){
	printf("===森林遍历===\n");
	int i=0;
	for(;i<forest.count;i++){
		printf("第%d棵树遍历：\n",i+1);
		preOrderTraversal(&forest.trees[i],0);
		printf("\n");
	}
}
//在森林中查找节点!!!!!!!需要再读一遍 
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
//像树中添加子节点//兄弟链 
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
//像森林中添加新树
void addTreeToForest(Forest* forest,int rootData){
	TreeNode* newTree=creatNode(rootData);
	forest->trees=(TreeNode**)realloc(forest->trees,(forest->count+1)*sizeof(TreeNode*));
	forest->trees[forest->count]=newTree;
	forest->count++;
} 
//计算树的高度!!!!!!回头重看 (＜（＾－＾）＞看懂了） 
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
//计算树的节点
int TreeNodeCount(TreeNode* root){
	if(root==NULL)return 0;
	int count=1;//计算当前节点
	TreeNode*  child=root->firstChoild;
	while(child!=NULL){
		count+=TreeNodeCount(child);
		child=child->nextSibling; 
	} 
	return count;
} 
//显示森林统计信息
void showForestStats(Forest forest){
	printf("====森林统计===\n");
	printf("森林中包含%d棵树\n",forest.count);
	int total=0;
	int i=0;
	for(;i<forest.count;i++){
		int h=treeHeight(forest.trees[i]);
		int k=TreeNodeCount(forest.trees[i]);
		printf("树%d:节点数=%d,高度=%d\n",i+1,k,h);
		total+=k;
	}
	printf("总结点数=%d\n",total);
} 
//释放单颗树的内存
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
//释放整个森林的内存
void freeForest(Forest forest){
	int i=0;
		for(;i<forest.count;i++){
			freeTree(forest.trees[i]);
}
	free(forest.trees); 
}
//交互式菜单
void display(){
	printf("\n====森林操作菜单====\n");
	printf("1.显示森林结构\n");
	printf("2.显示森林统计信息\n");
	printf("3.查找节点\n");
	printf("4.添加子节点\n");
	printf("5.添加新树\n");
	printf("6.退出\n");
	printf("请选择:\n");
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
				printf("请输入要查找的节点值：\n");
				scanf("%d",&t);
				TreeNode* n=findNodeInForest(forest,t);
				if(n!=NULL){
					printf("找到节点%d",n->data);
					
				}else{
					printf("没找到\n");
				}
				break;
			}
			
			case 4:
				{
					int l,k;
					printf("请输入父节点的值:\n");
					scanf("%d",&l);
					printf("请输入子节点的值:\n");
					scanf("%d",&k);
					TreeNode* h=findNodeInForest(forest,l);
					if(h!=NULL){
						addChildToNode(h,k);
						printf("已添加\n");
					}else{
						printf("meizhaodao \n");
					}
					break;
				}
			case 5:{
				int rootdata;
				printf("请输入新树的根节点值：\n");
				scanf("%d",&rootdata);
				addTreeToForest(&forest,rootdata);
				printf("已添加%d为根节点的树",rootdata);
				break;
			}
				
			case 6:
				printf("结束！");
				break;
			default:
				printf("无效\n");
				break;
				
	}}while(c!=6);



	freeForest(forest);
	return 0;
}