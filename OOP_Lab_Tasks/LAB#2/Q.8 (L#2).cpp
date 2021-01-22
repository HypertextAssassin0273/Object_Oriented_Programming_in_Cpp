#include<iostream>
using namespace std;
int count_digits(int num,int digit_counter){
	if(num>0){ //i.e. base condition
	num/=10;
	return count_digits(num,++digit_counter); //i.e. 12345,0 -> 1234,1 -> 123,2 -> 12,3 -> 1,4 -> 0,5
	}
	return digit_counter;
}
int main(){
	int num;
	cout<<"Input: ";
	cin>>num; //i.e. 12345
	cout<<"Output: "<<count_digits(num,0)<<" digits";
	return 0;
}
