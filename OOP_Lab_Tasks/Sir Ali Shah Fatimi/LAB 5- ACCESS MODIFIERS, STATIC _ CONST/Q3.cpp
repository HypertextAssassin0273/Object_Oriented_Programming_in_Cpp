#include<iostream>
using namespace std;

class Account{
	int account_no;
	int account_bal;
	int security_code;
	
	public:
		void setAccountBal(int account_bal){
			this->account_bal=account_bal;
		}
		
		void setAccountNo(int account_no){
			this->account_no=account_no;
		}
		
		void setSecurityCode(int security_code){
			this->security_code=security_code;
		}
		
		int getAccountBal(){
			return account_bal;
		}
		
		int getAccountNo(){
			return account_no;
		}
		
		int getSecurityCode(){
			return security_code;
		}
};


int main(){
	Account ob1;
	
	ob1.setAccountBal(15000);
	ob1.setAccountNo(23);
	ob1.setSecurityCode(2432);
	cout<<ob1.getAccountBal()<<endl;
	cout<<ob1.getAccountNo()<<endl;
	cout<<ob1.getSecurityCode();
}
