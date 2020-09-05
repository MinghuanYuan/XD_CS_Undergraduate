#include<stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	int print[10000]={0};
	int p=1;
	int p1=n*n-2;
	int a[100][100]={0};
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	print[0]=a[0][0];
	int i=0,j=1;
	for(int k=0;k<n-1;k++){
		if(i<j){
			while(j>=0){
				print[p]=a[i][j];
				p++;i++;j--;
			}
			j=0;
		}
		else{
			while(i>=0){
				print[p]=a[i][j];
				p++;i--;j++;
			}
			i=0;
		}
	}
	print[n*n-1]=a[n-1][n-1];
	int i1=n-1,j1=n-2;
	for(int k=0;k<n-2;k++){
		if(i1>j1){
			while(j1<=n-1){
				print[p1]=a[i1][j1];
				p1--;i1--;j1++;
			}
			j1=n-1;		
		}
		else{
			while(i1<=n-1){
				print[p1]=a[i1][j1];
				p1--;i1++;j1--;
			}
			i1=n-1;
		}
	}
	for(int i=0;i<n*n;i++)printf("%d ",print[i]);
	return 0;
}


