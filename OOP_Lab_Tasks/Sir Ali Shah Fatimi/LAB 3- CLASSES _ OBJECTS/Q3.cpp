#include<iostream>
using namespace std;

class glass{
	public:
		int LiquidLevel;
		
//		void drink(int milliliters){
//			
//			LiquidLevel=LiquidLevel-milliliters;
//		}
		
		void Refill(){
			int qty;
			cout<<"ENTER QUANTITY Drank: ";
			cin>>qty;
			
			LiquidLevel=LiquidLevel-qty;
			
			if(LiquidLevel<100){
				cout<<"YOU NEED A REFILL!!!";
			}
			else{
				cout<<"YOU DONT NEED A REFILL!!";
			}
		}
		
		
		glass(){
			LiquidLevel=200;
		}
};


int main(){
	glass ob1;

	ob1.Refill();
}



