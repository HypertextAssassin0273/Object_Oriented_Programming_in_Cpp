#include<iostream>
using namespace std; 
class Employee{
	char* Employee_Name;
	int Employee_Id;
public:
	Employee(char* Name,int Id):Employee_Name{Name},Employee_Id{Id} {}

	/*Extra Note: Functions inside the class are inlined by default,
	 			  so you dont have to use inline keyword here
				  (i.e. inline -> to optimize code) */	
	void set_name(char* name){
		Employee_Name=name;
	}
	char* Get_Name() const{ //i.e. read only & inlined function
		return Employee_Name;
	}
	int Get_Id() const{ //i.e. read only & inlined function
		return Employee_Id;
	}
};

int main(){
	//NOTE: If the following string literals are not type-casted to char*, then Compiler generates warning
	Employee Employee1((char*)"ASAD",40401);
	cout<<"Employee ID:   "<<Employee1.Get_Id()<<endl
		<<"Employee Name: "<<Employee1.Get_Name()<<"\n\n";
		
	Employee Employee2((char*)"AHMED",40402);
	cout<<"Employee ID:   "<<Employee2.Get_Id()<<endl
		<<"Employee Name: "<<Employee2.Get_Name()<<"\n\n";
		
	Employee Employee3((char*)"BILAL",40403);
	cout<<"Employee ID:   "<<Employee3.Get_Id()<<endl
		<<"Employee Name: "<<Employee3.Get_Name()<<endl;
	Employee3.set_name((char*)"FURQAN");
	cout<<"Employee Name: "<<Employee3.Get_Name()<<" (changed)"<<endl;
	return 0;
}
