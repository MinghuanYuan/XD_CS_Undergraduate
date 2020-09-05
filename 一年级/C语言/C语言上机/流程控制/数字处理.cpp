#include<stdio.h>
long deal(long n){
	long sum=0;
	while(n>0){
		sum+=n%10;
		n/=10;
	}
	if(sum<10)return sum;
	else return deal(sum);
}

int main(){
	long m;
	while(1){
		scanf("%ld",&m);
		if(m==0)break;
		else printf("%d\n",deal(m));
	}
	return 0;
}

