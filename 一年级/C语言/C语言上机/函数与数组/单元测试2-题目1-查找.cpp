#include<stdio.h>
int main(){
	int n,k;
	int a[100];
	int b=-1;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=0;i<n;i++){
		if(a[i]==k){
			printf("%d ",i);
			b=1;
		}
	}
	if(b==-1)printf("-1");
	return 0;
}
