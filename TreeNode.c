#include<stdio.h>
#include<stdlib.h>
//�������ڵ�
typedef struct TreeNode{
	int data;
	struct TreeNode* left;
	struct TreeNode* right;
}TreeNode;
//�����½ڵ�
TreeNode* createNode(int data){
	TreeNode* newNode=(TreeNode*)malloc(sizeof(TreeNode));
	if(newNode==NULL){
		printf("�ڴ����ʧ��\n");
		exit(1);
	}
	newNode->data=data;
	newNode->left=NULL;
	newNode->right=NULL;
	return newNode;
} 
//����ڵ�
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
//�������
void preorderTraversal(TreeNode* root){
	if(root!=NULL){
	
		printf("%d ",root->data);
		preorderTraversal(root->left);
		preorderTraversal(root->right);
	}
} 
//�������
void inorderTraversal(TreeNode* root) {
	if(root!=NULL){
		inorderTraversal(root->left);
		printf("%d ",root->data);
		inorderTraversal(root->right);
	}
}
//�������
void postorderTraversal(TreeNode* root){
	if(root!=NULL){
	postorderTraversal(root->left);
	postorderTraversal(root->right);
	printf("%d ",root->data);
	}
} 
//���ҽڵ�
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
//������С�ڵ�
TreeNode* findMin(TreeNode* root){
	while(root!=NULL&&root->left!=NULL){
		root=root->left;
	}
	return root;
} 
//ɾ���ڵ�
TreeNode* deleteNode(TreeNode* root,int value){
	if(root==NULL){
		return root;
	}
	if(value<root->data){
		root->left=deleteNode(root->left,value);
	}else if(root->data<value){
		root->right=deleteNode(root->right,value);
	}else{
		//�ҵ�Ҫɾ���Ľڵ� 
		//1.ֻ��һ���ӽڵ����û���ӽڵ� 
		if(root->left==NULL){
			TreeNode* tep=root->right;
			free(root);
			return tep;
		}else if(root->right==NULL){
			TreeNode* temp=root->left;
			free(root);
			return temp;
		}
		//2.�������ӽڵ�
		TreeNode* temp=findMin(root->right);
		root->data=temp->data;
		root->right=deleteNode(root->right,temp->data); 
		
	}
	return root;
} //д�����������˼�ֱ�����`````` 
//�������ĸ߶�
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
//����ڵ�����
int countNodes(TreeNode* root){
	if(root==NULL){
		return 0;
		
	}
	return 1+countNodes(root->left)+countNodes(root->right);
} 
//���ٶ�����
void destoryTree(TreeNode* root){
	if(root!=NULL){
		destoryTree(root->left);
		destoryTree(root->right);
		free(root);
	}
} 
int main() {
    TreeNode* root = NULL;
    
    // ����ڵ�
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);
    
    printf("������������ʾ:\n");
    
    // ����
    printf("�������: ");
    preorderTraversal(root);
    printf("\n");
    
    printf("�������: ");
    inorderTraversal(root);
    printf("\n");
    
    printf("�������: ");
    postorderTraversal(root);
    printf("\n");
    
    // ����
    int searchValue = 40;
    TreeNode* found = searchNode(root, searchValue);
    if (found != NULL) {
        printf("�ҵ��ڵ� %d\n", searchValue);
    } else {
        printf("δ�ҵ��ڵ� %d\n", searchValue);
    }
    
    // ������Ϣ
    printf("���ĸ߶�: %d\n", treeHeight(root));
    printf("�ڵ�����: %d\n", countNodes(root));
    
    // ɾ���ڵ�
    printf("ɾ���ڵ� 20\n");
    root = deleteNode(root, 20);
    printf("������� after deletion: ");
    inorderTraversal(root);
    printf("\n");
    
    // �����ڴ�
    destoryTree(root);
    
    return 0;
}