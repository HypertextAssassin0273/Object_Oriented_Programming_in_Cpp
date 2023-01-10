#include<iostream>
using namespace std;

class book{
	string author;
	string title;
	int price;
	string publisher;
	int stock_position;
	
	public:
		book(string title, string author, int price){
			this->title=title;
			this->author=author;
			this->price=price;
		}
		
		void Check(string title){
			int qty;
			
			if(title=="Harry Potter"){
				cout<<title<<": Yes it is in stock, how many copies would u like: ";
				cin>>qty;
				
				cout<<"Total Price: $ "<<qty*price;
			}
			else{
				cout<<endl<<endl<<title<<": Required copies not in stock";
			}
		}
};

int main(){
	book ob1("Harry Potter", "JK Rowling", 30);
	ob1.Check("Harry Potter");
	
	
	book ob2("Hunger Games","Musawar",145);
	ob2.Check("Hunger Games");
}
