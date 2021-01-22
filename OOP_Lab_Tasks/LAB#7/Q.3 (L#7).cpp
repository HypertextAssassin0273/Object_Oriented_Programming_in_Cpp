#include<iostream>
using namespace std;
class Account{
public:
	float Balance;
	
	Account():
		Balance(0){}
	Account(float Balance):
		Balance(Balance){}
	
	void Deposit(float Amount){
		Balance+=Amount;
	}
	void WithDraw(float Amount){
		if (Balance>=Amount)
		Balance-=Amount;
	}
	void Check_Balance()const{
		cout<<"Balance: "<<Balance;
	}
};
class Interest_Account: virtual public Account{
protected:
	float Interest; //Note: We can access protected attributes directly in all further inherited classes
public:
	Interest_Account():
		Interest(0.3){}
	Interest_Account(float Balance,float Interest):
		Interest(Interest/100),Account(Balance){}
	
	void Deposit(float Amount){
		Balance+=((Interest+1)*Amount); //i.e. (Interest+1)*Amount = (Interest*Amount)+Amount
	}
};

class Charging_Account: virtual public Account{
protected:
	float Fee;
public:
	Charging_Account():
		Fee(3){}
	Charging_Account(float Balance,float Fee):
		Fee(Fee),Account(Balance){}
	
	void WithDraw(float Amount){
		if (Balance>=(Fee+Amount))
		Balance-=(Fee+Amount);
	}
};

class ACI: public Interest_Account,public Charging_Account{
public:
	ACI(){}	//i.e. default ctor (Note: it also triggers the inherited classes default ctor's without calling)
	ACI(float Balance,float Interest,float Fee): //i.e. parameterized ctor
		Interest_Account(Balance,Interest),Charging_Account(Balance,Fee),Account(Balance){}
	
	template<class T>
	void Transfer(float Amount,T& obj){
		if(Balance>=Amount){
		Balance-=Amount;
		obj.Balance+=Amount;		
		}
	}
};
int main(){
	cout<<"Normal Account:-\n";
	Account obj;
	obj.Check_Balance();
	cout<<" (initial amount)"<<endl;
	obj.WithDraw(5000.5);
	obj.Check_Balance();
	cout<<" (WithDraw at zero balance)"<<endl;
	obj.Deposit(10000.5);
	obj.Check_Balance();
	cout<<" (After Deposit)"<<endl;
	obj.WithDraw(5000.5);
	obj.Check_Balance();
	cout<<" (After WithDraw)"<<"\n\n";
	
	cout<<"Interest Account:-\n";
	Interest_Account obj1;
	obj1.Check_Balance();
	cout<<" (initial amount)"<<endl;
	obj1.Deposit(30000);
	obj1.Check_Balance();
	cout<<" (After Deposit with Interest)"<<endl;
	obj1.WithDraw(1000);
	obj1.Check_Balance();
	cout<<" (After WithDraw)"<<"\n\n";
	
	cout<<"Charging Account:-\n";
	Charging_Account obj2(5000,100);
	obj2.Check_Balance();
	cout<<" (initial amount)"<<endl;
	obj2.Deposit(10000);
	obj2.Check_Balance();
	cout<<" (After Deposit)"<<endl;
	obj2.WithDraw(5000);
	obj2.Check_Balance();
	cout<<" (After WithDraw with Fees)"<<"\n\n";
	
	cout<<"ACI Account:-\n";
	ACI obj3(50000,50,10);
	obj3.Check_Balance();
	cout<<" (initial amount)"<<endl;
	obj3.Deposit(500);
	obj3.Check_Balance();
	cout<<" (After Deposit with Interest)"<<endl;
	obj3.WithDraw(1000);
	obj3.Check_Balance();
	cout<<" (After WithDraw with Fees)"<<"\n\n";

	cout<<"Amount Transfer from ACI Account to Normal Account:-"<<endl;
	obj3.Transfer(20000,obj);
	obj3.Check_Balance();
	cout<<" (ACI Account)"<<endl;
	obj.Check_Balance();
	cout<<" (Normal Account)"<<"\n\n";
	
	cout<<"Amount Transfer from ACI Account to Interest Account:-"<<endl;
	obj3.Transfer(30000,obj1);
	obj3.Check_Balance();
	cout<<" (ACI Account)"<<endl;
	obj1.Check_Balance();
	cout<<" (Interest Account)"<<endl
		<<"Note: Transfer Failed due to Insufficient Amount in ACI Account"<<"\n\n\a";
		
	cout<<"Amount Transfer from ACI Account to Charging Account:-"<<endl;
	obj3.Transfer(15000,obj2);
	obj3.Check_Balance();
	cout<<" (ACI Account)"<<endl;
	obj2.Check_Balance();
	cout<<" (Charging Account)"<<"\n\n";
	
	return 0;
}

