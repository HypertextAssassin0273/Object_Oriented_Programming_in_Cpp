#include<iostream>
using namespace std;
class distance{
	float feets,inches;
	
	void calculations(float meters){ //i.e. making secure calculations (extra)
		feets=meters*3.28084;
		inches=meters*39.3701;	
	}
public:
	distance(){
		feets=0,inches=0;
	}
	void input_data(){
		cout<<"Enter Distance in Meters: ";
		float meters;
		cin>>meters;
		calculations(meters);
	}
	void display_in_inches(){
		cout<<"Distance in Inches: "<<inches<<endl;
	}
	void display_in_feets(){
		cout<<"Distance in Feets: "<<feets<<endl;
	}
	~distance(){
		cout<<"Note: Object is Destroyed!"<<endl;
	}
}d1;
int main(){
	d1.input_data();
	d1.display_in_feets();
	d1.display_in_inches();
	return 0;
}
