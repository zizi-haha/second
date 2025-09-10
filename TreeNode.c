#include<stdio.h>
#include<stdlib.h>
//二叉树节点
typedef struct TreeNode{
	int data;
	struct TreeNode* left;
	struct TreeNode* right;
}TreeNode;
//创建新节点
TreeNode* createNode(int data){
	TreeNode* newNode=(TreeNode*)malloc(sizeof(TreeNode));
	if(newNode==NULL){
		printf("内存分配失败\n");
		exit(1);
	}
	newNode->data=data;
	newNode->left=NULL;
	newNode->right=NULL;
	return newNode;
} 
//插入节点
TreeNode* insertNode(TreeNode* root,int value){
	if(root==NULL){
		return createNode(value);
		
	}
	if(value<root->data){
		root->left=insertNode(root->left,value);
	}else if(root->data<value){
		root->right=insertNode(root->right,value);
	}	
	return root;
} 
//先序遍历
void preorderTraversal(TreeNode* root){
	if(root!=NULL){
	
		printf("%d ",root->data);
		preorderTraversal(root->left);
		preorderTraversal(root->right);
	}
} 
//中序遍历
void inorderTraversal(TreeNode* root) {
	if(root!=NULL){
		inorderTraversal(root->left);
		printf("%d ",root->data);
		inorderTraversal(root->right);
	}
}
//后序遍历
void postorderTraversal(TreeNode* root){
	if(root!=NULL){
	postorderTraversal(root->left);
	postorderTraversal(root->right);
	printf("%d ",root->data);
	}
} 
//查找节点
TreeNode* searchNode(TreeNode* root,int value){
	if(root==NULL||root->data==value){
		return root;
	}
	if(value<root->data){
		return searchNode(root->left,value);
	}else{
		return searchNode(root->right,value);
	}
} 
//查找最小节点
TreeNode* findMin(TreeNode* root){
	while(root!=NULL&&root->left!=NULL){
		root=root->left;
	}
	return root;
} 
//删除节点
TreeNode* deleteNode(TreeNode* root,int value){
	if(root==NULL){
		return root;
	}
	if(value<root->data){
		root->left=deleteNode(root->left,value);
	}else if(root->data<value){
		root->right=deleteNode(root->right,value);
	}else{
		//找到要删除的节点 
		//1.只有一个子节点或者没有子节点 
		if(root->left==NULL){
			TreeNode* tep=root->right;
			free(root);
			return tep;
		}else if(root->right==NULL){
			TreeNode* temp=root->left;
			free(root);
			return temp;
		}
		//2.有两个子节点
		TreeNode* temp=findMin(root->right);
		root->data=temp->data;
		root->right=deleteNode(root->right,temp->data); 
		
	}
	return root;
} //写出这个程序的人简直是天才`````` 
//计算树的高度
int treeHeight(TreeNode* root){
	if(root==NULL){
		return 0;
	}
	else{
		int l=treeHeight(root->left);
		int r=treeHeight(root->right);
		return(l>r)?l+1:r+1;
	}
} 
//计算节点总数
int countNodes(TreeNode* root){
	if(root==NULL){
		return 0;
		
	}
	return 1+countNodes(root->left)+countNodes(root->right);
} 
//销毁二叉树
void destoryTree(TreeNode* root){
	if(root!=NULL){
		destoryTree(root->left);
		destoryTree(root->right);
		free(root);
	}
} 
int main() {
    TreeNode* root = NULL;
    
    // 插入节点
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);
    
    printf("二叉树操作演示:\n");
    
    // 遍历
    printf("先序遍历: ");
    preorderTraversal(root);
    printf("\n");
    
    printf("中序遍历: ");
    inorderTraversal(root);
    printf("\n");
    
    printf("后序遍历: ");
    postorderTraversal(root);
    printf("\n");
    
    // 搜索
    int searchValue = 40;
    TreeNode* found = searchNode(root, searchValue);
    if (found != NULL) {
        printf("找到节点 %d\n", searchValue);
    } else {
        printf("未找到节点 %d\n", searchValue);
    }
    
    // 树的信息
    printf("树的高度: %d\n", treeHeight(root));
    printf("节点总数: %d\n", countNodes(root));
    
    // 删除节点
    printf("删除节点 20\n");
    root = deleteNode(root, 20);
    printf("中序遍历 after deletion: ");
    inorderTraversal(root);
    printf("\n");
    
    // 清理内存
    destoryTree(root);
    
    return 0;
}