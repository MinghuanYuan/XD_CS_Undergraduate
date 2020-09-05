#include<stdio.h>
#include<string.h>
int main(){
	char a[101]={0};
	char print[101]={0};
	char b[10]="***end***";
	int len=0;
	while(1){
		gets(a);
		if(!strcmp(a,b))break;
		else{
			if(strlen(a)>len){
				strcpy(print,a);
				len=strlen(a);
			}
		}
	}
	printf("%d\n",len);
	puts(print);
	return 0;
}

