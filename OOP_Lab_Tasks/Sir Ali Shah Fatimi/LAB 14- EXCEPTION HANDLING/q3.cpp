#include<iostream>
using namespace std;

class invalidDay{
	public:
		void wrong()const throw(){
			cout<<"wrong day";
		}
};

class invalidMonth{
	public:
		void wrong()const throw(){
			cout<<"wrong month";
		}
};


int main(){
	int day;
	int month;
	int year;
	
	try{
		cout<<"Enter day: ";
		cin>>day;
		if (day<=0 || day>31){
			throw invalidDay();
		}
		
		
		cout<<"Enter month: ";
		cin>>month;
		if (month<=0 || month>12){
			throw invalidMonth();
		}
		
		cout<<"Enter Year: ";
		cin>>year;
		}
		
	catch (invalidDay &ob){
		ob.wrong();
	}
	
	catch (invalidMonth &ob){
		ob.wrong();
	}
	
	if(month==1){
		cout<<"Jan "<<day<<", "<<year;
	}
	else if (month==2){
		cout<<"Feb "<<day<<", "<<year;
	}
	
	else if (month==3){
		cout<<"Mar "<<day<<", "<<year;
	}
	
	else if (month==4){
		cout<<"Apr "<<day<<", "<<year;
	}
	
	else if (month==5){
		cout<<"May "<<day<<", "<<year;
	}
	
	else if (month==6){
		cout<<"Jun "<<day<<", "<<year;
	}
	
	else if (month==7){
		cout<<"Jul "<<day<<", "<<year;
	}
	
	else if (month==8){
		cout<<"Aug "<<day<<", "<<year;
	}
	
	else if (month==9){
		cout<<"Sept "<<day<<", "<<year;
	}
	
	else if (month==10){
		cout<<"Oct "<<day<<", "<<year;
	}
	
	else if (month==11){
		cout<<"Nov "<<day<<", "<<year;
	}
	
	else if (month==12){
		cout<<"Dec "<<day<<", "<<year;
	}
	
}
