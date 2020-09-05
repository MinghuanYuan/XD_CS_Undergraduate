#include<stdio.h>
int main(){
	int m;
	scanf("%d",&m);
	int a[m][m],sum[40]={0},print[40]={0};
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			scanf("%d",&a[i][j]);
			sum[i]+=a[i][j];
		}
	}
	for(int j=0;j<m;j++){
		for(int i=0;i<m;i++){
			sum[m+j]+=a[i][j];
		}
	}
	for(int i=0;i<m;i++){
		sum[2*m]+=a[i][i];
		sum[2*m+1]+=a[i][m-1-i];
	}
	for(int i=0;i<2*m+2;i++){
		for(int j=i;j<2*m+2;j++){
			if(sum[i]<sum[j]){
				int k=sum[i];
				sum[i]=sum[j];
				sum[j]=k;
			}
		}
	}
	for(int i=0;i<2*m+2;i++){
		printf("%d ",sum[i]);
	}
	return 0;
}

