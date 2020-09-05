#include<stdio.h>
#include<stdlib.h>

typedef int Status;
Status ERROR = 500;
Status SUCCESS = 200;

typedef struct LNode{
	int value;
	int exponent;
	struct LNode *next;
}LNode, *LinkList;

Status InitList(LinkList &L){
	L = (LinkList)malloc(sizeof(LNode));
	if(L == NULL)return ERROR;
	L->next = NULL;
	return SUCCESS; 
}

void DispList(LinkList L){
	LinkList p = L->next;
	while(p != NULL){
		if(p->value == 0);
		else if(p->exponent == 0){
			if(p->value > 0)printf("+%d", p->value);
			else if(p->value < 0)printf("%d", p->value);
		}
		else if(p->exponent == 1){
			if(p->value == 1)printf("+x");
			else if(p->value == -1 )printf("-x");
			else if(p->value > 1)printf("+%dx", p->value);
			else if(p->value < -1)printf("%dx", p->value); 
		}
		else if(p->exponent != 0 && p->exponent != 1){
			if(p->value == 1)printf("+x^%d", p->exponent);
			else if(p->value == -1)printf("-x^%d", p->exponent);
			else if(p->value > 1)printf("+%dx^%d", p->value, p->exponent);
			else if(p->value < -1)printf("%dx^%d", p->value, p->exponent);
		}
		p = p->next;
	}
}

void AddListAtTail(LinkList L, int value, int exponent){
	LinkList p = L;
	while(p->next != NULL){
		p = p->next; 
	}
	LinkList temp = (LinkList)malloc(sizeof(LNode));
	temp->value = value;
	temp->exponent = exponent;
	p->next = temp;
	temp->next = NULL;
}

void ListPlusCombine(LinkList L, LinkList L1, LinkList L2){
	LinkList p1 = L1->next;
	LinkList p2 = L2->next;
	while(p1 != NULL && p2 != NULL){
		if((p1->exponent - p2->exponent) == 0){
			if((p1->value + p2->value) == 0){
				LinkList temp1 = p1;
				LinkList temp2 = p2;
				p1 = p1->next;
				p2 = p2->next;
				free(temp1);
				free(temp2);
			} 
			else{
				AddListAtTail(L, (p1->value + p2->value), p1->exponent);
				LinkList temp1 = p1;
				LinkList temp2 = p2;
				p1 = p1->next;
				p2 = p2->next;
				free(temp1);
				free(temp2);
			}
		}
		else if((p1->exponent - p2->exponent) < 0){
			if(p1->value == 0){
				LinkList temp1 = p1;
				p1 = p1->next;
				free(temp1);
			}
			else{
				AddListAtTail(L, p1->value, p1->exponent);
				LinkList temp1 = p1;
				p1 = p1->next;
				free(temp1);
			}
		}
		else if((p1->exponent - p2->exponent) > 0){
			if(p2->value == 0){
				LinkList temp2 = p2;
				p2 = p2->next;
				free(temp2);
			}
			else{
				AddListAtTail(L, p2->value, p2->exponent);
				LinkList temp2 = p2;
				p2 = p2->next;
				free(temp2);
			}
		}
	}
	if(p1 == NULL && p2 != NULL){
		while(p2 != NULL){
			if(p2->value == 0){
				LinkList temp2 = p2;
				p2 = p2->next;
				free(temp2);
			}
			else{
				AddListAtTail(L, p2->value, p2->exponent);
				LinkList temp2 = p2;
				p2 = p2->next;
				free(temp2);
			}
		}
		free(p2);
	}
	else if(p1 != NULL && p2 == NULL){
		while(p1 != NULL){
			if(p1->value == 0){
				LinkList temp1 = p1;
				p1 = p1->next;
				free(temp1);
			}
			else{
				AddListAtTail(L, p1->value, p1->exponent);
				LinkList temp1 = p1;
				p1 = p1->next;
				free(temp1);
			}
		}
		free(p1);
	}
}

int main(){
	int m, n, t;
	LinkList L, L1, L2;
	InitList(L);
	InitList(L1);
	InitList(L2);
	scanf("%d%d%d",&m, &n, &t);
	getchar();
	for(int i=0; i<m; i++){
		int value, exponent;
		scanf("%d%d",&value, &exponent);
		AddListAtTail(L1, value, exponent);
	}
	getchar();
	for(int i=0; i<n; i++){
		int value, exponent;
		scanf("%d%d",&value, &exponent);
		AddListAtTail(L2, value, exponent);
	}
	if(t == 0){
		ListPlusCombine(L, L1, L2);
	} 
	else if(t == 1){
		LinkList p = L2->next;
		while(p != NULL){
			p->value = -p->value;
			p = p->next;
		}
		ListPlusCombine(L, L1, L2);
	}
	
	if(L->next == NULL)printf("0");
	else{
		LinkList p = L->next;
		if(p->exponent == 0){
			if(p->value > 0)printf("%d", p->value);
			else if(p->value < 0)printf("%d", p->value);
		}
		else if(p->exponent == 1){
			if(p->value == 1)printf("x");
			else if(p->value == -1 )printf("-x");
			else if(p->value > 1)printf("%dx", p->value);
			else if(p->value < -1)printf("%dx", p->value); 
		}
		else if(p->exponent != 0 && p->exponent != 1){
			if(p->value == 1)printf("x^%d", p->exponent);
			else if(p->value == -1)printf("-x^%d", p->exponent);
			else if(p->value > 0)printf("%dx^%d", p->value, p->exponent);
			else if(p->value < 0)printf("%dx^%d", p->value, p->exponent);
		}
		DispList(p);
	}
	return 0;
}

