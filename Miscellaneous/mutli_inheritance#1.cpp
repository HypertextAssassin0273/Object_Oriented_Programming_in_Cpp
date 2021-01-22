#include<iostream>
using namespace std;
class A{
	public:
		void print(){
			cout<<"A"<<endl;
		}
};
class B: protected A{
	public:
		void print(){
			cout<<"B"<<endl;
		}
};
class C: public B{
	public:
	void print(){
		A::print();
		}
};
int main(){
	C c;
	c.print();
	return 0;
}
