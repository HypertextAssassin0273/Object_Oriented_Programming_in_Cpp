#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;
#define pi 3.1412

class Circle{
	float radius;
	public:
		Circle(float radius){
			this->radius=radius;
			cout<<"Radius is: "<<radius;
		}
		
		float GetArea(){
			float area;
			area=pi*pow(radius,2);
			cout<<"\nArea: "<<area;
		}
		
		float GetPerimeter(){
			float peri;
			peri=2*pi*radius;
			cout<<"\nPerimater is: "<<peri;
		}
	
};

int main(){
	//i have taken radius as 12
	Circle ob1(12);
	ob1.GetArea();
	ob1.GetPerimeter();
	
	
}

