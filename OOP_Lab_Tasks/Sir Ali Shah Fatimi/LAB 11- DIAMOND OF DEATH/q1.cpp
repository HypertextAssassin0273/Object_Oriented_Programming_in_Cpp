#include<iostream>
using namespace std;

class Employee{
	protected:
		string name;
		string code;
		
	public:
		Employee(){
			
		}
		Employee(string n, string c){
			name=n;
			code=c;
		}
};

class Manager:virtual public Employee
{
	protected:
		int teams;
	
	public:
		Manager(){
			
		}
		Manager(int t){
			teams=t;
		}
};


class Consultant:virtual public Employee
{
	protected:
		int years;
		
	public:
		Consultant(){
			
		}
		Consultant(int y){
			years =y;
		}
};

class ConsultantManager:public Consultant, public Manager
{
	public:
		ConsultantManager(string n, string c, int t, int y):Employee(n,c),Manager(t),Consultant(y){
			
		}
		
		void display() const {
			cout<<"Name: "<<name<<endl;
			cout<<"Code: "<<code<<endl;
			cout<<"Years of Exp: "<<years<<endl;
			cout<<"Num of teams: "<<teams<<endl;
		}	
};



int main(){
	ConsultantManager ob("Ali","S-123",17,5);
	ob.teams=6;
	ob.display();
	return 0; 
}



