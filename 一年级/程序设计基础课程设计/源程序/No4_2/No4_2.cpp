#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>


typedef struct{
	//定义一个图书的结构体 
    int booknumber;
    char bookname[100];
    int bookamount;
}book;


typedef struct{
	//定义一个读者的结构体 
    int readernumber;
    char readername[100];
    book borrowing;
}reader;


//初始化读者和图书的数量 
reader readerarray[1000];//最多有1000的读者 
book bookarray[10000];//最多有10000本书 


int borrowbook(char a[100],book b){
	//借书函数
	//a为输入的读者姓名，b为书的相关信息 
	int i=0;
	while(i<1000){
		if(strcmp(a,readerarray[i].readername)==0){
			readerarray[i].borrowing=b;
			break; 
		}
		i++;
	}
}


int returnbook(char a[100],book b){
	//还书函数 
	//a为输入的读者姓名，b为书的相关信息 ,b没用，只是和borrowbook函数保持一致 
	int i=0;
	while(i<1000){
		if(strcmp(a,readerarray[i].readername)==0){
			readerarray[i].borrowing.booknumber=0;
			strcpy(readerarray[i].borrowing.bookname,"0");
			readerarray[i].borrowing.bookamount=0;
			break;
		}
		i++;
	}
}


int addreader(int a,char b[100],book c){
	//添加某读者函数 
	//a为读者编号，b为读者姓名，c为书的相关信息 
	int i=0;
	while(i<1000) {
		if(readerarray[i].readernumber==0){
		//通过寻找空白的读者编号 
			readerarray[i].readernumber=a;
			strcpy(readerarray[i].readername,b);
			readerarray[i].borrowing.booknumber=0;
			strcpy(readerarray[i].borrowing.bookname,"0");
			readerarray[i].borrowing.bookamount=0;
			break;
		}
		else if(strcmp(readerarray[i].readername,"")==0){
		//通过寻找空白的读者姓名 
			readerarray[i].readernumber=a;
			strcpy(readerarray[i].readername,b);
			readerarray[i].borrowing.booknumber=0;
			strcpy(readerarray[i].borrowing.bookname,"0");
			readerarray[i].borrowing.bookamount=0;
			break;
		}
		i++; 
	} 
} 


int searchreader(int a,char b[100]){
	//查找某读者函数 
	//a为读者编号，b为读者姓名，c为书的相关信息
	int i=0;
	while(i<1000){
		if(readerarray[i].readernumber==a){
		//通过寻找相同的读者编号 
			break;
		}
		else if(strcmp(readerarray[i].readername,b)==0){
		//通过寻找相同的读者姓名 
			break;
		}
		i++;
	}
	//i=1000说明没找到 
	return i;
}



int deletereader(int a,char b[100]){
	//删除某读者 
	//a为读者编号，b为读者姓名，c为书的相关信息 
	int i=0;
	while(i<1000){
		if(readerarray[i].readernumber==a){
		//通过寻找相同的读者编号 
			readerarray[i].readernumber=0;
			strcpy(readerarray[i].readername,"0");
			readerarray[i].borrowing.booknumber=0;
			strcpy(readerarray[i].borrowing.bookname,"0");
			readerarray[i].borrowing.bookamount=0;
			break;
		}
		else if(strcmp(b,readerarray[i].readername)==0){
		//通过寻找相同的读者姓名 
			readerarray[i].readernumber=0;
			strcpy(readerarray[i].readername,"0");
			readerarray[i].borrowing.booknumber=0;
			strcpy(readerarray[i].borrowing.bookname,"0");
			readerarray[i].borrowing.bookamount=0;
			break;
		}
		i++;
	}
}


int addbook(int a,char b[100],int c){
	//添加图书函数 
	//a为图书编号，b为图书名称，c为图书数量 
	int i=0;
	while(i<10000){
		if(bookarray[i].booknumber==0){
		//通过寻找空白的图书编号 
			bookarray[i].booknumber=a;
			strcpy(bookarray[i].bookname,b);
			bookarray[i].bookamount=c;
			break;
		}
		else if(strcmp(bookarray[i].bookname,"")==0){
		//通过寻找空白的图书名称 
			bookarray[i].booknumber=a;
			strcpy(bookarray[i].bookname,b);
			bookarray[i].bookamount=c;
			break;
		}
		i++;
	} 
}


