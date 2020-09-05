#include<stdio.h>
int main(){
	int m,a,b=0,i=0,j=0,k=0,l=0;
	scanf("%d",&m);
	a=m;
	if(a==0){
		b=1;
	}
	else{
		while(a>0){
		b++;
		a=a/10;
		}
	}
	a=m;
	while(a>0){
		j=a%10;
		if(j>i){
			i=j;
		}
		a=a/10;
	}
	a=m;
	k=a%10;
	while(a>0){
		l=a%10;
		if(l<k){
			k=l;
		}
		a=a/10;
	}
	printf("%d %d %d",b,i,k);
	return 0;
}

