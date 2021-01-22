#include<iostream>
using namespace std;
class Employee{
protected:
	string Name,Code; //Note: We can access protected attributes directly in all further inherited classes 
	
	Employee(string Name,string Code):
		Name(Name),Code(Code){}
};
class Consultant: virtual protected Employee{
protected:
	unsigned short Years_of_Experience;
	
	Consultant(string Name,string Code,unsigned short Years_of_Experience):
		Years_of_Experience(Years_of_Experience),Employee(Name,Code){}
};

class Manager: virtual protected Employee{
protected:
	unsigned int No_of_Teams;
	
	Manager(string Name,string Code,unsigned int No_of_Teams):
		No_of_Teams(No_of_Teams),Employee(Name,Code){}
};

class Consultant_Manager: private Consultant,private Manager{
public:
	Consultant_Manager(string Name,string Code,unsigned short Years_of_Experience,unsigned int No_of_Teams):
		Consultant(Name,Code,Years_of_Experience),Manager(Name,Code,No_of_Teams),Employee(Name,Code){}
	
	void Display()const{
		cout<<"Name: "<<Name<<endl
			<<"Code: "<<Code<<endl
			<<"Years of Experience: "<<Years_of_Experience<<endl
			<<"No of Teams: "<<No_of_Teams<<endl;
	}
};

int main(){
	Consultant_Manager obj("Ali","S-123",17,5);
	obj.Display();
	return 0;
}


