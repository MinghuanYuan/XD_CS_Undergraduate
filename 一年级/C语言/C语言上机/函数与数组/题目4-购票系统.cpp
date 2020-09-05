#include<stdio.h>
void deal(int a[][5],int m){
	for(int i=0;i<20;i++){
		for(int j=0;j<6-m;j++){
			if(a[i][j]==0){
				while(m--){
					a[i][j]=1;
					printf("%d ",5*i+j+1);
					j++;
				}
			goto here;	
			}
		}
	}
	for(int i=0;i<20;i++){
		for(int j=0;j<20;j++){
			if(a[i][j]==0&&m>0){
				a[i][j]=1;
				printf("%d ",5*i+j+1);
				m--;
			}
		}
	}
	here:printf("\n");
}

int main(){
	int a[20][5]={0};
	int n;
	int b[100]={0};
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&b[i]);
	}
	for(int i=0;i<n;i++){
		deal(a,b[i]);
	}
	
	/*for(int i=0;i<20;i++){
		for(int j=0;j<5;j++){
			printf("%d",a[i][j]);
		}
		printf("\n");
	}*/
	return 0;
}
