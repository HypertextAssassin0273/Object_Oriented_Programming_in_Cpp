#include<iostream>
using namespace std;

class add{
	public:
		static int a;
		static int b;
		
		static int sum(){
			return a+b;
		}
};
int add::a=5;
int add::b=7;

int main(){
	add ob1;
	cout<<add::sum();
}
