#include<stdio.h>
int main(){
	int a,b,c,d,e,f,s;
	scanf("%d%d%d",&a,&b,&c);
	if(a>b)f=a;
	else f=b;
	if(c>f)f=c;
	if(a<b)d=a;
	else d=b;
	if(c<d)d=c;
	if(a>d&&a<f)e=a;
	if(b>d&&b<f)e=b;
	if(c>d&&c<f)e=c;
	if(d*d+e*e==f*f){
		s=d*e;
		printf("%d",s);
	}
	else printf("no");
	return 0;	
} 

