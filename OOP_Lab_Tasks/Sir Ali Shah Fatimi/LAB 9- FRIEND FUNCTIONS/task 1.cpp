#include<iostream>
using namespace std;



class A{
	
	public:
		float a;
		
		A(float x){
			a=x;
		}
		
		void operator --(){
			a=a*4;
		}
		
		void operator --(int ){
			a=a/4;
		}
};

int main(){

	A ob(3);
	--ob;
	cout<<"Pre Decrement: "<<ob.a<<endl;
	
	A ob1(2);
	ob1--;
	cout<<"Post Decrement: "<<ob1.a<<endl;
	
}
