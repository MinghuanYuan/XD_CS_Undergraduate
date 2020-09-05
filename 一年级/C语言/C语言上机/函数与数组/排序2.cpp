#include<stdio.h>
int main(){
	int m,n,o=0,e=0;
	int odd[100]={0},even[100]={0};
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		scanf("%d",&n);
		if(n%2==0)even[e++]=n;
		else odd[o++]=n;
	}
	for(int i=0;i<=e;i++){
		for(int j=i;j<=e;j++){
			if(even[i]<even[j]){
				int k=even[i];
				even[i]=even[j];
				even[j]=k;
			}
		}
	}
	for(int i=0;i<=o;i++){
		for(int j=i;j<=o;j++){
			if(odd[i]<odd[j]){
				int k=odd[i];
				odd[i]=odd[j];
				odd[j]=k;
			}
		}
	}
	for(int i=0;i<e;i++){
		printf("%d ",even[i]);
	}
	for(int i=0;i<o;i++){
		printf("%d ",odd[i]);
	}
	return 0;
}

