#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    srand((unsigned int)time(NULL));
    int i=rand()%99+1;
    int j=0;
    printf("������һ��0-99������\n");
    scanf("%d",&j);
    while(true){
        if(i==j){
            printf("��¶���\n");
            break;
        }
        if(i<j){
            printf("����,����������\n");
            scanf("%d",&j);
        }
        if(i>j){
            printf("С�ˣ�����������\n");
            scanf("%d",&j);
        }
    }
    return 0;
}
