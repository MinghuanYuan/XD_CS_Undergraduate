#include<stdio.h>
#include<string.h>

int main(){
    FILE *fp1=NULL,*fp2=NULL;
    char str1[90]={0};
    char str2[90]={0};
    fp1=fopen("No1_1_1.txt","r");
    fp2=fopen("No1_1_2.txt","r");
    //以只读的方式打开同目录下的两个文件 
    if(fp1==NULL||fp2==NULL){
        printf("无法正确打开文件\n");
    }
    else{
        while((strcmp(str1,str2))==0){
            fgets(str1,80,fp1);
            fgets(str2,80,fp2);
        }
        fclose(fp1);
        fclose(fp2);
        puts(str1);
        puts(str2);
    }
    return 0;
}
