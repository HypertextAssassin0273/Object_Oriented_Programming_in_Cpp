#include<iostream>
using namespace std; 
class Hotel_Mercato{
	string Customer_Name;
	unsigned short Number_Of_Days;
	float Rent_Per_Day,Customer_Rent;
	
	float Rent_With_Bonus(){ //i.e. inlined function by default
		return Rent_Per_Day*(Number_Of_Days-1);
	}
	float Rent_Without_Bonus(){ //i.e. inlined function by default
		return Rent_Per_Day*Number_Of_Days;
	}
public:
	Hotel_Mercato(string Customer_Name,unsigned short Number_Of_Days){
		this->Customer_Name=Customer_Name;
		this->Number_Of_Days=Number_Of_Days;
		Rent_Per_Day=1000.85; 
		Customer_Rent=0;
	}
	void Set_Rent_Per_Day(float Rent_Per_Day){ //i.e. provided so that later, the hotel can change it as per its needs
		this->Rent_Per_Day=Rent_Per_Day;	
	}
	void Set_Number_Of_Days(float Number_Of_Days){ //i.e. provided so that later, the hotel can change it as per its needs
		this->Number_Of_Days=Number_Of_Days;	
	}
	void Rent_Calculator(){
		if (Number_Of_Days>7)
		Customer_Rent=Rent_With_Bonus();
		else
		Customer_Rent=Rent_Without_Bonus();
	}
	Display_Rent()const{ //i.e. read only function
		static unsigned short Customer_Count=0; //i.e. Extra feature: to count customers
		cout<<"Customer "<<++Customer_Count<<":-"<<endl
			<<"Name: "<<Customer_Name<<endl
			<<"Days: "<<Number_Of_Days<<endl
			<<"Rent: "<<Customer_Rent<<"\n\n";
	}
};

int main(){
	Hotel_Mercato customer1("Dummy1",7),customer2("Dummy2",8);
	customer1.Rent_Calculator();
	customer1.Display_Rent();
	
	customer2.Rent_Calculator();
	customer2.Display_Rent();
	return 0;
}
