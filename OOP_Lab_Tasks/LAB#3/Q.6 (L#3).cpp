#include<iostream>
using namespace std;
class Vehicle{
	int year,speed;
	string manufacturer;
	bool isUsed,X;
public:
	Vehicle(){ year=0,speed=0,isUsed=0,X=0; }
	void set_data(int year,string manufacturer){
		this->year=year;
		this->manufacturer=manufacturer;
	}
	void display_data(){
		if(manufacturer!="\0"&&!X) //i.e. no need of string copy function for manufacturer, bcz string datatype is already overloaded for '=' operator
		cout<<"Manufacturer: "<<manufacturer<<endl;
		if (year&&!X)
		cout<<"year: "<<year<<endl;
		if (isUsed&&X)
		cout<<"New ";
		cout<<"Speed: "<<speed<<endl;
		X=1;	
	}
	void accelerate(){
		speed+=5;
		isUsed=1;
	}
	void brake(){
		speed-=5;
		isUsed=1;
	}
};
int main(){
	Vehicle Rickshaw,Bike;
	Bike.set_data(2016,"Honda Kawasaki");
	for (unsigned char i=0;i<5;i++)
	Bike.accelerate();
	Bike.display_data();
	Bike.brake(),Bike.brake();
	Bike.display_data();
	return 0;
}
