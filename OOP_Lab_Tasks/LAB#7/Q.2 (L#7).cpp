#include<iostream>
using namespace std;
class Vehicle{
protected:
	string Type,Make,Model,Color; //Note: We can access protected attributes directly in all further inherited classes
	int Year;
	float Miles_Driven;
	
	Vehicle(string Type,string Make,string Model,string Color,int Year,float Miles_Driven):
		Type(Type),Make(Make),Model(Model),Color(Color),Year(Year),Miles_Driven(Miles_Driven){}
};

class Electrical_Vehicle: virtual protected Vehicle{
protected:
	unsigned int Energy_Storage;
	
	Electrical_Vehicle(string Type,string Make,string Model,string Color,int Year,float Miles_Driven,unsigned int Energy_Storage):
		Energy_Storage(Energy_Storage),Vehicle(Type,Make,Model,Color,Year,Miles_Driven){}
};

class Gas_Vehicle: virtual protected Vehicle{
protected:
	unsigned int Full_Tank_Size;
	
	Gas_Vehicle(string Type,string Make,string Model,string Color,int Year,float Miles_Driven,unsigned int Full_Tank_Size):
		Full_Tank_Size(Full_Tank_Size),Vehicle(Type,Make,Model,Color,Year,Miles_Driven){}
};

class High_Performance: protected Gas_Vehicle{
protected:
	unsigned int Horse_Power;
	float Top_Speed;
	
	High_Performance(string Type,string Make,string Model,string Color,int Year,float Miles_Driven,unsigned int Full_Tank_Size,unsigned int Horse_Power,float Top_Speed):
		Gas_Vehicle(Type,Make,Model,Color,Year,Miles_Driven,Full_Tank_Size),Vehicle(Type,Make,Model,Color,Year,Miles_Driven),Horse_Power(Horse_Power),Top_Speed(Top_Speed){}
};

class Sports_Car: protected High_Performance{
protected:
	string Gearbox,	//i.e. here gearbox ->auto/manual
		   Drive_System;	//i.e. here DriveSystem -> rearwheel/frontwheel/4x4
	
	Sports_Car(string Type,string Make,string Model,string Color,int Year,float Miles_Driven,unsigned int Horse_Power,float Top_Speed,string Gearbox,string Drive_System):
		High_Performance(Type,Make,Model,Color,Year,Miles_Driven,Full_Tank_Size,Horse_Power,Top_Speed),Vehicle(Type,Make,Model,Color,Year,Miles_Driven),Gearbox(Gearbox),Drive_System(Drive_System){}
};

class Heavy_Vehicle: protected Electrical_Vehicle,protected Gas_Vehicle{
protected:
	float Max_Weight,Length;
	unsigned short No_of_Wheels;
	
	Heavy_Vehicle(string Type,string Make,string Model,string Color,int Year,float Miles_Driven,unsigned int Energy_Storage,unsigned int Full_Tank_Size,float Max_Weight,float Length,unsigned short No_of_Wheels):
		Max_Weight(Max_Weight),Length(Length),No_of_Wheels(No_of_Wheels),Electrical_Vehicle(Type,Make,Model,Color,Year,Miles_Driven,Energy_Storage),Gas_Vehicle(Type,Make,Model,Color,Year,Miles_Driven,Full_Tank_Size),Vehicle(Type,Make,Model,Color,Year,Miles_Driven){}
};

class Construction_Truck: private Heavy_Vehicle{
	string Cargo; //i.e. here cargo -> cement/gravel/sand
public:
	Construction_Truck(string Type,string Make,string Model,string Color,int Year,float Miles_Driven,unsigned int Energy_Storage,unsigned int Full_Tank_Size,float Max_Weight,float Length,unsigned short No_of_Wheels,string Cargo):
		Heavy_Vehicle(Type,Make,Model,Color,Year,Miles_Driven,Energy_Storage,Full_Tank_Size,Max_Weight,Length,No_of_Wheels),Vehicle(Type,Make,Model,Color,Year,Miles_Driven),Cargo(Cargo){}
};

class Bus: private Heavy_Vehicle{
	unsigned int No_of_Seats;
public:
	Bus(string Type,string Make,string Model,string Color,int Year,float Miles_Driven,unsigned int Energy_Storage,unsigned int Full_Tank_Size,float Max_Weight,float Length,unsigned short No_of_Wheels,unsigned int No_of_Seats):
		Heavy_Vehicle(Type,Make,Model,Color,Year,Miles_Driven,Energy_Storage,Full_Tank_Size,Max_Weight,Length,No_of_Wheels),Vehicle(Type,Make,Model,Color,Year,Miles_Driven),No_of_Seats(No_of_Seats){}
	
	void Display()const{
		cout<<"Type: "<<Type<<endl
			<<"Make: "<<Make<<endl
			<<"Model: "<<Model<<endl
			<<"Color: "<<Color<<endl
			<<"Year: "<<Year<<endl
			<<"Miles Driven: "<<Miles_Driven<<endl
		
			<<"Energy Storage: "<<Energy_Storage<<endl
			<<"Full Tank Size: "<<Full_Tank_Size<<endl
			
			<<"Max Weight: "<<Max_Weight<<endl
			<<"Length: "<<Length<<endl
			<<"No of Wheels: "<<No_of_Wheels<<endl
			
			<<"No of Seats: "<<No_of_Seats<<endl;
	}
};

int main(){
	Bus obj("Car","Suzuki","ACX-1024","Light Grey",2019,1000.5,0,3500,850,60,4,4);
	obj.Display();
	return 0;
}


