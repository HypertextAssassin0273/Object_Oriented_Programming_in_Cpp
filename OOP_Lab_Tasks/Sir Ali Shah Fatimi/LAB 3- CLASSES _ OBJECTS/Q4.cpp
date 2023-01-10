#include<iostream>
using namespace std;

class employee{
	
	public:
		string f_name;
		string l_name;
		double monthly_salary;
	
		void display_salary(){
			cout<<"Salary of "<<f_name<<" is "<<monthly_salary;
		}
		void bonus(){
			double bon;
			
			bon=(monthly_salary*10)/100;
			cout<<"Salary after 10% raise: "<<bon+monthly_salary;
		}
	
	
};

int main(){
	employee ob1;
	employee ob2;
	
	ob1.f_name="Rayyan";ob1.l_name="Minhaj";
	ob1.monthly_salary=21000;
	ob1.display_salary();
	cout<<endl;
	ob1.bonus();
	cout<<endl<<endl;
	
	ob2.f_name="Phillip";ob1.l_name="McHunt";
	ob2.monthly_salary=5000;
	ob2.display_salary();
	cout<<endl;
	ob2.bonus();
	
	
	
	
}
