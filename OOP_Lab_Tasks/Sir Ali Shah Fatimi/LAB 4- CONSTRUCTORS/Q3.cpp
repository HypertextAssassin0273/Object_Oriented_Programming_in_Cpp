#include<iostream>
using namespace std;

class invoice{
	string part_no;
	string description;
	int qty;
	double price;
	
	public:
		invoice(string part_no, string description, int qty, double price){
			this->part_no=part_no;
			this->description=description;
			this->qty=qty;
			this->price=price;
		}
		
		double GetInvoiceAmount(){
			double invoice_amount;
			if(qty<0){
				qty=0;
			}
			if(price<0){
				price=0;
			}
			invoice_amount=qty*price;
			return invoice_amount;
		}
};

int main(){
	double invoice_amount;
	
	invoice ob1("abcd", "screwdriver", 5, 15);
	invoice_amount=ob1.GetInvoiceAmount();
	
	cout<<"Invoice amount: "<<invoice_amount;
	
}
