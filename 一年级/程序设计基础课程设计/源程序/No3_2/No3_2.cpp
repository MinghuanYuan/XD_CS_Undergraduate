#include<stdio.h>

typedef struct{
    int shibu;
    int xubu;
}plural;

int main(){
    plural a,b,c;
    printf("����������������ʵ�����鲿�Կո�ָ�\n");
    scanf("%d%d%d%d",&a.shibu,&a.xubu,&b.shibu,&b.xubu);
    printf("��ѡ������Ҫ�����㷨��(+��-��*)\n");
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
    else printf("��������\n");
    printf("%d %di",c.shibu,c.xubu);
    return 0;
}
