#include<stdio.h>
#include<stdlib.h>

int main(){
    char a[1000]={0};
    gets(a);
    char *s;
    printf("%d\n",strtol(a,&s,2));
    return 0;
}
