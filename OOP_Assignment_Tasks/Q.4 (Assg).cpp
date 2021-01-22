#include<iostream>
#include<conio.h>
using namespace std;
template<class T>
T Cel_To_Fah(T Temp){
    return ((Temp*9.0/5.0)+32.0);
}
template<class T>
T Fah_To_Cel(T Temp){
    return ((Temp-32.0)*5.0/9.0);
}
int main(){
    cout<<"Press 1 to convert Fahrenheit To Celsius"<<endl
    	<<"Press 2 to convert Celsius To Fahrenheit"<<endl<<endl;
    switch(getch()-48){
    	case 1:
    		cout<<"Enter temperature in Fahrenheit: ";
			float var;
			cin>>var;
			cout<<"In Celsius that's: "<<Fah_To_Cel(var)<<endl;
			break;
		case 2:
			cout<<"Enter temperature in Celsius: ";
			cin>>var;
			cout<<"In Fahrenheit that's: "<<Cel_To_Fah(var)<<endl;
			break;			
	}
    return 0;
}
