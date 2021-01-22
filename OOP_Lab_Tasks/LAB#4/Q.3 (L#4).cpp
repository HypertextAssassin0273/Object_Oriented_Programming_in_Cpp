#include<iostream>
using namespace std;
class Sales{
	int SaleID,Quantity;
	string ItemName; //i.e. no need to initialize string data-type variables
public:
	Sales(){
		this->SaleID=1;this->Quantity=1;
	}
	Sales(bool X){
		if (X){
		cout<<"Enter Item Name: ";
		cin>>ItemName;
		cout<<"Enter Sale ID: ";
		cin>>SaleID;
		cout<<"Enter Quantity: ";
		cin>>Quantity;
		}
	}
	Sales(int SaleID,int Quantity,string ItemName){
		this->ItemName=ItemName;
		this->SaleID=SaleID;
		this->Quantity=Quantity;
	}
	Sales(Sales &object){
		ItemName=object.ItemName;
		SaleID=object.SaleID;
		Quantity=object.Quantity;		
	}
	void display(){
		cout<<"Item Name: "<<ItemName<<endl
			<<"Sale ID: "<<SaleID<<endl
			<<"Quantity: "<<Quantity<<endl<<endl;
	}
};
int main(){
	Sales s1; //i.e. default constructor call
	s1.display();
	Sales s2(0); //i.e. false constructor call for user input (extra)
	s2.display();
	Sales s3(1); //i.e. constructor call for user input
	s3.display();
	Sales s4(40411,5000,"BCCI-FAST"); //i.e. parameterized constructor call initialization
	s4.display();
	Sales s5=s4; //i.e. copy constructor call
	s4.display();
	return 0;
}
/*NOTE: If a constructor is called inside of another constructor,
 		then it is observed (in this program, as a test case) 
		that the constructor works as normal function
		whose variables are temporary*/
