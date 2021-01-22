#include<iostream>
using namespace std;
struct time_format{
	int secs,mins,hours;
};
time_format calc_standard_time(int n){
	static time_format time;
	time.hours=(n/3600)%24;
	time.mins=(n/60)%60;
	time.secs=n%60;
	return time;
}
void display_standard_time(time_format time){
	/*NOTE: Using power set formula to calc. possible outcomes: 2n-> 8 possibilities, 8-1=7 (neglecting null possiblity)*/
	if (time.hours&&time.mins&&time.secs)
	cout<<time.hours<<" hours "<<time.mins<<" mins "<<time.secs<<" secs";
	else if (time.mins&&time.secs)
	cout<<time.mins<<" mins "<<time.secs<<" secs";
	else if (time.hours&&time.mins)
	cout<<time.hours<<" hours "<<time.mins<<" mins";
	else if (time.hours&&time.secs)
	cout<<time.hours<<" hours "<<time.secs<<" secs";
	else if (time.secs)
	cout<<time.secs<<" secs";	
	else if (time.mins)
	cout<<time.mins<<" mins";
	else if (time.hours)
	cout<<time.hours<<" hours";
}
int main(){
	int t;
	cout<<"Enter time in seconds: ";
	cin>>t;
	display_standard_time(calc_standard_time(t));
	return 0;
}

