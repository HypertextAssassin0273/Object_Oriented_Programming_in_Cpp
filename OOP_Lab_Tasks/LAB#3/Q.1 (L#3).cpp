#include<iostream>
using namespace std;
class rectangle{
	float length, width;
public:
	rectangle(){ length=1, width=1; }
	void set_data(float x, float y){
		if(x>0&&y>0&&x<20&&y<20)
		length=x, width=y;
		else
		cout<<"Invalid Input!";
	}
	float get_length(){
		return length;
	}
	float get_width(){
		return width;
	}
	float get_permimeter(){
		return (2*(length+width));
	}
	float get_area(){
		return (length*width);
	}
}r;
int main(){
	r.set_data(2.5,4.5);
	cout<<"Length: "<<r.get_length()<<" Width: "<<r.get_width();
	cout<<endl<<"Perimeter: "<<r.get_permimeter();
	cout<<endl<<"Area: "<<r.get_area()<<"\n\n";
	return 0;
}
