#include<stdio.h>

int main()
{
	char letter='a';
	scanf("%c",&letter);
	if(letter>='a'&&letter<='z')
	{
		letter=letter-32;
		printf("%c",letter);
	}
	else if(letter>='A'&&letter<='Z')
	{
		letter=letter+32;
		printf("%c",letter);
	}
	else
	{
		printf("%c",letter);
	}
	
	return 0;
	
}

