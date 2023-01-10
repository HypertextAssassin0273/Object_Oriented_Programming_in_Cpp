#include<iostream>
using namespace std;

int main(){
	int flag=1;
	float feet=-5;
	float inches;
	
	
	while(feet<0){
		try{
			
			cout<<endl<<"Enter length in feet: ";
			cin>>feet;
		
			if(feet<0){
				throw feet;
			}
			else{
				inches=feet*12;
				cout<<"Value in inches: "<<inches;
			}

						
		}
		
		catch(float x){
			cout<<x<<" is a negative number, please enter a value again";
		}
		

	}
	
	
}
