#include<iostream>
using namespace std;

class Book{
	public:
		string name;
		int isbn;
		string a_name;
		string publisher;
	
		void GetBookInfo(){
			cout<<"Book Name: "<<name<<endl;
			cout<<"ISB number: "<<isbn<<endl;
			cout<<"Author's Name: "<<a_name<<endl;
			cout<<"Publiusher: "<<publisher;
		}
		
		
};

int main(){
	Book ob1;
		
	ob1.name="Harry Potter";
	ob1.isbn=5540;
	ob1.a_name="JK Rowling";
	ob1.publisher="Oxford";
	
	
	ob1.GetBookInfo();
}
