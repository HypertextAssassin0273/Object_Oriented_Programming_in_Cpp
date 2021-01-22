#include<iostream>
#include<iomanip>
#define pi 3.141592653589793238
using namespace std;
class Circle{
	string color;
	double radius;
public:
	Circle():radius(1.0),color("red"){}
	Circle(double r):radius(r),color("red"){}
	Circle(double r, string c):radius(r),color(c){}
	//i.e. default values: radius=1.0,color=red"
	double Get_Radius()const{ return radius; }
	string Get_Color()const{ return color; }
	double Get_Area()const{ return pi*radius*radius; }
	
	friend class C1;
	friend class C2;
	friend class C3;
};
class C1{
	Circle c1;
public:
	C1():c1(2.0,"blue"){}
	
	double Get_Radius()const{ return c1.radius; }
	string Get_Color()const{ return c1.color; }
	double Get_Area()const{ return pi*c1.radius*c1.radius; }
};
class C2{
	Circle c2;
public:
	C2():c2(2.0){}
	
	double Get_Radius()const{ return c2.radius; }
	string Get_Color()const{ return c2.color; }
	double Get_Area()const{ return pi*c2.radius*c2.radius; }
};
class C3{
	Circle c3;
public:
	double Get_Radius()const{ return c3.radius; }
	string Get_Color()const{ return c3.color; }
	double Get_Area()const{ return pi*c3.radius*c3.radius; }
};
int main(){
	Circle obj1,obj2(5),obj3(10,"green");
	cout<<"Obj1:-\n^^^^^^\n"
		<<"Radius of Cirle: "<<obj1.Get_Radius()<<endl	
		<<"Color of Cirle: "<<obj1.Get_Color()<<endl	
		<<"Area of Cirle: "<<fixed<<setprecision(2)<<obj1.Get_Area()<<endl	
		<<"\nObj2:-\n^^^^^^\n"	
		<<"Radius of Cirle: "<<obj2.Get_Radius()<<endl	
		<<"Color of Cirle: "<<obj2.Get_Color()<<endl	
		<<"Area of Cirle: "<<fixed<<setprecision(2)<<obj2.Get_Area()<<endl	
		<<"\nObj3:-\n^^^^^^\n"	
		<<"Radius of Cirle: "<<obj3.Get_Radius()<<endl	
		<<"Color of Cirle: "<<obj3.Get_Color()<<endl	
		<<"Area of Cirle: "<<fixed<<setprecision(2)<<obj3.Get_Area()<<endl;
	C1 obj4;
	cout<<"\nObj4:-\n^^^^^^\n"
		<<"Radius of C1: "<<obj4.Get_Radius()<<endl	
		<<"Color of C1: "<<obj4.Get_Color()<<endl	
		<<"Area of C1: "<<fixed<<setprecision(2)<<obj4.Get_Area()<<endl;
	C2 obj5;
	cout<<"\nObj5:-\n^^^^^^\n"
		<<"Radius of C2: "<<obj5.Get_Radius()<<endl
		<<"Color of C2: "<<obj5.Get_Color()<<endl
		<<"Area of C2: "<<fixed<<setprecision(2)<<obj5.Get_Area()<<endl;
	C3 obj6;
	cout<<"\nObj6:-\n^^^^^^\n"
		<<"Radius of C3: "<<obj6.Get_Radius()<<endl
		<<"Color of C3: "<<obj6.Get_Color()<<endl
		<<"Area of C3: "<<fixed<<setprecision(2)<<obj6.Get_Area()<<endl;
	return 0; 
}
