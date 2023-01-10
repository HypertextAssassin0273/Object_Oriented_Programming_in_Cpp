#include<iostream>
using namespace std;

class A{
	public:
	static int count;
	

		A(){
			count++;
		}
	
};
int A::count=0;

int main(){
	A ob1,ob2,ob3;
	
	cout<<"Number of objects created: "<<A::count;
}

