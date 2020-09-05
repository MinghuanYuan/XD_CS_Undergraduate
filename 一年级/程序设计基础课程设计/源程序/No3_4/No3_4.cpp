#include<stdio.h>

int deal(int a){
	int sum=0;
	while(a>0){
		sum=sum+(a%10)*(a%10);
		a=a/10;
	}
	return sum;
}

int chain(int n){
	int array[100];
	int mark=1;
	array[0]=n;
	while(n>9){
		n=deal(n);
		array[mark]=n;
		mark++;
	}
	for(int i=0;i<mark;i++){
		printf("%d",array[i]);
		if(array[i]>9){
			printf("->");
		}
	}
	printf("\n");
	if(array[mark-1]==1)return 1;
	else return 0;
} 

int main(){
	int n=0;
	scanf("%d",&n); 
	int sum=0;
	while(n){
		sum=sum+chain(n);
		n--;
	}
	printf("数据链末尾数字是1的数据个数为%d个",sum);
	return 0;
}
