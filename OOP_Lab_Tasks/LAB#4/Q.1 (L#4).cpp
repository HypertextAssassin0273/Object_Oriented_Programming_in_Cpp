#include<iostream>
using namespace std;
class phone{
	int area_code,exchange,number;
	bool X;
public:
	phone(string number){
		area_code=0,exchange=0,this->number=0;
		if (number[0]=='0') //i.e. checking if string starts with '0' or not 
		X=1;
		else
		X=0;
		for(unsigned char i=0,len=number.length();i<len;i++) //i.e. char range -> 255
		if (i<3)
		area_code=area_code*10+(number.at(i)-48); //i.e. ascii conversion; number.at(i)->string extractor func
		else if (i<7)
		exchange=exchange*10+(number.at(i)-48);
		else
		this->number=this->number*10+(number.at(i)-48);
	}
	void display(){
		if (X)
		cout<<"Your Area code is: 0"<<area_code<<endl;
		else
		cout<<"Your Area code is: "<<area_code<<endl;
		cout<<"Your Exchange Code is: "<<exchange<<endl
			<<"Your Consumer No is: "<<number<<endl;
	}
};
int main(){
	cout<<"Please Enter Your No: ";
	string number;
	cin>>number;
	phone p1(number);
	p1.display();
	return 0;
}
