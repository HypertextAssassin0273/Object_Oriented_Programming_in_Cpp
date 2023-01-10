#include<iostream>
using namespace std;

class shape{
	
	public:
		virtual int getArea()=0;
};

class rectangle:public shape{
	int area;
	
	public:
		rectangle(int a){
			area=a;
		}
		
		int getArea(){
			return area;
		}
};

class triangle:public shape{
	int area;
	
	public:
		triangle(int a){
			area=a;
		}
		
		int getArea(){
			return area;
		}
};

int main(){
	rectangle ob1(4);
	cout<<"Rectangle Area: "<<ob1.getArea()<<endl;
	
	triangle ob2(6);
	cout<<"Triangle Area: "<<ob2.getArea()<<endl;
	
}
