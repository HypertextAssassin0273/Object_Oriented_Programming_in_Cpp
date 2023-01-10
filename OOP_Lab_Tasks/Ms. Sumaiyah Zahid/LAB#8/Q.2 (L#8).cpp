#include<iostream>
using namespace std;
class Time{
	unsigned char Hours,Mins,Secs; //i.e. max limit: 255
public:
	Time():Hours(0),Mins(0),Secs(0){}
	Time(unsigned char Hours,unsigned char Mins,unsigned char Secs):Hours(Hours),Mins(Mins),Secs(Secs){}
	
	void Display_Time()const{ cout<<"Time:  "<<(short)Hours<<" hrs : "<<(short)Mins<<" mins : "<<(short)Secs<<" secs\n"; }
	
	Time operator+(Time obj){
        obj.Hours+=Hours;
        obj.Mins+=Mins;
        obj.Secs+=Secs;
        return obj;
    }
	bool operator<(const Time& obj){
		if ((Hours*3600+Mins*60+Secs)<(obj.Hours*3600+obj.Mins*60+obj.Secs))
        return true;
        else 
		return false;
    }
};
int main(){
	Time obj1(1,2,3),obj2(3,2,1);
	cout<<"Obj1 ";
	obj1.Display_Time();
	cout<<"\nObj2 ";
	obj2.Display_Time();
	Time obj3=obj1+obj2,obj4; //i.e. triggers default copy ctor for obj3
	cout<<"\nObj3 ";
	obj3.Display_Time(); 
	cout<<"\nIs obj1 smaller than obj2?:  ";
	if (obj1<obj2)
	cout<<"True";
	else
	cout<<"False";
	return 0;
}
