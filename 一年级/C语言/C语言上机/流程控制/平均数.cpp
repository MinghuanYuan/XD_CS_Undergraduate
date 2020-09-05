#include<stdio.h>
int main()
{
	int n,i=0,a;
	float b=0,c;
	scanf("%d",&n);
	for(;i<n;i++){
		scanf("%d",&a);
		b=b+a;
	}
	c=b/n;
	printf("%.2f",c);
	return 0;
}


