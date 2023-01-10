#include<iostream>
#include<math.h>
using namespace std;

class circle{
	float radius;
	
	public:
		static int count;
		
		circle(){
			count++;
		}
		
		circle(float radius){
			this->radius=radius;
		}
		
		float get_Area(){
			float area;
			area=3.1416*pow(radius,2);
		}
};
int circle :: count=0;
	


int main(){
	circle ob1,ob2,ob3;
	
	
}


