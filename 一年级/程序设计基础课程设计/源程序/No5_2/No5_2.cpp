#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    srand((unsigned int)time(0));
    int a[10]={0};
    int i=0;
    int k=0;
    while(a[9]==0){
        int k=rand()%99+1;
        a[i]=k;
        for(int j=0;j<i;j++){
            if(a[j]==k){
                a[i]=0;
                i--;
                break;
            }
        }
        i++;
    }
    for(int j=0;j<10;j++){
        printf("%d  ",a[j]);
    }
    return 0;
}
