#include<iostream>
#include<stdlib.h>
using namespace std;
class phone{
	int area_code,exchange,number;
public:
	phone(long long num){
		int count=0;
		for(long long temp=num;temp>0;temp/=10,count++); //i.e. digit counter
		if (count!=10){
		cout<<"Invalid Number Format!"<<endl;
		exit(1);
		}
		area_code=num/100000000,exchange=(num/10000)%10000,number=(num%10000);
	}
	void display(){
		cout<<"Your Area code is: 0"<<area_code<<endl;
		cout<<"Your Exchange Code is: "<<exchange<<endl;
		cout<<"Your Consumer No is: "<<number<<endl;
	}
};
int main(){
	cout<<"Please Enter Your No: ";
	long long num;
	cin>>num;
	phone p1(num);
	p1.display();
	return 0;
}
