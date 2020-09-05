#include<stdio.h>
#include<stdlib.h>

typedef int Status;
Status ERROR = 500;
Status SUCCESS = 200;

typedef struct BiTreeNode{
	int data;
	struct BiTreeNode* lchild;
	struct BiTreeNode* rchild; 
}BiTreeNode, *BiTree;

Status CreateHuffmanTree(BiTree *forest, int n, BiTree &tree){
	for(int i = 0; i<n-1; i++){
		
		int mark1, mark2;
		mark1 = -1;
		for(int j = 0; j<n; j++){
			if(forest[j] != NULL && mark1 == -1){
				mark1 = j;
				continue;
			}
			else if(forest[j] != NULL){
				mark2 = j;
				break;
			}
		}
		
		for(int j = mark2; j<n; j++){//寻找当前森林中权值最小的两棵树 
			if(forest[j] != NULL){
				if(forest[j]->data < forest[mark1]->data){
					mark2 = mark1;
					mark1 = j;
				}
				else if(forest[j]->data < forest[mark2]->data){
					mark2 = j;
				}
			}
			else continue;
		}
		
		BiTree temp = (BiTree)malloc(sizeof(BiTreeNode));
		temp->data = forest[mark1]->data + forest[mark2]->data;
		temp->lchild = forest[mark1];
		temp->rchild = forest[mark2];
		forest[mark1] = temp;
		forest[mark2] = NULL;
		tree = temp;
	}
	return SUCCESS;
} 

int WeightPathLength(BiTree tree, int length){
	if(tree == NULL)return 0;
	else{
		if(tree->lchild == NULL && tree->rchild == NULL){
			return tree->data*length;
		}
		else return WeightPathLength(tree->lchild, length+1) + WeightPathLength(tree->rchild, length+1);
	}
}

int main(){
	int n, wpl;
	scanf("%d", &n);
	int array[n];// = {0};
	for(int i = 0; i<n; i++){
		scanf("%d", &array[i]);
	}
	BiTree forest[n], tree;//为什么*forest不行，是因为没分配空间吗？ 
	for(int i = 0; i<n; i++){
		forest[i] = (BiTree)malloc(sizeof(BiTreeNode));
		forest[i]->data = array[i];
		forest[i]->lchild = forest[i]->rchild = NULL;
	}
	CreateHuffmanTree(forest, n, tree);
//	free(forest);为什么不可以free 
	wpl = WeightPathLength(tree, 0);
	printf("%d", wpl);
	return 0;
} 
