#include<iostream>
using namespace std;

class Vehicle{
	public:
	string type;
	string make;
	string model;
	string color;
	int year;
	float miles;
	

};

class ElectricVehicle: virtual public Vehicle{
	int energy_storage;
};

class GasVehicle: virtual public Vehicle{
	public:
	int fuel_tank_size;
	
	public:
		GasVehicle(string a, string b, string c, string d, int y, int m){
			type=a;
			make=b;
			model=c;
			color=d;
			year=y;
			miles=m;
		}
};

class HeavyVehicle: public ElectricVehicle, public GasVehicle{
	public:
	int max_weight;
	int no_wheels;
	int len;
	
	public:
		HeavyVehicle(int fuel, string a, string b, string c, string d, int y, int m):GasVehicle(a, b, c, d, y, m){
			fuel_tank_size=fuel;
		}
};

class HighPerformance: public GasVehicle{
	int horse_power;
	int top_speed;
};

class SportsCar{
	char gearbox; //a for automatic, m for manual
	string drive_system;
};

class ConstructionTruck: public HeavyVehicle{
	string cargo;
};

class Bus: public HeavyVehicle{
	public:
	int no_seats;
	
	public:
		Bus(int seats, int max, int wheels, int length, int fuel, string a, string b, string c, string d, int y, int m):HeavyVehicle(fuel, a, b, c, d, y, m)
		{
			no_seats=seats;
			max_weight=max;
			no_wheels=wheels;
			len=length;		
		}
		
		void display(){
			cout<<"Type of Car: "<<Vehicle::type<<endl;
			cout<<"Brand of Car: "<<Vehicle::make<<endl;
			cout<<"Model of Car: "<<Vehicle::model<<endl;
			cout<<"Color of Car: "<<Vehicle::color<<endl;
			cout<<"Year of Manufacture: "<<Vehicle::year<<endl;
			cout<<"Miles Driven: "<<Vehicle::miles<<endl;
			cout<<"Number of seats: "<<no_seats<<endl;
			cout<<"Maximum Weight: "<<HeavyVehicle::max_weight<<endl;
			cout<<"Number of wheels: "<<HeavyVehicle::no_wheels<<endl;
			cout<<"Length of Car: "<<HeavyVehicle::len<<endl;
			cout<<"Fuel Tank Size: "<<GasVehicle::fuel_tank_size<<endl;
		}
};


int main(){
	Bus obj(10, 500, 4, 176, 156, "SUV", "Toyota", "Corolla", "pink", 2017, 78);
	
	obj.display();
	
}
