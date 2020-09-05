#include<stdio.h>
double fun(int n){
	if(n==1){
		return 1;
	}
	else{
		return 1/(1+fun(n-1));
	}
}

int main(){
	int m;
	int n;
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		scanf("%d",&n);
		printf("%.6f\n",fun(n));
	}
	return 0;
}