int searchbook(int a,char b[100]){
	//查找某图书函数 
	//a为图书编号，b为图书名称，c为图书数量 
	int i=0;
	while(i<10000){
		if(bookarray[i].booknumber==a){
		//通过寻找相同的图书编号 
			break;
		}
		else if(strcmp(bookarray[i].bookname,b)==0){
		//通过寻找相同的图书名称
			break;
		}
		i++;
	} 
	//i=10000说明没找到 
	return i;
}


int deletebook(int a,char b[100]){
	//删除某图书函数 
	//a为图书编号，b为图书名称，c为图书数量 
	int i=0;
	while(i<10000){
		if(bookarray[i].booknumber==a){
		//通过寻找相同的图书编号 
			bookarray[i].booknumber=0;
			strcpy(bookarray[i].bookname,"0");
			bookarray[i].bookamount=0;
			break; 
		}
		else if(strcmp(bookarray[i].bookname,b)==0){
		//通过寻找相同的图书名称 
			bookarray[i].booknumber=0;
			strcpy(bookarray[i].bookname,"0");
			bookarray[i].bookamount=0;
			break;
		}
		i++;
	} 
}

book numberorname(char a[100]){
	//该函数可以通过读者输入的图书编号或者图书名称查找图书 
	book b;
	if(isdigit(a[0])!=0){
	//通过图书编号查找该图书 
		b.booknumber=atoi(a);
		strcpy(b.bookname,"");
		int k=0;
		while(k<10000){
			if(b.booknumber==bookarray[k].booknumber){
				b=bookarray[k];
				break;
			}
			k++;
		} 
	}
	else{
		//通过图书名称查找该图书 
		strcpy(b.bookname,a);
		int k=0;
		while(k<10000){
			if(strcmp(bookarray[k].bookname,b.bookname)==0){
				b=bookarray[k];
				break;
			}
			k++;
		}
	}
	return b;
}


