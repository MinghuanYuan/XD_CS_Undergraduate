#include<stdio.h>
int isPrime(long a){
	if(a==1)return 0;
	else{
		int max=1;
		for(int i=2;i<a;i++){
			if(a%i==0)max=i;
		}
		if(max==1)return 1;
		else return 0;
	}
}
int main(){
	while(true){
		char a[100]={0};
		int b=0;
		gets(a);
		if(a[0]=='\0')break;
		else{
			for(int i=0;i<100;i++){
				if(a[i]<='9'&&a[i]>='0'){
					b=10*b+a[i]-48;
				}
		
			}
			if(b==0)printf("0\n");
			else{
				if(isPrime(b)==1)printf("%d\n",b);
				else{
					int y=b-1;
					for(;y>1;y--){
						if(b%y==0)break;
					}
					printf("%d\n",y);
				}
			}
		}
	}
	return 0;
}

