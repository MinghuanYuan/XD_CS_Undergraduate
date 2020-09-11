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
		cout<<"员工编号："<<number; 
		cout<<"\t\t员工姓名："<<name;
		cout<<"\t\t员工年龄："<<age;
		cout<<"\t\t员工职位："<<position<<endl;
	}
	
	virtual void outputWithNumber(){
		cout<<"1员工编号："<<number; 
		cout<<"\t\t2员工姓名："<<name;
		cout<<"\t\t3员工年龄："<<age;
		cout<<"\t\t4员工职位："<<position<<endl;
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
		cout<<"员工编号："<<number; 
		cout<<"\t\t员工姓名："<<name;
		cout<<"\t\t员工年龄："<<age;
		cout<<"\t\t员工职位："<<position;
		cout<<"\t\t销售额："<<salecount<<endl;
	}
	
	virtual void outputWithNumber(){
		cout<<"1员工编号："<<number; 
		cout<<"\t\t2员工姓名："<<name;
		cout<<"\t\t3员工年龄："<<age;
		cout<<"\t\t4员工职位："<<position;
		cout<<"\t\t5销售额："<<salecount<<endl;
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
		cout<<"员工编号："<<number; 
		cout<<"\t\t员工姓名："<<name;
		cout<<"\t\t员工年龄："<<age;
		cout<<"\t\t员工职位："<<position;
		cout<<"\t\t管理人数："<<managestaffcount<<endl;
	}
	
	virtual void outputWithNumber(){
		cout<<"1员工编号："<<number; 
		cout<<"\t\t2员工姓名："<<name;
		cout<<"\t\t3员工年龄："<<age;
		cout<<"\t\t4员工职位："<<position;
		cout<<"\t\t6管理人数："<<managestaffcount<<endl;
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
		cout<<"员工编号："<<number; 
		cout<<"\t\t员工姓名："<<name;
		cout<<"\t\t员工年龄："<<age;
		cout<<"\t\t员工职位："<<position;
		cout<<"\t\t销售额："<<salecount;
		cout<<"\t\t管理人数："<<managestaffcount<<endl;
	}
	
	virtual void outputWithNumber(){
		cout<<"1员工编号："<<number; 
		cout<<"\t\t2员工姓名："<<name;
		cout<<"\t\t3员工年龄："<<age;
		cout<<"\t\t4员工职位："<<position;
		cout<<"\t\t5销售额："<<salecount;
		cout<<"\t\t6管理人数："<<managestaffcount<<endl;
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
		cout<<"------请输入相应数字选择您需要的功能：------"<<endl; 
		cout<<"1：增加数据"<<endl;
		cout<<"2：更新数据"<<endl;
		cout<<"3：查询数据"<<endl;
		cout<<"4：删除数据"<<endl;
		cout<<"5：重组文件"<<endl;
		cout<<"6：统计人数"<<endl;
		cout<<"7：退出系统"<<endl;
		cin>>mode;
		switch(mode){
			case 1:{
				cout<<"请输入员工编号、姓名、年龄"<<endl;
				cin>>number>>name>>age;
				cout<<"请选择增加的员工类型"<<endl;
				cout<<"1：Salesman	2：Manager	3：SalesManager"<<endl;
				cin>>choice;
				switch(choice){
					case 1:{
						cout<<"请输入销售额"<<endl;
						cin>>salecount;
						Salesman* temp = new Salesman(number, name, age, "Salesman", false, salecount);
						obj.push_back(temp);
						sum++;
						break;
					}
					case 2:{
						cout<<"请输入管理人数"<<endl;
						cin>>managestaffcount;
						Manager* temp = new Manager(number, name, age, "Manager", false, managestaffcount);
						obj.push_back(temp);
						sum++;
						break;
					}
					case 3:{
						cout<<"请输入销售额"<<endl;
						cin>>salecount;
						cout<<"请输入管理人数"<<endl;
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
				cout<<"以下是公司所有员工"<<endl;
				for(int i=0; i<sum; i++){
					obj[i]->output();
				}
				cout<<"请输入需要更新的员工编号"<<endl;
				cin>>number;
				id = findByNumber(obj, number, sum);
				obj[id]->outputWithNumber(); 
				cout<<"请输入相应数字选择需要更新的属性"<<endl;
				cin>>property;
				if(property == 2 || property == 4){
					cout<<"请输入新属性值"<<endl;
					string update;
					cin>>update;
					obj[id]->updateProperty(property, update);
				}
				else{
					cout<<"请输入新属性值"<<endl;
					int update;
					cin>>update;
					obj[id]->updateProperty(property, update);
				}
				cout<<"更新成功"<<endl; 
				obj[id]->output();
				break;
			}
			case 3:{
				cout<<"请输入相应数字选择查询方式"<<endl;
				cout<<"1：查询所有员工"<<endl;
				cout<<"2：按员工编号查询"<<endl;
				cout<<"3：按员工姓名查询"<<endl;
				cin>>choice;
				switch(choice){
					case 1:{
						cout<<"以下是公司所有员工"<<endl;
						for(int i=0; i<sum; i++){
							if(obj[i]->getIsDeleted() != true){
								obj[i]->output();
							}
						}
						break;
					}
					case 2:{
						cout<<"请输入待查询的员工编号"<<endl;
						cin>>number; 
						id = findByNumber(obj, number, sum);
						obj[id]->output(); 
						break;
					}
					case 3:{
						cout<<"请输入待查询的员工姓名"<<endl;
						cin>>name;
						id = findByName(obj, name, sum);
						obj[id]->output(); 
						break;
					}
				} 
				break;
			}
			case 4:{
				cout<<"请输入待删除的员工编号"<<endl;
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
				cout<<"文件重组完成"<<endl;			
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
				cout<<"Salesman有："<<salesmansum<<"人"<<endl;
				cout<<"Manager有："<<managersum<<"人"<<endl;
				cout<<"SalesManager有："<<salesmanagersum<<"人"<<endl; 
				cout<<"Staff有："<<sum<<"人"<<endl; 
				break;
			}
			case 7:{
				mode = 8;
				break;
			}							
		}
	}
//	可以覆盖原有数据 
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
