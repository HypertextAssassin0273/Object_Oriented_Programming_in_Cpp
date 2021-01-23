//exercise#1
#include<iostream>
using namespace std;
class Parent{
	virtual void Message()=0;
};
class Child1:Parent{
public:
	void Message()override{
		cout<<"This is 1st sub class"<<endl;
	}
};
class Child2:Parent{
public:
	void Message()override{
		cout<<"This is 2nd sub class"<<endl;
	}
};
int main(){
	Child1 obj1;
	obj1.Message();
	Child2 obj2;
	obj2.Message();
	return 0;
}
