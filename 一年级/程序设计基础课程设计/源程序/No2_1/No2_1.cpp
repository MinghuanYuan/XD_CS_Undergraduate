#include<stdio.h>

int main(){
    FILE *fp1=NULL,*fp2=NULL;
    fp1=fopen("No2_1_1.txt","r");
    fp2=fopen("No2_1_2.txt","a");
    if(fp1==NULL||fp2==NULL){
    	printf("无法正确打开文件\n");
	} 
	else{
		char s;
    	int i=2;
   		int j=0;
    	fprintf(fp2,"%c",'1');
    	while(fscanf(fp1,"%c",&s)!=EOF){
        	if(s=='\n'){
           		fprintf(fp2,"%c",'\n');
            	fprintf(fp2,"%d",i);
            	i++;
            	j=0;
        	}
        	else if(s=='/'){
            	j=1;
            	continue;
        	}
        	else if(j==1){
            	continue;
        	}
        	else{
            	fprintf(fp2,"%c",s);
        	}
    	}
    	fclose(fp1);
    	fclose(fp2);
    	remove("No2_1_1.txt");
    	rename("No2_1_2.txt","No2_1_1.txt");
	}
    printf("程序执行完成\n");
    return 0;
}
