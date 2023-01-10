#include<iostream>
using namespace std;
class MyJava_Coffee{
	int no_of_bags,large_boxes,medium_boxes,small_boxes;
	float cost_per_bag,order_cost,large_boxes_cost,medium_boxes_cost,small_boxes_cost,TOTAL_COST;
	
	void Calculations(){
		//i.e. cost_per_bag=5.50
		order_cost=5.50*no_of_bags;
		//i.e. large_box=20,medium_box=10,small_box=5
		large_boxes=no_of_bags/20,medium_boxes=(no_of_bags%20)/10,small_boxes=((no_of_bags%20)/10)%5;
		//i.e. large_box_cost=1.80, medium_box_cost=1.00, small_box_cost=0.60
		large_boxes_cost=large_boxes*1.80,medium_boxes_cost=medium_boxes*1.00,small_boxes_cost=small_boxes*0.60;
		TOTAL_COST=order_cost+large_boxes_cost+medium_boxes_cost+small_boxes_cost;
	}
public:
	MyJava_Coffee(int no_of_bags){
		this->no_of_bags=no_of_bags;
		Calculations(); //i.e. making calculations secured
	}
	void Display_Data(){
		cout<<"Number of Bags Ordered: "<<no_of_bags<<endl;
		cout<<"The Cost of Order: $ "<<order_cost<<endl;
		cout<<"Boxes Used:\n"
			<<"  "<<large_boxes<<" Large - $ "<<large_boxes_cost<<endl
			<<"  "<<medium_boxes<<" Medium - $ "<<medium_boxes_cost<<endl
			<<"  "<<small_boxes<<" Small - $ "<<small_boxes_cost<<endl;
		cout<<"Your total cost is: $ "<<TOTAL_COST<<endl;
	}
};
int main(){
	MyJava_Coffee Outlet(52);
	Outlet.Display_Data();
	return 0;
}
