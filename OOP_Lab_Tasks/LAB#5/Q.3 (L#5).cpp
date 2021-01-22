#include<iostream>
using namespace std; 
class Bank_Account{
	unsigned int Account_Number;
	string Depositor_Name,Account_Type;
	float Balance_Amount;
	//Note: Set to constexpr (i.e. const in C++11), as information provided in this question is ambigous
 	static constexpr float Interest_Rate=404.404;
 	bool amount_flag;
 	
 	void Set_Account_Number(){ //i.e. provided so that it automatically sets the account no. for each entry
 		static unsigned int count=40400;
		Account_Number=++count;
	 }
public:
	Bank_Account(){ //i.e. default ctor
		Set_Account_Number();
		Depositor_Name="(Not Provided)";
		Account_Type="(Not Provided)";
		Balance_Amount=0;
		amount_flag=0;
	}
	Bank_Account(string Depositor_Name,string Account_Type){ //i.e. parameterized ctor
		Set_Account_Number();
		this->Depositor_Name=Depositor_Name;
		this->Account_Type=Account_Type;
		Balance_Amount=0;
		amount_flag=0;
	}
	void Deposit_Amount(float Amount){
		Balance_Amount+=Amount;
	}
	void Withdraw_Amount(float Amount){
		if (Balance_Amount>=Amount){
		Balance_Amount-=Amount;	
		amount_flag=0;
		}
		else
		amount_flag=1;
	}
	void Set_Account_Type(string Type){ //i.e. provided so that later it can be changed as per needs
		Account_Type=Type;
	}
	void Display_Account_Details()const{ //i.e. read only function
		cout<<"Account Number: "<<Account_Number<<endl
			<<"Depositor Name: "<<Depositor_Name<<endl
			<<"Account Type:   "<<Account_Type<<endl
			<<"Balance Amount: "<<Balance_Amount<<endl;
		if (amount_flag)		
		cout<<"Note: Due to Insufficient Amount in Account, you can't withdraw!\a"<<endl;
		cout<<endl;
	}
	static void Display_Interest_Rate(){
		cout<<"Interest Rate: "<<Interest_Rate<<endl;
	}
};

int main(){
	Bank_Account a1,a2("Asim Khan","current-account"),a3("Bial Ahmed","saving-account"),a4("Ahmed Shuja","current-account");
	a1.Display_Account_Details();

	a2.Deposit_Amount(1000.50);
	a2.Display_Account_Details();

	a3.Deposit_Amount(5000);
	a3.Withdraw_Amount(2000);
	a3.Display_Account_Details();

	a4.Deposit_Amount(5000);
	a4.Withdraw_Amount(10000);
	a4.Display_Account_Details();

	Bank_Account::Display_Interest_Rate();
	return 0;
}
