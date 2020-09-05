#include<stdio.h>
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	if(m>n)m=n;
	int a[1000]={0};
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(a[j]>a[i]){
				int t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
	}
	for(int i=0;i<m;i++){
		printf("%d ",a[i]);
	}
	return 0;
}
