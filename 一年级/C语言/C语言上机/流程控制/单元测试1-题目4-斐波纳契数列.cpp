#include<stdio.h> 
int f(int a){
	if(a==1||a==2)return 1;
	else return f(a-1)+f(a-2);
}

int isprime(long n){
	if(n==1){
		return 0;
	}
	else{
		int max=1;
		for(int i=2;i<n;i++){
			if(n%i==0){
				max=i;
			}
		}
		if(max==1){
			return 1;
		}
		else return 0;
	}
}

int main(){
	int n;
	scanf("%d",&n);
	if(isprime(f(n))==1){
		printf("yes");
	}
	else{
		printf("%d",f(n));
	}
	return 0;
}

