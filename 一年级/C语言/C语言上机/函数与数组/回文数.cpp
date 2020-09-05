#include<stdio.h>
int len(int a){
	int l=0;
	while(a!=0){
		l++;
		a/=10;
	}
	return l;
}

int main(){
	int m,n;
	scanf("%d",&m);
	while(m--){
		scanf("%d",&n);
		int n1=n;
		int l=len(n);
		int nu[l];
		for(int i=0;i<l;i++){
			nu[i]=n%10;
			n/=10;
		}
		int i=0;
		for(;i<l/2;i++){
			if(nu[i]!=nu[l-i-1])break;
		}
		if(i<l/2){
			printf("no\n");
		}
		else{
			int sum=0;
			while(n1!=0){
				sum+=n1%10;
				n1/=10;
			}
			printf("%d\n",sum);
		}
	}
	return 0;
}