int main(){
	FILE *fp1=NULL,*fp2=NULL;
	FILE *fp3=NULL,*fp4=NULL;
	fp1=fopen("reader.txt","r");
	fp2=fopen("book.txt","r");
	if(fp1==NULL||fp2==NULL){
		printf("未能成功读入数据\n");
	}
	else{
	int i=0;
	int j=0;
	while(~fscanf(fp1,"%d%s%d%s%d",&readerarray[i].readernumber,&readerarray[i].readername,&readerarray[i].borrowing.booknumber,&readerarray[i].borrowing.bookname,&readerarray[i].borrowing.bookamount)){
		i++;
	}
	while(~fscanf(fp2,"%d%s%d",&bookarray[j].booknumber,&bookarray[j].bookname,&bookarray[j].bookamount)){
		j++;
	}
	printf("欢迎来到图书馆管理系统\n");
	while(true){
		printf("请选择您的身份\n");
		printf("读者请选择1，管理员请选择2，退出请选择3\n");
		int choice1=0;
		scanf("%d",&choice1);
		while(choice1==1){
			printf("请选择您需要的服务\n");
			printf("借书请选择1，还书请选择2，图书信息查询请选择3，退出请选择4\n");
			int choice2=0;
			scanf("%d",&choice2);
			if(choice2==1){
				reader newreader;
				book newbook;
				char a[100]={0}; 
				printf("请输入读者姓名\n");
				scanf("%s",&newreader.readername);
				printf("请输入要借图书的编号或者名称\n");
				scanf("%s",&a); 
				newbook=numberorname(a);
				borrowbook(newreader.readername,newbook);
				printf("您的姓名：%s\n所借图书编号：%d\n所借图书名称：%s\n",newreader.readername,newbook.booknumber,newbook.bookname);
			}
			else if(choice2==2){
				reader newreader;
				book newbook;
				char a[100]={0}; 
				printf("请输入读者姓名\n");
				scanf("%s",&newreader.readername);
				printf("请输入要还图书的编号或者名称\n");
				scanf("%s",&a); 
				newbook=numberorname(a);
				returnbook(newreader.readername,newbook);
				printf("您的姓名：%s\n所借图书编号：%d\n所借图书名称：%s\n",newreader.readername,newbook.booknumber,newbook.bookname);
			}
			else if(choice2==3){
				book newbook;
				char a[100]={0};
				printf("请输入要查询图书的编号或者名称\n");
				scanf("%s",&a);
				newbook=numberorname(a);
				printf("该图书编号：%d\n该图书名称：%s\n",newbook.booknumber,newbook.bookname);
			}
			else if(choice2==4){
				break;
			}
			else{
				printf("输入有误，请重新选择您需要的服务111\n");
				continue;
			}
		}
		while(choice1==2){
			printf("请选择您需要的服务\n");
			printf("录入读者信息请选择1，修改读者信息请选择2，删除读者信息请选择3，");
			printf("录入图书信息请选择4，修改图书信息请选择5，删除图书信息请选择6，退出请选择7\n");
			int choice3=0;
			scanf("%d",&choice3);
			if(choice3==1){
				printf("请输入待录入读者信息的编号\n");
				int a=0;
				scanf("%d",&a);
				printf("请输入待录入读者信息的姓名\n");
				char b[100]={0};
				scanf("%s",&b);
				book c;
				addreader(a,b,c);
			}
			else if(choice3==2){
				printf("请输入原读者信息的编号或姓名\n");
				char array[100]={0};
				scanf("%s",&array);
				int k=-1;
				if(isdigit(array[0])!=0){
					int a=atoi(array);
					char b[100]={0};
					k=searchreader(a,b);
				}
				else{
					int a=0;
					k=searchreader(a,array);
				}
				if(k<1000&&k>-1){
					printf("请输入新的编号\n");
					scanf("%d",&readerarray[k].readernumber);
					printf("请输入新的姓名\n");
					scanf("%s",&readerarray[k].readername); 
				}
				else{
					printf("没有该读者的旧信息\n");
				}
			}
			else if(choice3==3){
				printf("请输入待删除读者的编号或者姓名\n");
				char array[100]={0};
				scanf("%s",&array);
				if(isdigit(array[0])!=0){
					int a=atoi(array);
					char b[100]={0};
					deletereader(a,b);
				}
				else{
					int a=0;
					deletereader(a,array);
				}
			}
			else if(choice3==4){
				printf("请输入待录入图书的编号\n");
				int a=0;
				scanf("%d",&a);
				printf("请输入待录入图书的名称\n");
				char b[100]={0};
				scanf("%s",&b);
				printf("请输入待录入图书的数量\n");
				int c=0;
				scanf("%d",&c);
				addbook(a,b,c);
			}
			else if(choice3==5){
				printf("请输入原图书的编号或名称\n");
				char array[100]={0};
				scanf("%s",&array);
				int k=-1;
				if(isdigit(array[0])!=0){
					int a=atoi(array);
					char b[100]={0};
					k=searchbook(a,b);
				}
				else{
					int a=0;
					k=searchbook(a,array);
				}
				if(k<10000&&k>-1){
					printf("请输入新的编号\n");
					scanf("%d",&bookarray[k].booknumber);
					printf("请输入新的名称\n");
					scanf("%s",&bookarray[k].bookname);
					printf("请输入新的数量\n");
					scanf("%d",&bookarray[k].bookamount);
				}
				else{
					printf("未找到该图书的旧信息\n");
				}
			}
			else if(choice3==6){
				printf("请输入待删除图书的编号或者名称\n");
				char array[100]={0};
				scanf("%s",&array);
				if(isdigit(array[0])!=0){
					int a=atoi(array);
					char b[100]={0};
					deletebook(a,b);
				}
				else{
					int a=0;
					deletebook(a,array);
				}
			}
			else if(choice3==7)break;
			else{
				printf("输入有误，请重新输入222\n");
				continue;
			}
		} 
		if(choice1==1||choice1==2||choice1==3){
			if(choice1==3)break;
		}
		else{
			printf("输入有误，请重新输入333\n");
			continue;
		}
	}
	fp3=fopen("reader1.txt","w");
	fp4=fopen("book1.txt","w");
	for(int i1=0;i1<1000;i1++){
		fprintf(fp3,"%d %s %d %s %d\n",readerarray[i1].readernumber,readerarray[i1].readername,readerarray[i1].borrowing.booknumber,readerarray[i1].borrowing.bookname,readerarray[i1].borrowing.bookamount);
	}
	for(int j1=0;j1<10000;j1++){
		fprintf(fp4,"%d %s %d\n",bookarray[j1].booknumber,bookarray[j1].bookname,bookarray[j1].bookamount);
	}
	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
	fclose(fp4);
	remove("reader.txt");
    rename("reader1.txt","reader.txt");
    remove("book.txt");
    rename("book1.txt","book.txt");
	printf("欢迎您再次使用本图书馆管理系统，再见。\n"); 
}
    return 0;
}
