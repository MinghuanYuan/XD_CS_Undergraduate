#include<stdio.h>
int sum=0;
int robot(char a[][25],int b,int c){
	int i=b;
	int j=c;
	if(a[i][j]=='N'){sum++;a[i][j]='X';i--;}
	if(a[i][j]=='S'){sum++;a[i][j]='X';i++;}
	if(a[i][j]=='W'){sum++;a[i][j]='X';j--;}
	if(a[i][j]=='E'){sum++;a[i][j]='X';j++;}
	if(a[i][j]=='N'||a[i][j]=='S'||a[i][j]=='W'||a[i][j]=='E')return robot(a,i,j);
	if(a[i][j]=='X'){sum=-sum;return sum;}
	else return sum;
}

int main(){
	int n,m,c;
	char s;
	scanf("%d%d%d%c",&n,&m,&c,&s);
	char a[25][25]={0};
	for(int i=1;i<n+1;i++){
		for(int j=1;j<m+2;j++){
			scanf("%c",&a[i][j]);
		}
	}
	int sum=robot(a,1,c);
	if(sum>0)printf("out %d",sum);
	else printf("loop %d",-sum);
	return 0;
}

