#include<stdio.h>
int main(){
	int a=1,b=2,sum=0,i;
	scanf("%d%d",&a,&b);
	for(a;a<=b;a++){
		for(sum=0,i=1;i<a;i++){
			if(a%i==0){
				sum=sum+i;
			}
		}
		if(sum==a){
			printf("%d\n",a);
		}
	}
	return 0;
}

