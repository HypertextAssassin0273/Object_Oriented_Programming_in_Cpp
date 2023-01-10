#include<iostream>
using namespace std;

class Books
{
	public:
		string genre;
};

class ABC:public Books
{
	public:
		string title;
		string author;
};

class XYZ: public Books
{
	public:
		string title;
		string author;
};

int main(){
	ABC ob1;
	XYZ ob2;
	
	ob1.genre="mystery";
	ob1.title="Harry Potter";
	ob1.author="JK Rowling";
	
	ob2.genre="fiction";
	ob2.title="Programming Fundamentals";
	ob2.author="Musawar Ali";
	
	cout<<ob1.title<<endl<<ob1.author<<endl<<ob1.genre<<endl;
	
	cout<<endl<<ob2.title<<endl<<ob2.author<<endl<<ob2.genre;
	
}
