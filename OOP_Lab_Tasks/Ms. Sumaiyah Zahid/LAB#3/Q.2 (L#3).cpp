#include<iostream>
using namespace std;

#define N 3 // N -> compile-time

class employee{
	char* first_name;
	string last_name;
	int monthly_salary;
	
public:
	void set_data(char* x, string y, int z){
		if (z<0)
		monthly_salary=0;
		else
		monthly_salary=z;
		first_name=x, last_name=y;	
	}
	char* get_first_name(){
		return first_name;
	}
	string get_last_name(){
		return last_name;
	}
	int get_monthly_salary(){
		return monthly_salary;
	}
	int display_yearly_salary(){
		return 12*monthly_salary;
	}
	int display_raised_yearly_salary(){
		return ((12*monthly_salary)/100)*10;
	}
};

int main(){
	employee emp[N];
	emp[0].set_data("Shahzaib","Khan",150000),
	emp[1].set_data("Ali","Mohammad",140000),
	emp[2].set_data("FAST","NUCES",-999);
	cout<<"DATA INFO:-\n\n";
	for (unsigned int i=0;i<N;i++,cout<<endl){
		cout<<"$ Employee "<<i+1<<" $\n"
			<<"First Name: "<<emp[i].get_first_name()<<endl
			<<"Last Name: "<<emp[i].get_last_name()<<endl
			<<"Monthly Salary: "<<emp[i].get_monthly_salary()<<endl
			<<"Yearly Salary: "<<emp[i].display_yearly_salary()<<endl
			<<"Raised Yearly Salary: "<<emp[i].display_raised_yearly_salary()<<endl;
	}
	return 0;
}
