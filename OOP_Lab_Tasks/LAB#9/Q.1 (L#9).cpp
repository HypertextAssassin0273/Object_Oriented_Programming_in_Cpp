#include<iostream>
using namespace std;
class Time{
	unsigned char Hours,Mins,Secs; //i.e. max limit: 255
public:
	Time(unsigned char Hours=0,unsigned char Mins=0,unsigned char Secs=0):Hours(Hours),Mins(Mins),Secs(Secs){}
	
	void Display_Standard_Time()const{ cout<<"Standard Time:  "<<(short)Hours<<" hrs : "<<(short)Mins<<" mins : "<<(short)Secs<<" secs\n"; }
	
    friend void Display_Time_in_Secs(const Time);
};
void Display_Time_in_Secs(const Time obj){
	cout<<"Time in Seconds: "<<(obj.Hours*3600+obj.Mins*60+obj.Secs)<<" secs";
}

int main(){
	Time obj(1,2,3);
	obj.Display_Standard_Time();
	Display_Time_in_Secs(obj);
	return 0;
}
