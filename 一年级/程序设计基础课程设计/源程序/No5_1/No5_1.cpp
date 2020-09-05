#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    srand((unsigned int)time(NULL));
    int i=rand()%99+1;
    int j=0;
    printf("请输入一个0-99的整数\n");
    scanf("%d",&j);
    while(true){
        if(i==j){
            printf("你猜对了\n");
            break;
        }
        if(i<j){
            printf("大了,请重新输入\n");
            scanf("%d",&j);
        }
        if(i>j){
            printf("小了，请重新输入\n");
            scanf("%d",&j);
        }
    }
    return 0;
}
