#include<stdio.h>

typedef struct hash{
	int key;
	int mark;//0表示没有被占用，1表示已经被占用 
}hash;

int IsExist(hash hash[], int key, int m){
	for(int i=0; i<m; i++){
		if(hash[i].key == key)return i;
	}
	return -1;
} 

int main(){
	int m, p;
	scanf("%d%d", &m, &p);
	int key, length = 0;
	hash hash[m];
	for(int i=0; i<m; i++){
		hash[i].key = -1;
		hash[i].mark = 0;
	}
	while(true){
		scanf("%d", &key);
		if(key == -1)break;
		else{
			int k = IsExist(hash, key, m);
			if(k != -1)printf("%d\n", k);
			else if(length == m-1){
				printf("Table full\n");
			} 
			else{
				int temp = key%p;
				if(hash[temp].mark == 0){
					hash[temp].key = key;
					hash[temp].mark = 1;
					printf("%d\n", temp);
					length++;
				}
				else if(hash[temp].mark == 1){
					int stamp = 0;
					for(int i=1; i<m; i++){
						if(stamp == 1)break;
						else{
//							temp = (key+i)%m;//错误 
							temp = (temp+1)%m;
							if(hash[temp].mark == 0){
								hash[temp].key = key;
								hash[temp].mark = 1;
								printf("%d\n", temp);
								length++;
								stamp = 1;
							}
						}
					}							 
				}
			}	
		}
	}
	return 0;
}
