#include<iostream>
using namespace std;

class demo{
	public:
		void showMessage(){
			cout<<"INSIDE SHOW FUNCTION";
		}
		
		void Display() const{
			cout<<"INSIDE DISPLAY FUNCTION";
		}
};

int main(){
	demo ob1;
	ob1.showMessage();
	cout<<"\n";
	ob1.Display();
}
