/* Name: Shahzaib Khan
   Roll No: 19K-0273
   Section: 3C
   Question: 2
*/
#include<iostream>
#include<conio.h>
using namespace std;
int main(){
	int a,b,c,d;
	cout<<"Enter first fraction: ";
	a=getch();
	cout<<(a-=48)<<"/";
	b=getch();
	cout<<(b-=48)<<endl;
	cout<<"Enter second fraction: ";
	c=getch();
	cout<<(c-=48)<<"/";
	d=getch();
	cout<<(d-=48)<<endl;
	cout<<"Sum: "<<(a*d+b*c)<<"/"<<(b*d);
	return 0;
}

