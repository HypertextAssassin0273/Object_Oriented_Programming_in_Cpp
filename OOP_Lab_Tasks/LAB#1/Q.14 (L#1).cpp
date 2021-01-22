/* Name: Shahzaib Khan
   Roll No: 19K-0273
   Section: 3C
   Question: 14
*/
#include<iostream>
using namespace std;
int F(int x,int y,int n){
	if (n>0)
	return x+y;
	else if(n<=0)
	return x-y;
}
int main(){
	int x,y,n;
	cout<<"Input x: ";
	cin>>x;
	cout<<"Input y: ";
	cin>>y;
	cout<<"Input n: ";
	cin>>n;
	cout<<"\nResult: "<<F(x,y,n);
	return 0;
}

