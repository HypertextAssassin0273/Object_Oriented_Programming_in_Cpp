#include<iostream>
using namespace std;
class Pair{
	public:
		int a,b;
		
		int sum(){
			return a+b;
		}
};

int main(){
	int x;
	Pair ob1;
	ob1.a=5;
	ob1.b=6;
	x=ob1.sum();
	cout<<x;
}
