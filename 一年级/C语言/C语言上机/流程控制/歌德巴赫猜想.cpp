#include<stdio.h>
int isPrime(long a){
	if(a==1)return 0;
	else{
		int max=1;
		for(int i=2;i<a;i++){
			if(a%i==0)max=i;
		}
		if(max==1)return 1;
		else return 0;
	}
}

int main(){
	int m;
	int n;
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		scanf("%d",&n);
		for(int k=3;k<=n;k++){
			if(isPrime(k)==1&&isPrime(n-k)==1){
				printf("%d %d\n",k,n-k);
				break;
			}
		}
	}
	return 0;
}

