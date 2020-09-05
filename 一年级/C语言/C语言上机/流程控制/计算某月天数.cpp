#include<stdio.h>

int main()
{
	int a=1,b=1;
	scanf("%d%d",&a,&b);
	switch(b)
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			printf("31");
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			printf("30");
			break;
		case 2:
			if((a%4==0&&a%100!=0)||a%400==0)
			{
				printf("29");
			}
			else
			{
				printf("28");
			}
	}
	return 0;
}

