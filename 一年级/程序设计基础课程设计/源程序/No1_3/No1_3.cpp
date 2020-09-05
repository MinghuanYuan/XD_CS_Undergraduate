#include<stdio.h>
#include<string.h>

typedef struct{
	char name[100]={0};
	int englishscore=0;
	int mathscore=0;
	int averagescore=0;
}student;

int main(){
	student array[100];
	FILE *fp1=NULL,*fp2=NULL,*fp3=NULL;
	fp1=fopen("db1.txt","r");
	fp2=fopen("db2.txt","r");
	fp3=fopen("db3.txt","w");
	if(fp1==NULL||fp2==NULL||fp3==NULL){
		printf("无法正确打开文件\n");
	}
	else{
		int i=0;
		while(~fscanf(fp1,"%s%d",&array[i].name,&array[i].englishscore)){
			i++;
		}
		int j=0;
		char str[100]={0};
		int score=0;
		while(~fscanf(fp2,"%s%d",&str,&score)){
			for(j=0;j<i;j++){
				if(strcmp(str,array[j].name)==0){
					array[j].mathscore=score;
				}
			}
		}
		for(int k=0;k<i;k++){
			array[k].averagescore=0.5*(array[k].englishscore+array[k].mathscore);
			fprintf(fp3,"%s %d %d %d\n",array[k].name,array[k].englishscore,array[k].mathscore,array[k].averagescore);
		}
		fclose(fp1);
		fclose(fp2);
		fclose(fp3);
		printf("程序执行完成\n");
	}
	return 0;
} 
