#include<stdio.h>

typedef struct{
    int shibu;
    int xubu;
}plural;

int main(){
    plural a,b,c;
    printf("请输入两个复数，实部和虚部以空格分隔\n");
    scanf("%d%d%d%d",&a.shibu,&a.xubu,&b.shibu,&b.xubu);
    printf("请选择您需要的运算法则(+、-、*)\n");
    char s1,s2;
    scanf("%c%c",&s1,&s2);
    if(s2=='+'){
        c.shibu=a.shibu+b.shibu;
        c.xubu=a.xubu+b.xubu;
    }
    else if(s2=='-'){
        c.shibu=a.shibu-b.shibu;
        c.xubu=a.xubu-b.xubu;
    }
    else if(s2=='*'){
        c.shibu=(a.shibu*b.shibu)-(a.xubu*b.xubu);
        c.xubu=(a.xubu*b.shibu)+(a.shibu*b.xubu);
    }
    else printf("输入有误\n");
    printf("%d %di",c.shibu,c.xubu);
    return 0;
}
