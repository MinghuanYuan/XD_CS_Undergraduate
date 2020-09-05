#include<stdio.h>
int f(int a){
	if(a==0)return 7;
	if(a==1)return 11;
	else return f(a-1)+f(a-2);
}

int main(){
	int m;
	int n;
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		scanf("%d",&n);
		if(f(n)%3==0){
			printf("yes\n");
		}
		else{
			printf("no\n");
		}
	}
	return 0;
}


