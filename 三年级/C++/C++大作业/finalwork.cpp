#include<iostream>
#include<fstream>
#include<vector>
#include<string>

using namespace std;

class Staff{
	protected: int number;
	protected: string name;
	protected: int age;
	protected: string position;
	protected: bool isDeleted;
	
	public: Staff(){}
	public: Staff(int number, string name, int age, string position, bool isDeleted){
		this->number = number;
		this->name = name;
		this->age = age;
		this->position =position;
		this->isDeleted = isDeleted;
	}
	
	virtual void updateProperty(int property, int update){
		if(property == 1)number = update;
		else if(property == 3)age = update;
	}
	
	virtual void output(){
		cout<<"Ա����ţ�"<<number; 
		cout<<"\t\tԱ��������"<<name;
		cout<<"\t\tԱ�����䣺"<<age;
		cout<<"\t\tԱ��ְλ��"<<position<<endl;
	}
	
	virtual void outputWithNumber(){
		cout<<"1Ա����ţ�"<<number; 
		cout<<"\t\t2Ա��������"<<name;
		cout<<"\t\t3Ա�����䣺"<<age;
		cout<<"\t\t4Ա��ְλ��"<<position<<endl;
	} 
	
	virtual void updateProperty(int property, string update){
		if(property == 2)name = update;
		else if(property == 4)position = update;
	}
	
	public: int getNumber(){return number;}
	public: void setNumber(int number){
		this->number = number;
	}
	
	public: string getName(){return name;}
	public: void setName(string name){
		this->name = name;
	}
	
	public: int getAge(){return age;}
	public: void setAge(int age){
		this->age = age;
	}
	
	public: string getPosition(){return position;}
	public: void setPosition(string position){
		this->position = position;
	}
	
	public: bool getIsDeleted(){return isDeleted;}
	public: void setIsDeleted(bool isDeleted){
		this->isDeleted = isDeleted;
	}
	
};

class Salesman:virtual public Staff{
	protected: int salecount;
	
	public: Salesman(int number, string name, int age, string position, bool isDeleted, int salecount):Staff(number, name, age, position, isDeleted){
		this->salecount = salecount;
	}
	
	virtual void updateProperty(int property, int update){
		Staff::updateProperty(property, update);
		if(property == 5)salecount = update;
	}
	
	virtual void output(){
		cout<<"Ա����ţ�"<<number; 
		cout<<"\t\tԱ��������"<<name;
		cout<<"\t\tԱ�����䣺"<<age;
		cout<<"\t\tԱ��ְλ��"<<position;
		cout<<"\t\t���۶"<<salecount<<endl;
	}
	
	virtual void outputWithNumber(){
		cout<<"1Ա����ţ�"<<number; 
		cout<<"\t\t2Ա��������"<<name;
		cout<<"\t\t3Ա�����䣺"<<age;
		cout<<"\t\t4Ա��ְλ��"<<position;
		cout<<"\t\t5���۶"<<salecount<<endl;
	}
	
	public: int getSaleCount(){return salecount;}
	
};

class Manager:virtual public Staff{
	protected: int managestaffcount;
	
	public: Manager(int number, string name, int age, string position, bool isDeleted, int managestaffcount):Staff(number, name, age, position, isDeleted){
		this->managestaffcount = managestaffcount;
	}
	
	virtual void updateProperty(int property, int update){
		Staff::updateProperty(property, update);
		if(property == 6)managestaffcount = update;
	}
	
	virtual void output(){
		cout<<"Ա����ţ�"<<number; 
		cout<<"\t\tԱ��������"<<name;
		cout<<"\t\tԱ�����䣺"<<age;
		cout<<"\t\tԱ��ְλ��"<<position;
		cout<<"\t\t����������"<<managestaffcount<<endl;
	}
	
	virtual void outputWithNumber(){
		cout<<"1Ա����ţ�"<<number; 
		cout<<"\t\t2Ա��������"<<name;
		cout<<"\t\t3Ա�����䣺"<<age;
		cout<<"\t\t4Ա��ְλ��"<<position;
		cout<<"\t\t6����������"<<managestaffcount<<endl;
	}
	
	public: int getManageStaffCount(){return managestaffcount;}
	
};

class SalesManager:public Salesman, public Manager{
	public: SalesManager(int number, string name, int age, string position, bool isDeleted, int salecount, int managestaffcount):Staff(number, name, age, position, isDeleted), Salesman(number, name, age, position, isDeleted, salecount), Manager(number, name, age, position, isDeleted, managestaffcount){}
	
