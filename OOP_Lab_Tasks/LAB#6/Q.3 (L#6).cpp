#include<iostream>
using namespace std;
class Product{
	string Product_Name;
	unsigned long Bar_Code;
public:
	Product():Product_Name("(Not Provided)"),Bar_Code(0){}
	Product(string Product_Name,unsigned long Bar_Code):
		Product_Name(Product_Name),Bar_Code(Bar_Code){}
	
	void Set_Code(unsigned long Bar_Code){ this->Bar_Code=Bar_Code; } //i.e. extra, question requirement 
	unsigned long Get_Code()const{ return Bar_Code; } //i.e. extra, question requirement	
	void _Scanner(){ //i.e. for test cases
		cout<<"Enter Product Name: ";
		cin>>Product_Name;
		cout<<"Enter Barcode: ";
		cin>>Bar_Code;
		cout<<endl;
	 }
	void _Printer()const{ //i.e. for test cases
		cout<<"Product Name: "<<Product_Name<<endl
			<<"Barcode: "<<Bar_Code<<"\n\n";
	}
};
class Prepacked_Food:private Product{
	float Unit_Price;
public:
	Prepacked_Food():Product(),Unit_Price(0){}
	Prepacked_Food(string Product_Name,unsigned long Bar_Code,float Unit_Price):
		Product(Product_Name,Bar_Code),Unit_Price(Unit_Price){}

	void Scanner(){ //i.e. for test cases
		_Scanner();
		cout<<"Enter Unit Price: ";
		cin>>Unit_Price;
		cout<<endl;
	}
	void Printer()const{ //i.e. for test cases
		_Printer();
		cout<<"Unit Price: "<<Unit_Price<<"\n\n";
	}
};
class Fresh_Food:private Product{
	float Weight,Price_per_Kilo;
public:
	Fresh_Food():Product(),Weight(0),Price_per_Kilo(0){}
	Fresh_Food(string Product_Name,unsigned long Bar_Code,float Weight,float Price_per_Kilo):
		Product(Product_Name,Bar_Code),Weight(Weight),Price_per_Kilo(Price_per_Kilo){}

	void Scanner(){ //i.e. for test cases
		_Scanner();
		cout<<"Enter Weight: ";
		cin>>Weight;
		cout<<"Enter Price (per Kilo): ";
		cin>>Price_per_Kilo;
		cout<<endl;
	 }
	void Printer()const{ //i.e. for test cases
		_Printer();
		cout<<"Weight: "<<Weight<<endl
			<<"Price (per Kilo): "<<Price_per_Kilo<<"\n\n";
	}
};
int main(){
	Product P_obj1("Doughnut",4040410),P_obj2,P_obj3;
	Prepacked_Food PF_obj1("Tuna Can",4040420,500.50),PF_obj2;
	Fresh_Food FF_obj1("Eggs",4040430,44.5,1200),FF_obj2;

	cout<<"PRODUCT OBJ 2:"<<endl;
	P_obj2._Scanner();
	cout<<"PREPACKED-FOOD OBJ 2:"<<endl;
	PF_obj2.Scanner();	
	cout<<"FRESH-FOOD OBJ 2:"<<endl;
	FF_obj2.Scanner();
	
	cout<<"\nPRODUCT OBJ 1:"<<endl;
	P_obj1._Printer();
	cout<<"PRODUCT OBJ 2:"<<endl;
	P_obj2._Printer();
	cout<<"PRODUCT OBJ 3:"<<endl;
	P_obj3._Printer();
	P_obj3.Set_Code(987654321);
	cout<<"Updated Barcode: "<<P_obj3.Get_Code()<<"\n\n";
	
	cout<<"PREPACKED-FOOD OBJ 1:"<<endl;
	PF_obj1.Printer();
	cout<<"PREPACKED-FOOD OBJ 2:"<<endl;
	PF_obj2.Printer();

	cout<<"FRESH-FOOD OBJ 1:"<<endl;
	FF_obj1.Printer();
	cout<<"FRESH-FOOD OBJ 2:"<<endl;
	FF_obj2.Printer();
	return 0;
}
