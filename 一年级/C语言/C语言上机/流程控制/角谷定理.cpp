#include<stdio.h>
int sum=0;
int jiaogu(int a){
	if(a==1)return 1;
	else{
		if(a%2==0){
			a/=2;
			sum++;
		}
		else{
			a=3*a+1;
			sum++;
		}
		if(a==1)return sum+1;
		else return jiaogu(a);
	}
}

int main(){
	int m;
	int n;
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		scanf("%d",&n);
		printf("%d\n",jiaogu(n));
		sum=0;
	}
	return 0;
}

