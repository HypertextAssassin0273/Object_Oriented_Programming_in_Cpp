#include<iostream>
using namespace std;

struct MenuItem{
			string item;
			char type;
			int price;
		};


class CoffeeShop{
	public:
		
	MenuItem m[3]={{"donuts",'f',12},{"pizza",'f',15},{"pepsi",'l',5}};
	string name;
	string order[3];
	
	
	void addOrder(){
		int i;
		for(i=0;i<3;i++){
			order[i]=m[i].item;
		}
	}
	
	void fullfillorder(){
		cout<<"All orders have been fulfilled\n\n";
	
	
	}
	
	void listOrders(){
		int i;
		for(i=0;i<3;i++){
			cout<<m[i].item<<endl;
		}
	}
	void dueAmount(){
		int sum;
		int i;
		for(i=0;i<3;i++){
			sum=sum+m[i].price;
		}
		
		cout<<"\nTotal Price: $ "<<sum;
	}
	
	void cheapestItem(){
		int i;
		string min_item;
		int low=5;
		
		for(i=0;i<2;i++){
			if(m[i].price==low){
				low=m[i].price;
				min_item=m[i].item;
			}
		}
		
		cout<<"\n\n\Cheapest item: "<<m[i].item;
		cout<<"\n\n\n";
	}
	
	void drinksOnly(){
		int i;
		string drink;
		for(i=0;i<3;i++){
			if(m[i].type=='l'){
				drink=m[i].item;
			}
		}
		
		cout<<"\nDrink is: "<<drink;
		
	}
	
	void FoodOnly(){
		int i;
		string food;
		cout<<"\n\nFood is: ";
		for(i=0;i<3;i++){
			if(m[i].type=='f'){
				food=m[i].item;
				cout<<"\n"<<food;
			}
		}
		
		
		
	}
};

int main(){
	CoffeeShop ob1;
	
	ob1.addOrder();
	ob1.fullfillorder();
	ob1.listOrders();
	ob1.dueAmount();
	ob1.cheapestItem();
	ob1.drinksOnly();
	ob1.FoodOnly();
}
