#include<stdio.h>
#include<string.h>
int k=0,o=0;
int len=0;
void find1(char a[],char b[][101],int c,int d){
	if(a[k]==b[d][o]){
		k++;o++;len++;
		if(len<c)return find1(a,b,c,d);
		if(len==c)printf("%s\n",b[d]);
	}
	else{
		if(k>0&&o>00&&a[k-1]==b[d][o-1]){
			len=0;k=0;return find1(a,b,c,d);
		}
		else{
			len=0;k=0;
			while(o<strlen(b[d])){
				o++;
				return find1(a,b,c,d);
			}
		}
	}
}


void find0(char a[],char b[][101],int c,int d){
	if(a[k]==b[d][o]||a[k]==b[d][o]+32||a[k]==b[d][o]-32){
		k++;o++;len++;
		if(len<c)return find0(a,b,c,d);
		if(len==c)printf("%s\n",b[d]);
	}
	else{
		if(k>0&&o>00&&(a[k-1]==b[d][o-1]||a[k-1]==b[d][o-1]+32||a[k-1]==b[d][o-1]-32)){
			len=0;k=0;return find0(a,b,c,d);
		}
		else{
			len=0;k=0;
			while(o<strlen(b[d])){
				o++;
				return find0(a,b,c,d);
			}
		}
	}
}



int main(){
	char a[101]={0};
	int m,n;
	scanf("%s%d%d",&a,&m,&n);
	char b[100][101]={0};
	for(int i=0;i<n;i++){
		scanf("%s",&b[i]);
	}
	/*printf("%s\n",a);
	for(int i=0;i<n;i++){
		printf("%s\n",&b[i]);
	}
	printf("\n");*/
	if(m==0){
		for(int i=0;i<n;i++){
			find0(a,b,strlen(a),i);
			k=0;o=0;len=0;
		}
	}
	else{
		for(int i=0;i<n;i++){
			find1(a,b,strlen(a),i);
			k=0;o=0;len=0;
		}
	}
	return 0;
}
