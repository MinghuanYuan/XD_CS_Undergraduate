#include<stdio.h>
int main(){
	int n;
	int a[1000]={0};
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(a[i]<a[j]){
				int t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
	}
	int c=-1,d=-1;
	int k=n/2;
	for(int i=0;i<n;i++){
		if(a[i]==a[k]){
			c=i;
			break;
		}
	}
	for(int i=n-1;i>=0;i--){
		if(a[i]==a[k]){
			d=i;
			break;
		}
	}
	int l=n-d-1;
	if(l==c){
		printf("%d",a[k]);
	}
	else{
		printf("-1");
	}
	return 0;
}
