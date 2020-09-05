#include<stdio.h>
#include<string.h>
int main(){
	char s,s1;
	int n;
	scanf("%c%d%c",&s,&n,&s1);
	char a[101]={0};
	gets(a);
	int len=strlen(a);
	int sum=0;
	if(n==1){
		for(int i=0;i<len;i++){
			if(a[i]==s)sum++;
		}
	}
	else{
		if(s>='a'&&s<='z'){
			for(int i=0;i<len;i++){
				if(a[i]==s||a[i]==s-32)sum++;
			}
		}
		else{
			for(int i=0;i<len;i++){
				if(a[i]==s||a[i]==s+32)sum++;
			}
		}
	}
	printf("%d",sum);
	return 0;
}

