#include<iostream>
using namespace std;

class Vehicle{
	public:
		float price;
};

class Car: public Vehicle
{
	public:
		int seats;
		int num_doors;
		string fuel;
};

class Motorcycle:public Vehicle
{
	public:
		int num_cylinder;
		int num_gears;
		int num_wheels;
};

class Audi: public Car
{
	string model;
};

class Yamaha: public Motorcycle
{
	string make_type;
};

int main(){
	Audi ob1;
	ob1.price=35000;
	ob1.fuel="diesel";
	ob1.num_doors=2;
	ob1.seats=4;
	
	Yamaha ob2;
	ob2.price=56000;
	ob2.num_cylinder=5;
	ob2.num_gears=2;
	ob2.num_wheels=2;
}




