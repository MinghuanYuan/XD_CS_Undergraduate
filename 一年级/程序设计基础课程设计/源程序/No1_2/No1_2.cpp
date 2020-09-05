#include<stdio.h>

int main(){
    FILE *fp1=NULL,*fp2=NULL,*fp3=NULL;
    int a1[100]={0};
    int i=0;
    fp1=fopen("No1_2_1.txt","r");
    fp2=fopen("No1_2_2.txt","r");
    //以只读的方式打开同目录下的两个文件 
    if(fp1==NULL||fp2==NULL){
        printf("无法正确打开文件\n");
    }
    else{
        while(~fscanf(fp1,"%d",&a1[i])){
            i++;
        }
        while(~fscanf(fp2,"%d",&a1[i])){
            i++;
        }
    }
    fclose(fp1);
    fclose(fp2);
    int lenth=0;
    for(int j=0;j<100;j++){
        if(a1[j]!=0)lenth++;
    }
    for(int j=0;j<lenth;j++){
        for(int k=j+1;k<lenth;k++){
            if(a1[j]>a1[k]){
                int t=a1[j];
                a1[j]=a1[k];
                a1[k]=t;
            }
        }
    }
    fp3=fopen("No1_2_3.txt","w");
    ////以只写的方式打开同目录下的文件
    if(fp3==NULL){
        printf("无法正确打开文件\n");
    }
    else{
        for(int j=0;j<lenth;j++){
            fprintf(fp3,"%d\t",a1[j]);
        }
    }
    fclose(fp3);
    printf("程序执行完成\n");
    return 0;
}
