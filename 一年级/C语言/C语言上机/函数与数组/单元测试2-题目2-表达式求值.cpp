#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	char a[9]={0};char b[9]={0};char c[9]={0};char d[2]={0};char plus[2]="+";char minus[2]="-";char mul[2]="*";char div[2]="/";char rem[2]="%";
	int num1=0,num2=0;
	scanf("%s",&a);
	scanf("%s",&b);
	scanf("%s",&c);
	
	int a1=atoi(a);
	if(a1==0)strcpy(d,a);
	else num1=a1;
	
	int a2=atoi(b);
	if(a2==0)strcpy(d,b);
	else if(num1==0)num1=a2;
		else num2=a2;
	
	int a3=atoi(c);
	if(a3==0)strcpy(d,c);
	else num2=a3;
	
	int sum=0;
	if(strcmp(d,plus)==0)sum=num1+num2;
	if(strcmp(d,minus)==0)sum=num1-num2;
	if(strcmp(d,mul)==0)sum=num1*num2;
	if(strcmp(d,div)==0)sum=num1/num2;
	if(strcmp(d,rem)==0)sum=num1%num2;
	
	printf("%d",sum);
	return 0;
}

