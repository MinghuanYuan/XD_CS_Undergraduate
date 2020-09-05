#include<stdio.h>
#include<stdlib.h>

typedef struct BiTreeNode{
	int data;
	int location;
	struct BiTreeNode* lchild;
	struct BiTreeNode* rchild; 
}BiTreeNode, *BiTree;

int Partition(int array[], int low, int high, BiTree root);
void QuickSort(int array[], int low, int high, BiTree root){
	if(low < high){
		int pivotloc = Partition(array, low, high, root);
		QuickSort(array, low, pivotloc-1, root->rchild);
		QuickSort(array, pivotloc+1, high, root->lchild);
	} 
}

int Partition(int array[], int low, int high, BiTree root){
	int pivotkey = array[low];
	while(low < high){
		while(low < high && array[high] >= pivotkey)high--;
		array[low] = array[high];
		while(low < high && array[low] <= pivotkey)low++;
		array[high] = array[low];
	}
	array[low] = pivotkey;
	BiTree temp = (BiTree)malloc(sizeof(BiTreeNode));
	temp->data = pivotkey;
	temp->location = low;
	temp->lchild = NULL;
	temp->rchild = NULL;
	if(temp->location > root->location) root->rchild = temp;
	else root->lchild = temp; 
	return low;
}

void PostOrderTraverse(BiTree tree){
	if(tree != NULL){
		PostOrderTraverse(tree->lchild);
		PostOrderTraverse(tree->rchild);
		printf("%d", tree->data); 
	}
}

int main(){
	int n;
	scanf("%d",&n);
	int array[n+1];
	for(int i=1; i<=n; i++){
		scanf("%d", &array[i]);
	}

//	for(int i=1; i<=n; i++){
//		printf("%d  ", array[i]);
//	}

	BiTree tree = (BiTree)malloc(sizeof(BiTreeNode));
	tree->data = -1;
	tree->location = -1;
	tree->lchild = NULL;
	tree->rchild = NULL; 
	QuickSort(array, 1, n, tree);
	
	PostOrderTraverse(tree);
	
	return 0;
} 
