#include<stdio.h>
#include<stdlib.h>
#include<ctype.h> 

typedef int Status;
Status ERROR = 500;
Status SUCCESS = 200;

typedef struct STNode{
	char character;
	struct STNode *next;
}STNode, *LinkStack;

Status Push(LinkStack &S, char character){
	LinkStack temp = (LinkStack)malloc(sizeof(STNode));
	if(!temp)return ERROR;
	else{
		temp->character = character;
		temp->next = S;
		S = temp;
		return SUCCESS;
	}
}

Status Pop(LinkStack &S, char &character){
	if(S == NULL)return ERROR;
	else{
		character = S->character;
		LinkStack temp =  S;
		S = S->next;
		free(temp);
		return SUCCESS; 
	}
}

typedef struct QNode{
	char character;
	struct QNode *next;
}QNode, *QueuePtr;

typedef struct {
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

Status InitQueue(LinkQueue &Q){
	Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
	if(Q.front == NULL)return ERROR;
	else{
		Q.front->next = NULL;
		return SUCCESS; 
	}
}

Status EnQueue(LinkQueue &Q, char character){
	QueuePtr temp = (QueuePtr)malloc(sizeof(QNode));
	temp->character = character;
	temp->next = NULL;
	Q.rear->next = temp;
	Q.rear = temp;
	return SUCCESS;
}

Status DeQueue(LinkQueue &Q, char &character){
	if(Q.front == Q.rear)return ERROR;
	else{
		QueuePtr temp = Q.front->next;
		character = temp->character;
		Q.front->next = Q.front->next->next;
		if(Q.rear == temp){
			Q.rear = Q.front;
			free(temp);
		}
		return SUCCESS;
	}
}

Status UpperChar(LinkQueue &Q, char character){
	if(character == 'A'){
		EnQueue(Q, 's');
		EnQueue(Q, 'a');
		EnQueue(Q, 'e');
	}
	else if(character == 'B'){
		EnQueue(Q, 't');
		EnQueue(Q, 's');
		EnQueue(Q, 'a');
		EnQueue(Q, 'e');
		EnQueue(Q, 'd');
		EnQueue(Q, 's');
		EnQueue(Q, 'a');
		EnQueue(Q, 'e');
	}
	return SUCCESS;
}

int main(){
	char s;
	LinkQueue Qprint, Qtemp, Qdeal;
	InitQueue(Qprint);
	InitQueue(Qtemp);
	InitQueue(Qdeal);
	LinkStack S = NULL;
	int mark = 0;//读到（变为1，读到）变为0 
	while(true){
		scanf("%c", &s);
		if(s == '\n')break;
		else if(s == '('){
			mark = 1; 
			continue;
		}
		else if(s == ')'){
			char head, temp;
			DeQueue(Qtemp, head);
			if(isalpha(head) || isdigit(head)){
				while(DeQueue(Qtemp, temp) == 200){
					Push(S, temp);
				}
				while(S != NULL){
					EnQueue(Qdeal, head);
					Pop(S, temp);
					EnQueue(Qdeal, temp);
				}
				EnQueue(Qdeal, head);
				mark = 0;
				continue; 
			}
			else{
				mark = 0;
				continue; 
			}
		} 
		else if((isalpha(s) || isdigit(s)) && mark == 1){
			EnQueue(Qtemp, s);
		} 
		else if(isalpha(s) || isdigit(s))EnQueue(Qdeal, s);
	}
	
	char temp;
	while(DeQueue(Qdeal, temp) == 200){
		if(isupper(temp))UpperChar(Qprint, temp);
		else EnQueue(Qprint, temp);
	}
	
	while(Qprint.front != Qprint.rear){
		DeQueue(Qprint, s);
		printf("%c", s); 
	}
	
//	while(Qdeal.front != Qdeal.rear){
//		DeQueue(Qdeal, s);
//		printf("%c", s); 
//	}
	
	return 0; 
}
