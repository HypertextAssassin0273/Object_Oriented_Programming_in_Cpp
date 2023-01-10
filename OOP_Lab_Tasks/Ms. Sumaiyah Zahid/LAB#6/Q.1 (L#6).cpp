#include<iostream>
using namespace std;
class Person{
	unsigned short Age;
protected:
	string Name;
	
	Person(unsigned short Age,string Name):Age(Age),Name(Name){}
	
	unsigned short Get_Age()const{ return Age; } //i.e. defined to get indirect access of private members
};
class Employee{
	string Emp_Id;
protected:
	float Salary;
	
	Employee(string Emp_Id,float Salary):Emp_Id(Emp_Id),Salary(Salary){}
	
	string Get_Emp_Id()const{ return Emp_Id; }
};
class Manager: protected Person,protected Employee{
	string Type;
protected:
	Manager(unsigned short Age,string Name,string Emp_Id,float Salary,string Type):
		Person(Age,Name),Employee(Emp_Id,Salary),Type(Type){}
		
	string Get_Type()const{ return Type; }
};
class ITManager: private Manager{
	unsigned int No_of_Persons;		
public:
	ITManager(unsigned short Age,string Name,string Emp_Id,float Salary,string Type,unsigned int No_of_Persons):
		Manager(Age,Name,Emp_Id,Salary,Type),No_of_Persons(No_of_Persons){} 
	
	void Display()const{
		cout<<"Age: "<<Get_Age()<<endl
			<<"Name: "<<Name<<endl
			<<"Employee Id: "<<Get_Emp_Id()<<endl
			<<"Salary: "<<Salary<<endl
			<<"Type: "<<Get_Type()<<endl
			<<"No. of Persons: "<<No_of_Persons<<endl;
	}
};
int main(){
	ITManager obj(21,"Shahzaib Khan","19K-0273",30000,"Student",1);
	obj.Display();
	return 0;
}
