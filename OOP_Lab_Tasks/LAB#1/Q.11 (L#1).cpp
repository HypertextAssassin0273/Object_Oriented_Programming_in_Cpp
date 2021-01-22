/* Name: Shahzaib Khan
   Roll No: 19K-0273
   Section: 3C
   Question: 11
*/
#include<iostream>
using namespace std;
int main(){
	int num,lim,res=2,temp=2;
	cout<<"Enter limit for sequence: ";
	cin>>lim;
	cout<<"\nSequence: 2,";
	for(int i=0;i<lim-1;i++){
		cout<<(res+=(temp*=2))<<","; //i.e. 2+(2*2)=6+4*2=14+(8*2)=30+(16*2)=62
	}
	cout<<"\b ";
	return 0;
}

