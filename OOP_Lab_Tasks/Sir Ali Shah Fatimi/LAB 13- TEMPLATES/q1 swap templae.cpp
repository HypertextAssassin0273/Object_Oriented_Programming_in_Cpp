#include<iostream>
#include<string>
#include<conio.h>
#include<fstream>
using namespace std;

class A{
	
	public:
		template<class T1> void swap(T1 x, T1 y){
			T1 temp;
			temp=x;
			x=y;
			y=temp;
			
			cout<<"x: "<<x<<endl<<"y: "<<y<<endl;
		}
	
	
};

int main(){
	A ob;
	ob.swap("yahoo","heehoo"); //x,y
}