	virtual void updateProperty(int property, int update){
		Staff::updateProperty(property, update);
		if(property == 5)salecount = update;
		else if(property == 6)managestaffcount = update;
	}
	
	virtual void output(){
		cout<<"Ա����ţ�"<<number; 
		cout<<"\t\tԱ��������"<<name;
		cout<<"\t\tԱ�����䣺"<<age;
		cout<<"\t\tԱ��ְλ��"<<position;
		cout<<"\t\t���۶"<<salecount;
		cout<<"\t\t����������"<<managestaffcount<<endl;
	}
	
	virtual void outputWithNumber(){
		cout<<"1Ա����ţ�"<<number; 
		cout<<"\t\t2Ա��������"<<name;
		cout<<"\t\t3Ա�����䣺"<<age;
		cout<<"\t\t4Ա��ְλ��"<<position;
		cout<<"\t\t5���۶"<<salecount;
		cout<<"\t\t6����������"<<managestaffcount<<endl;
	}
	
};

int findByNumber(vector<Staff*> obj, int number, int sum){
	for(int i=0; i<sum; i++){
		if(obj[i]->getNumber() == number)return i;
	}
	return -1;
}

int findByName(vector<Staff*> obj, string name, int sum){
	for(int i=0; i<sum; i++){
		if(obj[i]->getName() == name)return i;
	}
	return -1;
}

