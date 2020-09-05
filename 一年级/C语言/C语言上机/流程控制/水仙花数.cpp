#include<stdio.h>
#include<math.h>
int intLen(int num){
	int len=0;
	while(num!=0){
		len++;
		num/=10;
	}
	return len;
}


int pow(int a,int b){
	if(b==0)return 1;
	int temp = a;
	while(b>1){
		temp*=a;
		b--;
	}
	return temp;
}


int fun(int a,int b){
	
	/*int sum1=0,n,sum2=0;
	if(a<=100){
		for(a=100;a<=b;a++){
			sum1=1;
			n=a;
			while(n>0){
				sum1=sum1+pow(n%10,intLen(a));
				n/=10;
			}
			if(sum1==a){
				sum2++;
			}
		}
		
	}
	else{
		for(a;a<=b;a++){
			sum1=1;
			n=a;
			while(n>0){
				sum1=sum1+pow(n%10,intLen(a));
				n/=10;
			}
			if(sum1==a){
				sum2++;
			}
		}
	}
	return sum2;
}
*/
	int sum=0;
	for(int i=a;i<=b;i++){
		if(i<100)continue;
		int geweihe=0;
		int temp = i;
		while(temp>0){
			geweihe+=pow(temp%10,intLen(i));
			temp/=10;
		}
		if(geweihe==i){
			sum++;
		}
		//printf("%d\n",i);
	}
	return sum;
}
int main(){
	int m,i=1,x,y;
	//printf("%d",pow(100,intLen(100)));
	scanf("%d",&m);
	for(i;i<=m;i++){
		scanf("%d%d",&x,&y);
		printf("%d\n",fun(x,y));
		//fun(x,y);
	}
	return 0;
}

