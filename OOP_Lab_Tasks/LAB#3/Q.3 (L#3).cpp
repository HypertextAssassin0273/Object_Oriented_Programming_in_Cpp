#include<iostream>
#define N 3
using namespace std;
class invoice{
	string number,description;
	int item_quantity;
	float item_price;
public:
	void set_data(string x, string y, int m, float n){
		if (m<0)
		item_quantity=0; 
		else
		item_quantity=m; 
		if (n<0)
		item_price=0;
		else
		item_price=n;
		description=x, number=y;	
	}
	string get_description(){
		return description;
	}
	string get_number(){
		return number;
	}
	int get_item_quantity(){
		return item_quantity;
	}
	float get_item_price(){
		return item_price;
	}
	float get_invoice_amount(){
		return item_quantity*item_price;
	}
}I[N];
int main(){
	I[0].set_data("1001","ACX",15,1000),
	I[1].set_data("123","BCCI",15,3500),
	I[2].set_data("404","ErOr",15,-3500);
	cout<<"DATA INFO:-\n\n";
	for (unsigned int i=0;i<N;i++,cout<<endl){
		cout<<"$ Invoice "<<i+1<<" $\n"
			<<"Description: "<<I[i].get_description()<<endl
			<<"Number: "<<I[i].get_number()<<endl
			<<"Item Quantity: "<<I[i].get_item_quantity()<<endl
			<<"Item Price: "<<I[i].get_item_price()<<endl
			<<"Invoice Amount: "<<I[i].get_invoice_amount()<<endl;
	}
	return 0;
}
