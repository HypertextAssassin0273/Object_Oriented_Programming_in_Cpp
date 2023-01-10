#include<iostream>
using namespace std;
class Employee{
	string Name;
	unsigned int Number;
protected:
	Employee(string Name,unsigned int Number):
		Name(Name),Number(Number){}

	string Get_Name()const{ return Name; }
	unsigned int Get_Number()const{ return Number; }
};
class Manager:protected Employee{
	string Title;
	int Club_Dues;
public:
	Manager(string Name,unsigned int Number,string Title,int Club_Dues):
		Employee(Name,Number),Title(Title),Club_Dues(Club_Dues){}
	
	void Display_Info()const{
		cout<<"Employee Name: "<<Get_Name()<<endl
			<<"Employee No: "<<Get_Number()<<endl
			<<"Title: "<<Title<<endl
			<<"Club Dues: "<<Club_Dues<<"\n\n";
	}
};
class Scientist:protected Employee{
	string Title;
	unsigned int No_of_Publications;
public:
	Scientist(string Name,unsigned int Number,string Title,unsigned int No_of_Publications):
		Employee(Name,Number),Title(Title),No_of_Publications(No_of_Publications){}
	
	void Display_Info()const{
		cout<<"Employee Name: "<<Get_Name()<<endl
			<<"Employee No: "<<Get_Number()<<endl
			<<"Title: "<<Title<<endl
			<<"No of Publications: "<<No_of_Publications<<"\n\n";
	}
};
class Laborer:protected Employee{
	string Title;
public:
	Laborer(string Name,unsigned int Number,string Title):
		Employee(Name,Number),Title(Title){}
	
	void Display_Info()const{
		cout<<"Employee Name: "<<Get_Name()<<endl
			<<"Employee No: "<<Get_Number()<<endl
			<<"Title: "<<Title<<"\n\n";
	}
};
int main(){
	Manager M_obj("Hamza",40401,"Behind the Mask",20500);
	M_obj.Display_Info();
	Scientist S_obj("Bilal",40402,"Art of Science",100);
	S_obj.Display_Info();
	Laborer L_obj("Ahmed",40403,"Overseas Sail");
	L_obj.Display_Info();
	return 0;
}
