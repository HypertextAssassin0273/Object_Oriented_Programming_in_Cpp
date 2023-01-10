#include<iostream>
using namespace std;

class shape{
	float a; //a for area
	
	public:
		void Area(int x){
			a=x;
		}
		
		shape operator +(const shape& o){
			shape temp;
			temp.a=a+o.a;
			return temp;
		}
		
		void display(){
			cout<<"Added area of both shapes: "<<a;
		}
};

int main(){
	shape shape1;
	shape shape2;
	shape ob;
	
	shape1.Area(12.4);
	shape2.Area(3.6);
	
	ob=shape1 + shape2;
	ob.display();
	
}
