#include<stdio.h>
#include<stdlib.h> 

#define MAX_VERTEX_NUM 50 

typedef struct ArcNode{
	int adjvex;
	struct ArcNode *nextarc;
}ArcNode;

typedef struct Vnode{
	ArcNode *firstarc;
}VNode, AdjList[MAX_VERTEX_NUM];

typedef struct{
	AdjList vertices;
	int vexnum;
	int arcnum;
}ALGraph;
//memset

void DFS(ALGraph graph, int visited[], int v, int sum, int acount[]);

int DFSTraverse(ALGraph graph, int visited[], int acount[]){
	int sum = 0;
	for(int v=1; v<=graph.vexnum; v++)visited[v] = 0;
	for(int v=1; v<=graph.vexnum; v++){
		if(visited[v] == 0){
			DFS(graph, visited, v, sum, acount);
			sum++;
		}
	}
	return sum;
}

void DFS(ALGraph graph, int visited[], int v, int sum, int acount[]){
	ArcNode* p;
	visited[v] = 1;
	acount[sum]++;
//	printf("%d", v);
	p = graph.vertices[v].firstarc;
	while(p != NULL){
		if(visited[p->adjvex] == 0)DFS(graph, visited, p->adjvex, sum, acount);
		p = p->nextarc;
	}
}

int main(){
	int n, m, visited[MAX_VERTEX_NUM], acount[MAX_VERTEX_NUM];
	scanf("%d%d", &n, &m);
	ALGraph graph;
	graph.vexnum = n;
	graph.arcnum = m;
	for(int i=0; i<MAX_VERTEX_NUM; i++){
		graph.vertices[i].firstarc = NULL;
		acount[i] = 0;
	}
	for(int i=1; i<=m; i++){
		int firstnode, secondnode;
 		scanf("%d%d", &firstnode, &secondnode);
 		
		if(graph.vertices[firstnode].firstarc != NULL){
			ArcNode* p = graph.vertices[firstnode].firstarc;
			while(p->nextarc != NULL)
			p = p->nextarc;
			ArcNode* temp1 = (ArcNode*)malloc(sizeof(ArcNode));
 			temp1->adjvex = secondnode;
			p->nextarc = temp1;
			temp1->nextarc = NULL;
		}
		else{
			ArcNode* temp1 = (ArcNode*)malloc(sizeof(ArcNode));
 			temp1->adjvex = secondnode;
			graph.vertices[firstnode].firstarc = temp1;
			temp1->nextarc = NULL;
		}
		
		if(graph.vertices[secondnode].firstarc != NULL){
			ArcNode* p = graph.vertices[secondnode].firstarc;
			while(p->nextarc != NULL)
			p = p->nextarc;
			ArcNode* temp2 = (ArcNode*)malloc(sizeof(ArcNode));
 			temp2->adjvex = firstnode;
			p->nextarc = temp2;
			temp2->nextarc = NULL;
		}
		else{
			ArcNode* temp2 = (ArcNode*)malloc(sizeof(ArcNode));
 			temp2->adjvex = firstnode;
			graph.vertices[secondnode].firstarc = temp2;
			temp2->nextarc = NULL;
		}
		
	}
	
	int sum = DFSTraverse(graph, visited, acount);
	printf("%d\n", sum);
	for(int i=0; i<sum; i++){
		for(int j=i+1; j<sum; j++){
			if(acount[i] > acount[j]){
				int temp = acount[i];
				acount[i] = acount[j];
				acount[j] = temp;
			}
		}
	}
	for(int i=0; i<sum; i++)printf("%d ", acount[i]); 
	
	return 0;
} 
