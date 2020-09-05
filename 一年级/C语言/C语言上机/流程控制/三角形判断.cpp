#include<stdio.h>

int main()
{
	int a=1,b=1,c=1,d;
	scanf("%d%d%d", &a,&b,&c);
	if(a+b>c&&b+c>a&&a+c>b)
	{
		d=a+b+c;
		printf("%d",d);
	}
	else
	{
		printf("No");
	}
	return 0;
}

