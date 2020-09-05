#include<stdio.h>

typedef struct{
	int u;
	int v;
	int w;
}Edge;

void Kruskal(Edge E[], int n){
	int vset[n+1];
	for(int i=1; i<=n; i++)vset[i] = i;
	int k = 1;
	int j = 1;
	while(k < n){
		if(vset[E[j].u] != vset[E[j].v]){
			if(E[j].u < E[j].v)printf("%d %d %d\n", E[j].u, E[j].v, E[j].w);
			else printf("%d %d %d\n", E[j].v, E[j].u, E[j].w);
			k++;
			int su = vset[E[j].u];
			int sv = vset[E[j].v];
			for(int i=1; i<=n; i++){
				if(vset[i] == sv)vset[i] = su;
			}
		}
		j++;
	}
}

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	Edge E[m+1];
	for(int i=1; i<=m; i++){
		scanf("%d%d%d", &E[i].u, &E[i].v, &E[i].w); 
	}
	for(int i=1; i<=m; i++){
		for(int j=i+1; j<=m; j++){
			if(E[i].w > E[j].w){
				Edge temp = E[i];
				E[i] = E[j];
				E[j] = temp;
			}
		}
	}
	
//	printf("\n");
//	for(int i=1; i<=m; i++){
//		printf("%d %d %d\n", E[i].u, E[i].v, E[i].w); 
//	}
//	printf("\n");
	
	Kruskal(E, n);
	
	return 0;
} 
