//exercise#3
#include<iostream>
using namespace std;
class Parent{
public:
	Parent(){ cout<<"This is abstract class ctor"<<endl; }
	virtual void Abstract_Method()const=0;
	void Normal_Method()const{ cout<<"This is normal method"<<endl; }
};
class Child:public Parent{
public:
	void Abstract_Method()const override{ cout<<"This is abstract method"<<endl; }
};
int main(){
	Child obj;
	obj.Abstract_Method();
	obj.Normal_Method();
	return 0;
}
