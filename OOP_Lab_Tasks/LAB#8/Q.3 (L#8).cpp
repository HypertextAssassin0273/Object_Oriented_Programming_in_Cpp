#include<iostream>
#include<time.h>
using namespace std;
class Phone_Call{
	unsigned __int64 Phone_No;
	unsigned short Call_Length;
	float Rate_per_Min;
public:
	Phone_Call():Phone_No(0),Call_Length(0),Rate_per_Min(0){}
	Phone_Call(unsigned __int64 Phone_No):Phone_No(Phone_No),Call_Length(0),Rate_per_Min(0){}	
	/*Note: Use of Call_Length & Rate_per_Min not stated in problem.
			Hence, only defined & initialized */
	void Set_Phone_No(unsigned __int64 Phone_No) { this->Phone_No=Phone_No; }
	void Display_Phone_No()const{ cout<<"Phone_No: "<<Phone_No<<endl; }
	
	bool operator==(const Phone_Call& obj){
		if (Phone_No==obj.Phone_No)
        return true;
        else
		return false;
    }
};
int main(){
	Phone_Call* obj=new Phone_Call[10];
	srand(time(NULL)); //i.e. for random seed
	for (unsigned char i=0;i<10;i++){ 
        obj[i] = Phone_Call(rand()% 999999999999+123456789000);
		//i.e. rand() generates random no.s lying b/w 123456789000 to 999999999999
        cout<<"Obj "<<i+1<<")  ";
		obj[i].Display_Phone_No();
    }
	cout<<"\nResults:-\n";
	if (obj[0]==obj[1])
	cout<<"obj1 & obj2 are same";
	else
	cout<<"obj1 & obj2 aren't same";
	obj[0]=obj[2]; //i.e. just for checking
	if (obj[0]==obj[2])
	cout<<"\nobj1 & obj3 are same";
	else
	cout<<"\nobj1 & obj3 aren't same";
	return 0;
}
