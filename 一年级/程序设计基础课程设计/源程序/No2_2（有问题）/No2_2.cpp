#include<stdio.h>
#include<string.h>

int main(){
    FILE *fp1=NULL,*fp2=NULL;
    fp1=fopen("No2_2_1.txt","r");
    fp2=fopen("No2_2_2.txt","a");
    if(fp1==NULL||fp2==NULL){
        printf("无法正确打开文件\n");
    }
    else{
        char s1;
        int a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0,i=0,j=0,k=0,l=0,m=0;
        int n=0,o=0,p=0,q=0,r=0,s=0,t=0,u=0,v=0,w=0,x=0,y=0,z=0;
        while(fscanf(fp1,"%c",&s1)!=EOF){
            if(((s1>64)&&(s1<91))||((s1>96)&&(s1<123))){
                if(s1=='a'||s1=='A')a++;
                else if(s1=='b'||s1=='B')b++;
                else if(s1=='c'||s1=='C')c++;
                else if(s1=='d'||s1=='D')d++;
                else if(s1=='e'||s1=='E')e++;
                else if(s1=='f'||s1=='F')f++;
                else if(s1=='g'||s1=='G')g++;
                else if(s1=='h'||s1=='H')h++;
                else if(s1=='i'||s1=='I')i++;
                else if(s1=='j'||s1=='J')j++;
                else if(s1=='k'||s1=='K')k++;
                else if(s1=='l'||s1=='L')l++;
                else if(s1=='m'||s1=='M')m++;
                else if(s1=='n'||s1=='N')n++;
                else if(s1=='o'||s1=='O')o++;
                else if(s1=='p'||s1=='P')p++;
                else if(s1=='q'||s1=='Q')q++;
                else if(s1=='r'||s1=='R')r++;
                else if(s1=='s'||s1=='S')s++;
                else if(s1=='t'||s1=='T')t++;
                else if(s1=='u'||s1=='U')u++;
                else if(s1=='v'||s1=='V')v++;
                else if(s1=='w'||s1=='W')w++;
                else if(s1=='x'||s1=='X')x++;
                else if(s1=='y'||s1=='Y')y++;
                else if(s1=='z'||s1=='Z')z++;
            }
        }
        printf("a:%d\nb:%d\nc:%d\nd:%d\ne:%d\nf:%d\ng:%d\n",a,b,c,d,e,f,g);
        printf("h:%d\ni:%d\nj:%d\nk:%d\nl:%d\nm:%d\n",h,i,j,k,l,m);
        printf("n:%d\no:%d\np:%d\nq:%d\nr:%d\ns:%d\nt:%d\n",n,o,p,q,r,s,t);
        printf("u:%d\nv:%d\nw:%d\nx:%d\ny:%d\nz:%d\n",u,v,w,x,y,z);
        
        //以下是查找并替换字符串功能 
        printf("请输入待查找的字符串\n");
        char a1[100]={0};
        gets(a1);
        char a2[100]={0};
        char a3[100]={0};
        char s2;
        fseek(fp1,0,0);
        int ii=-1;
        while(fscanf(fp1,"%s",&a3)!=EOF){
            if(strcmp(a1,a3)==0&&ii==-1){
            	ii=1;
            	printf("已找到您要查找的字符串，");
            	printf("请输入替换的字符串\n");
        		gets(a2);
                fprintf(fp2,"%s",a2);
            }
            else if(strcmp(a1,a3)==0&&ii==1){
            	ii=0;
            	fprintf(fp2,"%s",a2);
			}
            else{
            	fprintf(fp2,"%s",a3);
			}
			fscanf(fp1,"%c",&s2);
			if(s2=='\n'){
				fprintf(fp2,"\n");
			}
			else if(s2==' '){
				fprintf(fp2," ");
			}
        }
        if(ii==-1)printf("未找到您要查找的字符串\n");
    }
    fclose(fp1);
    fclose(fp2);
    remove("No2_2_1.txt");
    rename("No2_2_2.txt","No2_2_1.txt");
    printf("程序执行完成\n");
    return 0;
}
