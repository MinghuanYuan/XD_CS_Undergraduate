#include<stdio.h>
#include<stdlib.h>

typedef int Status;
Status ERROR = 500;
Status SUCCESS = 200;

typedef struct STNode{
	int x;
	int y;
	int direction;
	struct STNode *next;
}STNode, *LinkStack;

Status Push(LinkStack &S, int x, int y, int direction){
	LinkStack temp = (LinkStack)malloc(sizeof(STNode));
	if(!temp)return ERROR;
	else{
		temp->x = x;
		temp->y = y;
		temp->direction = direction;
		temp->next = S;
		S = temp;
		return SUCCESS;
	}
}

Status Pop(LinkStack &S, int &x, int &y, int &direction){
	if(S == NULL)return ERROR;
	else{
		x = S->x;
		y = S->y; 
		direction = S->direction;
		LinkStack temp =  S;
		S = S->next;
		free(temp);
		return SUCCESS; 
	}
}

Status Move(LinkStack &S, int map[100][100], int currentx, int currenty, int currentdirection, int finalx, int finaly){
	int movex[4] = {0,1,0,-1};
	int movey[4] = {1,0,-1,0};
	int status;
	while((currentx != finalx) || (currenty != finaly)){
		int i = currentdirection - 1;
		for(; i < 4; i++){
			if(map[currentx + movex[i]][currenty + movey[i]] == 0){
				if(map[currentx][currenty] == 2){
					int a, b, c;
					status = Pop(S, a, b, c);
					if(S == NULL)return ERROR;
				}	
				Push(S, currentx, currenty, i+1);
				map[currentx][currenty] = 2;
				currentx =  currentx + movex[i];
				currenty =  currenty + movey[i];
				currentdirection = 1;
				break;
			}
		}
		if(i == 4 && map[currentx][currenty] == 0){
			Push(S, currentx, currenty, i+1);
			map[currentx][currenty] = 2;
			int a, b, c;
			status = Pop(S, a, b, c);
			if(S == NULL)return ERROR;
			currentx = S->x;
			currenty = S->y;
			currentdirection = S->direction;
		}
		else if(i == 4 && map[currentx][currenty] == 2){
			int a, b, c;
			status = Pop(S, a, b, c);
			if(S == NULL)return ERROR;
			currentx = S->x;
			currenty = S->y;
			currentdirection = S->direction;
		}
		
	}
	if(status == ERROR)return ERROR;
	else return SUCCESS;
}

int main(){
	int m, n;
	scanf("%d%d", &m, &n);
	int array[100][100] = {0};
	for(int i = 0; i < n+2; i++){
		array[0][i] = 3;
		array[m+1][i] = 3;
	}
	for(int i = 0; i < m+2; i++){
		array[i][0] = 3;
		array[i][n+1] = 3;
	}
	int firstx, firsty, finalx, finaly;
	scanf("%d%d", &firstx, &firsty);
	scanf("%d%d", &finalx, &finaly);
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= n; j++){
			scanf("%d", &array[i][j]);
		}
	}
	
	int finaltemp;
	if(array[firstx][firsty] == 1){
		printf("no");
		return 0;
	}
	LinkStack S = NULL;
	LinkStack Sprint = NULL; 
	int status = Move(S, array, firstx, firsty, 1, finalx, finaly);	
	
	if(array[finalx][finaly+1] == 3)finaltemp = 1;
	else if(array[finalx+1][finaly] == 3)finaltemp = 2;
	else if(array[finalx][finaly-1] == 3)finaltemp = 3;
	else if(array[finalx-1][finaly] == 3)finaltemp = 4;
	else finaltemp = 5; 
	
	if(finaltemp == 5){
		printf("no");
		return 0;
	}
	else if(status == 200){
		while(S != NULL){
			int a,b,c;
			Pop(S,a,b,c);
			Push(Sprint,a,b,c);
		}
		while(Sprint != NULL){
			int a,b,c;
			Pop(Sprint,a,b,c);
			printf("(%d,%d,%d),",a,b,c);
		}
		printf("(%d,%d,%d)", finalx, finaly, finaltemp);
	}
	else printf("no");
	
	/*testmap*/ 
//	printf("\n");
//	for(int i = 0; i < 100; i++){
//		for(int j = 0; j < 100; j++){
//			printf("%d",array[i][j]);
//		}
//		printf("\n");
//	}
	return 0;
}

