#include<iostream>
using namespace std;
int reverse_num(int num){
static int rev_num=0,base=1;
if(num>0){ //i.e. base condition
	reverse_num(num/10); //i.e. 1234->123->12->1->0
	rev_num+=(num%10)*base;
	base*=10;
}
return rev_num;
}
int main(){
	int num;
	cout<<"Enter Any number: ";
	cin>>num; //i.e. 1234
	cout<<"Reverse of no. is: "<<reverse_num(num);
	return 0;
}