int main(){
	
	ifstream infile;
	infile.open("test.txt", ios::in);
	
	int number;
	string name;
	int age;
	string position;
	bool isDeleted;
	int salecount;
	int managestaffcount;
	
	int sum = 0;
	vector<Staff*> obj;
	
	int id;
	int property;
	int choice;
	
	while(!infile.eof()){
		infile>>number>>name>>age>>position>>isDeleted;
		if(infile.fail())break;
		else if(position == "Staff"){
			Staff* temp = new Staff(number, name, age, position, isDeleted);
			obj.push_back(temp);
			sum++;
		}
		else if(position == "Salesman"){
			infile>>salecount;
			Salesman* temp = new Salesman(number, name, age, position, isDeleted, salecount);
			obj.push_back(temp);
			sum++;
		}
		else if(position == "Manager"){
			infile>>managestaffcount;
			Manager* temp = new Manager(number, name, age, position, isDeleted, managestaffcount);
			obj.push_back(temp);
			sum++;
		}
		else if(position == "SalesManager"){
			infile>>salecount>>managestaffcount;
			SalesManager* temp = new SalesManager(number, name, age, position, isDeleted, salecount, managestaffcount);
			obj.push_back(temp);
			sum++;
		}
	}
	
	infile.close();
	
	int mode = 0;
	while(mode != 8){
		cout<<"--------------------------------------------"<<endl;
		cout<<"------��������Ӧ����ѡ������Ҫ�Ĺ��ܣ�------"<<endl; 
		cout<<"1����������"<<endl;
		cout<<"2����������"<<endl;
		cout<<"3����ѯ����"<<endl;
		cout<<"4��ɾ������"<<endl;
		cout<<"5�������ļ�"<<endl;
		cout<<"6��ͳ������"<<endl;
		cout<<"7���˳�ϵͳ"<<endl;
		cin>>mode;
		switch(mode){
			case 1:{
				cout<<"������Ա����š�����������"<<endl;
				cin>>number>>name>>age;
				cout<<"��ѡ�����ӵ�Ա������"<<endl;
				cout<<"1��Salesman	2��Manager	3��SalesManager"<<endl;
				cin>>choice;
				switch(choice){
					case 1:{
						cout<<"���������۶�"<<endl;
						cin>>salecount;
						Salesman* temp = new Salesman(number, name, age, "Salesman", false, salecount);
						obj.push_back(temp);
						sum++;
						break;
					}
					case 2:{
						cout<<"�������������"<<endl;
						cin>>managestaffcount;
						Manager* temp = new Manager(number, name, age, "Manager", false, managestaffcount);
						obj.push_back(temp);
						sum++;
						break;
					}
					case 3:{
						cout<<"���������۶�"<<endl;
						cin>>salecount;
						cout<<"�������������"<<endl;
						cin>>managestaffcount;
						SalesManager* temp = new SalesManager(number, name, age, "SalesManager", false, salecount, managestaffcount);
						obj.push_back(temp);
						sum++;
						break;
					}
				}
				break;
			}
			case 2:{
				cout<<"�����ǹ�˾����Ա��"<<endl;
				for(int i=0; i<sum; i++){
					obj[i]->output();
				}
				cout<<"��������Ҫ���µ�Ա�����"<<endl;
				cin>>number;
				id = findByNumber(obj, number, sum);
				obj[id]->outputWithNumber(); 
				cout<<"��������Ӧ����ѡ����Ҫ���µ�����"<<endl;
				cin>>property;
				if(property == 2 || property == 4){
					cout<<"������������ֵ"<<endl;
					string update;
					cin>>update;
					obj[id]->updateProperty(property, update);
				}
				else{
					cout<<"������������ֵ"<<endl;
					int update;
					cin>>update;
					obj[id]->updateProperty(property, update);
				}
				cout<<"���³ɹ�"<<endl; 
				obj[id]->output();
				break;
			}
			case 3:{
				cout<<"��������Ӧ����ѡ���ѯ��ʽ"<<endl;
				cout<<"1����ѯ����Ա��"<<endl;
				cout<<"2����Ա����Ų�ѯ"<<endl;
				cout<<"3����Ա��������ѯ"<<endl;
				cin>>choice;
				switch(choice){
					case 1:{
						cout<<"�����ǹ�˾����Ա��"<<endl;
						for(int i=0; i<sum; i++){
							if(obj[i]->getIsDeleted() != true){
								obj[i]->output();
							}
						}
						break;
					}
					case 2:{
						cout<<"���������ѯ��Ա�����"<<endl;
						cin>>number; 
						id = findByNumber(obj, number, sum);
						obj[id]->output(); 
						break;
					}
					case 3:{
						cout<<"���������ѯ��Ա������"<<endl;
						cin>>name;
						id = findByName(obj, name, sum);
						obj[id]->output(); 
						break;
					}
				} 
				break;
			}
			case 4:{
				cout<<"�������ɾ����Ա�����"<<endl;
				cin>>number; 
				id = findByNumber(obj, number, sum);
				obj[id]->setIsDeleted(true);
				break;
			}
			case 5:{
				for(int i=0; i<sum; i++){
					if(obj[i]->getIsDeleted() == true){
						obj.erase(obj.begin()+i);
						sum--;
					}
				}
				cout<<"�ļ��������"<<endl;			
				break;
			}
			case 6:{
				int salesmansum = 0;
				int managersum = 0;
				int salesmanagersum = 0;
				for(int i=0; i<sum; i++){
					if(obj[i]->getPosition() == "Salesman")salesmansum++;
					else if(obj[i]->getPosition() == "Manager")managersum++;
					else if(obj[i]->getPosition() == "SalesManager")salesmanagersum++;
				}
				cout<<"Salesman�У�"<<salesmansum<<"��"<<endl;
				cout<<"Manager�У�"<<managersum<<"��"<<endl;
				cout<<"SalesManager�У�"<<salesmanagersum<<"��"<<endl; 
				cout<<"Staff�У�"<<sum<<"��"<<endl; 
				break;
			}
			case 7:{
				mode = 8;
				break;
			}							
		}
	}
//	���Ը���ԭ������ 
	ofstream outfile;
	outfile.open("test.txt", ios::out);
	for(int i=0; i<sum; i++){
		if(obj[i]->getPosition() == "Staff"){
			outfile<<obj[i]->getNumber()<<"\t"<<obj[i]->getName()<<"\t"<<obj[i]->getAge()<<"\t"<<obj[i]->getPosition()<<"\t"<<obj[i]->getIsDeleted()<<endl;
		}
		else if(obj[i]->getPosition() == "Salesman"){
			Salesman* temp = dynamic_cast<Salesman*>(obj[i]);
			outfile<<temp->getNumber()<<"\t"<<temp->getName()<<"\t"<<temp->getAge()<<"\t"<<temp->getPosition()<<"\t"<<temp->getIsDeleted()<<"\t"<<temp->getSaleCount()<<endl;
		}
		else if(obj[i]->getPosition() == "Manager"){
			Manager* temp = dynamic_cast<Manager*>(obj[i]);
			outfile<<temp->getNumber()<<"\t"<<temp->getName()<<"\t"<<temp->getAge()<<"\t"<<temp->getPosition()<<"\t"<<temp->getIsDeleted()<<"\t"<<temp->getManageStaffCount()<<endl;
		}
		else if(obj[i]->getPosition() == "SalesManager"){
			SalesManager* temp = dynamic_cast<SalesManager*>(obj[i]); 
			outfile<<temp->getNumber()<<"\t"<<temp->getName()<<"\t"<<temp->getAge()<<"\t"<<temp->getPosition()<<"\t"<<temp->getIsDeleted()<<"\t"<<temp->getSaleCount()<<"\t"<<temp->getManageStaffCount()<<endl;
		}
	}
}
