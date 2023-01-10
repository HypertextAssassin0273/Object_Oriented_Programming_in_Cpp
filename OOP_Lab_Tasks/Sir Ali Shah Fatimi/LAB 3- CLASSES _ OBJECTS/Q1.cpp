#include<iostream>
using namespace std;

class User{
	public:
		int age;
		string name;
		
		int getAge(){
			return age;
		}
		string getName(){
			return name;
		}
};


int main(){
	User ob1;
	
	ob1.age=24;
	ob1.name="Teo";
	
	cout<<"My name is "<<ob1.getName()<<" and I am "<<ob1.getAge()<<" years old";
	
}
