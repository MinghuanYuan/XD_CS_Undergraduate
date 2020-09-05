#include<stdio.h>
int main(){
	int m,n;
	scanf("%d%d",&m,&n);
	int a[101][101]={0};
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	
	for(int i=0;i<m;i++){
		int b=-1,max=0,len=0,d=0;
		for(int j=0;j<n;j++){
			if(a[i][j]==1&&b==-1)b=j;
			if(a[i][j]==0&&b!=-1){
				len=j-b;
				b=-1;
				if(len>max){max=len;d=j-1;}
			}
			if(j==n-1&&b!=-1){
				len=j-b+1;
				if(len>max){max=len;d=j;}
			}
		}
		if(max==0)printf("-1 -1\n");
		else printf("%d %d\n",d-max+1,d);
	}
	return 0;
}

