#include<iostream>
#include<string>
#include<conio.h>
#include<fstream>
using namespace std;


template <class T> class A
{
	public:
		int arr[5];
		
		void search(T x){
			for(int i=0;i<5;i++){
				if(arr[i]==x){
					cout<<"Your number "<<x<<" is on position "<<i;
				}
			}
		}
	
};


int main(){
	A<int> ob;
	
	ob.arr[0]=1;
	ob.arr[1]=2;
	ob.arr[2]=3;
	ob.arr[3]=4;
	ob.arr[4]=5;
	
	ob.search(3);
}
