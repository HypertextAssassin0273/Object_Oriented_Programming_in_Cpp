//exercise#2
#include<iostream>
using namespace std;
class Bank{
protected:
	int Balance;
	virtual int Get_Balance()=0;
};
class Bank_A:Bank{
public:
	Bank_A(){ Balance=100; }
	int Get_Balance()override{
		return Balance;
	}
};
class Bank_B:Bank{
public:
	Bank_B(){ Balance=150; }
	int Get_Balance()override{
		return Balance;
	}
};
class Bank_C:Bank{
public:
	Bank_C(){ Balance=200; }
	int Get_Balance()override{
		return Balance;
	}
};
int main(){
	Bank_A obj1;
	cout<<"Bank A Balance: "<<obj1.Get_Balance()<<endl;
	Bank_B obj2;
	cout<<"Bank B Balance: "<<obj2.Get_Balance()<<endl;
	Bank_C obj3;
	cout<<"Bank C Balance: "<<obj3.Get_Balance()<<endl;
	return 0;
}
