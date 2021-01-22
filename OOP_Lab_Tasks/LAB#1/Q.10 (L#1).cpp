/* Name: Shahzaib Khan
   Roll No: 19K-0273
   Section: 3C
   Question: 10
*/
#include<iostream>
using namespace std;
int main(){
	long n; int count=0;
	cout<<"Enter a number string: ";
	cin>>n;
	int temp=n;
	while(temp>0){
	temp/=10;
	count++;
	}
	int number_string[count],i;
	temp=count;
	while(n>0){
		number_string[--count]=(n%10)+1;
		n/=10;
	}
	for(i=0;i<temp;i++)
	if(number_string[i]<=9)
	cout<<number_string[i];
	else
	cout<<"0";
	return 0;
}
