#include<iostream>
using namespace std;

class invalidHr{
	public:
		void WrongHour() const throw(){
			cout<<"WRONG VALUE OF HOUR IDIOT!!";
		}
};

class invalidMin{
	public:
		void WrongMinute() const throw(){
			cout<<"WRONG VALUE OF MINUTES IDIOT!!";
		}
};


class invalidSec{
	public:
		void WrongSecond() const throw(){
			cout<<"WRONG VALUE OF SECONDS IDIOT!!";
		}
};


int main(){
	int hr;
	int min;
	int sec;
	string ampm;
	
	try{
		
		cout<<"Enter hours: ";
		cin>>hr;
		if(hr<=0 || hr>12){
			throw invalidHr();
		}
		
		cout<<"Enter minutes: ";
		cin>>min;
		if(min<0 || min>60){
			throw  invalidMin();
		}
		
		cout<<"Enter seconds: ";
		cin>>sec;
		if(sec<0 || sec>60){
			throw invalidSec();
		}
		
		cout<<"Enter am or pm: ";
		cin>>ampm;
		
		if(ampm=="pm"){
			hr=hr+12;
			
			cout<<"Your time converted is: ";
			cout<<hr<<":"<<min<<":"<<sec;
		}
		else{
			cout<<"Your time converted is: ";
			cout<<hr<<":"<<min<<":"<<sec;
		}
		
		
	}
	
	catch (invalidHr &ob){
		ob.WrongHour();
	}
	
	catch (invalidMin &ob){
		ob.WrongMinute();
	}
	
	catch (invalidSec &ob){
		ob.WrongSecond();
	}
	
	
}

