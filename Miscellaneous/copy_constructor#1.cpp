#include<iostream>
using namespace std;
class wall{
	double length,height;
	void display(){
		cout<<"length: "<<length<<", height: "<<height<<endl;
	}
public:
	wall(double length,double height ){
		display();
		this->height=height;
		this->length=length;
	}
	wall (wall &obj){
		display();
		height=obj.height;
		length=obj.length;
	}	
	wall operator +(wall &obj){
		display();
		height=obj.height;
		length=obj.length;
	}
	double calc_area(){
		return length*height;
	}
};
int main(){
	/*Method#1*/
//	wall w1(10.5,8.6),w2(0,0);
//	cout<<"AREA 1: "<<w1.calc_area()<<endl;
//	w2 = w1;
//	cout<<"AREA 2: "<<w2.calc_area()<<endl;
	/*Method#2*/
//	wall w1(10.5,8.6);
//	cout<<"AREA 1: "<<w1.calc_area()<<endl;
//	wall w2 = w1;
//	cout<<"AREA 2: "<<w2.calc_area()<<endl;
	/*Method#3*/
	wall w1(10.5,8.6),w2(0,0);
	cout<<"AREA 1: "<<w1.calc_area()<<endl;
	w2+w1;
	cout<<"AREA 2: "<<w2.calc_area()<<endl;
	wall w3=w2;
	cout<<"AREA 2: "<<w3.calc_area()<<endl;
	return 0;
}
