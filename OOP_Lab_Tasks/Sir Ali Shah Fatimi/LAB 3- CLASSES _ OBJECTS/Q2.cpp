#include<iostream>
using namespace std;

class Date{
	int month;
	int day;
	int year;
	
	public:
		void displayDate(){
			cout<<day<<"/"<<month<<"/"<<year;
		}
		int getDate(int day, int month, int year){
			this->day=day;
			this->month=month;
			this->year=year;
		}
		
};


int main(){
	Date ob1;
	int day,month,year;
	cout<<"Enter day: ";
	cin>>day;
	
	cout<<"Enter month: ";
	cin>>month;
	cout<<"Enter year: ";
	cin>>year;
	
	ob1.getDate(day,month,year);
	ob1.displayDate();
}
