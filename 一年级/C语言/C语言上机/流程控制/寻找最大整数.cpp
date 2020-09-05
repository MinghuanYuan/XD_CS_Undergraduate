#include<stdio.h>

int main()
{
	int a=1,b=2,c=3,d=4,min=0;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	a>b?min=b:min=a;
	min>c?min=min:min=c;
	min>d?min=min:min=d;
	printf("%d",min);
	return 0;
}

