#include<iostream>
using namespace std;

class printClass;

class perimeter{
	int len;
	int bre;
	
	public:
		
		perimeter(int a, int b){
			len=a;
			bre=b;
		}
		
		friend class printClass;
		
};

class printClass{
	public:
		
		void printPerimeter(perimeter & ob){
			int sum;
			sum=ob.len +ob.bre;
			cout<<"Perimeter: "<<sum;
		}
		

		
};

int main(){
	perimeter ob1(3,4);
	printClass ob2;
	
	ob2.printPerimeter(ob1);
	
}
