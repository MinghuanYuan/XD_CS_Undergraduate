#include<stdio.h>
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		int a[100]={0},b[100]={0};
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
			b[i]=a[i];
		}
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				if(a[i]<a[j]){
					int t=a[j];
					a[j]=a[i];
					a[i]=t;
				}
			}
		}
		int c=a[0]-a[1];
		int d=a[1]-a[2];
		if(c==d)printf("%d\n",c);
		else printf("no\n");
	}
	return 0;
}

