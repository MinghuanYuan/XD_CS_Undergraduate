#include<stdio.h>
int main(){
	int l1=0,l2=0,l3=0,l4=0,l5=0,l6=0,n,sum=0,pi;
	double ave;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&pi);
		sum=sum+pi;
		if(pi>=0&&pi<=50)l1++;
		if(pi>=51&&pi<=100)l2++;
		if(pi>=101&&pi<=150)l3++;
		if(pi>=151&&pi<=200)l4++;
		if(pi>=201&&pi<=300)l5++;
		if(pi>=300)l6++;
	}
	ave=(double)sum/n;
	printf("%.2f\n%d %d %d %d %d %d ",ave,l1,l2,l3,l4,l5,l6);
	return 0;
}

