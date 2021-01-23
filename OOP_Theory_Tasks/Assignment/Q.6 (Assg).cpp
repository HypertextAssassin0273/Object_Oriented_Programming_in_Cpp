#include<iostream>
#include<conio.h>
#define up 72
#define down 80
#define escape 27
using namespace std;
class Boat{
protected:
	bool Anchor;
public:
	Boat():Anchor(true){}
	void Drop_Anchor(){ Anchor=true; }
	void Raise_Anchor(){ Anchor=false; }
};
class Sailing_Boat: virtual public Boat{
protected:
	int Sails;
public:
	Sailing_Boat():Sails(0){}
	void Lower_Sails(){ --Sails; }
	void Hoist_Sails(){ ++Sails; }
};
class Motor_Boat: virtual public Boat{
protected:
	bool Engine;
public:
	Motor_Boat():Engine(false){}	
	void Start_Engine(){ Engine=true; }
	void Stop_Engine(){ Engine=false; }

};
class Motor_Sailing_Yacht: public Sailing_Boat,public Motor_Boat{
	
	inline void Display_Boat_Menu()const{
		cout<<"\nBoat Menu:-\n^^^^^^^^^^^\n"
				<<"Toggle E to Start/Stop Engine\n"
				<<"Toggle A to Raise/Drop Anchor\n"
				<<"Press UP Arrow to Increase Speed of Boat\n"
				<<"Press Down Arrow to Decrease Speed of Boat\n";
	}
public:
	void Display_Boat_Status()const{
		cout<<"\nBoat Status:-\n^^^^^^^^^^^^^\n";
		if (Anchor)
		cout<<"Anchor: Dropped"<<endl;
		else
		cout<<"Anchor: Raised"<<endl;
		if (Engine)
		cout<<"Engine: Started"<<endl;
		else
		cout<<"Engine: Stopped"<<endl;
		cout<<"Boat Speed: "<<Sails<<" Km/h"<<endl;
	}
	void static Boat_Working(){
		Motor_Sailing_Yacht obj;
		while(1){
			system("cls");
			obj.Display_Boat_Status();
			obj.Display_Boat_Menu();
			switch(getch()){
				case up:
					if (!obj.Anchor&&obj.Engine)
					obj.Hoist_Sails();
					else
					cout<<"\a";
					break;
				case down:
					if (!obj.Anchor&&obj.Engine)
					obj.Lower_Sails();
					else
					cout<<"\a";
					break;
				case 'e':
				case 'E':
					if (obj.Engine)
					obj.Stop_Engine();
					else
					obj.Start_Engine();
					break;
				case 'a':
				case 'A':
					if (obj.Anchor)
					obj.Raise_Anchor();
					else
					obj.Drop_Anchor();				
					break;
				case escape:
				return;	
			}
		}
	}
};
int main(){
	Motor_Sailing_Yacht::Boat_Working();
	return 0;
}

