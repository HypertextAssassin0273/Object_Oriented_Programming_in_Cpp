#include<iostream>
using namespace std;

class Account{
	float balance;
	public:
		Account(float balance){
			this->balance=balance;
		}
		float Credit(float x){
			balance=balance+x;
		}
		float withdraw(float y){
			balance=balance-y;
		}
		float GetBalance(){
			cout<<"Current Balance: "<<balance;
		}
};


int main(){
	//current money in acc is 10,000
	Account ob1(10000);
	
	//depositing 50,000
	ob1.Credit(50000);
	
	//withdrawing 12,000
	ob1.withdraw(12000);
	
	//showing balance
	ob1.GetBalance();
}
