#include<iostream>
using namespace std;
class Base{
	mutable int x; //i.e. mutable -> allows data members to be modified inside constant methods
	int y;
public:
	Base():x{0},y{0} {} //i.e. Base():x{0},y{0} {} OR Base() { x=0, y=0; }
	Base(int a,int b):x{a},y{b} {}
	void set_x(int a){ x=a; }
	void set_y(int b){ x=b; }
	int get_x() const {
		x=10; // no error cuz of mutable keyword
		return x;
	}
	int get_y() const {
//		y=20; // error	
		return y;
	}
};
int main(){
	Base b;
	b.set_x(10);
	cout<<b.get_x()<<", "<<b.get_y()<<endl;
	return 0;
}
