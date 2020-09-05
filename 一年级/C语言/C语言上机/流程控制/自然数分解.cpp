#include<stdio.h>
int main(){
	int n,a;
	scanf("%d",&n);
	a=n*n-n+1;
	for(int i=1;i<=n;i++){
		printf("%d ",a);
		a=a+2;
	}
	return 0;
}

