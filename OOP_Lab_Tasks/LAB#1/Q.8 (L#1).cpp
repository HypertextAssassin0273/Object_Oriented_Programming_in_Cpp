/* Name: Shahzaib Khan
   Roll No: 19K-0273
   Section: 3C
   Question: 8
*/
#include<iostream>
using namespace std;
int main(){
	int ways=1,guests=0,chairs=0;
    cout<<"Enter No. of Guests: ";
    cin>>guests;
    cout<<"Enter No. of Chairs: ";
    cin>>chairs;
	for(int i=0;i<chairs;i++)
    	ways*=(guests-i);		
  	cout<<"Possible Combinations: "<<ways;
	return 0;
}

