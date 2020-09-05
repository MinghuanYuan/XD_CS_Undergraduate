#include<stdio.h>
typedef struct{
	char name[21];
	int win;
	int draw;
	int lose;
	int goal;
	int goal1;
	int jifen;
	int jingshengqiu;
}team;

int main(){
	int n,m;
	team a[32];
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%s%d%d%d%d%d",&a[i].name,&a[i].win,&a[i].draw,&a[i].lose,&a[i].goal,&a[i].goal1);
		a[i].jifen=3*a[i].win+a[i].draw;
		a[i].jingshengqiu=a[i].goal-a[i].goal1;
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(a[i].jifen<a[j].jifen){
				team t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
			if(a[i].jifen==a[j].jifen){
				if(a[i].jingshengqiu<a[j].jingshengqiu){
					team t=a[i];
					a[i]=a[j];
					a[j]=t;
				}
			}
		}
	}
	for(int i=0;i<m;i++){
		printf("%d %s %d %d\n",i+1,a[i].name,a[i].jifen,a[i].jingshengqiu);
	}
	return 0;
}
