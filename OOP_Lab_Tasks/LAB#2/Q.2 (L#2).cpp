#include<iostream>
using namespace std;
int main(){
	int num;
	cout<<"Enter an integer number: ";
	cin>>num;
	cout<<"Divisors of "<<num<<" are: ";
	for (int i=1;i<=num;i++){
		if(!(num%i))
		cout<<i<<" ";		
	}
	return 0;
}
