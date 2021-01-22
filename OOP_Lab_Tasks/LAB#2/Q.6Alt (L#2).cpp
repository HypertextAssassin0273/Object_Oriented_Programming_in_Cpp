#include<iostream>
using namespace std;
struct time_format{
private:
	int time,secs,mins,hours;
	
	void calc_standard_time(int n){
		hours=(n/3600)%24;
		mins=(n/60)%60;
		secs=n%60;
	}
	void input_time(){
		cout<<"Enter time in seconds: ";
		cin>>time;
	}
	void display_standard_time(){
		/*NOTE: Using power set formula to calc. possible outcomes: 2n-> 8 possibilities, 8-1=7 (neglecting null possiblity)*/
		if (hours&&mins&&secs)
		cout<<hours<<" hours "<<mins<<" mins "<<secs<<" secs";
		else if (mins&&secs)
		cout<<mins<<" mins "<<secs<<" secs";
		else if (hours&&mins)
		cout<<hours<<" hours "<<mins<<" mins";
		else if (hours&&secs)
		cout<<hours<<" hours "<<secs<<" secs";
		else if (secs)
		cout<<secs<<" secs";	
		else if (mins)
		cout<<mins<<" mins";
		else if (hours)
		cout<<hours<<" hours";
}
public:
	time_format(){
		input_time();
		calc_standard_time(time);
		display_standard_time();
	}
};
int main(){
	time_format time;
	return 0;
}
