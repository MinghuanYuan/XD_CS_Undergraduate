#include<stdio.h>
int main(){
	char a[51]={0},b[200]={0};
	int c=0;
	scanf("%s",&a);
	for(int i=0;i<50;i++){
		if(a[i]<='9'&&a[i]>='1'){
			if(a[i+1]<='9'&&a[i+1]>='0'){
				int k=(a[i]-48)*10+a[i+1]-48;
				for(int j=1;j<k;j++){
				b[c]=a[i-1];
				c++;
				}
				i++;
			}
			else{
				for(int j=1;j<a[i]-48;j++){
					b[c]=a[i-1];
					c++;
				}
			}
			
		}
		else{
			b[c]=a[i];
			c++;
		}
	}
	printf("%s",b);
	return 0;
}

