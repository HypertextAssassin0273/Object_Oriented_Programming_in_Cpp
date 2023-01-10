#include<iostream>
using namespace std;

class person{
	public:
		virtual int getData(){
			
		}
		
		virtual void displayData(){
			
		}
		
		virtual void bonus(){
			
		}
	
};

class admin:public person{
	
	public:
		int getData(){
			
		}
		
		void displayData(){
			
		}
		
		void bonus(){
			
		}
	
};

class account:public person{
	
	public:
		int getData(){
			
		}
		
		void displayData(){
			
		}
		
		void bonus(){
			
		}
	
};

class master:public admin, public account{
	
	public:
		int getData(){
			
		}
		
		void displayData(){
			
		}
		
		void bonus(){
			
		}
	
};

int main(){
	person *ob;
	ob=new admin; //here instead of admin i can put any class
	ob-> //now i can access any func of any class
}
