#include<iostream>
using namespace std;

class car{
	
	public:
		string model;
		int price;
	
		
		virtual void setPrice(int x)=0;
		
		void setModel(string m){
			model=m;
		}
		
		int getPrice(){
			return price;
		}
		string getModel(){
			return model;
		}
};

class color:public car{
	
	public:
		void setPrice(int x){
			price=x;
		}
};

class company:public car{
	
	public:
		void setPrice(int x){
			price=x;
		}
};

int main(){
	color ob1;
	ob1.setModel("Toyota");
	ob1.setPrice(3500);
	
	cout<<"Model: "<<ob1.getModel()<<endl<<"Price: "<<ob1.getPrice();
}
