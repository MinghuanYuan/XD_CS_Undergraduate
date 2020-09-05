#include<stdio.h>
#include<stdlib.h>

typedef int Status;
Status ERROR = 500;
Status SUCCESS = 200;

typedef struct LNode{
	int password;
	int position;
	struct LNode *next;
}LNode, *LinkList;

Status AddAtListTail(LinkList &L, int password, int position){
	LinkList temp = (LinkList)malloc(sizeof(LNode));
	if(temp == NULL)return ERROR;
	temp->password = password;
	temp->position = position;
	temp->next = L->next;
	L->next = temp;
	L = temp;
	return SUCCESS; 
} 

Status RemoveFromList(LinkList &temp, int &currentpassword){
	for(int i = 1; i<currentpassword; i++){
		temp = temp->next;
	}
	LinkList r = temp->next;
	printf("%d ", r->position);
	currentpassword = r->password;
	temp->next = r->next;
	free(r);
	return SUCCESS;
}

int main(){
	int population, currentpassword;
	scanf("%d%d", &population, &currentpassword);
	getchar();
	LinkList L = (LinkList)malloc(sizeof(LNode));
	L->next = L;
	L->position = 1;
	scanf("%d",&L->password);
	for(int i = 2; i <= population; i++){
		int password;
		scanf("%d", &password);
		AddAtListTail(L, password, i);
	}
	LinkList temp = L;
	for(int i = 0; i < population; i++){
		RemoveFromList(temp, currentpassword);
	}
	return 0;
}
