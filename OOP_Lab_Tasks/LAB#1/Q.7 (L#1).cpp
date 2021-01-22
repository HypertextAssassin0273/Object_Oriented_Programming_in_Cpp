/* Name: Shahzaib Khan
   Roll No: 19K-0273
   Section: 3C
   Question: 7
*/
#include<iostream>
using namespace std;
float add(float a,float b){
	return (a+b);
}
float sub(float a,float b){
	return (a-b);
}
float mul(float a,float b){
	return (a*b);
}
float div(float a,float b){
	return (a/b);
}
int main(){
	unsigned short choice; float a,b;
	cout<<"Enter First Number: ";
	cin>>a;
	cout<<"Enter Second Number: ";
	cin>>b;
	cout<<"\nWhich operation you want to run?\n1. addition\n2. subtract\n3. multiply\n4. division\n==>";
	cin>>choice;
	switch(choice){
		case 1:
		cout<<"\nResult: "<<add(a,b);
		break;
		case 2:
		cout<<"\nResult: "<<sub(a,b);
		break;
		case 3:
		cout<<"\nResult: "<<mul(a,b);
		break;
		case 4:
		cout<<"\nResult: "<<div(a,b);
		break;
		default:
		cout<<"invalid operation selected!";
		break;
	}
	return 0;
}
