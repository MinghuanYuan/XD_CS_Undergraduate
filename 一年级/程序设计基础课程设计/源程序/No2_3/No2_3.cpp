#include<stdio.h>
#include<string.h>
#include<ctype.h>

typedef struct{
	char word[50]={0};
	int sum=0;
}dictionary;

int main(){
	dictionary array[100];
    FILE *fp1=NULL,*fp2=NULL;
    fp1=fopen("No2_3_1.txt","r");
    fp2=fopen("No2_3_2.txt","a");
    char str[50]={0};
    if(fp1==NULL||fp2==NULL){
        printf("�޷���ȷ���ļ�\n");
    }
    else{
    	int i=0;
        while(~fscanf(fp1,"%s",&str)){
        	if(isalpha(str[strlen(str)-1])==0){
        		str[strlen(str)-1]=0;
			}
        	int mark1=0;
        	for(int j=0;j<i;j++){
        		if(strcmp(str,array[j].word)==0){
        			array[j].sum++;
        			mark1=1;
				}
			}
			if(mark1==0){
				strcpy(array[i].word,str);
				array[i].sum=1;
				i++;
			}
		}
		for(int j=0;j<i;j++){
			for(int k=j+1;k<i;k++){
				if(strcmp(array[j].word,array[k].word)>0){
					dictionary temp=array[j];
					array[j]=array[k];
					array[k]=temp;
				}
			}
		}
		for(int j=0;j<i;j++){
			printf("%s %d\n",array[j].word,array[j].sum);
		}
        
        //�����ǲ��Ҳ��滻���ʹ��� 
        printf("����������ҵĵ���\n");
        fseek(fp1,0,0);
        //a1Ϊ��Ҫ���ҵĵ��ʣ�a2Ϊ�滻�ĵ��ʣ�a3Ϊÿ�ζ���ĵ��� 
        char a1[100]={0},a2[100]={0},a3[100]={0};
        gets(a1);
        char s;
        int mark2=0,mark3=-1;
        //mark2��¼�Ƿ��б����ţ�mark3��¼�Ƿ��ҵ��õ��� 
        char punctuation;
        while(~fscanf(fp1,"%s",&a3)){
        	if(isalpha(a3[strlen(a3)-1])==0){
        		punctuation=a3[strlen(a3)-1];
        		a3[strlen(a3)-1]=0;
        		mark2=1;
			}
            if(strcmp(a1,a3)==0&&mark3==-1){
            	mark3=1;
            	printf("���ҵ���Ҫ���ҵ��ַ�����");
            	printf("�������滻���ַ���\n");
        		gets(a2);
                fprintf(fp2,"%s",a2);
                if(mark2==1){
                	fprintf(fp2,"%c",punctuation);
                	mark2=0; 
				}
            }
            else if(strcmp(a1,a3)==0&&mark3==1){
            	fprintf(fp2,"%s",a2);
            	if(mark2==1){
                	fprintf(fp2,"%c",punctuation);
                	mark2=0; 
				}
			}
            else{
            	fprintf(fp2,"%s",a3);
            	if(mark2==1){
                	fprintf(fp2,"%c",punctuation);
                	mark2=0; 
				}
			}
			fscanf(fp1,"%c",&s);
			if(s=='\n'){
				fprintf(fp2,"\n");
			}
			else if(s==' '){
				fprintf(fp2," ");
			}
        }
        if(mark3==-1)printf("δ�ҵ���Ҫ���ҵ��ַ���\n");
    }
    fclose(fp1);
    fclose(fp2);
    remove("No2_3_1.txt");
    rename("No2_3_2.txt","No2_3_1.txt");
    printf("����ִ�����\n");
    return 0;
}
