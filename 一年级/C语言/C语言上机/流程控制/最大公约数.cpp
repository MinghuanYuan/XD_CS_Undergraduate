#include<stdio.h>
int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
int main()
{
	int a,b;
	while(true){
		scanf("%d%d",&a,&b);
		if(a==0 && b==0)break;
		printf("%d\n",gcd(a,b));
	}
	//printf("%d\n",gcd(x,y));
	return 0;
}

