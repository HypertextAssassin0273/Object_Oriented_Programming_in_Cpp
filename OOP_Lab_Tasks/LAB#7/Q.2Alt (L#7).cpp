#include<iostream>
using namespace std;
class Vehicle{
/*Note: Defining Virtual Base Class makes it's child & grand-child classes also virtual, which 
		means that we only need to invoke ctor from the class where its obj is being instantiated
*/
	string Type,Make,Model,Color;
	int Year;
	float Miles_Driven;
protected:
	Vehicle():Year(0),Miles_Driven(0){}
	Vehicle(string Type,string Make,string Model,string Color,int Year,float Miles_Driven):
		Type(Type),Make(Make),Model(Model),Color(Color),Year(Year),Miles_Driven(Miles_Driven){}

	void Vehicle_Display()const{
		cout<<"Type: "<<Type<<endl
			<<"Make: "<<Make<<endl
			<<"Model: "<<Model<<endl
			<<"Color: "<<Color<<endl
			<<"Year: "<<Year<<endl
			<<"Miles Driven: "<<Miles_Driven<<endl;
	}
};

class Electrical_Vehicle: virtual protected Vehicle{
protected:
	int Energy_Storage;
	
	Electrical_Vehicle(int Energy_Storage):
		Energy_Storage(Energy_Storage){}
};

class Gas_Vehicle: virtual protected Vehicle{
protected:
	int Full_Tank_Size;
	
	Gas_Vehicle(int Full_Tank_Size):
		Full_Tank_Size(Full_Tank_Size){}
};

class High_Performance: protected Gas_Vehicle{
protected:
	int Horse_Power;
	float Top_Speed;
	
	High_Performance(int Full_Tank_Size,int Horse_Power,float Top_Speed):
		Gas_Vehicle(Full_Tank_Size),Horse_Power(Horse_Power),Top_Speed(Top_Speed){}
};

class Sports_Car: protected High_Performance{
protected:
	string Gearbox,
		   Drive_System;
public:	
	Sports_Car(string Type,string Make,string Model,string Color,int Year,float Miles_Driven,int Horse_Power,float Top_Speed,string Gearbox,string Drive_System):
		High_Performance(Full_Tank_Size,Horse_Power,Top_Speed),Vehicle(Type,Make,Model,Color,Year,Miles_Driven),Gearbox(Gearbox),Drive_System(Drive_System){}
		
	void Display()const{
		Vehicle_Display();
		cout<<"Horse Power: "<<Horse_Power<<endl
			<<"Top Speed: "<<Top_Speed<<endl
			<<"Gearbox: "<<Gearbox<<endl
			<<"Drive System: "<<Drive_System<<"\n\n";
	}
};

class Heavy_Vehicle: protected Electrical_Vehicle,protected Gas_Vehicle{
protected:
	float Max_Weight,Length;
	int No_of_Wheels;
	
	Heavy_Vehicle(int Energy_Storage,int Full_Tank_Size,float Max_Weight,float Length,int No_of_Wheels):
		Max_Weight(Max_Weight),Length(Length),No_of_Wheels(No_of_Wheels),Electrical_Vehicle(Energy_Storage),Gas_Vehicle(Full_Tank_Size){}
	
	void Heavy_Vehicle_Display()const{
		cout<<"Full Tank Size: "<<Full_Tank_Size<<endl	
			<<"Max Weight: "<<Max_Weight<<endl
			<<"Length: "<<Length<<endl;	
	}
};

class Construction_Truck: private Heavy_Vehicle{
	string Cargo;
public:
	Construction_Truck(string Type,string Make,string Model,string Color,int Year,float Miles_Driven,int Energy_Storage,int Full_Tank_Size,float Max_Weight,float Length,int No_of_Wheels,string Cargo):
		Heavy_Vehicle(Energy_Storage,Full_Tank_Size,Max_Weight,Length,No_of_Wheels),Vehicle(Type,Make,Model,Color,Year,Miles_Driven),Cargo(Cargo){}

	void Display()const{
		Vehicle_Display();
		cout<<"Energy Storage: "<<Energy_Storage<<endl;
		Heavy_Vehicle_Display();
		cout<<"No of Wheels: "<<No_of_Wheels<<endl;
		cout<<"Cargo: "<<Cargo<<"\n\n";
	}
};

class Bus: private Heavy_Vehicle{
	int No_of_Seats;
public:
	Bus(string Type,string Make,string Model,string Color,int Year,float Miles_Driven,int Energy_Storage,int Full_Tank_Size,float Max_Weight,float Length,int No_of_Wheels,int No_of_Seats):
		Heavy_Vehicle(Energy_Storage,Full_Tank_Size,Max_Weight,Length,No_of_Wheels),Vehicle(Type,Make,Model,Color,Year,Miles_Driven),No_of_Seats(No_of_Seats){}
	
	void Display()const{
		Vehicle_Display();
		cout<<"Energy Storage: "<<Energy_Storage<<endl;
		cout<<"Full Tank Size: "<<Full_Tank_Size<<endl;	
		Heavy_Vehicle_Display();
		cout<<"No of Seats: "<<No_of_Seats<<"\n\n";
	}
};

int main(){
	Bus obj("Car","Suzuki","ACX-1024","Light Grey",2019,1000.5,101,3500,850,60,4,4);
	obj.Display();
	Construction_Truck obj1("q","w","r","e",11,22,33,44,55,66,7,"xxx");
	obj1.Display();
	Sports_Car obj2("ui","rt","cv","eyt",11111,222222,333,444,"xxx","yyy");
	obj2.Display();
	return 0;
}


