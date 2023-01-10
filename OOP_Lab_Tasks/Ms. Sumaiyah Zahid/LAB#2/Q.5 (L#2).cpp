#include<iostream>
using namespace std;
struct rectangle{
private:
	float length,width;
	
	float calc_perimeter(){
		return (2*(length+width));
	}
	float calc_area(){
		return (length*width);
	}
public:
	void input_values(){
		cout<<"Enter length & width for recatngle: ";
		cin>>length>>width;
	}
	void display_perimeter(){
		cout<<"\nPerimeter of rectangle: "<<calc_perimeter();
	}	
	void display_area(){
		cout<<"\nArea of rectangle: "<<calc_area();
	}
}rect;

int main(){
	rect.input_values();
	rect.display_area();
	rect.display_perimeter();
	return 0;
}

