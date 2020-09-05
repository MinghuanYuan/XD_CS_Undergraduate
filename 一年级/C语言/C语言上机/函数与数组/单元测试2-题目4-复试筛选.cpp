#include<stdio.h>
typedef struct stu{
	char name[11];
	int score;
	int eng;
}stu;

int main(){
	stu s[200]={0};
	int m,n;
	scanf("%d%d",&m,&n);
	for(int i=0;i<m;i++)
	scanf("%s%d%d",&s[i].name,&s[i].score,&s[i].eng);
	
	for(int i=0;i<m;i++){
		for(int j=i+1;j<m;j++){
			if(s[i].score<s[j].score){
				stu t=s[i];
				s[i]=s[j];
				s[j]=t;
			}
			else if(s[i].score==s[j].score){
				if(s[i].eng<s[j].eng){
					stu t=s[i];
					s[i]=s[j];
					s[j]=t;
				}
			}
		}
	}
	for(int i=0;i<n;i++)
	printf("%s %d %d\n",s[i].name,s[i].score,s[i].eng);
	return 0;
}

