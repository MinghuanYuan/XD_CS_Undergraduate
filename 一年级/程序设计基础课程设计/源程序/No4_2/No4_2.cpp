#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>


typedef struct{
	//����һ��ͼ��Ľṹ�� 
    int booknumber;
    char bookname[100];
    int bookamount;
}book;


typedef struct{
	//����һ�����ߵĽṹ�� 
    int readernumber;
    char readername[100];
    book borrowing;
}reader;


//��ʼ�����ߺ�ͼ������� 
reader readerarray[1000];//�����1000�Ķ��� 
book bookarray[10000];//�����10000���� 


int borrowbook(char a[100],book b){
	//���麯��
	//aΪ����Ķ���������bΪ��������Ϣ 
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
	//���麯�� 
	//aΪ����Ķ���������bΪ��������Ϣ ,bû�ã�ֻ�Ǻ�borrowbook��������һ�� 
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
	//���ĳ���ߺ��� 
	//aΪ���߱�ţ�bΪ����������cΪ��������Ϣ 
	int i=0;
	while(i<1000) {
		if(readerarray[i].readernumber==0){
		//ͨ��Ѱ�ҿհ׵Ķ��߱�� 
			readerarray[i].readernumber=a;
			strcpy(readerarray[i].readername,b);
			readerarray[i].borrowing.booknumber=0;
			strcpy(readerarray[i].borrowing.bookname,"0");
			readerarray[i].borrowing.bookamount=0;
			break;
		}
		else if(strcmp(readerarray[i].readername,"")==0){
		//ͨ��Ѱ�ҿհ׵Ķ������� 
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
	//����ĳ���ߺ��� 
	//aΪ���߱�ţ�bΪ����������cΪ��������Ϣ
	int i=0;
	while(i<1000){
		if(readerarray[i].readernumber==a){
		//ͨ��Ѱ����ͬ�Ķ��߱�� 
			break;
		}
		else if(strcmp(readerarray[i].readername,b)==0){
		//ͨ��Ѱ����ͬ�Ķ������� 
			break;
		}
		i++;
	}
	//i=1000˵��û�ҵ� 
	return i;
}



int deletereader(int a,char b[100]){
	//ɾ��ĳ���� 
	//aΪ���߱�ţ�bΪ����������cΪ��������Ϣ 
	int i=0;
	while(i<1000){
		if(readerarray[i].readernumber==a){
		//ͨ��Ѱ����ͬ�Ķ��߱�� 
			readerarray[i].readernumber=0;
			strcpy(readerarray[i].readername,"0");
			readerarray[i].borrowing.booknumber=0;
			strcpy(readerarray[i].borrowing.bookname,"0");
			readerarray[i].borrowing.bookamount=0;
			break;
		}
		else if(strcmp(b,readerarray[i].readername)==0){
		//ͨ��Ѱ����ͬ�Ķ������� 
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
	//���ͼ�麯�� 
	//aΪͼ���ţ�bΪͼ�����ƣ�cΪͼ������ 
	int i=0;
	while(i<10000){
		if(bookarray[i].booknumber==0){
		//ͨ��Ѱ�ҿհ׵�ͼ���� 
			bookarray[i].booknumber=a;
			strcpy(bookarray[i].bookname,b);
			bookarray[i].bookamount=c;
			break;
		}
		else if(strcmp(bookarray[i].bookname,"")==0){
		//ͨ��Ѱ�ҿհ׵�ͼ������ 
			bookarray[i].booknumber=a;
			strcpy(bookarray[i].bookname,b);
			bookarray[i].bookamount=c;
			break;
		}
		i++;
	} 
}


int searchbook(int a,char b[100]){
	//����ĳͼ�麯�� 
	//aΪͼ���ţ�bΪͼ�����ƣ�cΪͼ������ 
	int i=0;
	while(i<10000){
		if(bookarray[i].booknumber==a){
		//ͨ��Ѱ����ͬ��ͼ���� 
			break;
		}
		else if(strcmp(bookarray[i].bookname,b)==0){
		//ͨ��Ѱ����ͬ��ͼ������
			break;
		}
		i++;
	} 
	//i=10000˵��û�ҵ� 
	return i;
}


int deletebook(int a,char b[100]){
	//ɾ��ĳͼ�麯�� 
	//aΪͼ���ţ�bΪͼ�����ƣ�cΪͼ������ 
	int i=0;
	while(i<10000){
		if(bookarray[i].booknumber==a){
		//ͨ��Ѱ����ͬ��ͼ���� 
			bookarray[i].booknumber=0;
			strcpy(bookarray[i].bookname,"0");
			bookarray[i].bookamount=0;
			break; 
		}
		else if(strcmp(bookarray[i].bookname,b)==0){
		//ͨ��Ѱ����ͬ��ͼ������ 
			bookarray[i].booknumber=0;
			strcpy(bookarray[i].bookname,"0");
			bookarray[i].bookamount=0;
			break;
		}
		i++;
	} 
}

book numberorname(char a[100]){
	//�ú�������ͨ�����������ͼ���Ż���ͼ�����Ʋ���ͼ�� 
	book b;
	if(isdigit(a[0])!=0){
	//ͨ��ͼ���Ų��Ҹ�ͼ�� 
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
		//ͨ��ͼ�����Ʋ��Ҹ�ͼ�� 
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
		printf("δ�ܳɹ���������\n");
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
	printf("��ӭ����ͼ��ݹ���ϵͳ\n");
	while(true){
		printf("��ѡ���������\n");
		printf("������ѡ��1������Ա��ѡ��2���˳���ѡ��3\n");
		int choice1=0;
		scanf("%d",&choice1);
		while(choice1==1){
			printf("��ѡ������Ҫ�ķ���\n");
			printf("������ѡ��1��������ѡ��2��ͼ����Ϣ��ѯ��ѡ��3���˳���ѡ��4\n");
			int choice2=0;
			scanf("%d",&choice2);
			if(choice2==1){
				reader newreader;
				book newbook;
				char a[100]={0}; 
				printf("�������������\n");
				scanf("%s",&newreader.readername);
				printf("������Ҫ��ͼ��ı�Ż�������\n");
				scanf("%s",&a); 
				newbook=numberorname(a);
				borrowbook(newreader.readername,newbook);
				printf("����������%s\n����ͼ���ţ�%d\n����ͼ�����ƣ�%s\n",newreader.readername,newbook.booknumber,newbook.bookname);
			}
			else if(choice2==2){
				reader newreader;
				book newbook;
				char a[100]={0}; 
				printf("�������������\n");
				scanf("%s",&newreader.readername);
				printf("������Ҫ��ͼ��ı�Ż�������\n");
				scanf("%s",&a); 
				newbook=numberorname(a);
				returnbook(newreader.readername,newbook);
				printf("����������%s\n����ͼ���ţ�%d\n����ͼ�����ƣ�%s\n",newreader.readername,newbook.booknumber,newbook.bookname);
			}
			else if(choice2==3){
				book newbook;
				char a[100]={0};
				printf("������Ҫ��ѯͼ��ı�Ż�������\n");
				scanf("%s",&a);
				newbook=numberorname(a);
				printf("��ͼ���ţ�%d\n��ͼ�����ƣ�%s\n",newbook.booknumber,newbook.bookname);
			}
			else if(choice2==4){
				break;
			}
			else{
				printf("��������������ѡ������Ҫ�ķ���111\n");
				continue;
			}
		}
		while(choice1==2){
			printf("��ѡ������Ҫ�ķ���\n");
			printf("¼�������Ϣ��ѡ��1���޸Ķ�����Ϣ��ѡ��2��ɾ��������Ϣ��ѡ��3��");
			printf("¼��ͼ����Ϣ��ѡ��4���޸�ͼ����Ϣ��ѡ��5��ɾ��ͼ����Ϣ��ѡ��6���˳���ѡ��7\n");
			int choice3=0;
			scanf("%d",&choice3);
			if(choice3==1){
				printf("�������¼�������Ϣ�ı��\n");
				int a=0;
				scanf("%d",&a);
				printf("�������¼�������Ϣ������\n");
				char b[100]={0};
				scanf("%s",&b);
				book c;
				addreader(a,b,c);
			}
			else if(choice3==2){
				printf("������ԭ������Ϣ�ı�Ż�����\n");
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
					printf("�������µı��\n");
					scanf("%d",&readerarray[k].readernumber);
					printf("�������µ�����\n");
					scanf("%s",&readerarray[k].readername); 
				}
				else{
					printf("û�иö��ߵľ���Ϣ\n");
				}
			}
			else if(choice3==3){
				printf("�������ɾ�����ߵı�Ż�������\n");
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
				printf("�������¼��ͼ��ı��\n");
				int a=0;
				scanf("%d",&a);
				printf("�������¼��ͼ�������\n");
				char b[100]={0};
				scanf("%s",&b);
				printf("�������¼��ͼ�������\n");
				int c=0;
				scanf("%d",&c);
				addbook(a,b,c);
			}
			else if(choice3==5){
				printf("������ԭͼ��ı�Ż�����\n");
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
					printf("�������µı��\n");
					scanf("%d",&bookarray[k].booknumber);
					printf("�������µ�����\n");
					scanf("%s",&bookarray[k].bookname);
					printf("�������µ�����\n");
					scanf("%d",&bookarray[k].bookamount);
				}
				else{
					printf("δ�ҵ���ͼ��ľ���Ϣ\n");
				}
			}
			else if(choice3==6){
				printf("�������ɾ��ͼ��ı�Ż�������\n");
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
				printf("������������������222\n");
				continue;
			}
		} 
		if(choice1==1||choice1==2||choice1==3){
			if(choice1==3)break;
		}
		else{
			printf("������������������333\n");
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
	printf("��ӭ���ٴ�ʹ�ñ�ͼ��ݹ���ϵͳ���ټ���\n"); 
}
    return 0;
}
