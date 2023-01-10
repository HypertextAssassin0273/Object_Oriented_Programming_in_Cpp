#include<iostream>
using namespace std;

class Animal{
	public:
		void animalsound(){
			cout<<"The animal makes a sound"<<endl;
		}
};

class Cat: public Animal{
	public:
		void animalsound(){
			cout<<"The cat says meow"<<endl;
		}
};

class Dog:public Animal{
	public:
		void animalsound(){
			cout<<"The dog says bow wow"<<endl;
		}
};

class Duck:public Animal{
	public:
		void animalsound(){
			cout<<"The duck says quack quack"<<endl;
		}
};

int main(){
	Animal ob1;
	ob1.animalsound();
	cout<<endl;
	Cat ob2;
	ob2.animalsound();
	cout<<endl;
	Dog ob3;
	ob3.animalsound();
	cout<<endl;
	Duck ob4;
	ob4.animalsound();
}
