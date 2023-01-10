#include<iostream>
using namespace std;

class cube{
	float side;
	public:
		cube(float x){
			side=x;
		}
		
		void calculate(){
			float volume;
			volume=side*side*side;
			cout<<"Volume of cube: "<<volume<<endl;
		}
};

class cylinder{
	float height;
	float radius;
	
	public:
		cylinder(float rad, float h){
			radius=rad;
			height=h;
		}
		void calculate(){
			float volume;
			volume=3.14*radius*radius*height;
			cout<<"Volume of rectangle: "<<volume<<endl;
		}
};

class rectangle{
	float len;
	float bre;
	float hei;
	
	public:
		rectangle(float l, float b, float h){
			len=l;
			bre=b;
			hei=h;
		}
		
		void calculate(){
			float volume;
			volume=len*bre*hei;
			cout<<"Volume of rectangle: "<<volume<<endl;
		}
		
};

int main(){
	cube ob1(34.2);
	ob1.calculate();
	
	cylinder ob2(12,5.67);
	ob2.calculate();
	
	rectangle ob3(12,34,56);
	ob3.calculate();
}
