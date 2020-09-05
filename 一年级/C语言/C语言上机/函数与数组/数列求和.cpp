#include<stdio.h>
int f1(int a){
	if(a==1)return 2;
	if(a==2)return 3;
	else return f1(a-1)+f1(a-2);
}


int f2(int a){
	if(a==1)return 1;
	if(a==2)return 2;
	else return f2(a-1)+f2(a-2);
}

double a(int n){
	return (double)f1(n)/f2(n);
}


int main(){
	int n;
	double sum=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		sum=sum+a(i);
	}
	printf("%.2f",sum);
	return 0;
}


