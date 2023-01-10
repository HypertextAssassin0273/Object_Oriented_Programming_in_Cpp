#include<iostream>
using namespace std;

class person{
	float id;
	
	public:
		person(float i){
			id=i;
		}
		
		float Getid(){
			return id;
		}
		
		void DisplayData(){
			cout<<"Employee id: "<<id<<endl;
		}
};

class admin:public person{
	string name;
	float income;
	
	public:
		admin(string n, float i,float x):person(x){
			name=n;
			income=i;
		}
		
		string GetName(){
			return name;
		}
		
		float GetIncome(){
			return income;
		}
		
		
		void DisplayData(){
			cout<<"Admin Name: "<<name<<endl;
			cout<<"Admin income: "<<income<<endl;
		}
		
		float GetBonus(){
			income=income+income*0.05;
			return income;
		}
	
};

class accounts:public person{
	string name;
	float income;
	public:
		accounts(string n, float i, float x):person(x){
			name=n;
			income=i;
		}
		
		string GetName(){
			return name;
		}
		
		float GetIncome(){
			return income;
		}
		
		
		void DisplayData(){
			cout<<"Accountants Name: "<<name<<endl;
			cout<<"Accountants income: "<<income<<endl;
		}
		
		
		float GetBonus(){
			income=income*0.05;
			return income;
		}
	
};

int main(){
	person p(24);
	p.DisplayData();
	
	admin a("Rayyan",150.25,54.6);
	a.DisplayData();
	
	accounts a1("Abdullah",456.8,12.3);
	a1.DisplayData();
	
	cout<<"Bonus of Rayyan (Admin): "<<a.GetBonus()<<endl;
	cout<<"Bonus of Abdullah (Account): "<<a1.GetBonus();
}
